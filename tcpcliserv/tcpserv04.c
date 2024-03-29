//
// Created by quals on 2019-06-12.
// 处理accept返回EINTR错误的TCP服务器程序最终（正确）版本
//

#include "unp.h"

extern void sig_chld(int signo);

extern void str_echo(int);

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

    Signal(SIGCHLD, sig_chld); /* must call waitpid */

    while (1) {
        clilen = sizeof(cliaddr);
        if ((connfd = accept(listenfd, (SA *) &cliaddr, &clilen)) < 0) {
            if (errno == EINTR) {
                continue;       /* back to for */
            } else {
                err_sys("accept error");
            }
        }
        if ((childpid = Fork()) == 0) {      /* child process */
            Close(listenfd);                /* close listening socket */
            str_echo(connfd);               /* process the request */
            exit(0);
        }
        Close(connfd);                      /* parent closes connected socket */
    }
}