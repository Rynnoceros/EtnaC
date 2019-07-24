#include <stdio.h>
int my_is_odd(int nb);

int main(void)
{
    printf("%i is odd ? : %i\n", 12, my_is_odd(12));
    printf("%i is odd ? : %i\n", 1, my_is_odd(1));
    printf("%i is odd ? : %i\n", -1, my_is_odd(-1));
    printf("%i is odd ? : %i\n", -13, my_is_odd(-13));
    printf("%i is odd ? : %i\n", 24, my_is_odd(24));
    printf("%i is odd ? : %i\n", -12, my_is_odd(-12));
}