#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>
//Functions defined within TIME.H
//time_t time(time_t *t)
//char* ctime(const time_t *timep);

//Can add static to get rid of automatic var when calling curTime() & CHEAT
//static char array[256];
char* curTime() {
    //malloc => give me some memory from HEAP
    char* result = malloc(256);
    //malloc returns pointer (if invalid returns NULL ptr)
    if (!result) {
        return result;
    }
    time_t secondsSince1970 = time(NULL);
    //Issue with ctime is that it has STATIC STORAGE
    //Good for calling it once, but not multiple times as it will overwrite bytes
    //We use malloc to get around this
    char* timeASCII = ctime(&secondsSince1970);
    //& means ADDRESS of var
    strcpy(result, timeASCII);
    return result;
}

int main() {
    char* time = curTime();
    printf("%s\n", time);
    free(time); 
    //Good practice, AFTER FREEING, set pointer to NULL
    time = NULL;
    //free(time); DON'T FREE 2 times or USE AFTER FREEING
    return 0;
}