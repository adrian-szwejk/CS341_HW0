#include <stdio.h>
//to use NULL & malloc
#include <stdlib.h>

struct Link {
    int value;
    struct Link* next;
};  

//instead of typing struct Link, can use "link_t" when defining
typedef struct Link link_t;
//Ex. typedef int number; => Can say number x = 5; instead of int x = 5;


int main() {
    //one.next = &one; => Creates a loop

    //Use malloc to allocate memory for struct 
    link_t* ptr1 = (link_t*) malloc(sizeof(link_t));
    link_t* ptr2 = (link_t*) malloc(sizeof(link_t));

    ptr1->value = 69;
    ptr1->next = ptr2;

    ptr2->value = 420;
    ptr2->next = NULL;

    link_t* cur = ptr1;
    while (cur) {
        printf("%d\n", cur->value);
        cur = cur->next;
    }
    free(ptr1);
    free(ptr2);
    return 0;
}