/*
** EPITECH PROJECT, 2018
** my_str_isnum.c
** File description:
** Returns if the string only contains letters
*/

#include "../../include/my.h"

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!my_isnumber(str[i]))
            return (0);
    }
    return (1);
}