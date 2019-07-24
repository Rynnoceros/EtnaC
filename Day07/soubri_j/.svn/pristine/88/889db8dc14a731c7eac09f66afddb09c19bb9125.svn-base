/*                                                                                                               
** ETNA PROJECT, 04/10/2018 by soubri_j                                                                          
** my_strchr                                                                                                
** File description:                                                                                             
**      Function that returns a the position of the first occurence found in
**      a string. If the character is not found returns -1.
*/
#include <stdlib.h>

int my_chrpos(char *str, char c)
{
    unsigned int cpt = 0;

    if (str == NULL)
        return -1;

    while (str[cpt] != '\0') {
        if (str[cpt] == c) {
            return cpt;
        }
        ++cpt;
    }

    return -1;
}