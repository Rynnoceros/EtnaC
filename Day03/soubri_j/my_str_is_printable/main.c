#include <stdio.h>
int my_str_is_printable(char *str);

int main(void)
{
    printf(": %d\n", my_str_is_printable(""));
    printf("A printable string (with 5 spaces) : %d\n", my_str_is_printable("A printable string (with 5 spaces)"));
    printf("A non-printable\tstring (with an horizontal tabulation) : %d\n", my_str_is_printable("A non-printable\tstring (with an horizontal tabulation)"));
    printf("A non-printable string (with a new line)\\n : %d\n", my_str_is_printable("A non-printable string (with a new line)\n"));
    printf("A printable string (with a \\0) : %d\n", my_str_is_printable("A non-printable string (with end of line \0)"));
    printf("A non-printable string (with \\r) : %d\n", my_str_is_printable("A non-printable string (with end \\r \r)"));
    printf("%c", 127);
    
    for (int i = 0; i < 256; ++i) {
        printf("%d:%c\n", i, i);
    }

    printf("NULL:%d\n", my_str_is_printable(NULL));
}