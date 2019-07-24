/*                                                                                                               
** ETNA PROJECT, 13/10/2018 by soubri_j                                                                          
** main                                                                                                
** File description:                                                                                             
**      Programs that reads parameters and capitalize it.
*/
#include <stdlib.h>
char *my_capitalize(char *str);
void my_putchar(char c);

int main(int nb_args, char **args)
{
    if (nb_args > 0) {
        for (int i = 0; i < nb_args; ++i) {
            my_capitalize(args[i]);
            my_putchar('\n');
        }
    }
    return 0;
}