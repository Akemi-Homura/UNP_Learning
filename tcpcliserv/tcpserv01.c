//
// Created by quals on 2019-06-11.
//

#include "unp.h"

void str_echo(int sockfd) {
    ssize_t n;
    char buf[MAXLINE];
    while (1) {
        while ((n = read(sockfd, buf, MAXLINE)) > 0) {
            Writen(sockfd, buf, n);
        }
        if (n < 0 && errno == EINTR) {
            continue;
        } else if (n < 0) {
            err_sys("str_echo: read error");
        }
        break;
    }
}

void sig_chld(int signo) {
    printf("recv signal %d\n", signo);
    pid_t pid;
    int stat;

    pid = wait(&stat);
    printf("child %d terminated\n", pid);
}

int main(int argc, char **argv) {
    int listenfd, connfd;
    pid_t childpid;
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;
    listenfd = Socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));
    Listen(listenfd, LISTENQ);

    Signal(SIGCHLD, sig_chld);

    if (Fork() == 0) {
        return 0;
    }

    while (1) {
        clilen = sizeof(cliaddr);
        connfd = Accept(listenfd, (SA *) &cliaddr, &clilen);
        if ((childpid = Fork()) == 0) { /* child process */
            Close(listenfd);            /* close listening socket */
            str_echo(connfd);           /* process the request */
            exit(0);
        }
        Close(connfd);                  /* parent close connected socket */
    }
}