cmake_minimum_required(VERSION 2.8)
project(lib C)

add_library(unp readline.c readn.c writen.c sock_ntop.c wrapsock.c err.c)
add_library(readline_fast readline_fast.c)