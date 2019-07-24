/*                                                                                                               
** ETNA PROJECT, 20/10/2018 by soubri_j                                                                          
** my_sort_list                                                                                                
** File description: 
**      Function which sorts the elements of the list in ascending order,
**      by comparing the data of two elements using a comparison function.
*/
#include <stdlib.h>
#include "my_list.h"

void my_sort_list(list_t **begin, int (*cmp)())
{
    list_t *ptr = NULL;
    list_t *prec_ptr = NULL;
    list_t *ptr2 = NULL;
    list_t *prec_ptr2 = NULL;

    if (begin != NULL && *begin != NULL) {
        ptr = malloc(sizeof(ptr));
        prec_ptr = malloc(sizeof(prec_ptr));
        ptr2 = malloc(sizeof(ptr2));
        prec_ptr2 = malloc(sizeof(prec_ptr2));
        if (ptr != NULL && prec_ptr != NULL && 
            ptr2 != NULL && prec_ptr2 != NULL) {
            ptr = *begin;
            prec_ptr = ptr;
            ptr2 = ptr;
            prec_ptr2 = ptr2;
            while (ptr != NULL) {
                ptr2 = ptr->next;
                while (ptr2 != NULL) {
                    if (cmp(ptr->data, ptr2->data) > 0) {
                        prec_ptr2->next = ptr2->next;
                        ptr2->next = ptr;
                        if (ptr == *begin) {
                            *begin = ptr2;
                        } else {
                            prec_ptr->next = ptr2;
                        }
                        ptr = ptr2;
                    }
                    prec_ptr2 = ptr2;
                    ptr2 = ptr2->next;                    
                }
                prec_ptr = ptr;
                ptr = ptr->next;
                prec_ptr2 = ptr;
            }
        }
    }
}