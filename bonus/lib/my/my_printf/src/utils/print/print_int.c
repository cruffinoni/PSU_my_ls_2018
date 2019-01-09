/*
** EPITECH PROJECT, 2018
** print_int.c
** File description:
** Print functions for signed int only
*/

#include <stdint.h>
#include "my.h"
#include "print_string.h"
#include "../flags.h"
#include "../../handle_args/extra_flags.h"

int int_print_nbr(intptr_t nbr, int *count)
{
    intptr_t displayed_number = 0;

    if (nbr < 0) {
        my_putchar('-');
        *count = *count + 1;
        nbr *= -1;
    }
    if (nbr >= 10) {
        displayed_number = nbr % 10;
        nbr = (nbr - displayed_number) / 10;
        *count = *count + 1;
        int_print_nbr(nbr, count);
        put_char_base(displayed_number, 0);
    }
    else {
        *count = *count + 1;
        put_char_base(nbr, 0);
    }
    return (0);
}

int int_print_sign(t_local_spe specifier_infos)
{
    int count = 0;

    if ((specifier_infos.flags & FLAG_IS_NEGATIVE) == FLAG_IS_NEGATIVE)
        my_putchar('-');
    else if ((specifier_infos.flags_extra & EXTRAF_PLUS) == EXTRAF_PLUS)
        count = my_putchar('+');
    return (count);
}

void int_print_precision(t_local_spe spe, int *count, int lnb)
{
    if ((spe.flags_extra & EXTRAF_SPACE) &&
        (spe.flags & FLAG_IS_NEGATIVE) != FLAG_IS_NEGATIVE)
        *count += my_putchar(' ');
    if ((spe.flags & FLAG_ACC_IS_ZERO) != FLAG_ACC_IS_ZERO &&
        (spe.flags_extra & EXTRAF_MINUS) != EXTRAF_MINUS &&
        spe.extra_precision == 0) {
        if ((spe.flags & FLAG_IS_NEGATIVE) == FLAG_IS_NEGATIVE
            || (spe.flags_extra & EXTRAF_PLUS) == EXTRAF_PLUS)
            lnb++;
        *count += print_char_ite(spe.precision - lnb, ' ');
    }
    *count += int_print_sign(spe);
    if (spe.extra_precision > 0)
        *count += print_char_ite(spe.extra_precision - lnb, '0');
    if (((spe.flags & FLAG_ACC_IS_ZERO) == FLAG_ACC_IS_ZERO) &&
        (spe.precision > 0 && spe.extra_precision == 0) &&
        (spe.flags_extra & EXTRAF_MINUS) != EXTRAF_MINUS)
        *count += print_char_ite(spe.precision - (*count + lnb), '0');
}