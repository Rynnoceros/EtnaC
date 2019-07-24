/*                                                                                                               
** ETNA PROJECT, 06/10/2018 by soubri_j                                                                          
** my_strcmp                                                                                                
** File description:                                                                                             
**      Function to compare two strings.
**          If the first string is "greater", the function should return a 
**          strictly positive number.
**          If the first string is "lesser", the function should return a 
**          strictly negative number.
**          If the two strings are exactly equal, the function should return 0
*/
#include <stdlib.h>
int compare_strings(char *s1, char *s2);

int my_strcmp(char *s1, char *s2)
{
    if (s1 == NULL && s2 == NULL) {
        return 0;
    }

    if (s1 == NULL) {
        return -1;
    } else if (s2 == NULL) {
        return 1;
    } else {
        return compare_strings(s1, s2);
    }
}

/* Function that compare 2 strings */
int compare_strings(char *s1, char *s2)
{
    int compare_result = 0;
    unsigned int cpt = 0;

    while (s1[cpt] != '\0' && s2[cpt] != '\0' && s1[cpt] == s2[cpt]) {
        ++cpt;
    }

    if (s1[cpt] == s2[cpt]) {
        compare_result = 0;
    } else if (s1[cpt] == '\0' || s1[cpt] < s2[cpt]) {
        compare_result = -1;
    } else if (s2[cpt] == '\0' || s1[cpt] > s2[cpt]) {
        compare_result = 1;
    }

    return compare_result;
}