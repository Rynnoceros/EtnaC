/*                                                                                                               
** ETNA PROJECT, 02/10/2018 by soubri_j                                                                          
** my_sort_intarr                                                                                                 
** File description:                                                                                             
**      Function that sorts an array of integers in ascending order. 
*/
void my_sort_intarr(int arr[], int size)
{
    int tmp = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[i]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}