/*
** ETNA PROJECT, 16/01/2019 by soubri_j/martin_m
** test_malloc.c
** File description: 
**      This file contains tests for malloc program.
*/

#include <stdio.h>
#include <string.h>
#include "../malloc.h"

char *init_str(char *str, char c, int n)
{
    while(n--) {
        str[n] = c;
    }

    return str;
}

int main()
{
    //int cpt = 0;
    /*void *ptr = NULL;
    char *ptr2 = NULL;
    int *ptr3 = NULL;
    printf("Test malloc\n");
    printf("-----------\n");
    printf("NULL pointer\n");
    printf("------------\n");
    print_list(ptr);
    ptr = malloc(1000);
    printf("After malloc 1000\n");
    printf("-----------------\n");
    print_list(ptr);
    ptr2 = malloc(6);
    strcpy(ptr2, "coucou");
    printf("PTR2 : %p\n", ptr2);
    printf("After malloc 6\n");
    printf("-----------------\n");

    block_t *bc = NULL;
    bc = (((block_t*)ptr2) - 1);
    printf("size ptr2 : %lu\n", bc->size);

    int i;
    char *str = malloc(573);
    for (i = 0; i<573; ++i) {
        str[i] = 'b';
    }
    printf("str : %s\n", str);
    free(str);

    char *letter = malloc(134); 
    for (i = 0; i<134; ++i) {
        letter[i] = 'a';
    }
    printf("letter : %s\n", letter);

    char *toto = malloc(571);
    for (i = 0; i<571; ++i) {
        toto[i] = 'c';
    }
    printf("toto : %s\n", toto);
    printf("letter : %s\n", letter);
    letter = realloc(letter, 160);
    printf("letter after realloc : %s\n", letter);
    
    char *titi = malloc(200);
    for (i = 0; i<200; ++i) {
        titi[i] = 'd';
    }

    printf("letter after malloc titi : %s\n", letter);


    printf("letter : %s\n", letter);
    print_list(ptr);
    printf("malloc 6 content : %s\n", ptr2);
    ptr3 = malloc(1000000);
    printf("After malloc 1000000\n");
    printf("--------------------\n");
    print_list(ptr);

    printf("Before free %p\n", ptr2);
    free(ptr2);
    printf("After free 6\n");
    printf("--------------------\n");
    print_list(ptr);
    *ptr3 = 34567;

    ptr2 = malloc(5);
    strcpy(ptr2, "hello");
    printf("PTR2 content : %s\n", ptr2);
    print_list(ptr);

    printf("PTR3 content : %d\n", *ptr3);
    */
 
   
    /*int *tabInt = (int *) calloc(13, sizeof(int));
    tabInt[0] = 1;
    tabInt[1] = 2;
    tabInt[3] = 3;
    int i = 0;
    for (i = 0; i < 13; ++i) {
        printf("%d : %d\n", i, *(tabInt + i));
    }*/


    int i;
    for (i = 0; i < 10000; ++i) {
        free(NULL);
    }

    return 0;
}