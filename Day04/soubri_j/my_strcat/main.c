#include <stdio.h>
char *my_strcat(char *dest, char *src);
void display_result(char *dest, char *src);

int main(void)
{
    display_result(NULL,NULL);
    char dest[] = "";
    char src[] = "";
    display_result(dest,src);
    char dest2[5] = { '1', '2', '3', '\0' };
    char src2[] = "";
    display_result(dest2,src2);
    display_result(dest2,NULL);
    char dest3[10] = { '1', '2', '3', '\0' };
    char src3[] = "abc";
    display_result(dest3,src3);
    char dest4[10] = { '1', '2', '3', '\0' };
    char src4[] = "abcde";
    display_result(dest4,src4);
    char dest5[6] = { '1', '2', '3', '4', '5', '\0' };
    char src5[] = "abc";
    display_result(dest5,src5);
}

void display_result(char *dest, char *src)
{
    printf("Appending %s ", src);
    printf("to %s\n", dest);
    printf("Result : %s\n", my_strcat(dest, src));
}