#ifndef EXPERIMENTAL_HTTP_SERVER_HTTP_RESPONSE_H_
#define EXPERIMENTAL_HTTP_SERVER_HTTP_RESPONSE_H_

#include <string>
#include <map>

#include "boost/asio.hpp"
#include "http_response_status.h"

namespace http_server {

  class HttpResponse {
   public:
    HttpResponse();
    ~HttpResponse();
    std::string str();
    void sent_through_socket(boost::asio::ip::tcp::socket& socket);
    std::string get_http_version();
    std::string get_status();
    int get_status_code();
    std::string get_status_description();
    std::string get_header_value(const std::string& header_name);
    std::string get_entity_body();
    void set_http_version(const std::string& http_version);
    void set_status(const int status_code);
    void add_header_field(const std::string& header_name, const std::string& header_value);
    void set_entity_body(const std::string& entity_body);
   private:
    std::string http_version_;
    HttpResponseStatus status_;
    std::map<std::string, std::string> headers_;
    std::string entity_body_;
  };

}

#endif  // EXPERIMENTAL_HTTP_SERVER_HTTP_RESPONSE_H_
