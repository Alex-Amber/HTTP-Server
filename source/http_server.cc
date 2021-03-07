#include "source/http_server.h"
#include "source/http_request.h"
#include "source/http_response.h"

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <memory>
#include <stdexcept>

#include "boost/asio.hpp"

namespace http_server {
  
  HttpServer::HttpServer(const std::string& ip_address, const int port, const std::string& root_path, const int http_major_version, const int http_minor_version) {
    // Check the validity of the argument ip_address.

    // Check the validity of the argument port.

    // Check the validity of the argument root_path.

    ip_address_ = ip_address;
    port_ = port;
    root_path_ = root_path;
    http_major_version_ = http_major_version;
    http_minor_version_ = http_minor_version;
  }

  HttpServer::~HttpServer() {}

  void HttpServer::run() {
    try {
      boost::asio::io_context io_context;
      boost::asio::ip::tcp::acceptor acceptor(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port_));
      for (;;) {
        auto socket_ptr = std::make_shared<boost::asio::ip::tcp::socket>(io_context);
        acceptor.accept(*socket_ptr);
        std::thread t(handle_single_connection, socket_ptr, std::ref(*this));
        t.join();
      }
    }
    catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
    return;
  }

  void HttpServer::handle_single_request(std::shared_ptr<boost::asio::ip::tcp::socket> socket_ptr) {
    // Construct empty HTTP request and response objects.
    HttpRequest request;
    HttpResponse response;
    // TODO(jinxinwang): verify the logic of determining the http version 
    // of the response when the http request and the server have different 
    // http versions.
    response.set_http_major_version(http_major_version_);
    response.set_http_minor_version(http_minor_version_);
    try {
      // Read the HTTP request from the socket.
      // Handle the situations where requests cannot be parsed correctly.
      if (request.parse_from_socket(*socket_ptr)) {
        response.set_status(400);
        response.sent_through_socket(*socket_ptr);
        return;
      }
      int request_http_major_version = request.get_http_major_version();
      int request_http_minor_version = request.get_http_minor_version();
      // Handle the situation where the request's http version is higher than
      // the server's http version.
      if (request_http_major_version > http_major_version_ || 
          (request_http_major_version == http_major_version_ && 
          request_http_minor_version > http_minor_version_)) {
        response.set_status(505);
        response.sent_through_socket(*socket_ptr);
        return;
      }
      if (request.get_method() == "HEAD") {
        response.set_status(405);
        response.sent_through_socket(*socket_ptr);
        return;
      }
      if (request.get_method() != "GET" && request.get_method() != "HEAD") {
        response.set_status(501);
        response.sent_through_socket(*socket_ptr);
        return;
      }
      // Extract the requested object url.
      std::string object_relative_path = request.get_uri().get_absolute_path();
      // Get the requested object.
      std::string requested_object;
      // Handle the error that the server failed to get the requested object.
      if (get_requested_object(object_relative_path, requested_object)) {
        response.set_status(404);
        response.sent_through_socket(*socket_ptr);
        return;
      }
      response.set_status(200);
      response.set_entity_body(requested_object);
      response.sent_through_socket(*socket_ptr);
    }
    // Handle all other errors happening during fulfilling the request.
    catch (std::exception &e) {
      response.set_status(500);
      response.sent_through_socket(*socket_ptr);
    }
  }
  
  int HttpServer::get_requested_object(const std::string &object_relative_path, std::string &requested_object) {
    // Check the validity of the argument object_url.

    std::string object_absolute_path = root_path_ + object_relative_path;
    std::ifstream ifs(object_absolute_path);
    std::ostringstream oss;
    if (ifs) {
      // Read the entire content of the file into a string
      oss << ifs.rdbuf();
      requested_object = oss.str();
      return 0;
    } else {
      return 1;
    }
  }

  void handle_single_connection(std::shared_ptr<boost::asio::ip::tcp::socket> socket_ptr,
                                HttpServer &server) {
    server.handle_single_request(socket_ptr);
  }

}
