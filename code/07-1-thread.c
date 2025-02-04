#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) {
    int id = *(int*)arg;
    printf("Thread %d is running\n", id);
    sleep(2); // Simulate some work
    printf("Thread %d finished\n", id);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int ids[3] = {1, 2, 3};

    // Creating 3 user-level threads
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, thread_function, &ids[i]);
    }

    // Waiting for threads to complete
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed\n");
    return 0;
}
