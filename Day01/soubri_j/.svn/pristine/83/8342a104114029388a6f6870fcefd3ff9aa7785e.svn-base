/*                                                                                                               
** ETNA PROJECT, 02/10/2018 by soubri_j                                                                          
** my_print_comb2                                                                                              
** File description:                                                                                             
**      Function that displays all the different combinations of two numbers
**      between 0 and 99, on a single line.
*/
void my_putchar(char c);
void print_digits(unsigned int d1, unsigned int d2, unsigned int d3, unsigned int d4);

void my_print_comb2(void)
{
    unsigned int d1 = 48;
    unsigned int d2 = 48;
    unsigned int d3 = 48;
    unsigned int d4 = 48;
    for (unsigned int i = 0; i <= 98; ++i) {
        if (i != 0) {
            if (i % 10 == 0) {
                d1 += 1;
                d2 = 48;
            } else {
                d2 += 1;
            }
        }
        d3 = d1;
        for (unsigned int j = i + 1; j <= 99; ++j) {
            d4 = 48 + j % 10;
            if (j % 10 == 0) {
                d3 += 1;
            }
            print_digits(d1, d2, d3, d4);
        }
    }
    my_putchar('\n');    
}

/* Function that print digits passed in parameters using formatting */
void print_digits(unsigned int d1, unsigned int d2, unsigned int d3, unsigned int d4)
{                    
    my_putchar(d1);
    my_putchar(d2);
    my_putchar(' ');
    my_putchar(d3);
    my_putchar(d4);
    if (!(d1 == 57 && d2 == 56 && d3 == 57 && d4 == 57)) {
        my_putchar(',');
        my_putchar(' ');
    }
}