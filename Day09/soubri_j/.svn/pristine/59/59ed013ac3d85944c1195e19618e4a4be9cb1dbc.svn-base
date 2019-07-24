/*                                                                                                               
** ETNA PROJECT, 20/10/2018 by soubri_j                                                                          
** my_find_node_elm_eq_in_list                                                                                                
** File description: 
**      Function which returns the address of the first element "equal"
**      to the reference data.
*/
#include <stdlib.h>
#include "my_list.h"

list_t *my_find_node_elm_eq_in_list(list_t *begin, void *data_ref, 
                                    int (*cmp)())
{
    list_t *ptr = NULL;
    list_t *to_return = NULL;
    
    if (begin != NULL) {
        ptr = malloc(sizeof(ptr));
        if (ptr != NULL) {
            ptr = begin;
            while (ptr != NULL) {
                if (cmp(ptr->data, data_ref) == 0) {
                    to_return = malloc(sizeof(to_return));
                    if (to_return != NULL)
                        to_return = ptr; 
                }
                ptr = ptr->next;
            }
        }
    }
    return to_return;
}