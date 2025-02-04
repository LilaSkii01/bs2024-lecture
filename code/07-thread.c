#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>

void *mythread(void *arg) {
    char *letter = arg;
    printf("Hello from Thread %s (pid: %d)! Argument of mythread() is stored at %p and points to %p!\n", 
	        letter, getpid(), &arg, arg);
    return NULL;
}

int main(int argc, char *argv[]) {
	pid_t pid = fork();
    pthread_t p1, p2;
    printf("Hello from the main thread (PID %d)\n", getpid());
    pthread_create(&p1, NULL, mythread, "A"); 
    pthread_create(&p2, NULL, mythread, "B");
	if (pid) {
		printf("Main thread waiting for PID %d\n", pid);
		waitpid(pid, NULL, 0);
	}
    // join waits for the threads to finish
    pthread_join(p1, NULL);
    pthread_join(p2, NULL); 
    printf("main thread (PID %d): done\n", getpid());
    return 0;
}
