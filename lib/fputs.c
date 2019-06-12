//
// Created by quals on 2019-06-12.
//

#include "unp.h"

int Fputs(const char *restrict s, FILE *restrict stream) {
    int v;
    if ((v = fputs(s, stream)) == EOF) {
        err_sys("fputs error");
    }
    return v;
}