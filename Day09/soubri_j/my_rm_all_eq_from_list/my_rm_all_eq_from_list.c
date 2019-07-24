/*                                                                                                               
** ETNA PROJECT, 20/10/2018 by soubri_j                                                                          
** my_rm_all_eq_from_list                                                                                                
** File description: 
**      Function my_rm_all_eq_from_list which deletes all items in the
**      list whose data is "equal" to the reference data.
*/
#include <stdlib.h>
#include "my_list.h"

void my_rm_all_eq_from_list(list_t **begin, void *data_ref, int (*cmp)())
{
    list_t *ptr = NULL;
    list_t *save = NULL;
    int cpt = 0;

    if (begin != NULL && *begin != NULL) {
        ptr = malloc(sizeof(ptr));
        save = malloc(sizeof(save));
        if (ptr != NULL && save != NULL) {
            ptr = *begin; 
            while (ptr != NULL) {
                if (cmp(ptr->data, data_ref) == 0) {
                    if (cpt > 0) {
                        save->next = ptr->next;
                    } else {
                        *begin = ptr->next;
                    }
                } else {
                    save = ptr;
                    ++cpt;
                }
                ptr = ptr->next;
            }
        }
    }
}