/*                                                                                                               
** ETNA PROJECT, 13/10/2018 by soubri_j                                                                          
** my_strdup                                                                                                
** File description:                                                                                             
**      Function that allocate a new string to the size of the one given
**      as parameter and copies its content to the new string. 
**      The function returns a pointer to the newly allocated string.
*/
#include <stdlib.h>
int my_strlen(char *str);
char *my_strcpy(char *dest, char *src);

char *my_strdup(char *str)
{
    int str_len = 0;
    char *dup_str = NULL;

    if (str != NULL) {
        str_len = my_strlen(str);
        dup_str = malloc(sizeof(char) * str_len);
        if (dup_str != NULL)
            dup_str = my_strcpy(dup_str, str);
    }

    return dup_str;
}

int my_strlen(char *str)
{
    int cpt = 0;

    if (str != NULL) {
        while (str[cpt] != '\0') {
            ++cpt;
        }
    }
    
    return cpt;
}

char *my_strcpy(char *dest, char *src)
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