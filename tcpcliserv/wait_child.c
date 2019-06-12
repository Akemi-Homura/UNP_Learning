//
// Created by quals on 2019-06-12.
//

#include "unp.h"
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void sig_chld(int signo){
    pid_t  pid = wait(NULL);
    printf("child %d terminated\n",pid);
}

int main(){
    Signal(SIGCHLD, sig_chld);
    if (Fork() > 0){
        sleep(4);
    }
}