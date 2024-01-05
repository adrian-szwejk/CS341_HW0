#include <stdio.h>
//Define change signature
void change(char*);

int main() {
    char* ptr = "Hello World";
    char array[] = "Hello World";
    //Although these both point to same first val they have DIFFERENT SIZES
    printf("Pointer Size: %d\nArray Size: %d\n", sizeof(ptr), sizeof(array));
    change(array);
    printf("Changed Array: %s\n", array);
    return 0;
}

//Error "change was implicitly declared" because we didn't declare its functin signature
void change(char * p) {
    //Function to change all 'l' chars to '*'
    while(*p) {
        //Change all of the letteres to be empty
        if (*p == 'l') {
            *p = '*';
        }
        //Don't do "*" because we'd use the address of * rather than the value
        p++;
    }
}