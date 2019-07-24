#include <stdio.h>
#include <stdlib.h>
#include "my_list.h"
list_t *my_params_in_list(int argc, char **argv);
void my_apply_on_eq_list(list_t *begin, int (*f)(), void *data_ref, 
                         int (*cmp)());
int my_strcmp(char *s1, char *s2);
int print_data (char *data);
int (*my_func)();

int main(int nb_args, char **args)
{
    list_t *my_list = NULL;

    my_list = my_params_in_list(nb_args, args);
    my_func = print_data;
    if (my_list != NULL) {
        my_apply_on_eq_list(my_list, my_func, "toto", my_strcmp);
    }
    return 0;
}

int print_data (char *data)
{
    printf("%s \n", data);
    return 0;
}