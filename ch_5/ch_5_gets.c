#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv) {
    //getchar() give me a single character
    //EOF is constant END OF FILE defined in stdio.h
    int c = 0x10203040;
    printf("%x\n",c);
    //c = getchar();
    //Stores the result of system/library calls inside var
    while((c = getchar()) != EOF) {
        //putchar() prints a single char
        //Basically whatever we INPUT is copied and printed in OUTPUT
        if (c >= 32) {
            //Flip the LOWEST BIT
            c = c ^ 1;
        }
        putchar(c);

        //can also display as char, int, hex
        //printf("%c %d %x\n",c,c,c);
        //Like so INPUT = abcd
        //OUTPUT:
        // a 97 61
        // b 98 62
        // c 99 63
        // d 100 64
    }

    // //Can instead work with whole lines rather than characters
    puts("Hello");  //EQUIVALENT to printf("%s\n", ptr);

    //gets() is a function that reads a line from stdin
    //gets() is UNSAFE because it doesn't check the size of the buffer
    //gets() is DEPRECATED
    char buffer[12];
    //We are getting 1st byte of ARRAY
    gets(buffer);
    printf("%x\n",c);
    puts(buffer);

    //Ex. when Input is "ABCDABCDABCD" is overflowed 13th byte so change INT c
    //OUTPUT:
    // c = 0x10203040
    // INPUT = abcdabcdabcd
    // c = 0x10203000
    // OUTPUT = abcdabcdabcd
    return EXIT_SUCCESS;
}