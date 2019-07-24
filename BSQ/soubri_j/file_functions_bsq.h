/*
** ETNA PROJECT, 12/10/2018 by soubri_j                                                                          
** file_functions_bsq                                                                                                
** File description:                                                                                             
**      Header for file access methods.
*/
int file_exist(char *filename);
char *read_file(char *filename, int *file_size, char *error_message);
char *read_line(char *buffer, int *buffer_pos);
char **read_map(char *filename, int *nb_lines, int *ret, char *error_message);
char **read_map_from_buffer(char *file_content, int *nb_lines, int buffer_size);