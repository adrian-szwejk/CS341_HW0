#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {

    //int files = open("output.txt", mode);
    write(1, "Hello\n", 6);
    return EXIT_SUCCESS;
}