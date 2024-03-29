/*                                                                                                               
** ETNA PROJECT, 06/10/2018 by soubri_j                                                                          
** my_strcat                                                                                                
** File description:                                                                                             
**      Function to append a string to another string.
*/
#include <stdlib.h>
int my_strlen(char *str);

char *my_strcat(char *dest, char *src)
{
    int cpt = 0;
    int dest_len = my_strlen(dest);

    if (src == NULL) {
        return dest;
    }

    while (src[cpt] != '\0') {
        dest[dest_len + cpt] = src[cpt];
        ++cpt;
    }
    dest[dest_len + cpt] = '\0';

    return dest; 
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