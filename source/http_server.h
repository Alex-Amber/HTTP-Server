#ifndef EXPERIMENTAL_HTTP_SERVER_HTTP_SERVER_H_
#define EXPERIMENTAL_HTTP_SERVER_HTTP_SERVER_H_

#include <string>

#include "boost/asio.hpp"

namespace http_server {
  
  class HttpServer {
   public:
    HttpServer();
    HttpServer(const std::string& ip_address, const int port, const std::string& root_path);
    ~HttpServer();
    void run();
    std::string get_requested_object(const std::string& object_url);
   private:
    std::string ip_address_;
    int port_;
    std::string root_path_;
  };

}

#endif  // EXPERIMENTAL_HTTP_SERVER_HTTP_SERVER_H_