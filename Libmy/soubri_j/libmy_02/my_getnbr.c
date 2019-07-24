/*                                                                                                               
** ETNA PROJECT, 09/10/2018 by soubri_j                                                                          
** my_getnbr                                                                                                
** File description:                                                                                             
**      Function to read an integer from a string taken as parameter.
*/
#include "libmy.h"

int my_getnbr(char *str)
{
    int first_number = 0;
    int is_neg = 0;
    int nb_digit = 0;
    int ret_nbr = 0;
    
    if (str != NULL) {
        first_number = first_digit_position(str, &is_neg);
        nb_digit = get_nb_digit(str, first_number);

        if (nb_digit > 0) {
            ret_nbr = convert_number(str, first_number, nb_digit, is_neg);
        }
    }

    return ret_nbr;
}