/*
** EPITECH PROJECT, 2018
** handle_args.c
** File description:
** Main function that handle every args after the '%' char.
*/

#ifndef HEADER_SRC_HANDLEARG
#define HEADER_SRC_HANDLEARG

#include <stdlib.h>
#include "../my_printf.h"

int handle_args(char const *src, int *index, va_list args, size_t *gflag);

#endif