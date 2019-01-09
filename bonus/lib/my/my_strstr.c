/*
** EPITECH PROJECT, 2018
** my_strstr.c
** File description:
** Find a string on an another and returns the index
*/

#include <stdio.h>

char *my_strstr(char *str, char const *to_find)
{
    int index = 0;

    for (int i = 0, j = 0; str[i] != '\0'; i++) {
        if ((j == 0) & (index == 0))
            index = j;
        if (to_find[j+1] == '\0')
            return (&str[i - j]);
        if (str[i] == to_find[j])
            j++;
        else
            j = 0;
    }
    return (NULL);
}