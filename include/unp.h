//
// Created by quals on 2019-05-31.
//

#ifndef UNP_LEARNING_UNP_H
#define UNP_LEARNING_UNP_H

#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include "my_err.h"

/* Following could be derived from SOMAXCONN in <sys/socket.h>, but many
 * kernels still #define it as 5, while actually supporting many more */
#define LISTENQ 1024            /* 2nd argument to listen */

/* Miscellaneous constants */
#define MAXLINE 4096           /* max text line length */
#define BUFFSIZE 8192          /* buffer size for reads and writes */

/* Following shortens all the typecasts of pointer arguments */
#define SA struct sockaddr

/* sock_ functions */
char *sock_ntop(const struct sockaddr* sockaddr, socklen_t addrlen);

/* wrap socket */
void Listen(int fd,int backlog);
int Socket(int family, int type, int protocol);
int Bind(int socket, const struct sockaddr* address, socklen_t address_len);
ssize_t Read(int fildes, void *buf, size_t nbyte);
ssize_t Write(int fildes, void *buf, size_t nbyte);
int Accept(int socket, struct sockaddr*restrict address, socklen_t *restrict address_len);
int Close(int fieldes);
int Connect(int socket, const struct sockaddr* address, socklen_t address_len);


ssize_t readn(int fd, void *vptr, size_t n);
ssize_t writen(int fd, const void* vptr, size_t n);
ssize_t readline(int fd, void* vptr, size_t maxlen);
#endif //UNP_LEARNING_UNP_H
