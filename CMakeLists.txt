cmake_minimum_required(VERSION 2.8)
project(UNP_Learning C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_subdirectory(lib)

add_subdirectory(Chapter3)
add_subdirectory(intro)
add_subdirectory(tcpcliserv)