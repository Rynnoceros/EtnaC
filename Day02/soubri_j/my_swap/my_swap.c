/*                                                                                                               
** ETNA PROJECT, 02/10/2018 by soubri_j                                                                          
** my_swap                                                                                                  
** File description:                                                                                             
**      Function that receives two pointers to integer as parameters. 
**      The function swaps the content of the two pointers.                                                  
*/
void my_swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}