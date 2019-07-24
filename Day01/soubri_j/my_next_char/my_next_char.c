/*                                                                                                               
** ETNA PROJECT, 01/10/2018 by soubri_j                                                                          
** my_next_char                                                                                                  
** File description:                                                                                             
**      Return the next letter of an alphabetic character                                                    
*/
void my_putchar(char c);

char my_next_char(char c)
{
    unsigned int decimal_char = c;
    if (decimal_char >= 97 && decimal_char < 122) {
        return decimal_char + 1;
    } else if (decimal_char == 122) {
        return 'a';
    } else if (decimal_char >= 65 && decimal_char < 90) {
        return decimal_char + 1;
    } else if (decimal_char == 90) {
        return 'A';
    } else {
        return ' ';
   }
}