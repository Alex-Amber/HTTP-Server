cmake_minimum_required(VERSION 3.11)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

add_library(http_request_uri http_request_uri.cc)

add_library(http_response_status http_response_status.cc)

add_library(http_request http_request.cc)
target_link_libraries(http_request http_request_uri ${Boost_LIBRARIES})

add_library(http_response http_response.cc)
target_link_libraries(http_response http_response_status ${Boost_LIBRARIES})

add_library(http_server http_server.cc)
target_link_libraries(http_server http_request http_response ${Boost_LIBRARIES})

add_executable(http_response_status_test http_response_status_test.cc)
target_link_libraries(http_response_status_test http_response_status gtest_main)
add_test(NAME http_response_status_test COMMAND http_response_status_test)

add_executable(http_server_test http_server_test.cc)
target_link_libraries(http_server_test gtest_main)
add_test(NAME http_server_test COMMAND http_server_test)