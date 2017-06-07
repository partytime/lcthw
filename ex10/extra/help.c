#include <stdio.h>

/*
Write another program that uses math on the letter to convert it to lowercase,
 and then remove all of the extraneous uppercase letters in the switch

 Make it handle all of the arguments you pass it with yet another for-loop.
*/

int main(int argc, char *argv[])
{
    if (argc <= 1) {
        printf("ERROR: You need one argument.\n");
        // this is how you abort a program
        return 1;
    }

    int w = 0;

    for (w = 0; w < argc; w++) {
        char *word = argv[w];

        int i = 0;
        for (i = 0; word[i] != '\0'; i++) {
            char letter = word[i];
            if ((letter >= 65) && (letter <= 90)) { // force to lowercase
                letter = letter + 32;
            }
        }
    }

    return 0;
}
