/*
** EPITECH PROJECT, 2018
** my_strcapitalize.c
** File description:
** Capitalizes the first letter of each word
*/

#include "../../include/my.h"

static int is_min(int c)
{
    return (c >= 'a' && c <= 'z');
}

static int is_up(int c)
{
    return (c >= 'A' && c <= 'Z');
}

char *my_strcapitalize(char *str)
{
    int word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!my_isalphanumeric(str[i]))
            word = 0;
        if (is_up(str[i]) && word)
            str[i] += 32;
        else if ((is_up(str[i]) || my_isnumber(str[i])) && !word)
            word = 1;
        if (is_min(str[i]) && !word) {
            str[i] -= 32;
            word = 1;
        }
    }
    return (str);
}