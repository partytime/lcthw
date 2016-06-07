#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    if(argc == 1) {
        printf("You only have one arg. You suck.\n");
    } else if(argc > 1 && argc < 4) {
        printf("heres your arguments:\n");

        for(i = 0; i < argc; i++){
            printf("%s ", argv[i]);
        }
        printf("\n");
    } else {
        printf("You have too many arguments. \n");
    }

    return 0;
}

