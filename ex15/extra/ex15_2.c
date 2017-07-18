#include <stdio.h>

/*
Rewrite this program to use a function for each of the ways you’re printing out things. 
Try to pass pointers to these functions so that they work on the data. Remember you can 
declare a function to accept a pointer, but just use it like an array.
*/

/*
• Change the for-loops to while-loops and see what works better for which kind of pointer usage.
basically always better.....
*/

void print1(int ages[], char *names[], int count)
{
    int i = 0;
    while (i < count) {
        printf("%s had %d years alive.\n", names[i], ages[i]);
        i++;
    }
}

void print2(int *ages, char **names, int count)
{
    int i = 0;
    for (i = 0; i < count; i++) {
        printf("%s is %d years old.\n", *(names + i), *(ages + i));
    }
}

void print3(int *ages, char **names, int count) 
{
    int i = 0;
    for (i = 0; i < count; i++) {
        printf("%s is %d years old again.\n", names[i], ages[i]);
    }
}

void print4(int ages[], char *names[], int *cur_age, char **cur_name, int count)
{
    int i = 0;
    for (cur_name = names, cur_age = ages;
            (cur_age - ages) < count; cur_name++, cur_age++) {
        printf("%s lived %d years so far.\n", *cur_name, *cur_age);
    }
}

int main(int argc, char *argv[])
{
    // create two arrays we care about
    int ages[] = { 23, 53, 12, 89, 2 };
    char *names[] = {
        "alan", "Frank",
        "Mary", "John", "Lisa"
    };

    // safely get the size of ages
    int count = sizeof(ages) / sizeof(int);
    int i = 0;
    
    // first way using indexing
    print1(ages, names, count);

    printf("---\n");

    // setup the pointers to the start of the arrays
    int *cur_age = ages;
    /*Try to make cur_age point at names. You’ll need to use a C cast to force it, so go look that up and try to figure it out.
    int *cur_age = (int*)names;
    */
    char **cur_name = names;

    // second way using pointers
    print2(cur_age, cur_name, count);

    printf("---\n");

    // third way, pointers are just arrays
    print3(cur_age, cur_name, count);

    /*Add another for-loop at the end that prints out the addresses that these pointers are
    using. You’ll need the %p format for printf.
    */
    for (i = 0; i < count; i++) {
        printf("%s is at %p and %d is at %p.\n", cur_name[i], cur_name[i], cur_age[i], cur_age[i]);
    }

    printf("---\n");

    // fourth way with pointers in a stupid complex way
    print4(ages, names, cur_age, cur_name, count);


    return 0;
}
