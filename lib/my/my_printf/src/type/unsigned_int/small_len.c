/*
** EPITECH PROJECT, 2018
** small_len.c
** File description:
** Handle unsigned small int.
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

int type_uschar(va_list args, t_local_spe specifier_infos)
{
    unsigned short var = va_arg(args, unsigned int);
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

int type_ushort(va_list args, t_local_spe specifier_infos)
{
    unsigned short var = va_arg(args, unsigned int);
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

int type_unint(va_list args, t_local_spe specifier_infos)
{
    unsigned int var = va_arg(args, unsigned int);
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

int type_unlong(va_list args, t_local_spe specifier_infos)
{
    unsigned long var = va_arg(args, unsigned long);
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

int type_unllong(va_list args, t_local_spe specifier_infos)
{
    unsigned long long var = va_arg(args, unsigned long long);
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