/*                                                                                                               
** ETNA PROJECT, 08/10/2018 by soubri_j                                                                          
** my_nbrlen_base                                                                                                
** File description:                                                                                             
**      Function that returns the number of characters required to write
**      an integer in the base base.
*/
#include "libmy.h"

int my_nbrlen_base(int n, int base)
{
    int power = 1;
    int is_neg = 0;

    if (n < 0) {
        is_neg = 1;
        n *= -1;
    }

    for (; my_pow(base, power) <= n; ++power) {
    }

    if (is_neg == 1)
        ++power;

    return power;
}