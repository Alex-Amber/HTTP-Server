#ifndef EXPERIMENTAL_HTTP_SERVER_HTTP_REQUEST_URI_H_
#define EXPERIMENTAL_HTTP_SERVER_HTTP_REQUEST_URI_H_

#include <string>

namespace http_server {
  
  class HttpRequestUri {
   public:
    HttpRequestUri() = default;
    HttpRequestUri(const std::string &request_uri);
    std::string get_absolute_path();
    std::string get_query();
    bool has_absolute_path();
    bool has_query();
   private:
    std::string absolute_path_;
    std::string query_;
  };

  bool is_absolute_path_valid(const std::string& absolute_path);
  bool is_query_valid(const std::string& query);

}  // namespace http_server

#endif  // EXPERIMENTAL_HTTP_SERVER_HTTP_REQUEST_URI_H_