/*                                                                                                               
** ETNA PROJECT, 08/10/2018 by soubri_j                                                                          
** my_putnbr_base                                                                                                
** File description:                                                                                             
**      Function to display an integer taken as parameter.
**      The integer will be displayed using the digits contained 
**      in the second parameter.
*/
#include <stdlib.h>
void my_putchar(char c);
char getchar_alphabet(int n, int base, char *alphabet);
int my_strlen(char *str);

void my_putnbr_base(int n, char *base)
{
    if (base != NULL) {
        if (n < 0) {
            my_putchar('-');
        }

        my_putchar(getchar_alphabet(n, my_strlen(base), base));
    }
}

char getchar_alphabet(int n, int base, char *alphabet)
{
    int int_part = n / base;
    int to_print = n % base;

    if (to_print < 0) 
        to_print *= -1;
    
    if (int_part < 0)
        int_part *= -1;
    
    if (int_part > 0)
        my_putchar(getchar_alphabet(int_part, base, alphabet));

    return alphabet[to_print];
}

int my_strlen(char *str)
{
    unsigned int cpt = 0;

    if (str != NULL) {
        while (str[cpt] != '\0') {
            ++cpt;
        }
    }
    
    return cpt;
}