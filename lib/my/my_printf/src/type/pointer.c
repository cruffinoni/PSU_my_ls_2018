/*
** EPITECH PROJECT, 2018
** hexadecimal.c
** File description:
** Print an hexadecimal number.
*/

#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>
#include "my.h"
#include "../my_printf.h"
#include "../handle_args/extra_flags.h"
#include "../utils/utils.h"
#include "../utils/print/print.h"
#include "../utils/print/print_string.h"
#include "../utils/print/print_uint.h"
#include "../utils/flags.h"

static int print_extra_space(t_local_spe specifier_infos, int nb_len, int
    count)
{
    if ((specifier_infos.flags_extra & EXTRAF_MINUS) == EXTRAF_MINUS)
        if (nb_len < specifier_infos.precision && specifier_infos.precision >
            count)
            count += print_char_ite(specifier_infos.precision - count, ' ');
    return (count);
}

int type_pointer(va_list args, t_local_spe specifier_infos)
{
    void *var = va_arg(args, void *);
    int count = 2;
    int nb_len = 14;

    if ((specifier_infos.flags_extra & EXTRAF_PLUS) != EXTRAF_PLUS) {
        if ((specifier_infos.flags_extra & EXTRAF_SPACE) == EXTRAF_SPACE)
            count += my_putchar(' ');
        count += print_extraf(specifier_infos, 0, 0);
    }
    else
        specifier_infos.precision--;
    count += print_precision(specifier_infos, nb_len);
    if ((specifier_infos.flags_extra & EXTRAF_PLUS) == EXTRAF_PLUS)
        count += print_extraf(specifier_infos, 0, 0);
    write(1, "0x", 2);
    uint_print_nbr((intptr_t) var, &count, 0, 16);
    print_extra_space(specifier_infos, nb_len, count);
    return (count);
}