#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	int str_len = strlen("Hello\0World");
	printf("strlen: %d\n", str_len);	
    int str_size = sizeof("Hello\0World");
    printf("sizeof: %d\n", str_size);

    //You can get length of argv through argc
    printf("Length of argc as len(argv): %d\n", argc);
    //Other way is to iterate through
    int len = 0;
    while(argv[++len]);
    printf("Length of iterating argv: %d\n", len);
    //Or use strlen
    int size = strlen(argv[0]);
    printf("Length of strlen argv: %d\n", size);

    
    printf("Size of float: %lu\n", sizeof(float));
    char *ptr = "Hello";
    printf("Size of ptr: %lu\n", sizeof(ptr));
    char arr[] = "Hello";
    printf("Size of array: %lu\n", sizeof(arr));
	return 0;
}


