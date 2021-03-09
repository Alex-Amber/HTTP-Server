cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(HttpServer VERSION 0.1)

# Specify the C++ standard
# Must be placed before the call to add_executable()
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD REQUIRED True)

# Add the executable
# Executable refers to the file containing the main() function
add_executable(HttpServer main/main.cc)
