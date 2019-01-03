/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** Allocate memory for a string
*/

#include "../../include/my.h"
#include <stdlib.h>
#include <stddef.h>

char *my_strdup(char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    if (str == NULL)
        return (NULL);
    for (i = 0; src[i] != '\0'; i++)
        str[i] = src[i];
    str[i] = '\0';
    return (str);
}