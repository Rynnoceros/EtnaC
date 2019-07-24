/*                                                                                                               
** ETNA PROJECT, 20/10/2018 by soubri_j                                                                          
** my_put_elem_in_sort_list                                                                                                
** File description: 
**      Function which creates a new item, and inserts it into a sorted list,
**      so that the list remains sorted in ascending order.
*/
#include <stdlib.h>
#include <stdio.h>
#include "my_list.h"

void my_put_elem_in_sort_list(list_t **begin, void *data, int (*cmp)())
{
    list_t *ptr = NULL;
    list_t *save = NULL;
    list_t *new = NULL;
    int cpt = 0;

    if (begin != NULL && *begin != NULL) {
        ptr = malloc(sizeof(ptr));
        save = malloc(sizeof(save));
        if (ptr != NULL && save != NULL) {
            ptr = *begin; 
            while (ptr != NULL && cmp(ptr->data, data) <= 0) {
                save = ptr;
                ptr = ptr->next;
                ++cpt;
            }
            new = malloc(sizeof(*new));
            if (new != NULL) {
                new->data = data;
                new->next = ptr;
            }
            save->next = new;
        }
        if (cpt <= 0) {
            *begin = new;
        }
    }
}