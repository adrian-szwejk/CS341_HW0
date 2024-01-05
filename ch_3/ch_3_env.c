#include <stdio.h>
#include <stdlib.h>

//extern means that environ is defined somewhere else and we just NEED ACCESS
extern char** environ;
int main () {
    //1st time we deference environ, we get a pointer to a character strings
    //Can iterate through to print dif environment variables
    char **ptr = environ;
    while(*ptr) {
        printf("%s\n", *ptr);
        ptr++;
    }
    //Can set the entries printed by typing "export SECRET=123456" in cmd
    
    //Can get specific environment variable by using getenv
    char * secret = getenv("SECRET");
    //Is NULL b/c we didn't set it
    if (secret) {
        printf("SECRET is %s\n", secret);
    }
    char * arch = getenv("PROCESSOR_ARCHITECTURE");
    printf("PROCESSOR_ARCHITECTURE is %s\n", arch);
    exit(0);
    return 0;
}