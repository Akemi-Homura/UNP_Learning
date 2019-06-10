cmake_minimum_required(VERSION 3.13)
project(UNP_Learning C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_subdirectory(Chapter3)
add_subdirectory(lib)
add_subdirectory(intro)

target_link_libraries(daytimetcpcli unp)
target_link_libraries(daytimetcpsrv1 unp)