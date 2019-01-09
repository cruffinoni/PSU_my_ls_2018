/*
** EPITECH PROJECT, 2018
** parse_redirect.c
** File description:
** Main function that handle every args after the '%' char.
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "../my_printf.h"
#include "../utils/utils.h"
#include "../utils/getid.h"
#include "../utils/flags.h"
#include "./extra_flags.h"
#include "./precision.h"
#include "../type/char.h"
#include "../type/string.h"
#include "../type/pointer.h"
#include "../type/unsigned_int/small_len.h"
#include "../type/unsigned_int/big_len.h"
#include "../type/signed_int/small_len.h"
#include "../type/signed_int/big_len.h"

static int handle_invalid_arg(char const *src, int *index, size_t *gflag)
{
    if (src[*index + 1] == '\0' && src[*index + 1] != '%') {
        *gflag |= GFLAG_INVALID_VALUE;
        return (0);
    }
    else {
        if (src[*index + 1] == '%')
            *index = *index + 1;
        my_putchar(src[*index]);
        return (1);
    }
}

static int handle_valid_args(char const *src, int *index, t_local_spe specifier,
    va_list args)
{
    int (*func_ptr_others[])(va_list, t_local_spe) = {type_pointer,
        type_char, type_string, type_string_escape};
    int (*func_ptr_int[][8])(va_list, t_local_spe) = {
        {type_int, type_schar, type_short, type_long, type_llong, type_intmax_t,
            type_ssize_t, type_ptrdiff_t},
        {type_unint, type_uschar, type_ushort, type_unlong, type_unllong,
            type_uintmax_t, type_sizet, type_unptrdiff_t}
    };
    int tmp = 0;

    specifier.basic_specifier = src[*index + 1];
    tmp = get_local_spe_index(specifier.basic_specifier);
    *index = *index + 1;
    if (get_local_spe_index(specifier.basic_specifier) < 6)
        return ((*func_ptr_int[!tmp ? 0 : 1][specifier.len_specifier])
            (args, specifier));
    else
        return ((*func_ptr_others[tmp - 6])(args, specifier));
}

int handle_args(char const *src, int *index, va_list args, size_t *gflag)
{
    t_local_spe specifier = {0, 0, 0, 0, 0, 0, 0};

    parse_extra_flags(src, index, &specifier);
    if (my_isnumber(src[*index + 1]))
        specifier.precision = handle_precision(src, index);
    if (src[*index + 1] == '.') {
        *index += 1;
        specifier.extra_precision = handle_precision(src, index);
        specifier.flags &= ~FLAG_ACC_IS_ZERO;
    }
    specifier.len_specifier = get_lenspe_index(src, index);
    if (specifier.len_specifier == INVALID_SPECIFIER)
        specifier.len_specifier = 0;
    if (get_local_spe_index(src[*index + 1]) != INVALID_SPECIFIER)
        return (handle_valid_args(src, index, specifier, args));
    return (handle_invalid_arg(src, index, gflag));
}