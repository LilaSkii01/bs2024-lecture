#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

char *getcmd() {
    char *buf = malloc(256);
    scanf("%s", buf);
    return buf;
}

int main(int argc, char const *argv[])
{
    while (1) {
        char *cmd = getcmd();
        pid_t pid = fork();
        if (pid == 0) {
            // This is the child process. Setup the child's process environment here
            // E.g., where is standard I/O, how to handle signals?
            execl(cmd, cmd);
            // exec does not return if it succeeds
            printf("ERROR: Could not execute %s\n", cmd);
            exit(1);
        } else {
            // This is the parent process; Wait for child to finish
            // wait(NULL); // Simple wait call for only child
            printf("Child (PID: %d) running\n", pid);
            int status = 0;
            waitpid(pid, &status, 0);
            printf("Child exited with status %d\n", status);
        }
        free(cmd);
    }
    return 0;
}

