#include <stdio.h>
void display_intarr(int arr[], int size)
{
    if (size > 0) {
        for (int i = 0; i < size - 1; ++i) {
            printf("%d, ", arr[i]);
        }
        printf("%d\n",arr[size - 1]);
    } else {
        printf("Empty array");
    }
}