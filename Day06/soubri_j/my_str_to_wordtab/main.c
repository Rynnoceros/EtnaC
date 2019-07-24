/*                                                                                                               
** ETNA PROJECT, 13/10/2018 by soubri_j                                                                          
** main                                                                                                
** File description:                                                                                             
**      Programs that reads parameters and capitalize it.
*/
#include <stdlib.h>
#include <stdio.h>
char **my_str_to_wordtab(char *str);
void display_result(char *str, int nb_words);

int main(void)
{
    display_result("", 1);
    display_result(" ", 1);
    display_result("         ", 1);
    display_result("You ok?", 3);
    display_result(";;$I/LOVE-^you/", 4);
    display_result("--hello world", 3);
}

void display_result(char *str, int nb_words)
{
    char **word_tab = NULL;

    word_tab = my_str_to_wordtab(str);
    //nb_words = 0;
    for (int i = 0; i < nb_words; ++i) {
        printf("%s\n", word_tab[i]);
    }
}