/*                                                                                                               
** ETNA PROJECT, 13/10/2018 by soubri_j                                                                          
** main                                                                                                
** File description:                                                                                             
**      Programs that reads parameters and capitalize it.
*/
#include <stdlib.h>
#include <stdio.h>
char **my_rev_params(int ac, char **av);

int main(void)
{
    char **args2 = NULL;
    char **args_rev = NULL;

    args2 = malloc(sizeof(char*) * 4);

    for (int i = 0; i < 4; ++i) {
        args2[i] = malloc(sizeof(char*) * 10);
    }

    args2[0] = "abcdeghijk";
    args2[1] = "?./=+^$*)(";
    args2[2] = "0123456789";
    args2[3] = "AZERTYUIOP";
    
    for (int i = 0; i < 4; ++i) {
        printf("%s\n", args2[i]);
    }

    args_rev = my_rev_params(4, args2);
    for (int i = 0; i < 4; ++i) {
        printf("%s\n", args_rev[i]);
    }
}