/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** Recode my_printf function (see man 3 printf)
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"
#include "my.h"
#include "./utils/flags.h"
#include "./handle_args/parse_redirect.h"

int my_printf(char const *src, ...)
{
    va_list args;
    int return_val = 0;
    size_t gflags = 0;

    va_start(args, src);
    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] == '%')
            return_val += handle_args(src, &i, args, &gflags);
        else
            return_val += my_putchar(src[i]);
    }
    va_end(args);
    return (compute_gflag(return_val, gflags));
}