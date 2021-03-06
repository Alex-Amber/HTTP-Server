#ifndef EXPERIMENTAL_HTTP_SERVER_HTTP_SERVER_H_
#define EXPERIMENTAL_HTTP_SERVER_HTTP_SERVER_H_

#include <string>
#include <memory>

#include "boost/asio.hpp"

namespace http_server {
  
  class HttpServer {
   public:
    HttpServer() = delete;
    HttpServer(const std::string& ip_address, const int port, const std::string& root_path, const int http_major_version, const int http_minor_version);
    ~HttpServer();
    void run();
    void handle_single_request(std::shared_ptr<boost::asio::ip::tcp::socket> socket_ptr);
    int get_requested_object(const std::string &object_relative_path, std::string &requested_object);
   private:
    std::string ip_address_;
    int port_;
    std::string root_path_;
    int http_major_version_;
    int http_minor_version_;
  };

  void handle_single_connection(std::shared_ptr<boost::asio::ip::tcp::socket> socket_ptr,
                                HttpServer &server);
}

#endif  // EXPERIMENTAL_HTTP_SERVER_HTTP_SERVER_H_