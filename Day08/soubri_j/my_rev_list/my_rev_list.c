/*                                                                                                               
** ETNA PROJECT, 17/10/2018 by soubri_j                                                                          
** my_rev_list                                                                                                
** File description: 
**      Function my_rev_list reverses the order of the elements
**      in the list. Only pointer sets are allowed.
*/
#include <stdlib.h>
#include "my_list.h"

void my_rev_list(list_t **begin)
{
    list_t *ptr = NULL;
    list_t *current_ptr = NULL;
    list_t *save_next = NULL;

    if (*begin != NULL) {
        ptr = *begin;
        current_ptr = ptr;
        save_next = current_ptr->next;
        (*begin)->next = NULL;
        do {
            ptr = current_ptr;
            current_ptr = save_next;
            if (current_ptr != NULL) {
                save_next = current_ptr->next;
                current_ptr->next = ptr;
            }
        } while (save_next != NULL);
        if (current_ptr == NULL) {
            current_ptr = ptr;
        }
    }

    *begin = current_ptr;
}