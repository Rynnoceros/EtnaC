/*                                                                                                               
** ETNA PROJECT, 04/10/2018 by soubri_j                                                                          
** my_revstr                                                                                                
** File description:                                                                                             
**      Function that inverts the str string and returns it.
*/
#include <stdlib.h>
int my_strlen(char *str);

char *my_revstr(char *str)
{
    int cpt = 0;
    int cpt_rev = my_strlen(str) - 1;
    char tmp;
    
    if (str != NULL && cpt_rev >= 0) {
        if (cpt_rev >= 0) {
            while (cpt < cpt_rev) {
                tmp = str[cpt];
                str[cpt] = str[cpt_rev];
                str[cpt_rev] = tmp;
                ++cpt;
                --cpt_rev;
            }
        }
    }

    return str;
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