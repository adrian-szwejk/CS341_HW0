#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Link {
    char* key;
    char* value;
    struct Link* next;
};

typedef struct Link link_t;

link_t* link_create(char* akey, char* avalue) {
    printf("Creating link %s => %s\n", akey, avalue);
    link_t* result = (link_t*) malloc(sizeof(link_t));
    //Pointers don't create NEW STRING ARRAYS
    result -> key = strdup(akey);
    //strdup => makes COPIES of strings
    //gives back POINTER to new string created on HEAP
    result -> value = strdup(avalue);
    return result;
}

void link_destroy(link_t* link) {
    printf("Destroying link %s => %s\n", link->key, link->value);
    //b/c of strdup, must free BOTH key & value
    free(link->key);
    free(link->value);
    //Destroy information INSIDE LINK
    memset(link, 0, sizeof(link_t));
    //Ensures no DANGLING POINTERS (Set to NULL)
    free(link);
}

link_t* root;

int main() {
    root = link_create("a", "1");
    link_t* link2 = link_create("b", "2");
    link_t* link3 = link_create("c", "3");
    root->next = link2;
    link2->next = link3;
    link3->next = NULL;

    link_t* cur = root;
    while (cur) {
        printf("Key: %s, Value: %s\n", cur->key, cur->value);
        cur = cur->next;
    }
    link_destroy(root);
    link_destroy(link2);
    link_destroy(link3);
    return 0;
}