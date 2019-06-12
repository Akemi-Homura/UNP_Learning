//
// Created by quals on 2019-06-12.
//

#include "unp.h"

pid_t Fork() {
    int v;
    if ((v = fork()) < 0) {
        err_sys("fork error");
    }
    return v;
}