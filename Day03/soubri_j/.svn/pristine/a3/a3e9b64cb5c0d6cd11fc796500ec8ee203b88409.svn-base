/*                                                                                                               
** ETNA PROJECT, 04/10/2018 by soubri_j                                                                          
** my_str_is_printable                                                                                                
** File description:                                                                                             
**      Function that returns 0 if the string passed as parameter 
**      contains at least one non-printable character and 1 if not.
*/
#include <stdlib.h>
int my_str_is_printable(char *str)
{
    unsigned int cpt = 0;
    int found = 0;
    int ascii_char;

    if (str != NULL) {
        while (str[cpt] != '\0' && found == 0) {
            ascii_char = (int) str[cpt];
            if ((ascii_char > 0 && ascii_char < 32) || ascii_char == 127) {
                found = 1;
            }
            ++cpt;
        }
    }

    return found == 1 ? 0 : 1;
}