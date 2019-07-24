#include <stdio.h>
#include <stdlib.h>
#include "my_list.h"
list_t *my_params_in_list(int argc, char **argv);
void my_rev_list(list_t **begin);

int main(int nb_args, char **args)
{
    list_t *my_list = NULL;
    list_t *ptr = NULL;

    my_list = my_params_in_list(nb_args, args);
    ptr = my_list;
    do {
        printf("%s\n", ((char *)ptr->data));
        ptr = ptr->next;
    } while (ptr != NULL);
    printf("----\n");
    my_rev_list(&my_list);

    while (my_list != NULL) {
        printf("%s\n", ((char *)my_list->data));
        my_list = my_list->next;
    } 
    return 0;
}
