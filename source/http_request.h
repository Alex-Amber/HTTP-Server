#ifndef EXPERIMENTAL_HTTP_SERVER_HTTP_REQUEST_H_
#define EXPERIMENTAL_HTTP_SERVER_HTTP_REQUEST_H_

#include <string>
#include <map>

#include "boost/asio.hpp"
#include "http_request_uri.h"

namespace http_server {
  
  class HttpRequest {
   public:
    HttpRequest() = delete;
    HttpRequest(boost::asio::ip::tcp::socket& socket);
    ~HttpRequest();
    std::string get_method();
    HttpRequestUri get_uri();
    int get_http_major_version();
    int get_http_minor_version();
    std::string get_http_version();
    std::string get_header_value(const std::string& header_name);
    std::string get_entity_body();
   private:
    std::string method_;
    HttpRequestUri uri_;
    int http_major_version_;
    int http_minor_version_;
    std::map<std::string, std::string> headers_;
    std::string entity_body_;
  };


}

#endif  // EXPERIMENTAL_HTTP_SERVER_HTTP_REQUEST_H_