cmake_minimum_required(VERSION 3.11)
# Set the project name and version
project(HttpServer VERSION 0.1)
# Include the following modules to use.
include(FetchContent)
include(CTest)

message(${CMAKE_SOURCE_DIR})
message(${CMAKE_BINARY_DIR})

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
  SOURCE_SUBDIR  .
)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  message(${googletest_SOURCE_DIR})
  message(${googletest_BINARY_DIR})
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

# Specify the C++ standard
# Must be placed before the call to add_executable()
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Enable all warning info during compiling
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
# Enable pthread library
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(source)
