cmake_minimum_required(VERSION 3.16)
project(irisCNN)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
add_subdirectory(src)

add_executable(irisCNN main.cpp)
target_link_libraries(irisCNN src)