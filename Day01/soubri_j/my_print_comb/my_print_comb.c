/*                                                                                                               
** ETNA PROJECT, 02/10/2018 by soubri_j                                                                          
** my_print_comb                                                                                              
** File description:                                                                                             
**      Function that displays all the different combinations of three 
**      different digits on a single line.
*/
void my_putchar(char c);

void my_print_comb(void)
{
    for (unsigned int i = 48; i <= 55; ++i) {
        for (unsigned int j = i + 1; j <= 56; ++j) {
            for (unsigned int k = j + 1; k <= 57; ++k) {
                my_putchar(i);
                my_putchar(j);
                my_putchar(k);
                if (!(i == 55 && j == 56 && k == 57)) {
                    my_putchar(',');
                    my_putchar(' ');
                }
            }
        }
    }
    my_putchar('\n');    
}