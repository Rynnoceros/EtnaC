/*
** ETNA PROJECT, 13/10/2018 by soubri_j
** my_strdup
** File description:
**      Function that allocate a new string to the size of the one given
**      as parameter and copies its content to the new string.
**      The function returns a pointer to the newly allocated string.
*/

#include "libmy.h"
char *my_strcpy_for_dup(char *dest, char *src);

char *my_strdup(char *str)
{
    int str_len = 0;
    char *dup_str = NULL;

    if (str != NULL) {
        str_len = my_strlen(str);
        dup_str = malloc(sizeof(char) * str_len);
        if (dup_str != NULL)
            dup_str = my_strcpy_for_dup(dup_str, str);
    }
    return dup_str;
}

char *my_strcpy_for_dup(char *dest, char *src)
{
    int cpt = 0;

    if (dest == NULL || src == NULL) {
        return NULL;
    } 
    while (src[cpt] != '\0') {
        dest[cpt] = src[cpt];
        ++cpt;
    }
    dest[cpt] = '\0';
    return dest; 
}