/*
** EPITECH PROJECT, 2018
** string.c
** File description:
** Print a string passed as an argument.
*/

#include <stdarg.h>
#include "my.h"
#include "../my_printf.h"
#include "../handle_args/extra_flags.h"
#include "../utils/utils.h"
#include "../utils/print/print_string.h"

int type_string(va_list args, t_local_spe specifier_infos)
{
    char *var = va_arg(args, char *);
    int count = 0;
    int str_len = my_strlen(var);

    if ((specifier_infos.flags_extra & EXTRAF_MINUS) != EXTRAF_MINUS) {
        if (specifier_infos.precision > str_len)
            count += print_char_ite(specifier_infos.precision - str_len, ' ');
    }
    print_string(var, &count, 0, specifier_infos);
    if ((specifier_infos.flags_extra & EXTRAF_MINUS) == EXTRAF_MINUS) {
        if (specifier_infos.precision > count)
            count += print_char_ite(specifier_infos.precision - count, ' ');
    }
    return (count);
}

int type_string_escape(va_list args, t_local_spe specifier_infos)
{
    char *var = va_arg(args, char *);
    int count = my_strlen(var);

    count = 0;
    print_string(var, &count, 1, specifier_infos);
    return (count + specifier_infos.precision);
}