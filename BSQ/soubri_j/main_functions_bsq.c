/*
** ETNA PROJECT, 12/10/2018 by soubri_j                                                                          
** main_functions_bsq                                                                                                
** File description:                                                                                             
**      Contains methods used by the main program.
*/
#include <stdlib.h>
#include "constants_bsq.h"
#include "file_functions_bsq.h"
#include "bonus/libmy.h"

/* 
    Function to check if we have at least one argument 
    Params :
        nb_args : number of arguments passed to the program
        error_message : variable to return an error message
    Returns :
        error_code if there is an error
        ok_code it everything is ok
*/
int check_arguments(int nb_args, char *error_message)
{
    if (nb_args <= 1) {
        error_message = my_strcpy(error_message, 
            "You must pass at least one argument to the program!!!\n");
        return ERROR_CODE;
    }
    return OK_CODE;
}

/* 
    Function to check if a file exists
    Params :
        filename : filename to check
        error_message : variable to return an error message
    Returns :
        error_code if there is an error
        ok_code it everything is ok
*/
int check_file_exist(char *filename, char *error_message)
{
    if (file_exist(filename) > 0)
        return OK_CODE;

    error_message = my_strcpy(error_message, "File \"");
    error_message = my_strcat(error_message, filename);
    error_message = my_strcat(error_message, "\" does not exists\n");
    return ERROR_CODE;
}