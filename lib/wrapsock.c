//
// Created by quals on 2019-06-10.
//

#include "my_err.h"
#include "unp.h"

void Listen(int fd, int backlog) {
    char *ptr;

    /* can override 2nd argument with environment variable */
    if ((ptr = getenv("LISTENQ")) != NULL) {
        backlog = atoi(ptr);
    }

    if (listen(fd, backlog) < 0) {
        err_sys("listen error");
    }
}

int Socket(int family, int type, int protocol) {
    int n;
    if ((n = socket(family, type, protocol)) < 0) {
        err_sys("socket error");
    }
    return n;
}

int Bind(int socket, const struct sockaddr *address, socklen_t address_len) {
    int v;
    if ((v = bind(socket, address, address_len)) < 0) {
        err_sys("bind error");
    }
    return v;
}

ssize_t Read(int fildes, void *buf, size_t nbyte) {
    int n;
    if ((n = read(fildes, buf, nbyte)) < 0) {
        err_sys("read error");
    }
    return n;
}

ssize_t Write(int fildes, void *buf, size_t nbyte) {
    int n;
    if ((n = write(fildes, buf, nbyte)) < 0) {
        err_sys("write error");
    }
    return n;
}

int Accept(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len) {
    int v;
    if ((v = accept(socket, address, address_len)) < 0) {
        err_sys("accept error");
    }
    return v;
}

int Close(int fieldes) {
    int v;
    if ((v = close(fieldes)) < 0) {
        err_sys("close error");
    }
    return v;
}

int Connect(int socket, const struct sockaddr *address, socklen_t address_len) {
    int v;
    if ((v = connect(socket, address, address_len)) < 0) {
        err_sys("connect error");
    }
    return v;
}

pid_t Fork() {
    int v;
    if ((v = fork()) < 0) {
        err_sys("fork error");
    }
    return v;
}

char *Fgets(char *restrict str, int size, FILE *restrict stream) {
    char *v;
    if ((v = fgets(str, size, stream)) == NULL && ferror(stream)) {
        err_sys("fgets error");
    }
    return v;
}

int Fputs(const char *restrict s, FILE *restrict stream) {
    int v;
    if ((v = fputs(s, stream)) == EOF) {
        err_sys("fputs error");
    }
    return v;
}

int Inet_pton(int af, const char *restrict src, void *restrict dst) {
    int v;
    if ((v = inet_pton(af, src, dst)) == -1) {
        err_sys("inet_pton error");
    } else if (v == 0) {
        err_msg("inet_pton error: the address was not parseable in the specified address family");
    }
    return v;
}

SigFunc *Signal(int signo, SigFunc *func) {
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