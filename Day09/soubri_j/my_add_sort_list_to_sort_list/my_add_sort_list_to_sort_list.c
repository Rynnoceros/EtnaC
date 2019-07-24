/*                                                                                                               
** ETNA PROJECT, 20/10/2018 by soubri_j                                                                          
** my_add_sort_list_to_sort_list                                                                                                
** File description: 
**      Function which integrates the elements of a sorted list (begin2) 
**      into another sorted list (begin1), so that the list (begin1) remains
**      sorted in ascending order.
*/
#include <stdlib.h>
#include "my_list.h"

void my_add_sort_list_to_sort_list(list_t **begin1, list_t *begin2, 
                                   int (*cmp)())
{
    list_t *ptr = NULL;
    list_t *save = NULL;
    list_t *save2 = NULL;

    if (begin1 != NULL) { 
        if (*begin1 != NULL) {
        ptr = malloc(sizeof(ptr));
            save = malloc(sizeof(save));
            save2 = malloc(sizeof(begin2));
            if (ptr != NULL && save != NULL && save2 != NULL) {
                while (begin2 != NULL) {
                    ptr = *begin1; 
                    while (ptr != NULL && cmp(ptr->data, begin2->data) <= 0) {
                        save = ptr;
                        ptr = ptr->next;
                    }
                    save2 = begin2;
                    begin2 = begin2->next;
                    save->next = save2;
                    save2->next = ptr;
                }
            }
        } else {
            *begin1 = begin2;
        }
    }
}