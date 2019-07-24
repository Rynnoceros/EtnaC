#include <stdio.h>
char *my_strstr(char *str, char *to_find);

int main(void)
{
    printf("Hello World/World:%s\n", my_strstr("Hello World", "World"));
    printf("Hello World/Hello%s\n", my_strstr("Hello World", "Hello"));
    printf("Hello World/Nothing%s\n", my_strstr("Hello World", "Nothing"));
    printf("%s\n", my_strstr("", ""));
    printf("%s\n", my_strstr("\\", "\\"));
    printf("%s\n", my_strstr("\0", "\0"));
    printf("%s\n", my_strstr("\0", "\0"));
    printf("%s\n", my_strstr("qwe asd zxc 123 456 789", "qwe asd zxc 123 456 789_"));
    printf("%s\n", my_strstr("qwe asd", "qwe asd zxc 123 456 789"));
    printf("%s\n", my_strstr(NULL, NULL));
}