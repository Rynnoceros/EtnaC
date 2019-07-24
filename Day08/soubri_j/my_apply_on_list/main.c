#include <stdio.h>
#include <stdlib.h>
#include "my_list.h"
list_t *my_params_in_list(int argc, char **argv);
void my_apply_on_list(list_t *begin, int (*f)());
int my_strlen(char *str);
int print_data (void *data);
int (*my_func)();

int main(void)
{
    list_t *my_list = NULL;
    char **args = NULL;

    my_func = print_data;
    args = malloc(sizeof(*args) * 3);
    args[0] = "toto";
    args[1] = "tutu";
    args[2] = "titi";
    my_list = my_params_in_list(3, args);
    if (my_list != NULL) {
        my_apply_on_list(my_list, my_func);
    }
    return 0;
}

int print_data (void *data)
{
    printf("%s \n", ((char *) data));
    return 0;
}