#include <stdio.h>
#include <stdlib.h>
#include "my_list.h"
void my_add_sort_list_to_sort_list(list_t **begin1, list_t *begin2, 
                                   int (*cmp)());
void print_list(list_t *params);
int compare_int(void *a, void *b);

int main(void)
{
    list_t *sorted_list = NULL;
    list_t *sorted_list2 = NULL;
    int a = 1;
    int b = 2;
    int c = 3;
    int g = 7;
    int d = 4;
    int e = 5;
    int f = 6;

    printf("Creating sorted list 1\n");
    sorted_list = malloc(sizeof(*sorted_list));
    sorted_list->data = &a;
    sorted_list->next = malloc(sizeof(*sorted_list->next));
    sorted_list->next->data = &e;
    sorted_list->next->next = malloc(sizeof(sorted_list->next->next));
    sorted_list->next->next->data = &f;
    sorted_list->next->next->next = malloc(sizeof(sorted_list->next->next->next));
    sorted_list->next->next->next->data = &g;
    sorted_list->next->next->next->next = NULL;
    printf("Printing list 1\n");
    print_list(sorted_list);

    printf("Creating sorted list 2\n");
    sorted_list2 = malloc(sizeof(*sorted_list2));
    sorted_list2->data = &b;
    sorted_list2->next = malloc(sizeof(*sorted_list2->next));
    sorted_list2->next->data = &c;
    sorted_list2->next->next = malloc(sizeof(sorted_list2->next->next));
    sorted_list2->next->next->data = &d;
    sorted_list2->next->next->next = NULL;
    print_list(sorted_list2);

    sorted_list = NULL;
    my_add_sort_list_to_sort_list(&sorted_list, sorted_list2, compare_int);

    printf("New list after adding\n");
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