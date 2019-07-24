/*                                                                                                               
** ETNA PROJECT, 13/10/2018 by soubri_j                                                                          
** my_init_arr2                                                                                                
** File description:                                                                                             
**      Function which allocates a new two-dimensional array of int,
**      fill each cell with value and returns it.
*/
#include <stdlib.h>
int **my_init_arr2(unsigned int sizex, unsigned int sizey, int value)
{
    int **array_to_init = NULL;

    array_to_init = malloc(sizeof(int*) * sizey);
    if (array_to_init != NULL) {
        for (unsigned int y = 0; y < sizey; ++y) {
            array_to_init[y] = malloc(sizeof(int*) * sizex);
            if (array_to_init[y] != NULL) {
                for (unsigned int x = 0; x < sizex; ++x) {
                    array_to_init[y][x] = value;
                }
            }
        }
    }

    return array_to_init;
}