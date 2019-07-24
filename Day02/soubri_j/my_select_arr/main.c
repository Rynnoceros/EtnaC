#include <stdio.h>
char my_select_arr(char arr[4][14], int i, int j);

int main(void)
{
    char arr[4][14];

    for (int i = 0; i < 4; ++i) {
        printf("%d:",i);
        for (int j = 0; j < 14; ++j) {
            arr[i][j] = i + j;
            printf("%d,", i + j);
        }
        printf("\n");
    }

    printf("Display value [%d][%d]:%d\n", 0, 12, my_select_arr(arr, 0, 12));
    printf("Display value [%d][%d]:%d\n", 1, 5, my_select_arr(arr, 1, 5));
    printf("Display value [%d][%d]:%d\n", 2, 0, my_select_arr(arr, 2, 0));
    printf("Display value [%d][%d]:%d\n", 3, 13, my_select_arr(arr, 3, 13));
}