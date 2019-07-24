#include <stdio.h>
#include <stdlib.h>
#include "../Libmy/soubri_j/libmy_01/libmy.h"
char *get_char(char *string);
void get_char2(char **dest, char *string);
void print_array2d(int **array);

int main(void)
{
    char *string = NULL;
    char **string2 = NULL;
    int **array2d = NULL;

    array2d = malloc(sizeof(int*) * 3);
    if (array2d != NULL) {
        for (int i = 0; i < 3; ++i) {
            array2d[i] = malloc(sizeof(int*) * 4);
            if (array2d[i] != NULL) {
                for (int j = 0; j < 4; j++) {
                    array2d[i][j] = i;
                }
            }
        }
    }

    print_array2d(array2d);

    printf ("%p\n", string);
    string = get_char("You're welcome\n");
    printf("%s", string);
    printf ("string pointer : %p\n", string);
    get_char2(string2, "test JSR");
    printf ("retour getchar2 : %p\n", string2);
    printf ("get_char2 : %s\n", string2[0]);
}

void print_array2d(int **array)
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            my_putnbr(array[i][j]);
        } 
        my_putchar('\n');
    }
}

char *get_char(char *string)
{
    char *new = NULL;
    printf ("get_char pointer : %p \n", new);
    int str_len = my_strlen(string);
    new = malloc(sizeof(char) * str_len);
    new[str_len] = '\0';
    new = my_strcpy(new, string);

    printf ("get_char pointer : %p \n", new);

    return new;
}

void get_char2(char **dest, char *string)
{
    char *new = NULL;
    new = malloc(sizeof(char) * my_strlen(string));
    new = my_strcpy(new, string);

    printf("new: %s\n", new);
    dest = &new;
    printf ("dest : %s\n", *dest);
}
