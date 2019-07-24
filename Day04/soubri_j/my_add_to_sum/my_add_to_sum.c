/*                                                                                                               
** ETNA PROJECT, 06/10/2018 by soubri_j                                                                          
** my_add_to_sum                                                                                                
** File description:                                                                                             
**      Function taking one parameter and adding it to an internal sum.
**      It should return the new value of the sum.
*/
#include <stdlib.h>
int my_add_to_sum(int to_add)
{
    static int total_sum = 0;

    return total_sum += to_add;
}