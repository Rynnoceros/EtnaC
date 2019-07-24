/*
** ETNA PROJECT, 12/10/2018 by soubri_j                                                                          
** map_functions_bsq                                                                                                
** File description:                                                                                             
**      Contains methods used to manipulate maps.
*/
#include <stdlib.h>
#include "constants_bsq.h"
#include "map_functions_bsq.h"
#include "bonus/libmy.h"

/*
    Function to find the biggest square on the board
    Params :
        nb_lines : number of lines in the board
        map : the board
        error_message : variable to return an error message
    Returns
        ERROR_CODE if there was an error
        OK_CODE if everything ok
*/
int find_biggest_square(int nb_lines, char **map, char *error_message)
{
    int **board_copy = NULL;
    int line_size = my_strlen(map[0]);
    board_copy = malloc(sizeof(int*) * nb_lines);
    
    if (board_copy != NULL) {
        for (int i = 0; i < nb_lines; ++i) {
            board_copy[i] = malloc(sizeof(int*) * line_size);
            for (int j = 0; j < line_size; ++j) {
                if (i > 0) { 
                    if (map[i][j] == '.')
                        board_copy[i][j] = board_copy[i - 1][j] + 1;
                    else
                        board_copy[i][j] = 0;
                } else {
                    if (map[i][j] == '.')
                        board_copy[i][j] = 1;
                    else 
                        board_copy[i][j] = 0;
                }
            }
        } 
    } else {
        error_message = my_strcpy(error_message, "Error reading map\n");
        return ERROR_CODE;
    }
    
    return fill_biggest_square(nb_lines, line_size, map, board_copy);
}

/*
    Function to fill map with the biggest square
    Params : 
        nb_lines : map number lines
        size : size of the line
        map : the map to fill
        board_copy : the board containing weight of squares
    Returns :
        ERROR_CODE if an error has occured
        OK_CODE if everything is good
*/
int fill_biggest_square(int nb_lines, int size, char **map, int **board_copy)
{
    int square_width = 0;
    int current_width = 0;
    int cpt = 0;
    int min = 2147483647;
    Coord *pos;
    pos = malloc(sizeof(pos));
    put_coordinates(pos, 0, 0);
    
    for (int i = 0; i < nb_lines; ++i) {
        cpt = 0;
        min = 2147483647;
        for (int j = 0; j < size; ++j) {
            if (board_copy[i][j] >= square_width) {
                current_width = board_copy[i][j];
                min = current_width < min ? current_width : min;
                ++cpt;
                if ((cpt >= current_width && cpt <= min) && 
                    (current_width > square_width || j + 1 < pos->y)) { 
                    square_width = current_width;
                    put_coordinates(pos, i + 1, j + 1);
                }
            } else {
                cpt = 0;
            }   
        }
    }

    put_coordinates(pos, pos->x -= square_width, pos->y -= square_width);

    for (int i = pos->x; i < pos->x + square_width; ++i) {
        for (int j = pos->y; j < pos->y + square_width; ++j) {
            map[i][j] = 'x';
        }
    }

    return OK_CODE;
}

/*
    Function to fill coordinates in Coord struc
    Params :
        coord : the coord struct to fill
        x : x value to put
        y : y value to put
*/
void put_coordinates(Coord *coord, int x, int y)
{
    coord->x = x;
    coord->y = y;
}

/*
    Function to display the content of a map
*/
void display_map(int nb_lines, char **map)
{
    if (map != NULL) {
        for (int i = 0; i < nb_lines; ++i) {
            my_putstr(map[i]);
            my_putchar('\n');
        }
    }
}