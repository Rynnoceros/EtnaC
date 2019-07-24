/*                                                                                                               
** ETNA PROJECT, 13/10/2018 by soubri_j                                                                          
** main                                                                                                
** File description:                                                                                             
**      Programs that reads parameters and capitalize it.
*/
#include <stdlib.h>
#include <stdio.h>
int **my_init_arr2(unsigned int sizex, unsigned int sizey, int value);
void display_result(unsigned int sizex, unsigned int sizey, int value);

int main(void)
{
    display_result(0,0,7);
    display_result(0,1,0);
    display_result(0,5,0);
    display_result(1,0,0);
    display_result(5,0,0);
    display_result(2,2,2);
    display_result(7,7,7);
    display_result(6,9,69);
    display_result(8,4,3);
    display_result(42,42,42);
    display_result(100,100,5);
}

void display_result(unsigned int sizex, unsigned int sizey, int value)
{
    int **args = NULL;
    
    args = my_init_arr2(sizex, sizey, value);

    if (args != NULL) {
        for (unsigned int i = 0; i < sizey; ++i) {
            for (unsigned int j = 0; j < sizex; ++j) {
                printf("%d", args[i][j]);
            }
            printf("\n");
        }
    }
}