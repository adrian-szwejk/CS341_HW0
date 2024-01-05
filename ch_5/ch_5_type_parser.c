#include <stdio.h>

int main() {
    char input[] = "Hello 5 World";

    //Created buffers to stored parsed vals (w/ #'s being MAX LENGTH)
    char bufferString1[10];
    int bufferInt;
    char bufferString2[10];

    //int sscanf(const char *str, const char *format, ...)
    //Reads input from string
    int result = sscanf(input, "%s %d %s",bufferString1, &bufferInt, bufferString2);
    printf("Result: %d\n", result);
    
    //Check if sscanf SUCCESSFULLY parsed all THREE THINGS
    if (result == 3) {
        printf("1: %s\n", bufferString1);
        printf("2: %d\n", bufferInt);
        printf("3: %s\n", bufferString2);
    } else {
        printf("Parsing failed.\n");
    }
    return 0;
}