/*
** EPITECH PROJECT, 2018
** hexadecimal.c
** File description:
** Print an hexadecimal number.
*/

#include <unistd.h>
#include <stdarg.h>
#include "my.h"
#include "../my_printf.h"
#include "../handle_args/extra_flags.h"
#include "../utils/print/print.h"
#include "../utils/print/print_string.h"
#include "../utils/print/print_uint.h"
#include "../utils/flags.h"

int type_char(va_list args, t_local_spe specifier_infos)
{
    int var = va_arg(args, int);
    int count = 0;

    specifier_infos.flags &= ~FLAG_ACC_IS_ZERO;
    specifier_infos.extra_precision = 0;
    count += print_precision(specifier_infos, 1);
    count += my_putchar(var);
    if ((specifier_infos.flags_extra & EXTRAF_MINUS) == EXTRAF_MINUS)
        if (1 < specifier_infos.precision && specifier_infos.precision >
            count)
            count += print_char_ite(specifier_infos.precision - count, ' ');
    return (count);
}