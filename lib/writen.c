//
// Created by quals on 2019-05-31.
//

#include "unp.h"

ssize_t Writen(int fd, const void *vptr, size_t n){
    size_t nleft;
    ssize_t  nwritten;
    const char * ptr;

    ptr = vptr;
    nleft = n;
    while ( nleft > 0){
        if ( (nwritten = write(fd, ptr, nleft)) <= 0){
            if (nwritten <0 && errno == EINTR){
                nwritten = 0;       /* and call write() again */
            }else{
                return -1;
            }
        }
        nleft -= nwritten;
        ptr += nwritten;
    }
    return n;
}