#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL);

    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}


void Person_destroy(struct Person *who)
{
    assert(who != NULL);
    free(who->name);
    free(who);
}

void Person_print(struct Person *who)
{
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

// create a struct on the stack, which means just like you've been making any other variable.

int main(int argc, char *argv[])
{

    //How to initialize it using the x.y (period) character instead of the x->y syntax.
    struct Person who2 = { .name = "Joe Norocket", .age = 99, .height = 666, .weight = 100 };
    printf("Name with norocket!: %s\n", who2.name);
    printf("\tAge: %d\n", who2.age);
    printf("\tHeight: %d\n", who2.height);
    printf("\tWeight: %d\n", who2.weight);
    // make two people structures

    struct Person who = { "Joe Alex", 32, 64, 140 };

    printf("Name: %s\n", who.name);
    printf("\tAge: %d\n", who.age);
    printf("\tHeight: %d\n", who.height);
    printf("\tWeight: %d\n", who.weight);

    struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

    // print them out and where they are in memory
    //printf("Joe is at mem location %p:\n", joe);
    //Person_print(joe);

    printf("Frank is at mem location %p:\n", frank);
    Person_print(frank);

    // make everyone age 20 and print them again
    //joe->age += 20;
    //joe->height -=2;
    //joe->weight += 40;
    //Person_print(joe);

    frank->age += 20;
    frank->weight += 20;
    Person_print(frank);

    // destroy both to clean up
    //Person_destroy(joe);
    Person_destroy(frank);

    return 0;
}









