#include <stdio.h>
void my_set_arr(int arr[], int size, int value);
void display_arr(int arr[], int size);

int main(void)
{
    int arr[6] = { 1, 5, 98, 30, 54, 200 };

    printf("Before setting : ");
    display_arr(arr, 6);
    my_set_arr(arr, 3, 7);
    printf("After setting 7 for the 3 first : ");
    display_arr(arr, 6);
    my_set_arr(arr, 6, 12);
    printf("After setting 12 for the 6 first : ");
    display_arr(arr, 6);
}

void display_arr(int arr[], int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%d,", arr[i]);
    }
    printf("\n");
}