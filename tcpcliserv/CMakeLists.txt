cmake_minimum_required(VERSION 2.8)
project(tcpcliserv C)

set(CMAKE_C_STANDARD 99)

add_executable(tcpserv01 tcpserv01.c)
add_executable(tcpcli01 tcpcli01.c)
add_executable(wait_child wait_child.c)

target_link_libraries(tcpserv01 unp)
target_link_libraries(tcpcli01 unp)
target_link_libraries(wait_child unp)