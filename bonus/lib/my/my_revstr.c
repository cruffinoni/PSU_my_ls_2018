/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** Reverse a string.
*/

#include "../../include/my.h"

static void revstr_my_swap(char *a, char *b)
{
    char c = *a;

    *a = *b;
    *b = c;
}

char *my_revstr(char *str)
{
    int max_size = my_strlen(str) - 1;
    int index = 0;
    int initial_ms = max_size / 2;

    while (initial_ms >= index) {
        revstr_my_swap(&(str[index]), &(str[max_size]));
        max_size--;
        index++;
    }
    return (str);
}