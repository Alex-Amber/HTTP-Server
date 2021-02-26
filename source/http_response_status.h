#ifndef EXPERIMENTAL_HTTP_SERVER_HTTP_RESPONSE_STATUS_H_
#define EXPERIMENTAL_HTTP_SERVER_HTTP_RESPONSE_STATUS_H_

#include <string>
#include <map>

namespace http_server {

  class HttpResponseStatus {
   public:
    HttpResponseStatus() = default;
    HttpResponseStatus(const int status_code);
    int get_status_code();
    std::string get_status_description();
    std::string get_status();
   private:
    int status_code_;
    std::string status_description_;
    static std::map<int, std::string> status_defs_;
  };

}  // namespace http_server

#endif  // EXPERIMENTAL_HTTP_SERVER_HTTP_RESPONSE_STATUS_H_