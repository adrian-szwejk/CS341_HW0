#include <stdio.h>
#include <stdlib.h>
/* unistd.h and fork are part of 
the POSIX standard. 
They aren't available on windows*/
#include <unistd.h>

int main() {
    //Turn single process into TWO
    printf("Hello!\n");

    pid_t child_id = fork();

    //Standard for PARENT to WAIT for CHILD to FINISH
    if (child_id > 0) {
        //ADULT
        int status;
        waitpid(child_id, &status, 0);
        //Use status to see if child EXITED normally
        printf("I am the ADULT process\n"); 
    }
    if (child_id == 0) {
        //CHILD
        printf("I am the CHILD process\n");
    }

    //We split into two processes so it prints TWICE
    //Parent-child relationship between processes
    printf("%d : Process id %d\n", child_id, getpid());
    //Separate memory space for each process
    return EXIT_SUCCESS;
}