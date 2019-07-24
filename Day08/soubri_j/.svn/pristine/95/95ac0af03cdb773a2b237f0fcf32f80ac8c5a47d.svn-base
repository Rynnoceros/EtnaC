/*                                                                                                               
** ETNA PROJECT, 17/10/2018 by soubri_j                                                                          
** my_apply_on_list                                                                                                
** File description: 
**      Function that applies a function passed as a parameter to the
**      data contained in each elements of the list.
*/
#include <stdlib.h>
#include "my_list.h"

void my_apply_on_list(list_t *begin, int (*f)())
{
    list_t *ptr = begin;
    if (ptr != NULL) {
        while (ptr != NULL) {
            f(ptr->data);
            ptr = ptr->next;
        } 
    }
}