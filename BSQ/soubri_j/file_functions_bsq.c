/*
** ETNA PROJECT, 12/10/2018 by soubri_j                                                                          
** file_functions_bsq                                                                                                
** File description:                                                                                             
**      Contains file access methods.
*/
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "constants_bsq.h"
#include "bonus/libmy.h"
#include "file_functions_bsq.h"

/*
    Function to check if a file exists
    Params :
        filename : fullname of a file
    Returns :
        ok_code : if file exists
        error_code : otherwise
*/

int file_exist(char *filename)
{
    int my_file;

    if ((my_file = open(filename, O_RDONLY)) > 0)
    {
        close(my_file);
        return 1;
    }
    
    return 0;
}

/*
    Function to read the content of a file
    Params :
        filename : the file to read
        error_message : variable to return error message
    Returns :
        A buffer containing the content of a file
*/
char *read_file(char *filename, int *file_size, char *error_message)
{
    int file;
    int status = 0;
    struct stat file_info;
    char *file_content = NULL;
    off_t nb_bytes_read = 0;

    status = stat(filename, &file_info);
    if (status == 0) {
        file = open(filename, O_RDONLY);
        if (file < 0) {
            error_message = my_strcpy(error_message, "Error opening file\n");
        } else {
            *file_size = file_info.st_size;
            file_content = malloc(sizeof(char) * file_info.st_size);
            nb_bytes_read = read(file, file_content, file_info.st_size);
            if (nb_bytes_read != file_info.st_size) {
                error_message = my_strcpy(error_message, "Error reading file\n");
            }

            close(file);
        }  
    }

    return file_content;
}

/*
    Function to read line of a buffer
    Params :
        buffer : buffer to read
        buffer_pos : position of the pointer in the buffer
    Returns the read line or NULL if there was a problem during reading
*/
char *read_line(char *buffer, int *buffer_pos)
{
    char *line_to_read = NULL;
    int buffer_start = *buffer_pos;
    int cpt = 0;
    int line_size = 0;

    if (buffer != NULL) {
        while (buffer[*buffer_pos] != '\n') {
            ++cpt;
            *buffer_pos = *buffer_pos + 1;
        }
        line_size = cpt;
        *buffer_pos = *buffer_pos + 1;
    }
    
    if (line_size > 0) {
        line_to_read = malloc(sizeof(char) * line_size);
        for (int i = 0; i < line_size; ++i) {
            line_to_read[i] = buffer[buffer_start + i];       
        }
        line_to_read[line_size] = '\0';
    }
    
    return line_to_read;
}

/*
    Function used to read map in a file
    Params : 
        filename : name of the file to read
        nb_lines : variable to get the number of lines to read
        ret : variable to get return value
        error_message : variable to get error_message
*/
char **read_map(char *filename, int *nb_lines, int *ret, char *error_message)
{
    char **map = NULL;
    char *file_content = NULL;
    int file_size = 0;

    *ret = OK_CODE;
    *nb_lines = 0;

    file_content = read_file(filename, &file_size, error_message);
    
    map = read_map_from_buffer(file_content, nb_lines, file_size);

    if (map == NULL) {
        error_message = my_strcpy(error_message, "Bad format file\n");
        *ret = ERROR_CODE;
    }

    return map;
}

/*
    Function to read a map from a buffer 
    Params :
        file_content : the buffer to read
        nb_lines : variable to get number of lines
        buffer_size : the buffer size
    Returns : 
        the map read if ok NULL otherwise
*/
char **read_map_from_buffer(char *file_content, int *nb_lines, int buffer_size)
{
    char *line = NULL;
    int line_size = 0;
    int buffer_pos = 0;
    char **map = NULL;
    int cpt = 0;

    line = read_line(file_content, &buffer_pos);
    *nb_lines = my_getnbr(line);
    if (*nb_lines > 0) {
        line = read_line(file_content, &buffer_pos);
        line_size = my_strlen(line);
        map = malloc(sizeof(char) * *nb_lines * line_size);
        if (map != NULL) {
            map[cpt] = line;
            ++cpt;
            while (line != NULL && buffer_pos < buffer_size) {
                line = read_line(file_content, &buffer_pos);
                if (line != NULL) {
                    map[cpt] = line;
                    ++cpt;
                }
            }
        }
    }

    if ((cpt != *nb_lines) || (*nb_lines <= 0)) {
        map = NULL;
    }
    return map;
}