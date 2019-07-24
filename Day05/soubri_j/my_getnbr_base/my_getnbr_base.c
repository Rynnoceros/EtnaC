/*                                                                                                               
** ETNA PROJECT, 09/10/2018 by soubri_j                                                                          
** my_getnbr_base                                                                                                
** File description:                                                                                             
**      Function that takes two string parameters. The first contains the
**      representation of a number using the base contained in the second. 
**      The function has to convert that representation to an integer.
*/
#include <stdlib.h>
int first_digit_position(char *str, int *is_neg);
int get_nb_digit(char *str, int start_pos, char *base);
int convert_number(char *str, int start_pos, int nb_digit, char *base);
int my_pow(int n, int p);
int get_char_pos(char *str, char c);
int my_strlen(char *str);

int my_getnbr_base(char *str, char *base)
{
    int first_number = 0;
    int is_neg = 0;
    int nb_digit = 0;
    int ret_nbr = 0;
    
    if (str != NULL && base != NULL) {
        if (get_char_pos(base, '-') < 0 && get_char_pos(base, '+') < 0) {
            first_number = first_digit_position(str, &is_neg);
            nb_digit = get_nb_digit(str, first_number, base);
            
            if (nb_digit > 0) {
                ret_nbr = convert_number(str, first_number, nb_digit, base);
                if (is_neg > 0)
                    ret_nbr *= -1;
            }
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

int get_nb_digit(char *str, int start_pos, char *base)
{
    int nb_digit = 0;

    while (str[start_pos] != '\0' && get_char_pos(base, str[start_pos]) >= 0) {
        ++start_pos;
        ++nb_digit;
    }    

    return nb_digit;
}

int convert_number(char *str, int start_pos, int nb_digit, char *base)
{
    int number = 0;
    int ibase = my_strlen(base);
    
    while (--nb_digit >= 0) {
        number += get_char_pos(base, str[start_pos]) * my_pow(ibase, nb_digit);
        ++start_pos;
    }

    return number;
}

int my_pow(int n, int p)
{
    int powed_value = 1;
    if (p < 0)
        return 0;

    for (int i = 0; i < p; ++i) {
        powed_value *= n;
    }
    return powed_value;
}

int get_char_pos(char *str, char c)
{
    int char_pos = -1;
    int cpt = 0;

    if (str != NULL) {
        while (str[cpt] != '\0' && str[cpt] != c) {
            ++cpt;
        }

        if (str[cpt] != '\0') {
            char_pos = cpt;
        }
    }

    return char_pos;
}

int my_strlen(char *str)
{
    unsigned int cpt = 0;

    if (str != NULL) {
        while (str[cpt] != '\0') {
            ++cpt;
        }
    }
    
    return cpt;
}