#include <stdio.h>
#include <stdlib.h>
#include "my_list.h"
list_t *my_params_in_list(int argc, char **argv);
int my_list_size(list_t *begin);

int main(int nb_args, char **args)
{
    list_t *my_list = NULL;

    my_list = my_params_in_list(nb_args, args);
    printf("List size : %d\n", my_list_size(my_list));

    return 0;
}
