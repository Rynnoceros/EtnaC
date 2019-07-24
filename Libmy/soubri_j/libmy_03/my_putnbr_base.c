/*
** ETNA PROJECT, 08/10/2018 by soubri_j
** my_putnbr_base
** File description:
**      Function to display an integer taken as parameter.
**      The integer will be displayed using the digits contained
**      in the second parameter.
*/

#include "libmy.h"

void my_putnbr_base(int n, char *base)
{
    if (base != NULL) {
        if (n < 0) {
            my_putchar('-');
        }
        my_putchar(my_getchar_alphabet(n, my_strlen(base), base));
    }
}