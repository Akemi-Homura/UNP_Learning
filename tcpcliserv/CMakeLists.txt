cmake_minimum_required(VERSION 2.8)
project(tcpcliserv C)

set(CMAKE_C_STANDARD 99)

add_executable(tcpserv01 tcpserv01.c str_echo.c)
add_executable(tcpcli01 tcpcli01.c str_cli.c)
add_executable(wait_child wait_child.c)
add_executable(tcpcli04 tcpcli04.c str_cli.c)
add_executable(tcpserv04 tcpserv04.c sigchldwaitpid.c str_echo.c)

target_link_libraries(tcpserv01 unp)
target_link_libraries(wait_child unp)
target_link_libraries(tcpcli01 unp)
target_link_libraries(tcpcli04 unp)
target_link_libraries(tcpserv04 unp)