#include "source/http_server.h"
#include "source/http_request.h"
#include "source/http_response.h"

#include <iostream>
#include <fstream>
#include <string>
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
        boost::asio::ip::tcp::socket socket(io_context);
        acceptor.accept(socket);
        // Read the HTTP request from the socket.
        HttpRequest request(socket);
        int request_http_major_version = request.get_http_major_version();
        int request_http_minor_version = request.get_http_minor_version();
        // Handle the situation where the request's http version is higher than
        // the server's http version.
        if (request_http_major_version > http_major_version_ || 
            (request_http_major_version == http_major_version_ && 
            request_http_minor_version > http_minor_version_)) {
          HttpResponse response;
          response.set_http_major_version(http_major_version_);
          response.set_http_minor_version(http_minor_version_);
          response.set_status(505);
          response.sent_through_socket(socket);
        } else if (request.get_method() == "HEAD") {
          HttpResponse response;
          response.set_http_major_version(http_major_version_);
          response.set_http_minor_version(http_minor_version_);
          response.set_status(405);
          response.sent_through_socket(socket);
        } else if (request.get_method() != "GET" && request.get_method() != "HEAD") {
          HttpResponse response;
          response.set_http_major_version(http_major_version_);
          response.set_http_minor_version(http_minor_version_);
          response.set_status(501);
          response.sent_through_socket(socket);
        } else {
          // Extract the requested object url.
          std::string object_relative_path = request.get_uri().get_absolute_path();
          std::cout << object_relative_path << std::endl;
          // Get the requested object.
          std::string requested_object = get_requested_object(object_relative_path);
          // Construct the response object and send it to the client through socket.
          HttpResponse response;
          // TODO(jinxinwang): verify the logic of determining the http version 
          // of the response when the http request and the server have different 
          // http versions.
          response.set_http_major_version(http_major_version_);
          response.set_http_minor_version(http_minor_version_);
          response.set_status(200);
          response.set_entity_body(requested_object);
          response.sent_through_socket(socket);
        }
      }
    }
    catch (std::exception& e) {
      std::cerr << e.what() << std::endl;
    }
    return;
  }

  std::string HttpServer::get_requested_object(const std::string& object_relative_path) {
    // Check the validity of the argument object_url.

    std::string object_absolute_path = root_path_ + object_relative_path;
    std::ifstream ifs(object_absolute_path);
    std::ostringstream oss;
    if (ifs) {
      // Read the entire content of the file into a string
      oss << ifs.rdbuf();
    } else {
      throw std::runtime_error("Fail to access the requested object.");
    }
    return oss.str();
  }
}

