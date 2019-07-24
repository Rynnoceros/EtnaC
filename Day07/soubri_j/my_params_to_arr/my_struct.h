/*                                                                                                               
** ETNA PROJECT, 15/10/2018 by soubri_j                                                                          
** my_struct                                                                                                
** File description:   
**      File containing prototypes and struc declarations.
*/
#ifndef _MY_STRUC_H_
#define _MY_STRUC_H_

struct stock_par_s {
    int size_param; /* length of the paramter              */
    char *str;      /* address of the next parameter       */
    char *copy;     /* copy of the parameter               */
    char **tab;     /* array returned by my_str_to_wordtab */
};

char **my_str_to_wordtab(char *str);
int my_strlen(char *str);
void fill_parameter(struct stock_par_s *param, int param_pos, char **wordtab);
struct stock_par_s *my_params_to_arr(int ac, char **av);
char *my_strdup(char *str);

#endif