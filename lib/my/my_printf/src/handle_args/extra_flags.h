/*
** EPITECH PROJECT, 2018
** extra_flags.h
** File description:
** Handle flags below: +, - and #
*/

#ifndef HEADER_SRC_EXTRA_FLAGS
#define HEADER_SRC_EXTRA_FLAGS

#include <stdlib.h>
#include "../my_printf.h"

#define EXTRAF_MINUS    (0b1)
#define EXTRAF_PLUS     (0b10)
#define EXTRAF_HASH     (0b100)
#define EXTRAF_SPACE    (0b1000)

void parse_extra_flags(char const *src, int *index, t_local_spe *specifier);

#endif