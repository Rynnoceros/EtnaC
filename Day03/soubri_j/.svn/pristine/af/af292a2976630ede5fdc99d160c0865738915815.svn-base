/*                                                                                                               
** ETNA PROJECT, 05/10/2018 by soubri_j                                                                          
** my_str_capitalize                                                                                                
** File description:                                                                                             
**      Function that capitalizes all the first letters of words and the rest 
**      of letters in lowercase of the str string and returns it.
*/
#include <stdlib.h>
char to_upper_char(int ascii_val);
char to_lower_char(int ascii_val);

char *my_str_capitalize(char *str)
{
    unsigned int cpt = 0;
    unsigned int ascii_val = 0;
    
    if (str != NULL) {
        while (str[cpt] != '\0') {
            ascii_val = (int) str[cpt];
            if (cpt > 0) {
                char previous_char = str[cpt - 1];
                if (previous_char == ' ' || previous_char == '\t' || 
                    previous_char == '\n') {
                    str[cpt] = to_upper_char(ascii_val);    
                } else {
                    str[cpt] = to_lower_char(ascii_val);
                }
            } else {
               str[cpt] = to_upper_char(ascii_val);
            }
            ++cpt;
        }
    }

    return str;
}

char to_upper_char(int ascii_val)
{
    if (ascii_val >= 97 && ascii_val <= 122) {
        ascii_val -= 32;
    }
    return ascii_val;
}

char to_lower_char(int ascii_val)
{
    if (ascii_val >= 65 && ascii_val <= 90)
        ascii_val += 32;

    return ascii_val;
}