/*
** ETNA PROJECT, 22/10/2018 by soubri_j
** my_putchar
** File description:
**      Function my_putchar that prints a character.
*/
#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}