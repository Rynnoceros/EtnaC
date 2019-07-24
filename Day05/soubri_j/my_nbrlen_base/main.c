#include <stdio.h>
int my_nbrlen_base(int n, int base);
void print_result(int value, int base);

int main(void)
{
    print_result(23, 10);
    print_result(23, 2);
    print_result(23, 16);
    print_result(-1, 10);
    print_result(-1, 2);
    print_result(-1, 20);
    print_result(0, 2);
    print_result(+1, 2);
    print_result(-542, 10);
    print_result(-542, 2);
    print_result(-542, 16);
    print_result(-999, 10);
    print_result(-999, 2);
    print_result(-999, 50);
    print_result(-1000, 10);
    print_result(-1000, 2);
    print_result(-1000, 50);
    print_result(-1000, 16);
    print_result(542, 10);
    print_result(542, 16);
    print_result(542, 2);
    print_result(+543, 50);
    print_result(999,2);
    print_result(999,10);
    print_result(999,40);
    print_result(1000, 10);
    print_result(1023, 2); 
    print_result(1024, 2); 
    print_result(1025, 2); 
    print_result(-1024, 2); 
    print_result(-0, 2); 
    print_result(0, 2); 
    print_result(1, 2);
    print_result(2, 2); 
    print_result(511, 2);  
}

void print_result(int value, int base)
{
    printf("len %d in base %d: %d\n", value, base, my_nbrlen_base(value, base));
}