/*
** EPITECH PROJECT, 2018
** print_uint.c
** File description:
** Print functions for unsigned int only
*/

#include <unistd.h>
#include <stdint.h>
#include "my.h"
#include "print_string.h"
#include "../../handle_args/extra_flags.h"
#include "../../my_printf.h"

static int print_hash_extraf(char basic_specifier)
{
    switch (basic_specifier) {
        case 'x': write(1, "0x", 2);
            return (2);
        case 'X': write(1, "0X", 2);
            return (2);
        case 'o': write(1, "0", 2);
            return (1);
    }
    return (0);
}

int print_extraf(t_local_spe spe_inf, int is_uint, int is_neg)
{
    int count = 0;

    if (spe_inf.flags_extra & EXTRAF_HASH)
        count += print_hash_extraf(spe_inf.basic_specifier);
    if (((spe_inf.flags_extra & EXTRAF_PLUS) == EXTRAF_PLUS) && !is_uint) {
        if (is_neg)
            count += my_putchar('-');
        else
            count += my_putchar('+');
    }
    return (count);
}

int uint_print_nbr(uintptr_t nbr, int *count, int upper_case, size_t base)
{
    uintptr_t displayed_number = 0;

    if (nbr >= base) {
        displayed_number = nbr % base;
        nbr = (nbr - displayed_number) / base;
        *count = *count + 1;
        uint_print_nbr(nbr, count, upper_case, base);
        put_char_base(displayed_number, upper_case);
    }
    else {
        *count = *count + 1;
        put_char_base(nbr, upper_case);
    }
    return (0);
}