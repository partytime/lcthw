#include <stdio.h>

void pass_by_reference(int* param)
{
    printf("pbr param val was %d\n", *param);
    (*param)++;
    printf("pbr param val is now %d\n", *param);
}

void pass_by_value(int param)
{
    printf("pbv param val was %d\n", param);
    param++;
    printf("pbv param val is now %d\n", param);
}

int main()
{
    int x = 5;
    printf("x is %d\n", x);
    pass_by_reference(&x);
    printf("x is %d after calling pass_by_reference\n", x);

    int y = 5;
    printf("y is %d\n", y);
    pass_by_value(y);
    printf("y is %d after calling pass_by_value\n", y);
}
