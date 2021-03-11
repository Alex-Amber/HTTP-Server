cmake_minimum_required(VERSION 3.10)

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