#include <stdio.h>
#include "my_list.h"
list_t *my_params_in_list(int argc, char **argv);

int main(int nb_args, char** args)
{
    list_t *params = NULL;

    params = my_params_in_list(nb_args, args);

    if (params != NULL) {
        do {
            printf("%s \n", ((char *)params->data));
            params = params->next;
        } while (params != NULL);
    }
    return 0;
}