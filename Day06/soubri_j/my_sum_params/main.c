/*                                                                                                               
** ETNA PROJECT, 13/10/2018 by soubri_j                                                                          
** main                                                                                                
** File description:                                                                                             
**      Programs that reads parameters and capitalize it.
*/
#include <stdlib.h>
#include <stdio.h>
char *my_sum_params(int argc, char **argv);

int main(void)
{
    char *summed_string = NULL;
    char **args2 = NULL;

    args2 = malloc(sizeof(char*) * 3);

    for (int i = 0; i < 3; ++i) {
        args2[i] = malloc(sizeof(char*) * 10);
    }

    args2[0] = "abcdeghijk";
    args2[1] = "?./=+^$*)(";
    args2[2] = "0123456789";
    
    summed_string = my_sum_params(3, args2);
    printf ("%s", summed_string);
    printf("\n");
    printf("%s", my_sum_params(0, NULL));
}