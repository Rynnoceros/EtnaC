/*
** ETNA PROJECT, 06/10/2018 by soubri_j
** my_strcpy
** File description:
**      Function to copy a string into another.
*/

#include "libmy.h"

char *my_strcpy(char *dest, char *src)
{
    unsigned int cpt = 0;
    unsigned int dest_len = my_strlen(dest);

    if (dest == NULL || src == NULL) {
        return NULL;
    } 
    while (src[cpt] != '\0') {
        dest[cpt] = src[cpt];
        ++cpt;
    }
    while (cpt < dest_len) {
        dest[cpt] = '\0';
        ++cpt;
    }
    return dest; 
}