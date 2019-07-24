#include <stdio.h>
void my_fibonacci_arr(int arr[], int size);
void display_intarr(int arr[], int size);

int main(void)
{
    int arr[40];
    my_fibonacci_arr(arr, 40);
    display_intarr(arr, 40);
}