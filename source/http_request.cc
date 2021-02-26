#include "http_request.h"

#include <string>
#include <map>
#include <exception>

#include "boost/asio.hpp"
#include "http_request_uri.h"

namespace http_server {
  
  HttpRequest::HttpRequest(boost::asio::ip::tcp::socket& socket) {
    // Read the request line from the socket.
    std::string buffer;
    size_t line_size = boost::asio::read_until(socket, boost::asio::dynamic_buffer(buffer), "\r\n");
    std::string request_line = buffer.substr(0, line_size - 2);
    buffer.erase(0, line_size);

    // Extract the method from the request line.
    size_t first_delim_pos = request_line.find(' ');
    method_ = request_line.substr(0, first_delim_pos);

    // Extract the object url from the request line.
    size_t second_delim_pos = request_line.find(' ', first_delim_pos + 1);
    uri_ = HttpRequestUri(request_line.substr(first_delim_pos + 1, second_delim_pos - first_delim_pos - 1));

    // Extract the http version from the request_line.
    http_version_ = request_line.substr(second_delim_pos + 1);

    // Extract the optional header lines until reaching the blank line.
    while ((line_size = boost::asio::read_until(socket, boost::asio::dynamic_buffer(buffer), "\r\n")) > 2) {
      std::string header_line = buffer.substr(0, line_size - 2);
      buffer.erase(0, line_size);
      size_t delim_pos = header_line.find(':');
      headers_[header_line.substr(0, delim_pos)] = header_line.substr(delim_pos + 2);
    }
    // Erase the blank line from buffer.
    buffer.erase(0, line_size);

    // Check whether the request includes an entity body.

    // If the entity body exists, extract it.

  }

  HttpRequest::~HttpRequest() {}

  std::string HttpRequest::get_method() {
    return method_;
  }

  HttpRequestUri HttpRequest::get_uri() {
    return uri_;
  }

  std::string HttpRequest::get_http_version() {
    return http_version_;
  }

  std::string HttpRequest::get_header_value(const std::string& header_name) {
    if (!headers_.count(header_name)) {
      throw std::runtime_error("No such header in the HTTP request.");
    }
    return headers_[header_name];
  }

  std::string HttpRequest::get_entity_body() {
    return entity_body_;
  }
}