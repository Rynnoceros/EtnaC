/*
** ETNA PROJECT, 18/10/2018 by soubri_j
** my_getnbr_func
** File description:
**      Functions used by my_getnbr functions.
*/

#include "libmy.h"

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

int get_nb_digit_base(char *str, int start_pos, char *base)
{
    int nb_digit = 0;

    while (str[start_pos] != '\0' && get_char_pos(base, str[start_pos]) >= 0) {
        ++start_pos;
        ++nb_digit;
    }    
    return nb_digit;
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

int convert_number_base(char *str, int start_pos, int nb_digit, char *base)
{
    int number = 0;
    int ibase = my_strlen(base);
    
    while (--nb_digit >= 0) {
        number += get_char_pos(base, str[start_pos]) * my_pow(ibase, nb_digit);
        ++start_pos;
    }
    return number;
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