#include <stdio.h>
#include <ctype.h>
#include <string.h>

// forward declarations
//int can_print_it(char ch);
void print_letters(char arg[]);

void print_arguments(int argc, char *argv[])
{
    int i = 0;

    for(i = 0; i < argc; i++) {
        printf("on %s\n", argv[i]);
        int len = strlen(argv[i]);
        printf("lenght is %d\n", len);

    }
}


void print_letters(char arg[])
{
    int i = 0;
    // use strlen to find length of arg and loop over
    // opposed to using nul byte
    for(i = 0; i <= strlen(arg); i++) {
        char ch = arg[i];

        //if(can_print_it(ch)) {
        if (isalpha(ch) || isblank(ch)) {
            printf("'%c' == %d ", ch, ch);
        }
    }

    printf("\n");
}

// do we need this func?
//int can_print_it(char ch)
//{
//    return isalpha(ch) || isblank(ch);
//}

int main(int argc, char *argv[])
{
    int i = 0;
    for(i = 0; i < argc; i++) {
        print_arguments(argc, argv);
        print_letters(argv[i]);
    }
    return 0;
}
