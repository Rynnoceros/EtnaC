#include <stdio.h>

int my_fibonacci(int n);

int main(void)
{
    int i = -10;

    while (i < 100) {
        printf("my_fibonacci(%d) = %d\n", i, my_fibonacci(i));
        i = i + 1;
    }
    return 0;
}