/*                                                                                                               
** ETNA PROJECT, 20/10/2018 by soubri_j                                                                          
** my_params_to_arr                                                                                                
** File description: 
**      Function which puts the elements of the begin2 list after the begin1 list.
*/
#include <stdlib.h>
#include "my_list.h"

void my_add_list_to_list(list_t **begin1, list_t *begin2)
{
    list_t *ptr = NULL;

    if (begin1 != NULL && *begin1 != NULL) {
        ptr = malloc(sizeof(ptr));
        if (ptr != NULL) {
            ptr = *begin1;
            if (ptr->data != NULL) {
                while (ptr->next != NULL) {
                    ptr = ptr->next;
                }
                ptr->next = begin2;
            } else {
                ptr = begin2;
            }
        }
    }
}