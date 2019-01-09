/*
** EPITECH PROJECT, 2018
** my_strcmp.c
** File description:
** Compare 2 strings
*/

#include "../../include/my.h"

static int strcmp_count_ascii(char const *s1)
{
    int count = 0;

    for (int i = 0; s1[i] != '\0'; i++)
        if (my_isletter(s1[i]))
            count += s1[i];
    return (count);
}

int my_strcmp(char const *s1, char const *s2)
{
    if (my_strlen(s1) != my_strlen(s2))
        return (my_strlen(s1) < my_strlen(s2) ? 1 : -1);
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return (strcmp_count_ascii(s1) < strcmp_count_ascii(s2) ? -2 : 2);
    return (0);
}