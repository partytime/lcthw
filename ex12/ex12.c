#include <stdio.h>

int main(int argc, char *argv[])
{
    char full_name[] = {
        'Z', 'e', 'd',
        ' ', 'A', '.', ' ',
        'S', 'h', 'a', 'w', '\0'
    };

    int areas[] = { 10, 12, 13, 14, 20 };
    char name[] = "Zed";


    printf("the size of an int: %ld\n", sizeof(int));
    printf("The size of areas (int[]): %ld\n", sizeof(areas));
    printf("The number of ints in the areas: %ld\n",
            sizeof(areas) / sizeof(int));
    printf("The first area is %d, the 2nd %d.\n", areas[0], areas[1]);

    areas[0] = name[0];


    printf("The first area is NOW %d, the 2nd %d.\n", areas[0], areas[1]);
    printf("areas 10 - The first area is NOW %d, the 2nd %d.\n", areas[0], areas[10]);

    printf("The size of a char: %ld\n", sizeof(char));
    printf("The size of name (char[]): %ld\n", sizeof(name) / sizeof(char));

    printf("The size of full_name (char[]): %ld\n", sizeof(full_name));
    printf("The number of chars: %ld\n",
            sizeof(full_name) / sizeof(char));

    printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);

    name[1] = 'Q';
    full_name[0] = 'Q';

    printf("SECOND name=\"%s\" and full_name=\"%s\"\n", name, full_name);

    return 0;
}
