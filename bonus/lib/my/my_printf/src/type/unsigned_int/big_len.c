/*
** EPITECH PROJECT, 2018
** big_len.c
** File description:
** Handle unsigned big int.
*/

#include <sys/types.h>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include "my.h"
#include "../../handle_args/extra_flags.h"
#include "../../my_printf.h"
#include "../../utils/utils.h"
#include "../../utils/getid.h"
#include "../../utils/print/print.h"
#include "../../utils/print/print_string.h"
#include "../../utils/print/print_uint.h"
#include "../../utils/flags.h"

int type_uintmax_t(va_list args, t_local_spe specifier_infos)
{
    uintmax_t var = va_arg(args, uintmax_t);
    int count = 0;
    size_t base = get_base_from_char(specifier_infos.basic_specifier);
    int nb_len = 0;

    uint_count_base(var, &nb_len, base);
    count += print_precision(specifier_infos, nb_len);
    count += print_extraf(specifier_infos, 1, 0);
    uint_print_nbr(var, &count, specifier_infos.basic_specifier == 'X', base);
    if ((specifier_infos.flags_extra & EXTRAF_MINUS) == EXTRAF_MINUS)
        if (nb_len < specifier_infos.precision && specifier_infos.precision >
            count)
            count += print_char_ite(specifier_infos.precision - count, ' ');
    return (count);
}

int type_sizet(va_list args, t_local_spe specifier_infos)
{
    size_t var = va_arg(args, size_t);
    int count = 0;
    size_t base = get_base_from_char(specifier_infos.basic_specifier);
    int nb_len = 0;

    uint_count_base(var, &nb_len, base);
    count += print_precision(specifier_infos, nb_len);
    count += print_extraf(specifier_infos, 1, 0);
    uint_print_nbr(var, &count, specifier_infos.basic_specifier == 'X', base);
    if ((specifier_infos.flags_extra & EXTRAF_MINUS) == EXTRAF_MINUS)
        if (nb_len < specifier_infos.precision && specifier_infos.precision >
            count)
            count += print_char_ite(specifier_infos.precision - count, ' ');
    return (count);
}

int type_unptrdiff_t(va_list args, t_local_spe specifier_infos)
{
    uintptr_t var = va_arg(args, uintptr_t);
    int count = 0;
    size_t base = get_base_from_char(specifier_infos.basic_specifier);
    int nb_len = 0;

    uint_count_base(var, &nb_len, base);
    count += print_precision(specifier_infos, nb_len);
    count += print_extraf(specifier_infos, 1, 0);
    uint_print_nbr(var, &count, specifier_infos.basic_specifier == 'X', base);
    if ((specifier_infos.flags_extra & EXTRAF_MINUS) == EXTRAF_MINUS)
        if (nb_len < specifier_infos.precision && specifier_infos.precision >
            count)
            count += print_char_ite(specifier_infos.precision - count, ' ');
    return (count);
}