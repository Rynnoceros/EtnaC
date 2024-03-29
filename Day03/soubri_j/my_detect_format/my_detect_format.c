/*                                                                                                               
** ETNA PROJECT, 05/10/2018 by soubri_j                                                                          
** my_detect_format                                                                                              
** File description:                                                                                             
**      Function that determines and print on the standard output the
**      format of each word in the str string.
*/
#include <stdlib.h>
int is_letter(char c);
int is_printable_char(char c);
int is_digit(char c);
void display_word_type(int nb_letter, int nb_digit);
void my_putchar(char c);
void my_putstr(char *str);

void my_detect_format(char *str)
{
    unsigned int cpt = 0;
    unsigned int nb_letter = 0;
    unsigned int nb_digit = 0;
    unsigned int nb_car = 0;

    if (str != NULL) {
        while (str[cpt] != '\0') {
            char current_char = str[cpt];
            if (is_printable_char(current_char)) {
                my_putchar(current_char);
                nb_letter += is_letter(current_char);
                nb_digit += is_digit(current_char);
                nb_car += 1;
            } else {
                if (nb_car > 0) {
                    display_word_type(nb_letter, nb_digit);
                    nb_letter = 0;
                    nb_digit = 0;
                    nb_car = 0;
                }
            }
            ++cpt;
        }
        if (nb_car > 0) {
            display_word_type(nb_letter, nb_digit);
        }
    }
}

/* Function that return 1 if a character is a letter 0 otherwise */
int is_letter(char c)
{
    int ascii_value = (int) c;
    return (ascii_value >= 65 && ascii_value <= 90) ||
           (ascii_value >= 97 && ascii_value <= 122) ? 1 : 0;
}

/* Function that return 1 if a character is printable 0 otherwise */
int is_printable_char(char c)
{
    int ascii_value = (int) c;
    return (ascii_value >= 0 && ascii_value <= 33) ? 0 : 1;
}

/* Function that return 1 if a character is a digit 0 otherwise */
int is_digit(char c)
{
    int ascii_value = (int) c;
    return (ascii_value >= 48 && ascii_value <= 57) ? 1 : 0;
}

/* Function that display on output the type of the read word */
void display_word_type(int nb_letter, int nb_digit)
{
    my_putstr(" => ");
    if (nb_digit > 0 && nb_letter > 0) {
        my_putstr("Unknown\n");
    } else if (nb_digit > 0) {
        my_putstr("Number\n");
    } else if (nb_letter > 0) {
        my_putstr("Word\n");
    } else {
        my_putstr("Unknown\n");
    }
}

/* Function that writes on output the content of str */
void my_putstr(char *str)
{
    unsigned int cpt = 0;

    while (str[cpt] != '\0') {
        my_putchar(str[cpt]);
        ++cpt;
    }
}