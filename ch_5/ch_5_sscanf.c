#include <stdio.h>


//sscanf() parses data inside a string INSIDE MEMORY
int main() {
    char * data = "Swiss_VERY_LONG_NAME_LSKDFJ 69";

    //Issue is when 1st STRING is too LONG (>20)
    char buffer[20];
    int score = -420;

    //Look at memory and convert STRING before " " then after is INT
    //result is number of elements CORRECTLY PARSSED
    int result = sscanf(data, "%19s %d", buffer, &score);
    //We tell sscanf() to ONLY read 1st 19 bytes
    //buffer gives address to 1st byte but &score gives address to 1st byte of INT

    printf("Results(%d items): %s %d\n", result, buffer, score);

    //Parse data from a file stream

    int result2 = fscanf(stdin, "%19s %d", buffer, &score);
    printf("Results(%d items): %s %d\n", result2, buffer, score);
    //These two are the SAME
    int result3 = scanf( "%19s %d", buffer, &score);
    printf("Results(%d items): %s %d\n", result3, buffer, score);

    return 0;
}