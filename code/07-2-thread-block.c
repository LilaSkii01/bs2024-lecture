#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Thread function
void* thread_function(void* arg) {
    int id = *(int*)arg;
    printf("Thread %d is running\n", id);
    
    if (id == 1) {
        printf("Thread %d doing I/O operation (blocking)\n", id);
        sleep(5); // Simulating a blocking I/O call
    }

    printf("Thread %d finished\n", id);
    return NULL;
}

int main() {
    pthread_t threads[2];
    int ids[2] = {1, 2};

    // Create two threads
    pthread_create(&threads[0], NULL, thread_function, &ids[0]);
    pthread_create(&threads[1], NULL, thread_function, &ids[1]);

    // Wait for both threads
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    printf("Main thread finished\n");
    return 0;
}

/* output:
Thread 1 is running
Thread 1 doing I/O operation (blocking)
Thread 2 is running
Thread 2 finished
Thread 1 finished
*/

/* which means he threading model used in your system 
is not pure user-level threading (1:N model), 
but rather kernel-level threading (1:1 model) */