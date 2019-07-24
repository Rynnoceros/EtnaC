/*
** ETNA PROJECT, 12/11/2018 by soubri_j
** my_readline.c
** File description: 
**    This function allows you to read a line of less than 50 characters
**    from the standard input.
**    The function does not take any parameter and returns an allocated 
**    string, dont forget to free().
**
**    my_putchar allows you to display a character on the standard output.
*/

#include <stdlib.h>
#include <unistd.h>
#include "ftl.h"

char *my_readline(void)
{
  char    *buff;
  ssize_t size;

  buff = malloc(sizeof(*buff) * (50 + 1));
  if (buff == NULL)
    return NULL;
  size = read(0, buff, 50);
  if (size > 1) {
    buff[size - 1] = '\0';
    return buff;
  }
  free(buff);
  return (NULL);
}

void my_putchar(const char c)
{
  write(1, &c, 1);
}

char my_alphabet(int n, int base, char *alphabet)
{
    int int_part = n / base;
    int to_print = n % base;

    if (to_print < 0) 
        to_print *= -1;
    if (int_part < 0)
        int_part *= -1;
    if (int_part > 0)
        my_putchar(my_alphabet(int_part, base, alphabet));
    return alphabet[to_print];
}

void my_putnbr(int n)
{
    if (n < 0) {
        my_putchar('-');
    }
    my_putchar(my_alphabet(n, 10, "0123456789"));
}