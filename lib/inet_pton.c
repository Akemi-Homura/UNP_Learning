//
// Created by quals on 2019-06-12.
//

#include "unp.h"

int Inet_pton(int af, const char *restrict src, void *restrict dst) {
    int v;
    if ((v = inet_pton(af, src, dst)) == -1) {
        err_sys("inet_pton error");
    } else if (v == 0) {
        err_msg("inet_pton error: the address was not parseable in the specified address family");
    }
    return v;
}