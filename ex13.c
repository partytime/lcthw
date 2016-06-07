#include <stdio.h>

char toLowerCase(char letter)
{
    if(letter >= 97 && letter <= 122) {
            return letter;
    } else if(letter >= 65 && letter <=90) {
        return letter + 32;
    } else {
        return letter;
    }
}


int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("ERROR: You need one argument.\n");
        // this is how to abort a program!
        return 1;
    }

    int i = 0;
    for(i = 0; argv[1][i] != '\0'; i++) {
        char letter = argv[1][i];
        char lowerCaseLetter = toLowerCase(letter);

        switch(lowerCaseLetter) {
            case 'a':
            // case 'A':
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
                if(i > 2) {
                    // only sometimes y!
                    printf("%d: 'Y'\n", i);
                }
                break;
            default:
                printf("%d: %c is not a vowel\n", i, lowerCaseLetter);
        }
    }

    return 0;
}

