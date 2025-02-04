#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        puts("Hi, I'm the child, and I'll turn into a zombie now.");
        exit(42);
    } else {
        printf("Hi, I'm the parent, and the child has pid %d\n", pid);
        puts("Now is a good time to use ps to check for my zombie child!");
        sleep(30);
        int status = 0;
        waitpid(pid, &status, 0);
        printf("Child finished with exit code %d.\n", status);
        sleep(10);
        puts("Parent says goodbye!");
    }
    return 0; 
}