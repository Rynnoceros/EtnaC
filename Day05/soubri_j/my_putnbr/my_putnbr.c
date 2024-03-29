/*                                                                                                               
** ETNA PROJECT, 08/10/2018 by soubri_j                                                                          
** my_putnbr                                                                                                
** File description:                                                                                             
**      Function to display an integer taken as parameter. 
**      The function must be able to display every possible value 
**      for an int correctly.
*/
void my_putchar(char c);
char getchar(int n);

void my_putnbr(int n)
{
    if (n < 0) {
        my_putchar('-');
        //n *= -1;
    }

    my_putchar(getchar(n));
}

char getchar(int n)
{
    int int_part = n / 10;
    int int_rest = n % 10;

    if (int_rest < 0)
        int_rest *= -1;
    
    if (int_part < 0)
        int_part *= -1;

    if (int_part > 0)
        my_putchar(getchar(int_part));

    return (char) (int_rest + 48);
}