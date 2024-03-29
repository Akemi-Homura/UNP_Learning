//
// Created by quals on 2019-05-31.
//

#include "unp.h"

/* PAINFULLY SLOW VERSION -- example only */
ssize_t Readline(int fd, void *vptr, size_t maxlen) {
    ssize_t n, rc;
    char c, *ptr;

    ptr = vptr;
    for (n = 1; n < maxlen; n++) {
        if ((rc = read(fd, &c, 1)) == 1) {
            *ptr++ = c;
            if (c == '\n')
                break;          /* newline is stored, like fgtes() */
        } else if (rc == 0) {
            *ptr = 0;
            return (n - 1);     /* EOF, n - 1 bytes were read */
        } else {
            if (errno == EINTR) {
                continue;
            }
            return -1;          /* errno, errno set by read() */
        }
    }
    *ptr = 0;
    return n;
}