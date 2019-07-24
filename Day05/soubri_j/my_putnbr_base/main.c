#include <stdio.h>
void my_putnbr_base(int n, char *base);

int main(void)
{
    my_putnbr_base(345678, "0123456789ABCDEF");
    printf("\n");
    my_putnbr_base(35, "01");
    printf("\n");
    my_putnbr_base(34565, "!))\\n");
    printf("\n");
    my_putnbr_base(-35, "01");
    printf("\n");
    my_putnbr_base(-35, "0123456789");
    printf("\n");
    my_putnbr_base(-35, "KJUIONHV");
    printf("\n");
    my_putnbr_base(999, NULL);
    printf("\n");
    my_putnbr_base(-2147483648, "0123456789");
    printf("\n");
    my_putnbr_base(2147483647, "01");
    printf("\n");
    my_putnbr_base(-2147483648, "01");
    printf("\n");
    my_putnbr_base(-2147483648, "0123456789ABCDEF");
    printf("\n");
    my_putnbr_base(-2147483648, "@#_$%&QW:rTY{=}");
    printf("\n");
    my_putnbr_base(244, "0123456789ABCDEF");
    printf("\n");
}