/*
** EPITECH PROJECT, 2018
** my_printf.h
** File description:
** Header file for my_printf.c
*/

#ifndef HEADER_SRC_PRINTF
#define HEADER_SRC_PRINTF

#include <stdlib.h>

int my_printf(char const *src, ...);

typedef struct s_specifier
{
    size_t flags;
    size_t flags_extra;
    int len_specifier;
    int extra_precision;
    int precision;
    size_t base;
    char basic_specifier;
} t_local_spe;

#endif