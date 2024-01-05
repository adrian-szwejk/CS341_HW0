#include <stdio.h>
#include <stdlib.h>

void f1() {
    //Lifetime of array is ONLY for Lifetime of function
    //When I return from f1 -> array goes out of scope -> memory is freed
    //Automatically freed when function returns
    char array[] = "f1f1";
    printf("f1 : %p\n", array);
}

void f2() {
    char array[] = "f2f2";
    printf("f2 : %p\n", array);
}

void eg() {
    char temp[1024];
    f1();
}

void rec(int level) {
    char arr[] = "f1f1";
    printf("arr : %p\n",arr);
    if (level) {
        rec(level - 1);
    }
}
//Very dangerous to return POINTERS to memory that is NO LONGER VALID!!!
char* bad() {
    char arr[] = "f1f1";
    return arr;
}

int main() {
    //When we print out f1 & f2 they have the SAME MEMORY LOCATION 
    //(No additional mem needed)
    //Stack DS used for memory
    f1();
    f2();
    //When calling eg we first have a temp array we define which 
    //moves f1() further down stack
    eg();
    //Recursive function that moves memory down
    rec(5);
    //When we get back pointer from bad it points to stale memory and DNE
    char *ptr = bad();
    //Will compile but won't work
    return 0;
}



