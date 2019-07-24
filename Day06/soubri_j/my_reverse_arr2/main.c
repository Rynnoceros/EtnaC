/*                                                                                                               
** ETNA PROJECT, 13/10/2018 by soubri_j                                                                          
** main                                                                                                
** File description:                                                                                             
**      Programs that reads parameters and capitalize it.
*/
#include <stdlib.h>
#include <stdio.h>
int **my_reverse_arr2(int **arr, unsigned int sizex, unsigned int sizey);
void display_result(int **arr, unsigned int sizex, unsigned int sizey);

int main(void)
{
    int **arr = NULL;
    int sizey = 4;
    int sizex = 10;
    int **arr_rev = NULL;

    arr = malloc(sizeof(int*) * sizey);
    for (int y = 0; y < sizey; ++y) {
        arr[y] = malloc(sizeof(int*) * sizex);
        for (int x = 0; x < sizex; ++x) {
            arr[y][x] = x;
        }
    }

    display_result(arr,sizex,sizey);
    display_result(NULL,4,0);
    arr_rev = my_reverse_arr2(arr, sizex, sizey);
    display_result(arr_rev,sizey,sizex);
    arr_rev = my_reverse_arr2(NULL, sizex, sizey);
    display_result(arr_rev,0,0);
}

void display_result(int **arr, unsigned int sizex, unsigned int sizey)
{
    if (arr != NULL) {
        for (unsigned int i = 0; i < sizey; ++i) {
            for (unsigned int j = 0; j < sizex; ++j) {
                printf("%d", arr[i][j]);
            }
            printf("\n");
        }
    }
}