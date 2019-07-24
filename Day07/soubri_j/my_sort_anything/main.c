#include <stdlib.h>
#include <stdio.h>

void *my_sort_anything(void *to_sort, int nmemb, int size, 
                       int (*compare)(void *, void *));
int compare_int(void *x, void *y);
int (*compare)(void *x, void *y);

void *my_duplicate(void *to_duplicate, int size);

int main(void)
{
    //int *sorted_array = NULL;
    int *array_to_sort = NULL;//[10] = { 100, 20, 40, 25, 67, 8, 1, 3, 90, 35 };

    array_to_sort = malloc(sizeof(int) * 3);
    array_to_sort[0] = 3;
    array_to_sort[1] = 12;
    array_to_sort[2] = 1;
    int *i = NULL;
    i = malloc(sizeof(int));
    *i = 10;

    int *j = NULL;
    j = malloc(sizeof(int));
    *j = 20;

    printf("i : %d : %p\n", *i, &(*i));
    int k = *((int *)my_duplicate(i, sizeof(int)));
    printf("k : %d : %p\n", k, &k);

    compare = compare_int;
    my_sort_anything(&array_to_sort, 3, sizeof(int), compare);
    
    for (int i = 0; i < 3; ++i) {
        printf("%d ", array_to_sort[i]);
    }
    printf("\n");
}

int compare_int(void *x, void *y)
{
    int ix = *((int *)x);
    int iy = *((int *)y);

    if (ix < iy)
        return -1;
    else if (ix > iy)
        return 1;
    else 
        return 0;
}