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
    // handle all arguments
    for (w = 1; w < argc; w++) {
        // why do we need to be a pointer to word here?
        // something with the fact that argv is a pointer array?
        char *word = argv[w];

        int i = 0;
        // then handle each letter of the argument
        for (i = 0; word[i] != '\0'; i++) {
            char letter = word[i];
            if ((letter >= 65) && (letter <= 90)) { // force to lowercase
                letter = letter + 32;
            }

            switch (letter) {
                case 'a':
                case 'A':
                    printf("%d: 'A'\n", i);
                    break;

                case 'e':
                case 'E':
                    printf("%d: 'E'\n", i);
                    break;

                case 'i':
                case 'I':
                    printf("%d: 'I'\n", i);
                    break;

                case 'o':
                case 'O':
                    printf("%d: 'O'\n", i);
                    break;

                case 'u':
                case 'U':
                    printf("%d: 'U'\n", i);
                    break;

                case 'y':
                case 'Y':
                    // why i > 2? is this a bug?
                    if (i > 2) {
                        // its only sometimes Y
                        printf("%d: 'E'\n", i);
                    }
                    break;

                default:
                    printf("%d: %c is not a vowel\n", i, letter);
                }
        }
    }

    return 0;
}
