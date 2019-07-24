#include <stdio.h>
char *my_strcpy(char *dest, char *src);
void display_result(char *dest, char *src);

int main(void)
{
    display_result(NULL,NULL);
    char dest[] = "";
    char src[] = "";
    display_result(dest,src);
    char dest2[] = "123";
    char src2[] = "";
    display_result(dest2,src2);
    char dest3[] = "";
    char src3[] = "abc";
    display_result(dest3,src3);
    char dest4[6] = "123";
    char src4[] = "abcde";
    display_result(dest4,src4);
    char dest5[] = "123456";
    char src5[] = "abc";
    display_result(dest5,src5);

    char dest6[4] = "";
    char src6[] = "abc";
    display_result(dest6, src6);
    char dest7[34];
    char src7[] = "Lorem ipsum dolor sit amet etc.";
    display_result(dest7, src7);
}

void display_result(char *dest, char *src)
{
    printf("Copy from src:%s\n", src);
    printf("To dest:%s\n", dest);
    printf("Result : %s\n", my_strcpy(dest, src));
}