/*                                                                                                               
** ETNA PROJECT, 13/10/2018 by soubri_j                                                                          
** my_str_next_token                                                                                                
** File description:                                                                                             
**      Function which returns a newly allocated string duplicate of the next
**      token. A token is a string which contains character other than the ones
**      present in the delim string passed as paramter. Each character from the 
**      string delim separate tokens from each other.
**      The first call to my_str_next_token will set the string to get the 
**      tokens from to the string str passed as parameter and return a copy of 
**      the first token.
**      Upon the following calls, if the value of the string str passed as 
**      parameter is NULL then a copy of the next token from the precedently 
**      set string is returned.
**      Otherwise if the string str passed as parameter isnt NULL the 
**      precedently set string is reset to the new string str and a copy of 
**      the first token is returned.
**      If no or no more token is to be found the function returns NULL.
*/
#include <stdlib.h>
char *get_word(char *str, int start, int end);
int is_delim(char c, char *delims);

char *my_str_next_token(char *str, char *delim)
{
    static char *set_string;
    char *token = NULL;
    int start_word = 0;
    int end_word = 0;

    if (str != NULL) {
        set_string = str;
    }

    if (set_string != NULL) {
        while (set_string[end_word] != '\0' &&
               is_delim(set_string[end_word], delim) == 1) {
            ++start_word;
            ++end_word;
        }
        while (set_string[end_word] != '\0' &&
               is_delim(set_string[end_word], delim) == 0) {
            ++end_word;
        }
        token = get_word(set_string, start_word, end_word);
        if (set_string[end_word] == '\0') {
            set_string = "";
        } else {
            set_string = &set_string[end_word];
        }
    } else {
        token = NULL;
    }

    return token;
}

int is_delim(char c, char *delims)
{
    int ret = 0;
    int cpt = 0;

    if (delims != NULL) {
        while (delims[cpt] != '\0' && delims[cpt] != c) {
            ++cpt;
        }
        if (delims[cpt] != '\0')
            ret = 1;
    }

    return ret;
}

char *get_word(char *str, int start, int end)
{
    char *word = NULL;
    int word_len = 0;
    int cpt = 0;
    int i = start;

    if (str != NULL && end > start) {
        word_len = end - start;
        word = malloc(sizeof(char) * (word_len));
        if (word != NULL) {
            while (str[i] != '\0' && i < end) {
                word[cpt] = str[i];
                ++cpt;
                ++i;
            }
            word[cpt] = '\0';
        }
    }
    if (word == NULL) {
        word = malloc(sizeof(char));
        if (word != NULL)
            word[0] = '\0';
    }


    return word;
}