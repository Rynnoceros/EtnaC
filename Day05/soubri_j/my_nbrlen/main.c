#include <stdio.h>
int my_nbrlen(int n);
void print_result(int value);

int main(void)
{
    print_result(23);
    print_result(-1);
    print_result(0);
    print_result(+1);
    print_result(-542);
    print_result(-999);
    print_result(-1000);
    print_result(542);
    print_result(+543);
    print_result(999);
    print_result(1000);
    print_result(1001); 
}

void print_result(int value)
{
    printf("len %d : %d\n", value, my_nbrlen(value));
}