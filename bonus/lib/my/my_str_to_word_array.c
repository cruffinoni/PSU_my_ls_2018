/*
** EPITECH PROJECT, 2018
** my_str_to_array_word.c
** File description:
** Function splits a string into words.
*/

#include <stddef.h>
#include <stdlib.h>
#include "../../include/my.h"

static void strtaw_getstr_infos(char const *str, int *msword, int *count_word)
{
    int previous_size = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_isalphanumeric(str[i]))
            previous_size++;
        else
            previous_size = 0;
        if (previous_size == 1)
            *count_word = *count_word + 1;
        if (previous_size > *msword)
            *msword = previous_size;
    }
    *count_word = *count_word + 1;
    *msword = *msword + 1;
}

static void strtaw_update_array(char **tab, char const *str)
{
    int count_word = -1;
    int previous_size = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_isalphanumeric(str[i]))
            previous_size++;
        else if (previous_size > -1)
            tab[count_word][previous_size + 1] = '\0';
        if (!my_isalphanumeric(str[i]))
            previous_size = -1;
        if (previous_size == 0)
            count_word++;
        if (previous_size >= 0)
            tab[count_word][previous_size] = str[i];
    }
    tab[count_word + 1] = '\0';
}

char **my_str_to_word_array(char const *str)
{
    char **tab;
    int max_size = 0;
    int count_word = 0;

    strtaw_getstr_infos(str, &max_size, &count_word);
    tab = malloc(sizeof(char *) * count_word);
    for (int i = 0; i < count_word; i++)
        tab[i] = malloc(sizeof(char) * max_size);
    strtaw_update_array(tab, str);
    return (tab);
}