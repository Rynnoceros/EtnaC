/*                                                                                                               
** ETNA PROJECT, 15/10/2018 by soubri_j                                                                          
** my_math_op                                                                                                
** File description: 
**      File containing all mathematical operations needed to the program
**      do-op.
*/
void my_putstr(char *str);
void my_putnbr(int n);

void add(int x, int y)
{
    my_putnbr(x + y);
    my_putstr("\n");
}

void substract(int x, int y)
{
    my_putnbr(x - y);
    my_putstr("\n");
}

void multiply(int x, int y)
{
    my_putnbr(x * y);
    my_putstr("\n");
}

void divide(int x, int y)
{
    if (y == 0) {
        my_putstr("buy ya-self some fingers\n");
        return;
    }
    my_putnbr(x / y);
    my_putstr("\n");
}

void modulo(int x, int y)
{
    if (y == 0) {
        my_putstr("buy ya-self some fingers\n");
        return;
    }
    my_putnbr(x % y);
    my_putstr("\n");
}

void init_operations(void (*ptr[5])(int x, int y))
{
    ptr[0] = add;
    ptr[1] = substract;
    ptr[2] = multiply;
    ptr[3] = divide;
    ptr[4] = modulo;
}