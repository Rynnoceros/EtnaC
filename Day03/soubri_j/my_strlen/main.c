#include <stdio.h>
int my_strlen(char *str);

int main(void)
{
    printf("Hello World! : %d\n", my_strlen("Hello World!"));
    printf("Hello! : %d\n", my_strlen("Hello!"));
    printf("Hi! : %d\n", my_strlen("Hi!"));
    printf("0123456789 : %d\n", my_strlen("0123456789"));
    printf("NULL:%d\n", my_strlen(NULL));
}