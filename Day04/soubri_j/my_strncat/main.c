#include <stdio.h>
char *my_strncat(char *dest, char *src, int n);
void display_result(char *dest, char *src, int n);

int main(void)
{
    display_result(NULL,NULL,5);
    char dest[] = "";
    char src[] = "";
    display_result(dest,src,3);
    char dest2[5] = { '1', '2', '3', '\0' };
    char src2[] = "";
    display_result(dest2,src2,-1);
    display_result(dest2,NULL, 5);
    char dest3[10] = { '1', '2', '3', '\0' };
    char src3[] = "abc";
    display_result(dest3,src3,2);
    char dest4[10] = { '1', '2', '3', '\0' };
    char src4[] = "abcde";
    display_result(dest4,src4,3);
    char dest5[6] = { '1', '2', '3', '4', '5', '\0' };
    char src5[] = "abc";
    display_result(dest5,src5,4);
    display_result(dest5,src5,0);
}

void display_result(char *dest, char *src, int n)
{
    printf("Appending %d first chars from %s ", n, src);
    printf("to %s\n", dest);
    printf("Result : %s\n", my_strncat(dest, src, n));
}