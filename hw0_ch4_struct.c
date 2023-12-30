#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person {
    char* name;
    int age;
    struct Person** friends;
};
//Define typedef so we don't have to type out struct Person everytime
typedef struct Person Person;

Person* createPerson(int age, char* name) {
    //Allocate mem for new person
    Person* p = (Person*)malloc(sizeof(Person));

    if (!p){
        fprintf(stderr, "NO SPACE for more people\n");
        exit(EXIT_FAILURE);
    }
    //Strdup() allocates the memory for the new string by calling malloc()
    //It creates duplicate and return pointer to copy
    p->name = strdup(name);
    if (!p->name) {
        fprintf(stderr, "INVALID mem space of name\n");
        exit(EXIT_FAILURE);
    }

    p->age = age;
    if (!p->age) {
        fprintf(stderr, "INVALID Age input\n");
        exit(EXIT_FAILURE);
    }

    //Initializing 10 friends
    p->friends = (Person**)malloc(10*sizeof(Person*));
    if (!p->friends) {
        fprintf(stderr, "NO SPACE for friends\n");
        exit(EXIT_FAILURE);
    }

    memset(p->friends, 0, 10*sizeof(Person*));
    return p;
}

void deletePerson(Person * p) {
    if (!p) {
        return;
    }
    //Need to free name b/c of strdup
    free(p->name);

    //Free all friends as all had mem located (free's p2 instead of copy as friend)
    // for (int i = 0; i < 10 && p->friends[i] != NULL; ++i) {
    //     printf("free: %d\n",i);
    //     free(p->friends[i]);
    // }

    // Free the friends array
    free(p->friends);


    //Finally free the whole person
    free(p);
}

void printPerson(Person* p) {
    printf("Person Created:\nName: %s\t Age:%d\nFriends:\n", p->name, p->age);
    int len = 10;
    //sizeof(p->friends)/sizeof(Person);
    for (int i = 0; i < len; ++i) {
        if (p->friends[i]) {
            printf("Friend(%d): Name:%s\tAge:%d\n", i, p->friends[i]->name, p->friends[i]->age);
        }
    }
    printf("------------------------------\n");
}

int main() {
    Person * p1 = createPerson(128, "Agent Smith");
    Person * p2 = createPerson(256, "Sonny Moore");
    //Make them friends of each other
    p1->friends[0] = p2;
    p2->friends[0] = p1;
    printPerson(p1);
    printPerson(p2);
    deletePerson(p1);
    deletePerson(p2);
    return 0;

}