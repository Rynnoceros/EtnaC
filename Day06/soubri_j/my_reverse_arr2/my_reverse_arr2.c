/*                                                                                                               
** ETNA PROJECT, 13/10/2018 by soubri_j                                                                          
** my_reverse_arr2                                                                                                
** File description:                                                                                             
**      Function which allocates a new two-dimensional array of int 
**      which is a copy of the one passed as parametters, but with 
**      the rows and column swapped.
*/
#include <stdlib.h>
int **my_reverse_arr2(int **arr, unsigned int sizex, unsigned int sizey)
{
    int **array_to_rev = NULL;

    if (sizex > 0 && sizey > 0 && arr != NULL) {
        array_to_rev = malloc(sizeof(int*) * sizex);
        if (array_to_rev != NULL) {
            for (unsigned int x = 0; x < sizex; ++x) {
                array_to_rev[x] = malloc(sizeof(int*) * sizey);
                if (array_to_rev[x] != NULL) {
                    for (unsigned int y = 0; y < sizey; ++y) {
                        array_to_rev[x][y] = arr[y][x];
                    }
                }
            }
        }
    } else {
        array_to_rev = malloc(sizeof(int**));
    }

    return array_to_rev;
}