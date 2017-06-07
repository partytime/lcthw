#include <stdio.h>

/*
The format for the if-statement is this:
if (TEST) {
	CODE ;
} else if (TEST) {
	CODE ;
} else {
	CODE ;
}
*/

int main(int argc, char *argv[])
{
    int i = 0;
    // Is the first test really saying the right thing? To you, the first argument isn’t the same first argument a user entered. 
    // Fix it. 
    if (argc == 2) { // start argc at two instead of one
        printf("You only have one argument. You suck.\n");
    } else if (argc > 2 && argc < 5) { // again increment argc by one
        printf("Here's your arguments:\n");

        for (i = 1; i < argc; i++) { // start the loop at the 1st element of argv[] instead of the 0th
            // this adds a (null) at the end?
            printf("%s ", argv[i]);
        }
        printf("\n");
    } else {
        printf("You have too many arguments.\n");
    }

    return 0;
}
