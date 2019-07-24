#include <stdio.h>
int my_pow(int n, int p);

int main(void)
{
    printf("2^3=%d\n", my_pow(2,3));
    printf("4^-1=%d\n", my_pow(4,-1));
    printf("6^0=%d\n", my_pow(6, 0));
    printf("7^15=%d\n", my_pow(7, 15));
}