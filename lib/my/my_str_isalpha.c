/*
** EPITECH PROJECT, 2018
** my_str_isalpha.c
** File description:
** Returns if the string only contains letters
*/

#include "../../include/my.h"

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!my_isletter(str[i]))
            return (0);
    }
    return (1);
}