/*                                                                                                               
** ETNA PROJECT, 04/10/2018 by soubri_j                                                                          
** my_strchr                                                                                                
** File description:                                                                                             
**      Function that returns a pointer to the first occurrence of the 
**      character c in the str string. If there is no occurrence, 
**      the end of the string ('\0') must be returned.
*/
#include <stdlib.h>

char *my_strchr(char *str, char c)
{
    unsigned int cpt = 0;

    if (str == NULL)
        return str;

    while (str[cpt] != '\0') {
        if (str[cpt] == c) {
            return &str[cpt];;
        }
        ++cpt;
    }

    return &str[cpt];
}