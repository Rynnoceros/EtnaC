#include <stdio.h>
void my_sort_intarr(int arr[], int size);
void display_arr(int arr[], int size);

int main(void)
{
    int arr[6] = { 1, 60, 15, 87, 3, 50 };

    printf("Before sorting : ");
    display_arr(arr, 6);
    my_sort_intarr(arr, 6);
    printf("After sorting : ");
    display_arr(arr, 6);
}

void display_arr(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d,", arr[i]);
    }
    printf("\n");
}