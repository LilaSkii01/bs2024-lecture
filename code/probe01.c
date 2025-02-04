#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    int pid = fork();
    printf("A");

    if (pid < 0) {
        printf("F");
        exit(1);
    } else if (pid == 0) {
        printf("B");
        exit(0);
    } else {
        printf("C");
        wait(NULL);
    }

    printf("D");
    exit(0);
}