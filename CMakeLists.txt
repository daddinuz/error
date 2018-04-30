cmake_minimum_required(VERSION 3.10)
project(error C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

add_library(error sources/error.h sources/error.c)

add_executable(main examples/main.c)
target_link_libraries(main PRIVATE error)
target_include_directories(main PRIVATE sources)
