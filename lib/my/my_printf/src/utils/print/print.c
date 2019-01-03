/*
** EPITECH PROJECT, 2018
** print.c
** File description:
** Utils functions for the main project, my_printf
*/

#include <stdint.h>
#include "my.h"
#include "../../handle_args/extra_flags.h"
#include "print_string.h"
#include "../../my_printf.h"
#include "../../utils/getid.h"
#include "../flags.h"

int print_higher_acc(t_local_spe speinfo, int nb_len)
{
    int c = 0;

    if (speinfo.precision - nb_len > 0)
        speinfo.precision -= nb_len;
    if (speinfo.extra_precision - nb_len > 0)
        speinfo.extra_precision -= nb_len;
    if (speinfo.precision > speinfo.extra_precision &&
        ((speinfo.flags & FLAG_ACC_IS_ZERO) != FLAG_ACC_IS_ZERO))
        c = print_char_ite(speinfo.precision - speinfo.extra_precision, ' ');
    else if (speinfo.precision > speinfo.extra_precision)
        c = print_char_ite(speinfo.precision - speinfo.extra_precision, '0');
    if (speinfo.extra_precision && (speinfo.flags_extra & EXTRAF_HASH) !=
        EXTRAF_HASH)
        c += print_char_ite(speinfo.extra_precision, '0');
    return (c);
}

int print_precision(t_local_spe speinfo, int nb_len)
{
    int count = 0;

    if ((speinfo.flags_extra & EXTRAF_HASH) == EXTRAF_HASH)
        nb_len += get_hash_size(speinfo.basic_specifier);
    if ((speinfo.flags_extra & EXTRAF_MINUS) != EXTRAF_MINUS &&
        nb_len < speinfo.precision)
        count += print_higher_acc(speinfo, nb_len);
    else if (nb_len < speinfo.extra_precision)
        count += print_char_ite(speinfo.extra_precision - nb_len, '0');
    return (count);
}