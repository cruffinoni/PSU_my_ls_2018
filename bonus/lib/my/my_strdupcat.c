/*
** EPITECH PROJECT, 2018
** my_strdupcat
** File description:
** Allocate enough memory to a new string to concatenate 2 strings.
*/

#include <stdlib.h>
#include "my.h"

char *my_strdupcat(char *origin, char *to_add)
{
    char *new_string = malloc(sizeof(char) * (my_strlen(origin) + 1) +
        (my_strlen(to_add) + 1));

    if (new_string == NULL)
        return (NULL);
    my_strcpy(new_string, origin);
    my_strcat(new_string, to_add);
    return (new_string);
}