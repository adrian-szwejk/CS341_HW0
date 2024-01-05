#define     _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    //ssize_t getline(char**lineptr, size_t *n, FILE *stream);
    char *buffer = NULL;
    //INT to see how BIG our buffer is
    size_t bufsize = 0; //unsigned int

    //allocating memory on HEAP
    ssize_t numChars = getline(&buffer, &bufsize, stdin);

    //Overwrite the newline character with a null byte
    if (numChars > 0 && buffer[numChars - 1] == '\n') {
        buffer[--numChars] = 0;
    }
    printf("%d : %s\n", numChars, buffer);

    //Free the memory
    free(buffer);
    return EXIT_SUCCESS;
}