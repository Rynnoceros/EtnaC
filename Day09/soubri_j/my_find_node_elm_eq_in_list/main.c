#include <stdio.h>
#include <stdlib.h>
#include "my_list.h"
list_t *my_find_node_elm_eq_in_list(list_t *begin, void *data_ref, 
                                    int (*cmp)());
void print_list(list_t *params);
int compare_int(void *a, void *b);

int main(void)
{
    list_t *sorted_list = NULL;
    int a = 1;
    int b = 5;
    int c = 10;
    int d = 11;
    
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

    list_t *z = NULL;
    z = my_find_node_elm_eq_in_list(sorted_list, &b, compare_int);
    if (z != NULL) {
        printf ("Found : %d\n", *((int *)z->data));
    }
    list_t *y = NULL;
    y = my_find_node_elm_eq_in_list(sorted_list, &d, compare_int);
    if (y == NULL) {
        printf ("Not Found\n");
    }
    list_t *x = NULL;
    x = my_find_node_elm_eq_in_list(NULL, &c, compare_int);
    if (x == NULL) {
        printf ("Not Found\n");
    }
    return 0;
}

int compare_int(void *a, void *b) {
    int x = *((int *)a);
    int y = *((int *)b);

    printf("Comparing...\n");
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