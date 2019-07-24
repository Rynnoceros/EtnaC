/*
** ETNA PROJECT, 12/10/2018 by soubri_j                                                                          
** map_functions_bsq                                                                                                
** File description:                                                                                             
**      Header for methods used to manipulate maps.
*/
typedef struct {
    int x;
    int y;
} Coord;

int find_biggest_square(int nb_lines, char **map, char *error_message);
int fill_biggest_square(int nb_lines, int size, char **map, int **board_copy);
void display_map(int nb_lines, char **map);
void put_coordinates(Coord *coord, int x, int y);