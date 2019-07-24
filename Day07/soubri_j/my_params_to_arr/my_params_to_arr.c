/*                                                                                                               
** ETNA PROJECT, 15/10/2018 by soubri_j                                                                          
** my_params_to_arr                                                                                                
** File description: 
**      Function which stock the program parameters into struct stock_par_s
**      array and return the adress of it later.
**      The array have to be dynamically allocated and the last element's 
**      str field set to NULL.
**      ac give the number of element inside the array of strings av.
*/
#include "my_struct.h"
#include <stdlib.h>

struct stock_par_s *my_params_to_arr(int ac, char **av)
{
    int cpt = 0;
    struct stock_par_s *tab_param = NULL;

    if (ac > 0) {
        tab_param = malloc(sizeof(*tab_param) * (ac + 1));
        if (tab_param != NULL) {
            while (cpt < ac) {
                fill_parameter(&tab_param[cpt], cpt, av);
                ++cpt;
            }
            tab_param[cpt].size_param = 0;
            tab_param[cpt].str = NULL;
            tab_param[cpt].copy = NULL;
            tab_param[cpt].tab = NULL;
        }
    }

    return tab_param;
}

void fill_parameter(struct stock_par_s *parameter, int param_pos, char **params)
{   
    if (parameter != NULL) {
        parameter->size_param = my_strlen(params[param_pos]);
        parameter->copy = my_strdup(params[param_pos]);
        parameter->str = params[param_pos];
        parameter->tab = my_str_to_wordtab(params[param_pos]);
    }
}

int my_strlen(char *str)
{
    int len = 0;

    if (str != NULL) {
        while (str[len] != '\0') {
            ++len;
        }
    }
    return len;
}

char *my_strdup(char *str)
{
    int str_len = 0;
    char *dup_str = NULL;
    int cpt = 0;

    if (str != NULL) {
        str_len = my_strlen(str);
        dup_str = malloc(sizeof(char) * str_len);
        if (dup_str != NULL) {
            while(str[cpt] != '\0') {
                dup_str[cpt] = str[cpt];
                ++cpt;
            }
            dup_str[cpt] = '\0';
        }
    }

    return dup_str;
}