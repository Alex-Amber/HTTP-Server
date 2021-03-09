cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(HttpServer VERSION 0.1)

# add the executable
# executable refers to the file containing the main() function
add_executable(HttpServer main/main.cc)
