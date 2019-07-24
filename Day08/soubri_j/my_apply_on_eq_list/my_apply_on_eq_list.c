/*                                                                                                               
** ETNA PROJECT, 17/10/2018 by soubri_j                                                                          
** my_apply_on_eq_list                                                                                                
** File description: 
**      Function that applies a function passed as a parameter to the 
**      data contained in specific elements of the list. A reference
**      data as well as a comparison function allow us to select the
**      right elements from the list: those that are "equal" with the
**      reference data.
*/
#include <stdlib.h>
#include "my_list.h"

void my_apply_on_eq_list(list_t *begin, int (*f)(), void *data_ref, 
                         int (*cmp)())
{
    list_t *ptr = begin;
    if (ptr != NULL) {
        while (ptr != NULL) {
            if (cmp(ptr->data,data_ref) == 0)
                f(ptr->data);
            ptr = ptr->next;
        }
    }
}