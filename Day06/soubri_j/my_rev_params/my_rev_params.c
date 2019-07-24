/*                                                                                                               
** ETNA PROJECT, 13/10/2018 by soubri_j                                                                          
** my_rev_params                                                                                                
** File description:                                                                                             
**      Function which allocates a new two-dimensional array of char with
**      the same size as the two-dimensional array passed as parameter.
**      The new array should contain the same strings from the one passed 
**      as parameter but in the reverse order. ac give the number of element
**      inside the array of strings av.
*/
#include <stdlib.h>
int my_strlen(char *str);
char *my_strcpy(char *dest, char *src);

char **my_rev_params(int ac, char **av)
{
    char **ap = NULL;
    int param_len = 0;

    if (ac > 0 && av != NULL) {
        ap = malloc(sizeof(char *) * ac);
        if (ap != NULL) {
            for (int i = 0; i < ac; ++i) {
                param_len = my_strlen(av[ac -i - 1]);
                ap[i] = malloc(sizeof(char*) * param_len);
                ap[i] = my_strcpy(ap[i], av[ac -i - 1]);
            }
        }
    }

    return ap;
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