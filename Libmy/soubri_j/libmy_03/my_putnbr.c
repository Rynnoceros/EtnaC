/*
** ETNA PROJECT, 08/10/2018 by soubri_j
** my_putnbr
** File description:
**      Function to display an integer taken as parameter.
**      The function must be able to display every possible value
**      for an int correctly.
*/

#include "libmy.h"

void my_putnbr(int n)
{
    if (n < 0) {
        my_putchar('-');
    }
    my_putchar(my_alphabet(n, 10, "0123456789"));
}