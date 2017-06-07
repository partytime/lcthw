#include <stdio.h>

int main(int argc, char *argv[])
{
    int distance = 100;
    float power = 2.345f;
    double super_power = 56789.4532;
    char initial = 'A';
    char first_name[] = "Zed";
    char last_name[] = "Shaw";

    printf("You are %d miles away.\n", distance);
    printf("You have %f levels of power.\n", power);
    printf("You have %f awesome super powers.\n", super_power);
    printf("I have an initial %c.\n", initial);
    printf("I have a first name %s.\n", first_name);
    printf("I have a last name %s.\n", last_name);
    printf("My whole name is %s %c. %s.\n", first_name, initial, last_name);

    int bugs = 100;
    double bug_rate = 1.2;

    printf("You have %d bugs at the imaginary rate of %f.\n", bugs, bug_rate);
    // Make the number you assign to universe_of_defects various sizes until you get a warn- ing from the compiler
    // that long number is too big!
    long universe_of_defects = 1L * 1024L * 1024L * 1024L * 32703969998L;
    printf("The universe has %ld bugs.\n", universe_of_defects);

    // Change long to unsigned long and try to  nd the number that makes it too big.
    // Go search online to find out what unsigned does

    /* Unless otherwise specified, all integer data types are signed data types, i.e. they have values which can be
        positive or negative. Unsigned means the integer must be positive, it can never be negative.
        Let's look at 4-bit integers. Tiny, but useful for illustration purposes.

        Since there are four bits in such an integer, it can assume one of 16 values; 16 is two to the fourth power, or
        2 times 2 times 2 times 2. What are those values? The answer depends on whether this integer is a signed int or
        an unsigned int. With an unsigned int, the value is never negative; there is no sign associated with the value.
        Here are the 16 possible values of a four-bit unsigned int:

        bits  value
        0000    0
        0001    1
        0010    2
        0011    3
        0100    4
        0101    5
        0110    6
        0111    7
        1000    8
        1001    9
        1010   10
        1011   11
        1100   12
        1101   13
        1110   14
        1111   15

        ... and Here are the 16 possible values of a four-bit signed int:

        bits  value
        0000    0
        0001    1
        0010    2
        0011    3
        0100    4
        0101    5
        0110    6
        0111    7
        1000   -8
        1001   -7
        1010   -6
        1011   -5
        1100   -4
        1101   -3
        1110   -2
        1111   -1
        As you can see, for signed ints the most significant bit is 1 if and only if the number is negative. That is why, 
        for signed ints, this bit is known as the "sign bit".
        */

    double expected_bugs = bugs * bug_rate;
    printf("You are expected to have %f bugs.\n", expected_bugs);

    double part_of_universe = expected_bugs / universe_of_defects;
    printf("That is only %e portion of the universe.\n", part_of_universe);

    // this makes no sense, just demo of something weird
    char nul_byte = '\0';
    int care_percentage = bugs * nul_byte;
    printf("Which means you should care %d%%.\n", care_percentage);

    return 0;
}
