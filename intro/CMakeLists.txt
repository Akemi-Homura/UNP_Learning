cmake_minimum_required(VERSION 2.8)
project(intro C)

add_executable(daytimetcpsrv1 daytimetcpsrv1.c)
add_executable(daytimetcpcli daytimetcpcli.c)

target_link_libraries(daytimetcpcli unp)
target_link_libraries(daytimetcpsrv1 unp)