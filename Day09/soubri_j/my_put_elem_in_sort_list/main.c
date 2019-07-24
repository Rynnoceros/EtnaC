#include <stdio.h>
#include <stdlib.h>
#include "my_list.h"
void my_put_elem_in_sort_list(list_t **begin, void *data, int (*cmp)());
void print_list(list_t *params);
int compare_int(void *a, void *b);

int main(void)
{
    list_t *sorted_list = NULL;
    int a = 2;
    int b = 5;
    int c = 10;
    int d = 7;
    int e = 10;
    int f = 15;
    int g = 1;

    printf("Creating sorted list 1\n");
    sorted_list = malloc(sizeof(*sorted_list));
    sorted_list->data =  &a;
    sorted_list->next = malloc(sizeof(*sorted_list->next));
    sorted_list->next->data = &b;
    sorted_list->next->next = malloc(sizeof(sorted_list->next->next));
    sorted_list->next->next->data = &c;
    sorted_list->next->next->next = NULL;
    printf("Printing list 1\n");
    print_list(sorted_list);

    printf("Adding 1\n");
    my_put_elem_in_sort_list(&sorted_list, &g, compare_int);
    print_list(sorted_list);

    printf("Adding 7\n");
    my_put_elem_in_sort_list(&sorted_list, &d, compare_int);
    print_list(sorted_list);

    printf("Adding 10\n");
    my_put_elem_in_sort_list(&sorted_list, &e, compare_int);
    print_list(sorted_list);

    printf("Adding 15\n");
    my_put_elem_in_sort_list(&sorted_list, &f, compare_int);
    print_list(sorted_list);
    return 0;
}

int compare_int(void *a, void *b) {
    int x = *((int *)a);
    int y = *((int *)b);

    if (x < y)
        return -1;
    else if(x > y)
        return 1;
    else
        return 0;
}

void print_list(list_t *params)
{        
    while (params != NULL) {
        printf("%d \n", *((int *)params->data));
        params = params->next;
    } 
}