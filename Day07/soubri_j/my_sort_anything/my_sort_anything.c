/*                                                                                                               
** ETNA PROJECT, 15/10/2018 by soubri_j                                                                          
** my_sort_anything                                                                                                
** File description: 
**      Function to sort an array of any types element.
*/
#include <stdlib.h>
#include <stdio.h>
void *my_duplicate(void *to_duplicate, int size);

void *my_sort_anything(void *to_sort, int nmemb, int size, 
                       int (*compare)(void *, void *))
{
    void **sorted_array = NULL;
    //void *swap_element = NULL;
    
    /*if (to_sort != NULL) {
        sorted_array = malloc(sizeof(to_sort));
        if (sorted_array != NULL) {
            *sorted_array = malloc(size * nmemb);
            if (*sorted_array != NULL) {
                for (int i = 0; i < nmemb; ++i) {
                    sorted_array[i * size] = my_duplicate(&to_sort[i * size], size);
                }
                
                for (int i = 0; i < nmemb; ++i) {
                    for (int j = i + 1; j < nmemb; ++j) {
                        if (compare(sorted_array[i * size], sorted_array[j * size]) > 0) {
                            swap_element = sorted_array[j * size];
                            sorted_array[j * size] = sorted_array[i * size];
                            sorted_array[i * size] = swap_element;
                        }
                    }
                }
            }
        }
    }*/

    if (to_sort != NULL) {
        sorted_array = my_duplicate(to_sort, nmemb * size);
        compare(&to_sort[0], &to_sort[1]);
        printf("for : %d\n", nmemb);
        for (int i = 0; i < nmemb; ++i) {
            sorted_array[i * size] = &to_sort[i * size];
            printf ("%d ", *((int*)sorted_array[i * size]));
        }
    }

    return *sorted_array;
}

void *my_duplicate(void *to_duplicate, int size)
{
    void **duplicate_element = NULL;
    void **to_duplicate2 = NULL;

    if (to_duplicate != NULL) {
        duplicate_element = malloc(size);
        if (duplicate_element != NULL) {
            to_duplicate2 = &to_duplicate;
            *duplicate_element = *to_duplicate2;
        }
    }

    return *duplicate_element;
}