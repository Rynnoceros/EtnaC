/*                                                                                                               
** ETNA PROJECT, 13/10/2018 by soubri_j                                                                          
** my_sum_params                                                                                                
** File description:                                                                                             
**      Function which concatenates each string within argv separated
**      by a new-line into a new string.
*/
#include <stdlib.h>
int my_strlen(char *str);
char *my_strcat(char *dest, char *src);

char *my_sum_params(int argc, char **argv)
{
    char *sum_str = NULL;
    int sum_len = 0;

    sum_str = malloc(sizeof(char));
    if (sum_str != NULL) {
        sum_str[0] = '\0';
    }
    if (argc > 0 && argv != NULL) {
        for (int i = 0; i < argc; ++i) {
            sum_len += my_strlen(argv[i]);
            ++sum_len;
        }

        sum_str = malloc(sizeof(char) * sum_len);
        if (sum_str != NULL) {
            for (int i = 0; i < argc; ++i) {
                sum_str = my_strcat(sum_str, argv[i]);
            }
            sum_str[sum_len - 1] = '\0';
        }
    }

    return sum_str;
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
    dest[dest_len + cpt] = '\n';

    return dest; 
}