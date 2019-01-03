/*
** EPITECH PROJECT, 2018
** flags.c
** File description:
** Utils functions for the main project, my_printf
*/

#include <stddef.h>
#include "flags.h"

int compute_gflag(int value, size_t flag)
{
    if (flag & GFLAG_INVALID_VALUE)
        return (-1);
    return (value);
}