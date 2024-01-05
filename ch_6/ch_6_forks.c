#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void nothankyou(int signal) {
    write(1, "No thank you!\n", 14);
}

int main() {
    //Gets USER'S Home directory
    char* ptr = getenv("HOMEPATH");

    //We get special signal SIGALARM
    alarm(7);


    //We cache signal and install our own handler
    //If we get a signal SIGINT (default that STOPS program)
    //We instead run our own code
    signal(SIGINT, nothankyou);

    while(1) {
        //Simply print out the path EVERY 3 seconds
        puts(ptr);
        sleep(3);
    }
    return EXIT_SUCCESS;
}