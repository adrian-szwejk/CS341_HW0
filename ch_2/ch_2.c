#include <stdio.h>

#include <limits.h>

#include <string.h>
int main() {
    int i = 5;
    //INT can be between these  --> -2^31 to 2^31 - 1
    //Integers can be at least 16 bits
    printf("INT MIN: %d\n", INT_MIN);
    printf("INT MAX: %d\n", INT_MAX);

    //Character is ONE BYTE (Not always 8 bits) >= 8 bits
    printf("CHAR MIN: %d\n", CHAR_MIN);
    printf("CHAR MAX: %d\n", CHAR_MAX);
    printf("Char is %d bits\n", CHAR_BIT);

    //To find # of bytes in a type
    printf("Size of int is %d bytes\n", sizeof(int));
    printf("Size of float is %d bytes\n", sizeof(float));
    printf("Size of long is %d bytes\n", sizeof(long));
    printf("Size of double is %d bytes\n", sizeof(double));
    printf("Size of long long is %d bytes\n", sizeof(long long));

    //We also have types short, long, long long which are ALL SIGNED
    //Unsigned types
    unsigned int j = 0;


    //4 bytes * 8 = 32 bytes storage on STACK
    int data[8];
    //%p means print it out as an ADDRESS
    printf("Data is a %p \n", data);
    //Going up by 4 bytes b/c int is 4 bytes 
    printf("Data+1 is a %p \n", data+1);
    printf("Data+2 is a %p \n", data+2);

    //Dereferencing the POINTER and talk to memory
    *(data) = 69;
    *(data+1) = 70;
    //OR could have written as
    data[2] = 71;
    3[data] = 72;
    int size = sizeof(data)/sizeof(int);
    printf("Size of data is %d\n", size);
    for (int i = 0; i < size; ++i)  {
        printf("Data[%d] is %d\n",i, data[i]);
    }

    //End of string always have a NULL character \0
    printf("Size of hello is %d\n", sizeof("hello"));
    //c initially points at "h" in "hello"
    char* c = "hello";
    int len = strlen(c);
    printf("Length of string is %d\n", len);
    int idx = 0;
    while (*c) {
        printf("c[%d] is %c\n", idx, *c);
        c++;
        idx++;
    }
    int str_size = sizeof("Hello\0World");
    printf("Size of string is %d\n", str_size);
    int str_len = strlen("Hello\0World");
    printf("Length of string is %d\n", str_len);

    //Seg fault when trying to change 1st element
    char *d = "world";
    //This is because this is read-only memory
    *d = 'W';
    printf("d is a %d\n", d);
    
    return 0;
}