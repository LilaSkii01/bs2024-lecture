#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    puts("This is the beginning"); /* printed once */
    pid_t pid = fork();
    if (pid == -1) { /* in exceptional circumstances, fork can also fail */
        puts("Failed to create child.");
    } else if (pid == 0) { /* fork returns 0 to the child */
        puts("Hello from the child");
    } else { /* fork returns child's pid to the parent */
        printf("The child has pid: %i\n", pid);
    }
    puts("Goodbye!"); /* printed twice */
    return 0; 
}