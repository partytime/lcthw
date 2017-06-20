#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    // go through each string in argv
    // why skip argv[0]?
    // argv[0] is basename
    for (i = 1; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    // let's make our own array of strings
    // array of strings is *name[]
    char *states[] = {
        "California", "\0",
        "Washington", "Texas"
    };

    int num_states = 4;

    argv[0] = "argvAssignment";

    for (i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }

    return 0;
}
