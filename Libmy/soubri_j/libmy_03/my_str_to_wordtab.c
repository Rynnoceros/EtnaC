/*
** ETNA PROJECT, 13/10/2018 by soubri_j
** my_str_to_wordtab
** File description:
**      Function which cuts a string into words.
**      A word only contains alphanumerical characters.
**      Every other characters separates the words from each other.
**      It returns a newly allocated array of words Where each cell
**      is the address of a string.
*/

#include "libmy.h"
int is_alphanum(char c);
int count_words(char *str);
char *get_word(char *str, int start, int end);

char **my_str_to_wordtab(char *str)
{
    char **array_of_word = NULL;
    int start_word = -1;
    int end_word = -1;
    int nb_words = 0;
    int current_word = 0;
    int cpt = 0;

    if (str != NULL) {
        nb_words = count_words(str);
        if (nb_words >= 0) {
            array_of_word = malloc(sizeof(char*) * (nb_words + 1));
            if (array_of_word != NULL) {
                while (str[cpt] != '\0') {
                    if (is_alphanum(str[cpt]) == 1) {
                        if (start_word < 0) {
                            start_word = cpt;
                            end_word = -1;
                        }
                    } else {
                        if (end_word < 0 && start_word >= 0) {
                            end_word = cpt;
                            array_of_word[current_word] = 
                                get_word(str, start_word, end_word);
                            start_word = -1;
                            ++current_word;
                        }
                    }
                    ++cpt;
                }
                if (start_word >= 0) {
                    end_word = cpt;
                    array_of_word[current_word] = 
                        get_word(str, start_word, end_word);
                    ++current_word;
                }
                array_of_word[current_word] = NULL;
            }
        }
    }
    return array_of_word;
}

char *get_word(char *str, int start, int end)
{
    char *word = NULL;
    int word_len = 0;
    int cpt = 0;

    if (str != NULL && end > start) {
        word_len = end - start;
        word = malloc(sizeof(char) * (word_len));
        if (word != NULL) {
            for (int i = start; i < end; ++i) {
                word[cpt] = str[i];
                ++cpt;
            }
            word[cpt] = '\0';
        }
    }
    return word;
}

int count_words(char *str)
{
    int start_word = -1;
    int end_word = -1;
    int nb_words = 0;
    int cpt = 0;

    if (str != NULL) {
        while (str[cpt] != '\0') {
            if (is_alphanum(str[cpt]) == 1) {
                if (start_word < 0) {
                    start_word = cpt;
                    end_word = -1;
                }
            } else {
                if (end_word < 0 && start_word >= 0) {
                    end_word = cpt;
                    start_word = -1;
                    ++nb_words;
                }
            }
            ++cpt;
        }
        if (start_word >= 0)
            ++nb_words;
    }
    return nb_words;
}

int is_alphanum(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || 
        (c >= '0' && c <= '9')) {
        return 1;
    } else {
        return 0;
    }
}