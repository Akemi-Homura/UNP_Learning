//
// Created by quals on 2019-05-30.
//

#include <stdio.h>

int main(int argc, char **argv) {
    union {
        short s;
        char c[sizeof(short)];
    } un;

    un.s = 0x0102;
    printf("macosx: ");
    if (un.c[0] == 1 && un.c[1] == 2) {
        printf("big-endian\n");
    } else if (un.c[0] == 2 && un.c[1] == 1) {
        printf("little-endian\n");
    } else {
        printf("unknown\n");
    }
    return 0;
}