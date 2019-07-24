/*                                                                                                               
** ETNA PROJECT, 09/10/2018 by soubri_j                                                                          
** my_getnbr_base                                                                                                
** File description:                                                                                             
**      Function that takes two string parameters. The first contains the
**      representation of a number using the base contained in the second. 
**      The function has to convert that representation to an integer.
*/
#include "libmy.h"

int my_getnbr_base(char *str, char *base)
{
    int first_number = 0;
    int is_neg = 0;
    int nb_digit = 0;
    int ret_nbr = 0;
    
    if (str != NULL && base != NULL) {
        if (get_char_pos(base, '-') < 0 && get_char_pos(base, '+') < 0) {
            first_number = first_digit_position(str, &is_neg);
            nb_digit = get_nb_digit_base(str, first_number, base);
            
            if (nb_digit > 0) {
                ret_nbr = convert_number_base(str, first_number, nb_digit, base);
                if (is_neg > 0)
                    ret_nbr *= -1;
            }
        }
    }

    return ret_nbr;
}