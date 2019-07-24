/*                                                                                                               
** ETNA PROJECT, 04/10/2018 by soubri_j                                                                          
** my_strstr                                                                                                
** File description:                                                                                             
**      Function that finds the first occurrence of the to_find string
**      in the str string. Your function will have to return the address 
**      of this occurrence in the str string. If there is no occurrence, 
**      a NULL pointer must be returned.
*/
#include "libmy.h"
int is_equal(char *str, char *str2);

char *my_strstr(char *str, char *to_find)
{
    unsigned int cpt = 0;
    unsigned int cpt2 = 0;

    if (str != NULL && to_find != NULL) {
        if (is_equal(str, to_find)) {
            return &str[cpt];
        }
        
        while (str[cpt] != '\0') {
            while (str[cpt + cpt2] == to_find[cpt2] && to_find[cpt2] != '\0') {
                ++cpt2;
            }
            if (to_find[cpt2] == '\0')
                return &str[cpt];
            cpt2 = 0;
            ++cpt;
        }
    }

    return NULL;
}

int is_equal(char *str, char *str2)
{
    unsigned int cpt = 0;

    while (str[cpt] == str2[cpt] && str[cpt] != '\0' && str2 != '\0') {
        ++cpt;
    }
    
    return str[cpt] == str2[cpt] ? 1 : 0;
}