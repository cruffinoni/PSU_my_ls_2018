/*
** EPITECH PROJECT, 2018
** extra_flags.c
** File description:
** Handle flags below: +, -, #, ' ' or 0
*/

#include "./extra_flags.h"
#include "../my_printf.h"
#include "../utils/getid.h"
#include "../utils/flags.h"

void parse_extra_flags(char const *src, int *index, t_local_spe *specifier)
{
    while (src[*index + 1] != '\0') {
        switch (src[*index + 1]) {
            case '-': specifier->flags_extra |= EXTRAF_MINUS;
                break;
            case '+': specifier->flags_extra |= EXTRAF_PLUS;
                break;
            case '#': specifier->flags_extra |= EXTRAF_HASH;
                break;
            case '0': specifier->flags |= FLAG_ACC_IS_ZERO;
                break;
            case ' ': specifier->flags_extra |= EXTRAF_SPACE;
                break;
            default: return;
        }
        *index = *index + 1;
    }
}