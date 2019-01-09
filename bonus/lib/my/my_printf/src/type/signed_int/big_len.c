/*
** EPITECH PROJECT, 2018
** integer.c
** File description:
** Handle case with integer only.
*/

#include <stdarg.h>
#include "my.h"
#include "../../my_printf.h"
#include "../../utils/utils.h"
#include "../../utils/flags.h"
#include "../../handle_args/extra_flags.h"
#include "../../utils/print/print_string.h"
#include "../../utils/print/print_int.h"

int type_intmax_t(va_list args, t_local_spe specifier_infos)
{
    intmax_t var = va_arg(args, intmax_t);
    int count = var < 0 ? 1 : 0;
    int lnb = 0;

    if (count == 1) {
        specifier_infos.flags |= FLAG_IS_NEGATIVE;
        var *= -1;
    }
    int_count(var, &lnb);
    int_print_precision(specifier_infos, &count, lnb);
    int_print_nbr(var, &count);
    if ((specifier_infos.flags_extra & EXTRAF_MINUS) == EXTRAF_MINUS &&
        specifier_infos.extra_precision == 0)
        count += print_char_ite(specifier_infos.precision - count, ' ');
    return (count);
}

int type_ssize_t(va_list args, t_local_spe specifier_infos)
{
    ssize_t var = va_arg(args, ssize_t);
    int count = var < 0 ? 1 : 0;
    int lnb = 0;

    if (count == 1) {
        specifier_infos.flags |= FLAG_IS_NEGATIVE;
        var *= -1;
    }
    int_count(var, &lnb);
    int_print_precision(specifier_infos, &count, lnb);
    int_print_nbr(var, &count);
    if ((specifier_infos.flags_extra & EXTRAF_MINUS) == EXTRAF_MINUS &&
        specifier_infos.extra_precision == 0)
        count += print_char_ite(specifier_infos.precision - count, ' ');
    return (count);
}

int type_ptrdiff_t(va_list args, t_local_spe specifier_infos)
{
    ptrdiff_t var = va_arg(args, ptrdiff_t);
    int count = var < 0 ? 1 : 0;
    int lnb = 0;

    if (count == 1) {
        specifier_infos.flags |= FLAG_IS_NEGATIVE;
        var *= -1;
    }
    int_count(var, &lnb);
    int_print_precision(specifier_infos, &count, lnb);
    int_print_nbr(var, &count);
    if ((specifier_infos.flags_extra & EXTRAF_MINUS) == EXTRAF_MINUS &&
        specifier_infos.extra_precision == 0)
        count += print_char_ite(specifier_infos.precision - count, ' ');
    return (count);
}