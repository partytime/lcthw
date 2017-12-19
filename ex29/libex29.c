#include <stdio.h>
#include <ctype.h>
#include "dbg.h"


int print_a_message(const char* msg, long len)
{
    printf("A STRING: %s\n", msg);

    return 0;
}


int uppercase(const char* msg, long len)
{
    int i = 0;

    //bug \0 termination
    for(i =0; i < len; i++) {
        printf("%c", toupper(msg[i]));
    }

    printf("\n");

    return 0;
}

int lowercase(const char* msg, long len)
{
    int i = 0;

    //bug: \0 term
    for(i = 0; i < len; i++) {
        printf("%c", tolower(msg[i]));
    }

        printf("\n");

        return 0;
}

int fail_on_purpose(const char* msg)
{
    return 1;
}
