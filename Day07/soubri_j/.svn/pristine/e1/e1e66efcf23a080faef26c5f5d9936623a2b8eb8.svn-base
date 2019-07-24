/*                                                                                                               
** ETNA PROJECT, 15/10/2018 by soubri_j                                                                          
** main                                                                                                
** File description: 
**      Program which evaluate a simple mathematic expression.
*/
#include <stdlib.h>
int my_getnbr(char *str, int *is_number);
void my_putstr(char *str);
int my_chrpos(char *str, char c);
void init_operations(void (*ptr[5])(int x, int y));

void (*operations[5])(int x, int y);
char *operators = "+-*/%";
const int nb_params = 4;

int main(int nb_args, char **args)
{
    int first_param = 0;
    int operator_pos = -1;
    int second_param = 0;
    int is_ok = 0;

    if (nb_args < nb_params) {
        return -1;
    }

    init_operations(operations);

    first_param = my_getnbr(args[1], &is_ok);
    if (is_ok >= 0) {
        operator_pos = my_chrpos(operators, *args[2]);
        is_ok = operator_pos;
        if (is_ok >= 0) {
            second_param = my_getnbr(args[3], &is_ok);
            if (is_ok >= 0) {
                operations[operator_pos](first_param, second_param);
            }
        }
    }

    if (is_ok < 0) {
        my_putstr("Syntax Error\n");
    }

    return 0;
}