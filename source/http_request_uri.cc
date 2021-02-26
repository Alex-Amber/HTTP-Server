#include "http_request_uri.h"

#include <string>

namespace http_server {
  /*
   * The URI (Uniform Resource Identifier) in a HTTP request can be one of 
   * the following four cases:
   * 1. "*"
   * 2. absoluteURI
   * 3. abs_path
   * 4. authority
   * Currently we are only dealing with the 3rd case, which is absolute path.
   */
  HttpRequestUri::HttpRequestUri(const std::string &request_uri) {
    size_t delimiter_position = request_uri.find('?');
    absolute_path_ = request_uri.substr(0, delimiter_position);
    if (delimiter_position + 1 < request_uri.size()) {
      query_ = request_uri.substr(delimiter_position + 1);
    }
    // TODO(jinxinwang): check the validity of the absolute path.
    // TODO(jinxinwang): check the validity of the query.
  }

  std::string HttpRequestUri::get_absolute_path() {
    return absolute_path_;
  }

  std::string HttpRequestUri::get_query() {
    return query_;
  }

  bool HttpRequestUri::has_absolute_path() {
    return !absolute_path_.empty();
  }

  bool HttpRequestUri::has_query() {
    return !query_.empty();
  }

}  // namespace http_server