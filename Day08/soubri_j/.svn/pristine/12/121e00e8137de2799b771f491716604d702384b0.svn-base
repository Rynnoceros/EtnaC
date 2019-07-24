/*                                                                                                               
** ETNA PROJECT, 17/10/2018 by soubri_j                                                                          
** my_params_to_arr                                                                                                
** File description: 
**      Function that creates a new list by adding each 
**      argv element to it. This function returns a pointer to the first 
**      element in the list.
*/
#include <stdlib.h>
#include "my_list.h"

list_t *my_params_in_list(int argc, char **argv)
{
    list_t *params_list = NULL;
    list_t *current_param = NULL;

    if (argc > 0 && argv != NULL) {
        params_list = malloc(sizeof(*params_list));
        if (params_list != NULL) {
            params_list->data = argv[0];
            params_list->next = NULL;
            for (int i = 1; i < argc; ++i) {
                current_param = malloc(sizeof(*current_param));
                if (current_param != NULL) {
                    current_param->data = argv[i];
                    current_param->next = params_list;
                    params_list = current_param;
                }
            }
        }
    }
    return params_list;
}