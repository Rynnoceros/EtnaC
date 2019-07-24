/*                                                                                                               
** ETNA PROJECT, 17/10/2018 by soubri_j                                                                          
** my_list_size                                                                                                
** File description: 
**      Function my_list_size that returns the number of elements in the list.
*/
#include <stdlib.h>
#include "my_list.h"

int my_list_size(list_t *begin)
{
    list_t *ptr = begin;
    int list_size = 0;

    if (ptr != NULL) {
        while (ptr != NULL) {
            ++list_size;
            ptr = ptr->next;
        }
    }

    return list_size;
}