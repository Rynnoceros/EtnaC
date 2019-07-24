#include <stdio.h>
void my_putnbr(int n);

int main(void)
{
    my_putnbr(-898989);
    printf("\n");
    my_putnbr(-89);
    printf("\n");
    my_putnbr(-1);
    printf("\n");
    my_putnbr(0);
    printf("\n");
    my_putnbr(1);
    printf("\n");
    my_putnbr(-10);
    printf("\n");
    my_putnbr(-1000);
    printf("\n");
    my_putnbr(-100000);
    printf("\n");
    my_putnbr(99999);
    printf("\n");
    my_putnbr(2147483647);
    printf("\n");
    my_putnbr(-2147483648);
    printf("\n");
    my_putnbr(-1234567890);
    printf("\n");
    my_putnbr(-2000000000);
    printf("\n");
}