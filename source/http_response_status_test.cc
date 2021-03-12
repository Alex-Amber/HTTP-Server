#include "http_response_status.h"

#include "gtest/gtest.h"

namespace http_server {

class HttpResponseStatusTest : public ::testing::Test {
 protected:
  void SetUp() override {}

  void TearDown() override {}
};

// According to RFC 7231, test all HTTP response status codes in the section 6.
// The complete list of HTTP status codes are maintained by the Internet 
// Assigned Numbers Authority (IANA). See <http://www.iana.org/assignments/http-status-codes>.
TEST_F(HttpResponseStatusTest, ValidHttpStatusTest) {
  HttpResponseStatus status100(100);
  EXPECT_EQ(status100.get_status_code(), 100);
  EXPECT_EQ(status100.get_status_description(), "Continue");

  HttpResponseStatus status101(101);
  EXPECT_EQ(status101.get_status_code(), 101);
  EXPECT_EQ(status101.get_status_description(), "Switching Protocols");

  HttpResponseStatus status200(200);
  EXPECT_EQ(status200.get_status_code(), 200);
  EXPECT_EQ(status200.get_status_description(), "OK");

  HttpResponseStatus status201(201);
  EXPECT_EQ(status201.get_status_code(), 201);
  EXPECT_EQ(status201.get_status_description(), "Created");

  HttpResponseStatus status202(202);
  EXPECT_EQ(status202.get_status_code(), 202);
  EXPECT_EQ(status202.get_status_description(), "Accepted");

  HttpResponseStatus status203(203);
  EXPECT_EQ(status203.get_status_code(), 203);
  EXPECT_EQ(status203.get_status_description(), "Non-Authoritative Information");

  HttpResponseStatus status204(204);
  EXPECT_EQ(status204.get_status_code(), 204);
  EXPECT_EQ(status204.get_status_description(), "No Content");

  HttpResponseStatus status205(205);
  EXPECT_EQ(status205.get_status_code(), 205);
  EXPECT_EQ(status205.get_status_description(), "Reset Content");

  HttpResponseStatus status206(206);
  EXPECT_EQ(status206.get_status_code(), 206);
  EXPECT_EQ(status206.get_status_description(), "Partial Content");

  HttpResponseStatus status300(300);
  EXPECT_EQ(status300.get_status_code(), 300);
  EXPECT_EQ(status300.get_status_description(), "Multiple Choices");

  HttpResponseStatus status301(301);
  EXPECT_EQ(status301.get_status_code(), 301);
  EXPECT_EQ(status301.get_status_description(), "Moved Permanently");

  HttpResponseStatus status302(302);
  EXPECT_EQ(status302.get_status_code(), 302);
  EXPECT_EQ(status302.get_status_description(), "Found");

  HttpResponseStatus status303(303);
  EXPECT_EQ(status303.get_status_code(), 303);
  EXPECT_EQ(status303.get_status_description(), "See Other");

  HttpResponseStatus status304(304);
  EXPECT_EQ(status304.get_status_code(), 304);
  EXPECT_EQ(status304.get_status_description(), "Not Modified");

  HttpResponseStatus status305(305);
  EXPECT_EQ(status305.get_status_code(), 305);
  EXPECT_EQ(status305.get_status_description(), "Use Proxy");

  HttpResponseStatus status307(307);
  EXPECT_EQ(status307.get_status_code(), 307);
  EXPECT_EQ(status307.get_status_description(), "Temporary Redirect");

  HttpResponseStatus status400(400);
  EXPECT_EQ(status400.get_status_code(), 400);
  EXPECT_EQ(status400.get_status_description(), "Bad Request");

  HttpResponseStatus status401(401);
  EXPECT_EQ(status401.get_status_code(), 401);
  EXPECT_EQ(status401.get_status_description(), "Unauthorized");

  HttpResponseStatus status402(402);
  EXPECT_EQ(status402.get_status_code(), 402);
  EXPECT_EQ(status402.get_status_description(), "Payment Required");

  HttpResponseStatus status403(403);
  EXPECT_EQ(status403.get_status_code(), 403);
  EXPECT_EQ(status403.get_status_description(), "Forbidden");

  HttpResponseStatus status404(404);
  EXPECT_EQ(status404.get_status_code(), 404);
  EXPECT_EQ(status404.get_status_description(), "Not Found");

  HttpResponseStatus status405(405);
  EXPECT_EQ(status405.get_status_code(), 405);
  EXPECT_EQ(status405.get_status_description(), "Method Not Allowed");

  HttpResponseStatus status406(406);
  EXPECT_EQ(status406.get_status_code(), 406);
  EXPECT_EQ(status406.get_status_description(), "Not Acceptable");

  HttpResponseStatus status407(407);
  EXPECT_EQ(status407.get_status_code(), 407);
  EXPECT_EQ(status407.get_status_description(), "Proxy Authentication Required");

  HttpResponseStatus status408(408);
  EXPECT_EQ(status408.get_status_code(), 408);
  EXPECT_EQ(status408.get_status_description(), "Request Timeout");

  HttpResponseStatus status409(409);
  EXPECT_EQ(status409.get_status_code(), 409);
  EXPECT_EQ(status409.get_status_description(), "Conflict");

  HttpResponseStatus status410(410);
  EXPECT_EQ(status410.get_status_code(), 410);
  EXPECT_EQ(status410.get_status_description(), "Gone");

  HttpResponseStatus status411(411);
  EXPECT_EQ(status411.get_status_code(), 411);
  EXPECT_EQ(status411.get_status_description(), "Length Required");

  HttpResponseStatus status412(412);
  EXPECT_EQ(status412.get_status_code(), 412);
  EXPECT_EQ(status412.get_status_description(), "Precondition Failed");

  HttpResponseStatus status413(413);
  EXPECT_EQ(status413.get_status_code(), 413);
  EXPECT_EQ(status413.get_status_description(), "Payload Too Large");

  HttpResponseStatus status414(414);
  EXPECT_EQ(status414.get_status_code(), 414);
  EXPECT_EQ(status414.get_status_description(), "URI Too Long");

  HttpResponseStatus status415(415);
  EXPECT_EQ(status415.get_status_code(), 415);
  EXPECT_EQ(status415.get_status_description(), "Unsupported Media Type");

  HttpResponseStatus status416(416);
  EXPECT_EQ(status416.get_status_code(), 416);
  EXPECT_EQ(status416.get_status_description(), "Range Not Satisfiable");

  HttpResponseStatus status417(417);
  EXPECT_EQ(status417.get_status_code(), 417);
  EXPECT_EQ(status417.get_status_description(), "Expectation Failed");

  HttpResponseStatus status426(426);
  EXPECT_EQ(status426.get_status_code(), 426);
  EXPECT_EQ(status426.get_status_description(), "Upgrade Required");

  HttpResponseStatus status500(500);
  EXPECT_EQ(status500.get_status_code(), 500);
  EXPECT_EQ(status500.get_status_description(), "Internal Server Error");

  HttpResponseStatus status501(501);
  EXPECT_EQ(status501.get_status_code(), 501);
  EXPECT_EQ(status501.get_status_description(), "Not Implemented");

  HttpResponseStatus status502(502);
  EXPECT_EQ(status502.get_status_code(), 502);
  EXPECT_EQ(status502.get_status_description(), "Bad Gateway");

  HttpResponseStatus status503(503);
  EXPECT_EQ(status503.get_status_code(), 503);
  EXPECT_EQ(status503.get_status_description(), "Service Unavailable");

  HttpResponseStatus status504(504);
  EXPECT_EQ(status504.get_status_code(), 504);
  EXPECT_EQ(status504.get_status_description(), "Gateway Timeout");

  HttpResponseStatus status505(505);
  EXPECT_EQ(status505.get_status_code(), 505);
  EXPECT_EQ(status505.get_status_description(), "HTTP Version Not Supported");
}

}  // namespace http_server