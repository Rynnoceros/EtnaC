/*                                                                                                               
** ETNA PROJECT, 02/10/2018 by soubri_j                                                                          
** my_pow_arr                                                                                                 
** File description:                                                                                             
**      The my_pow_arr function pre-computes numbers from 0 to size - 1 
**      raised to the power p in the array arr.
*/
int my_pow(int n, int p);

void my_pow_arr(int arr[], int size, int p)
{
    for (int i = 0; i < size; ++i) {
        arr[i] = my_pow(i, p);
    }
}