#include <string>

#include "source/http_server.h"

int main(int argc, char **argv) {
  std::string ip_address = "127.0.0.1";
  int port = 9876;
  std::string root_path = "/home/jinxin/experimental/http_server/test";
  http_server::HttpServer server(ip_address, port, root_path, 1, 1);
  server.run();
  return 0;
}
