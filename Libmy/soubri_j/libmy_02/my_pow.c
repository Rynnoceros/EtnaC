/*                                                                                                               
** ETNA PROJECT, 18/10/2018 by soubri_j                                                                          
** my_pow                                                                                                
** File description:                                                                                             
**      Function that compute the power of a number.
*/
int my_pow(int n, int p)
{
    int powed_value = 1;
    if (p < 0)
        return 0;

    for (int i = 0; i < p; ++i) {
        powed_value *= n;
    }
    return powed_value;
}