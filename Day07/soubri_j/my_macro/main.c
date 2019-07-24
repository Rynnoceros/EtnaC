#include "my_macro.h"
#include <stdio.h>

int main(void)
{
    printf("MY_ABS(-1) : %d\n", MY_ABS(-1));
    printf("MY_ISNEG(-1) : %d\n", MY_ISNEG(-1));
    printf("MY_MAX(4,6) : %d\n", MY_MAX(4,6));
    printf("MY_MIN(10,5) : %d\n", MY_MIN(10,5));
    printf("MY_IS_PRINTABLE(\\0) : %d\n", MY_IS_PRINTABLE('\0'));
    printf("MY_IS_ALPHA(f) : %d\n", MY_IS_ALPHA('f'));
    printf("MY_IS_NUM(A) : %d\n", MY_IS_NUM('A'));
    printf("MY_IS_ALPHANUM('A') : %d\n", MY_IS_ALPHANUM('A'));
    printf("MY_IS_LOWCASE('B') : %d\n", MY_IS_LOWCASE('B'));
    printf("MY_IS_UPPERCASE('c') : %d\n", MY_IS_UPPERCASE('c'));
    return 0;
}