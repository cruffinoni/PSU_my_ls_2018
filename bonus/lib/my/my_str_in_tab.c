/*
** EPITECH PROJECT, 2018
** my_str_to_word_tab
** File description:
** task04
*/

#include "stdlib.h"
#include "my.h"

int get_next_letter(char const *str, int i, char sep)
{
    for (i; str[i] != '\0'; i++) {
        if (str[i] != sep)
            return (i);
    }
    return (0);
}

int get_nbr_words(char const *str, char sep)
{
    int words = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sep) {
            i = get_next_letter(str, i, sep);
            if (i == 0)
                return (words);
            words = words + 1;
        }
    }
    return (words);
}

int get_top_len_word(char const *str, char sep)
{
    int max_len = 0;
    int clc_len = 0;

    for (int i = 0; str[i] != '\0'; i++, clc_len++) {
        if (str[i] == sep && max_len < clc_len) {
            max_len = clc_len;
            clc_len = 0;
        }
    }
    return (max_len);
}

char **fill_tab(char const *str, char **tab, char sep)
{
    int x = 0;
    int y = 0;

    for (int i = 0; str[i] != '\0'; i++, x++) {
        if (str[i] == sep) {
            tab[y][x] = '\0';
            x = 0;
            y++;
            i = get_next_letter(str, i, sep);
        }
        tab[y][x] = str[i];
    }
    tab[y][x] = '\0';
    return (tab);
}

char **my_str_in_tab(char const *str, char sep)
{
    int nbr_words = get_nbr_words(str, sep);
    char **tab = malloc(sizeof(char *) * (nbr_words + 1));
    int top_len = get_top_len_word(str, sep);
    int i = 0;

    if (tab == NULL)
        return (NULL);
    for (i; i != nbr_words; i++) {
        tab[i] = malloc(sizeof(char) * top_len + 1);
        if (tab[i] == NULL)
            return (NULL);
    }
    tab[i] = 0;
    tab = fill_tab(str, tab, sep);
    return (tab);
}
