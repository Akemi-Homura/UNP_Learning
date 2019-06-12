//
// Created by quals on 2019-06-12.
//

#include "unp.h"

char *Fgets(char *restrict str, int size, FILE *restrict stream) {
    char *v;
    if ((v = fgets(str, size, stream)) == NULL && ferror(stream)) {
        err_sys("fgets error");
    }
    return v;
}