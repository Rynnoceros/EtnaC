/*
** ETNA PROJECT, 06/10/2018 by soubri_j
** my_strncpy
** File description:
**      Function to copy the n first characters of a string into another.
*/

#include "libmy.h"

char *my_strncpy(char *dest, char *src, int n)
{
    int cpt = 0;
    int dest_len = my_strlen(dest);

    if (dest == NULL || src == NULL || n < 0) {
        return NULL;
    } 
    while (cpt < n && src[cpt] != '\0') {
        dest[cpt] = src[cpt];
        ++cpt;
    }
    if (cpt < n) {
        while (cpt < dest_len) {
            dest[cpt] = '\0';
            ++cpt;
        }
    }
    if (src[cpt] == '\0') {
        while (cpt < dest_len) {
            dest[cpt] = '\0';
            ++cpt;
        }
    }
    return dest; 
}