#include <stdio.h>
int my_is_neg(int n);
void my_putchar(char c);

int main(void)
{
    printf("-12 :%i\n", my_is_neg(-12));
    printf("-1 :%i\n", my_is_neg(-1));
    printf("0 :%i\n", my_is_neg(0));
    printf("1 :%i\n", my_is_neg(1));
    printf("12 :%i\n", my_is_neg(12));
}