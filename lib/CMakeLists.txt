cmake_minimum_required(VERSION 2.8)
project(lib C)

add_library(unp
        readn.c
        writen.c
        sock_ntop.c
        wrapsock.c
        err.c
        readline_fast.c
        sockfd_to_family.c
        signal.c
        fork.c
        fgets.c
        fputs.c
        inet_pton.c)
add_library(readline readline.c)