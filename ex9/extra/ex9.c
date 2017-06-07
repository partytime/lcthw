#include <stdio.h>

// Make the loop count backward by using i-- to start at 25 and go to 0

int main(int argc, char *argv[])
{
    int i = 25;
    while (i > 0) {
        printf("%d", i);
        i--;
    }

    // need this to add final newline
    printf("\n");

    return 0;
}
