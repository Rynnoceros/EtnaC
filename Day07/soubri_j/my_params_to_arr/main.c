#include "my_struct.h"
#include <stdio.h>
void print_struct(struct stock_par_s element);

int main(int nb_args, char **args)
{
    struct stock_par_s *list = NULL;

    list = my_params_to_arr(nb_args, args);
    for (int i = 0; i <= nb_args; ++i) {
        print_struct(list[i]);
    }
    printf("list[2].str : %s\n",list[2].str);
    printf("list[3].str : %s\n",list[3].str);
    return 0;
}

void print_struct(struct stock_par_s element)
{
    printf("---- Element ----\n");
    printf("param size : %d\n", element.size_param);
    printf("str : %s : %p\n", element.str, element.str);
    printf("copy : %s : %p\n", element.copy, element.copy);
    printf("tab : %p\n", element.tab);
    printf("-- End element --\n");
}