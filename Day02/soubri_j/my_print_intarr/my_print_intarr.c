/*                                                                                                               
** ETNA PROJECT, 02/10/2018 by soubri_j                                                                          
** my_print_intarr                                                                                                  
** File description:                                                                                             
**      Function that prints a one-dimensional array. 
*/
void my_putchar(char c);

void my_print_intarr(int arr[], int size)
{
    for (int i = 0; i < size ; ++i) {
        my_putchar(48 + arr[i]);
        my_putchar('\n');
    }
}