/*                                                                                                               
** ETNA PROJECT, 13/10/2018 by soubri_j                                                                          
** my_capitalize                                                                                                
** File description:                                                                                             
**      Function that capitalize a string in parameter and prints it
*/
#include <stdlib.h>
void my_putchar(char c);

void my_capitalize(char *str)
{
    int cpt = 0;

    if (str != NULL) {
        while (str[cpt] != '\0') {
            if (str[cpt] >= 97 && str[cpt] <= 122) {
                my_putchar(str[cpt] - 32);
            } else {
                my_putchar(str[cpt]);
            }
            ++cpt;
        }
    }
}