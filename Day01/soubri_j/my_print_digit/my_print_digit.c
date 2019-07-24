/*                                                                                                               
** ETNA PROJECT, 01/10/2018 by soubri_j                                                                          
** my_print_digit                                                                                              
** File description:                                                                                             
**      Function that prints all digits on a single line                                          
*/
void my_putchar(char c);

void my_print_digit(void)
{
    for (unsigned int i = 48; i <= 57; ++i) {
        my_putchar(i);
    }
    my_putchar('\n');
}