#include "http_response.h"

#include <string>
#include <map>
#include <exception>

#include "boost/asio.hpp"
#include "http_response_status.h"

namespace http_server {

  HttpResponse::HttpResponse() {}

  HttpResponse::~HttpResponse() {}

  std::string HttpResponse::str() {
    std::string serialized_response;
    serialized_response += (this->get_http_version() + " " + status_.get_status() + "\r\n");
    for (auto& entry : headers_) {
      serialized_response += (entry.first + ": " + entry.second + "\r\n");
    }
    serialized_response += "\r\n";
    serialized_response += entity_body_;
    return serialized_response;
  }

  void HttpResponse::sent_through_socket(boost::asio::ip::tcp::socket& socket) {
    const std::string serialized_response = this->str();
    boost::asio::write(socket, boost::asio::buffer(serialized_response));
    return;
  }

  std::string HttpResponse::get_http_version() {
    return std::to_string(http_major_version_) + "." + std::to_string(http_minor_version_);
  }

  std::string HttpResponse::get_status() {
    return status_.get_status();
  }

  int HttpResponse::get_status_code() {
    return status_.get_status_code();
  }

  std::string HttpResponse::get_status_description() {
    return status_.get_status_description();
  }

  std::string HttpResponse::get_header_value(const std::string& header_name) {
    if (!headers_.count(header_name)) {
      throw std::runtime_error("No such header in the response.");
    }
    return headers_[header_name];
  }

  std::string HttpResponse::get_entity_body() {
    return entity_body_;
  }

  void HttpResponse::set_http_major_version(int http_major_version) {
    http_major_version_ = http_major_version;
  }

  void HttpResponse::set_http_minor_version(int http_minor_version) {
    http_minor_version_ = http_minor_version;
  }

  void HttpResponse::set_status(const int status_code) {
    status_ = HttpResponseStatus(status_code);
  }

  void HttpResponse::add_header_field(const std::string& header_name, const std::string& header_value) {
    headers_[header_name] = header_value;
  }

  void HttpResponse::set_entity_body(const std::string& entity_body) {
    entity_body_ = entity_body;
    return;
  }

}  // namespace http_server
