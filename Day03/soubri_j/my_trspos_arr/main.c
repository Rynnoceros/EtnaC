#include <stdlib.h>
void my_trspos_arr(int c, int l, char **arr);

int main(void)
{
    char *arr[] = {
    "abcdefghij",
    "0123456789",
    "qwertyuiop"
    };

    my_trspos_arr(10, 3, arr);
    my_trspos_arr(10, 3, NULL);
    return 0;
}