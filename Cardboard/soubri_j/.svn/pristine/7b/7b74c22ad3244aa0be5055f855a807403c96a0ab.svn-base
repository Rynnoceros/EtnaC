/*                                                                                                               
** ETNA PROJECT, 04/10/2018 by soubri_j                                                                          
** my_strupcase                                                                                                
** File description:                                                                                             
**      Function that converts a string to upper case and returns it.
*/
#include "libmy.h"

char *my_strupcase(char *str)
{
    unsigned int cpt = 0;
    unsigned int ascii_val = 0;
    
    if (str != NULL) {
        while (str[cpt] != '\0') {
            ascii_val = (int) str[cpt];
            if (ascii_val >= 97 && ascii_val <= 122) {
                ascii_val -= 32;
                str[cpt] = (char) ascii_val;
            }
            ++cpt;
        }
    }

    return str;
}