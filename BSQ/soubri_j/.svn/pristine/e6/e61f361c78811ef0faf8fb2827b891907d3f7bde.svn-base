/*
** ETNA PROJECT, 05/10/2018 by soubri_j                                                                          
** main_bsq                                                                                                
** File description:                                                                                             
**      Main program for project BSQ.
**      First we check arguments passed to the program.
**      Second we check file exists.
**      Third we read the file and check it is well formatted.
**      Forth we seek for the biggest square.
**      Fifth we print the result.
*/
#include <stdlib.h>
#include "constants_bsq.h"
#include "main_functions_bsq.h"
#include "file_functions_bsq.h"
#include "map_functions_bsq.h"
#include "bonus/libmy.h"
void display_error(char *message);

int main(int nb_args, char **args)
{
    int return_value = 0;
    int nb_lines = 0;
    char **map = NULL;
    char message[80] = "";
    
    return_value = check_arguments(nb_args, message);
    if (return_value == OK_CODE)
        return_value = check_file_exist(args[1], message);
    
    if (return_value == OK_CODE)
        map = read_map(args[1], &nb_lines, &return_value, message);

    if (return_value == OK_CODE)
        return_value = find_biggest_square(nb_lines, map, message);

    if (return_value == OK_CODE)
        display_map(nb_lines, map);

    if (return_value != OK_CODE)
        display_error(message);

    return return_value;
}

/*
    Function to display error message on output
    Params :
        message : message to display
*/
void display_error(char *message)
{
    my_putstr(message);
}