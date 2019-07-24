#include <stdio.h>
#include <stdlib.h>
#include "my_list.h"
list_t *my_params_in_list(int argc, char **argv);
void my_add_list_to_list(list_t **begin1, list_t *begin2);
void print_list(list_t *params);

int main(int nb_args, char** args)
{
    list_t *params = NULL;
    list_t *params2 = NULL;

    params = my_params_in_list(nb_args, args);
    params2 = my_params_in_list(nb_args, args);

    if (params != NULL) {
        my_add_list_to_list(&params, params2);
        print_list(params);
    }

    my_add_list_to_list(&params, NULL);
    print_list(params);

    my_add_list_to_list(NULL, params2);
    print_list(params);
    return 0;
}

void print_list(list_t *params)
{        
    while (params != NULL) {
        printf("%s \n", ((char *)params->data));
        params = params->next;
    } 
}