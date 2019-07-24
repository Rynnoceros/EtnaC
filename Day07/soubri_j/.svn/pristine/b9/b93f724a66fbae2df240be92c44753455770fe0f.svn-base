/*                                                                                                               
** ETNA PROJECT, 09/10/2018 by soubri_j                                                                          
** my_getnbr                                                                                                
** File description:                                                                                             
**      Function to read an integer from a string taken as parameter.
*/
#include <stdlib.h>
int first_digit_position(char *str, int *is_neg);
int get_nb_digit(char *str, int start_pos);
int convert_number(char *str, int start_pos, int nb_digit, int is_neg);
int my_pow(int n, int p);

int my_getnbr(char *str, int *is_number)
{
    int first_number = 0;
    int is_neg = 0;
    int nb_digit = 0;
    int ret_nbr = 0;
    
    *is_number = -1;
    if (str != NULL) {
        first_number = first_digit_position(str, &is_neg);
        nb_digit = get_nb_digit(str, first_number);

        if (nb_digit > 0) {
            *is_number = 1;
            ret_nbr = convert_number(str, first_number, nb_digit, is_neg);
        }
    }

    return ret_nbr;
}

int first_digit_position(char *str, int *is_neg)
{
    int cpt = 0;
    int nb_minus = 0;

    while (str[cpt] != '\0' && (str[cpt] == '-' || str[cpt] == '+')) {
        if (str[cpt] == '-')
            ++nb_minus;
        ++cpt;
    }

    if (nb_minus % 2 > 0)
        *is_neg = 1;
    
    return cpt;
}

int get_nb_digit(char *str, int start_pos)
{
    int nb_digit = 0;

    while (str[start_pos] != '\0' && str[start_pos] >= '0' && 
           str[start_pos] <= '9') {
        ++start_pos;
        ++nb_digit;
    }    

    return nb_digit;
}

int convert_number(char *str, int start_pos, int nb_digit, int is_neg)
{
    int number = 0;
    
    while (--nb_digit >= 0) {
        number += (str[start_pos] - 48) * my_pow(10, nb_digit);
        ++start_pos;
    }

    if (is_neg == 1)
        number *= -1;

    return number;
}