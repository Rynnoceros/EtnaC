#include <stdio.h>
int my_is_even(int nb);

int main(void)
{
    printf("%i is even ? : %i\n", 12, my_is_even(12));
    printf("%i is even ? : %i\n", 1, my_is_even(1));
    printf("%i is even ? : %i\n", -1, my_is_even(-1));
    printf("%i is even ? : %i\n", -13, my_is_even(-13));
    printf("%i is even ? : %i\n", 24, my_is_even(24));
    printf("%i is even ? : %i\n", -12, my_is_even(-12));
}