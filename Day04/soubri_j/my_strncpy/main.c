#include <stdio.h>
char *my_strncpy(char *dest, char *src, int n);
void display_result(char *dest, char *src, int n);

int main(void)
{
    display_result(NULL,NULL,-1);
    char dest[1] = "";
    char src[1] = "";
    display_result(dest,src,2);
    char dest2[4] = "123";
    char src2[] = "";
    display_result(dest2,src2,2);
    char dest3[4] = "";
    char src3[] = "abc";
    display_result(dest3,src3,2);
    char dest4[6] = "123";
    char src4[] = "abcde";
    display_result(dest4,src4,2);
    char dest5[] = "123456";
    char src5[] = "abc";
    display_result(dest5,src5,7);

    char dest6[34] = "";
    char src6[] = "Lorem ipsum dolor sit amet etc.";
    display_result(dest6,src6,1);
    display_result(dest6,src6,5);
    display_result(dest6,src6,30);
    display_result(dest6,src6,31);
    display_result(dest6,src6,32);
    display_result(dest6,src6,512);
}

void display_result(char *dest, char *src, int n)
{
    printf("Copy %d chars from src:%s\n", n, src);
    printf("To dest:%s\n", dest);
    printf("Result : %s\n", my_strncpy(dest, src, n));
}