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
#include <stdlib.h>
int compare_strings_n(char *s1, char *s2, int n);

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

/* Function that compare the n first characters of 2 strings */
int compare_strings_n(char *s1, char *s2, int n)
{
    int compare_result = 0;
    int cpt = 0;

    while (s1[cpt] != '\0' && s2[cpt] != '\0' && 
           s1[cpt] == s2[cpt] && cpt < n) {
        ++cpt;
    }

    if ((s1[cpt] == '\0' && s2[cpt] == '\0' ) || cpt >= n) {
        compare_result = 0;
    } else if (s1[cpt] == '\0' || s1[cpt] < s2[cpt]) {
        compare_result = -1;
    } else if (s2[cpt] == '\0' || s1[cpt] > s2[cpt]) {
        compare_result = 1;
    }

    return compare_result;
}