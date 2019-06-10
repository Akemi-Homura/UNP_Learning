//
// Created by quals on 2019-05-31.
//

#include <errno.h>
#include "unp.h"

/**
 * read "n" bytes from a descriptor.
 */
ssize_t read(int fd, void *vptr, size_t n) {
    size_t nleft;
    ssize_t nread;
    char *ptr;

    ptr = vptr;
    nleft = n;
    while (nleft > 0) {
        if ((nread = read(fd, ptr, nleft)) < 0) {
            if (errno == EINTR) {
                nread = 0;          /* and call read() again */
            } else {
                return (-1);
            }
        } else if (nread == 0) {
            break;                  /* EOF */
        }

        nleft -= nread;
        ptr += nread;
    }
    return (n - nleft);             /* return >= 0 */
}