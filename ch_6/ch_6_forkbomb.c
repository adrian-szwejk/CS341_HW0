#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    //Create fork_bomb
    printf("Hello!\n");
    while (1) {
        fork();
        printf("%d\n", getpid());
        sleep(2);
    }
    return EXIT_SUCCESS;
}