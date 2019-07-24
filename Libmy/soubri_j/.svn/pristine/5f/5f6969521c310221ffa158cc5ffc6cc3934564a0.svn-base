/*                                                                                                               
** ETNA PROJECT, 06/10/2018 by soubri_j                                                                          
** my_strncmp                                                                                                
** File description:                                                                                             
**      Function to compare the n first charactersr of two strings.
**          If the first string is "greater", the function should return a 
**          strictly positive number.
**          If the first string is "lesser", the function should return a 
**          strictly negative number.
**          If the two strings are exactly equal, the function should return 0
*/
#include "libmy.h"

int my_strncmp(char *s1, char *s2, int n)
{
    if ((s1 == NULL && s2 == NULL) || n <= 0) {
        return 0;
    }

    if (s1 == NULL) {
        return -1;
    } else if (s2 == NULL) {
        return 1;
    } else {
        return compare_strings_n(s1, s2, n);
    }
}