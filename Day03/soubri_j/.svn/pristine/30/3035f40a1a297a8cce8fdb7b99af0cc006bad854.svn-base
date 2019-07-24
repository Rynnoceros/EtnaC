/*                                                                                                               
** ETNA PROJECT, 05/10/2018 by soubri_j                                                                          
** my_str_capitalize                                                                                                
** File description:                                                                                             
**      Function that prints the given array as a parameter in order to swap
**      columns and rows. The given array is two-dimensional and will 
**      only contain printable characters.
*/
#include <stdlib.h>
void my_putchar(char c);

void my_trspos_arr(int c, int l, char **arr)
{
    if (arr != NULL) {
        for (int i = c - 1; i >= 0; --i) {
            for (int j = 0; j < l; ++j) {
                my_putchar(arr[j][i]);
            }
            my_putchar('\n');
        }
    }
}