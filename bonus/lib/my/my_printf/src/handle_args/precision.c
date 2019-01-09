/*
** EPITECH PROJECT, 2018
** handle_precision.c
** File description:
** Handle every precision (precision + extra_precision)
*/

#include <stdlib.h>
#include "my.h"
#include "../utils/utils.h"

int handle_precision(char const *src, int *idx)
{
    int number = 0;
    char *cpy = malloc(my_strlen(src) + 1);
    char *ptr_cpy = cpy;

    if (cpy == NULL)
        return (-1);
    my_strcpy(cpy, src);
    while (cpy[*idx + 1] == '0')
        *idx = *idx + 1;
    *idx = *idx + 1;
    number = my_strtol(cpy + *idx, &cpy);
    *idx = *idx + (uint_len(number) - 1);
    free(ptr_cpy);
    return (number);
}