cmake_minimum_required(VERSION 3.11)

# Set the project name and version
project(HttpServer VERSION 0.1)

message(${CMAKE_SOURCE_DIR})
message(${CMAKE_BINARY_DIR})

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

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
# Add the executable
# Executable refers to the file containing the main() function
add_executable(http_server_main main/main.cc)

target_include_directories(http_server_main BEFORE PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(http_server_main http_server)