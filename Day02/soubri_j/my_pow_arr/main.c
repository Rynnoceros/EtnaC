#include <stdio.h>
void my_pow_arr(int arr[], int size, int p);
void display_arr(int arr[], int size);

int main(void)
{
    int arr[6];

    printf("Before my_pow_arr : ");
    display_arr(arr, 6);
    my_pow_arr(arr, 6, 3);
    printf("My pow arr 6-3 : ");
    display_arr(arr, 6);
    my_pow_arr(arr, 6, 7);
    printf("My pow arr 6-7 : ");
    display_arr(arr, 6);
}

void display_arr(int arr[], int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%d,", arr[i]);
    }
    printf("\n");
}