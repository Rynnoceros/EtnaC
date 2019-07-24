/*                                                                                                               
** ETNA PROJECT, 01/10/2018 by soubri_j                                                                          
** my_print_alpha                                                                                               
** File description:                                                                                             
**      Function that prints alphabet in lowercase                                            
*/
void my_putchar(char c);

void my_print_alpha(void)
{
    for (unsigned int i = 97; i <= 122; ++i) {
        my_putchar(i);
    }
    my_putchar('\n');
}