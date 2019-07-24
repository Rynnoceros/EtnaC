/*                                                                                                               
** ETNA PROJECT, 01/10/2018 by soubri_j                                                                          
** my_putchar                                                                                                 
** File description:                                                                                             
**      Function that write a character to the output.                                            
*/
#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}