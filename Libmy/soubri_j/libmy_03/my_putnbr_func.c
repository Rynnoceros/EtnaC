/*
** ETNA PROJECT, 18/10/2018 by soubri_j
** my_putnbr_func
** File description:
**      Function used by my_putnbr functions.
*/

#include "libmy.h"

char my_getchar_alphabet(int n, int base, char *alphabet)
{
    int int_part = n / base;
    int to_print = n % base;

    if (to_print < 0) 
        to_print *= -1;
    if (int_part < 0)
        int_part *= -1;
    if (int_part > 0)
        my_putchar(my_getchar_alphabet(int_part, base, alphabet));
    return alphabet[to_print];
}