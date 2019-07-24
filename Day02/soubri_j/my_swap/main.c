#include <stdio.h>
void my_swap(int *a, int *b);

int main(void)
{
    int a = 42;
    int b = 65;

    printf("Before swapping : a=%d, b=%d\n", a, b);
    printf("Before swapping : a_adr=%p, b_adr=%p\n", &a, &b);
    my_swap(&a, &b);
    printf("After swapping : a=%d, b=%d\n", a, b);
    printf("After swapping : a_adr=%p, b_adr=%p\n", &a, &b);
}