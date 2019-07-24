/*                                                                                                               
** ETNA PROJECT, 08/10/2018 by soubri_j                                                                          
** my_is_even                                                                                                
** File description:                                                                                             
**      Contains all libmy prototypes declaration                                          
*/
#ifndef __LIBMY_H__
# define __LIBMY_H__
#include <stdlib.h>
#include <unistd.h>

int my_is_even(int n);
int my_is_neg(int n);
int my_is_odd(int n);
void my_putchar(char c);
void my_putstr(char *str);
int my_strlen(char *str);
int  my_getnbr(char *str);
void my_putnbr(int nb);
char *my_strstr(char *str, char *to_find);
void my_swap(int *a, int *b);
char *my_strcpy(char *dest, char *src);
char *my_strncpy(char *dest, char *src, int n);
int  my_strcmp(char *s1, char *s2);
int  my_strncmp(char *s1, char *s2, int n);
char *my_strcat(char *str1, char *str2);
char *my_strncat(char *str1, char *str2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
int my_nbrlen(int n);
int my_nbrlen_base(int n, int base);
void my_putnbr_base(int n, char *base);
int my_getnbr_base(char *str, char *base);
char *my_strdup(char *str);
char **my_str_to_wordtab(char *str);
int my_pow(int n, int p);
char getchar_alphabet(int n, int base, char *alphabet);
int first_digit_position(char *str, int *is_neg);
int get_nb_digit_base(char *str, int start_pos, char *base);
int get_nb_digit(char *str, int start_pos);
int convert_number_base(char *str, int start_pos, int nb_digit, char *base);
int convert_number(char *str, int start_pos, int nb_digit, int is_neg);
int get_char_pos(char *str, char c);
int compare_strings(char *s1, char *s2);
int compare_strings_n(char *s1, char *s2, int n);
#endif