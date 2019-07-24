/*
** ETNA PROJECT, 01/10/2018 by soubri_j
** my_prev_char
** File description:
**      Return the previous letter of an alphabetic character
*/
void my_putchar(char c);

char my_prev_char(char c)
{
    unsigned int decimal_char = c;
    if (decimal_char > 97 && decimal_char <= 122) {
        return decimal_char - 1;
    } else if (decimal_char == 97) {
        return 'z';
    } else if (decimal_char > 65 && decimal_char <= 90) {
        return decimal_char - 1;
    } else if (decimal_char == 65) {
        return 'Z';
    } else {
        return ' ';
   }
}
