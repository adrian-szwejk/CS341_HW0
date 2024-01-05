#include <stdio.h>
#include <stdlib.h>
int main(int argc, char*argv[] ) {
    float i = 5.0;
    printf("i is %f\n",i);

    //1st argument is the execution path
    printf("argv[0]=%s\n", argv[0]);
    //Has a pointer to NULL
    printf("argv[argc]=%s\n", argv[argc]);

    //If you add arguments "./ch3 cat hat sat" it'll print those out in FOR LOOP
    printf("argc=%d\n", argc);
    for (int i = 1; i < argc; ++i) {
        printf("%d : %s\n", i, argv[i]);
    }

    //ASCII to INT
    int sum = 0;
    //Sums up inputs and prints out the sum
    for (int i = 0; i < argc; ++i) {
        sum += atoi(argv[i]);
    }
    //If you put in string, it's convert to 0
    printf("Sum is %d\n", sum);
}