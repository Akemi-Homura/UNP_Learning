//
// Created by quals on 2019-06-12.
//

#include "unp.h"

SigFunc *signal(int signo, SigFunc *func) {
    struct sigaction act, oact;

    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    if (signo == SIGALRM) {
#ifdef SA_INTERRUPT
        act.sa_flags |= SA_INTERRUPT; /* SunOS 4.x */
#endif
    } else {
#ifdef SA_RESTART
        act.sa_flags |= SA_RESTART; /* SVR4, 4.4BSD */
#endif
    }
    if (sigaction(signo, &act, &oact) < 0) {
        return SIG_ERR;
    }
    return oact.sa_handler;
}

SigFunc *Signal(int signo, SigFunc *func) {
    SigFunc *sigFunc;

    if ((sigFunc = signal(signo, func)) == SIG_ERR) {
        err_sys("signal error");
    }
    return sigFunc;
}
