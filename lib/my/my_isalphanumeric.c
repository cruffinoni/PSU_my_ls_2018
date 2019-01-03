/*
** EPITECH PROJECT, 2018
** my_isalphanumeric.c
** File description:
** Return if a char is letter or a number
*/

#include "../../include/my.h"

int my_isalphanumeric(char c)
{
    return (my_isletter(c) || my_isnumber(c));
}