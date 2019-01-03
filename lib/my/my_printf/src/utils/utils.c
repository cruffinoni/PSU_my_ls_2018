/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** Utils functions for the main project, my_printf
*/

#include <stdint.h>
#include "my.h"
#include "flags.h"

int uint_len(uintptr_t number)
{
    size_t count = 0;

    while (number > 0) {
        count++;
        number /= 10;
    }
    return (count);
}

int uint_count_base(uintptr_t nbr, int *count, size_t base)
{
    uintptr_t displayed_number = 0;

    if (nbr >= base) {
        displayed_number = nbr % base;
        nbr = (nbr - displayed_number) / base;
        *count = *count + 1;
        uint_count_base(nbr, count, base);
    }
    else
        *count = *count + 1;
    return (0);
}

int int_len(intptr_t number, size_t base)
{
    size_t count = 0;

    while (number > 0) {
        count++;
        number /= base;
    }
    return (count);
}

int int_count(intptr_t nbr, int *count)
{
    intptr_t displayed_number = 0;

    if (nbr < 0) {
        *count = *count + 1;
        nbr *= -1;
    }
    if (nbr >= 10) {
        displayed_number = nbr % 10;
        nbr = (nbr - displayed_number) / 10;
        *count = *count + 1;
        int_count(nbr, count);
    }
    else
        *count = *count + 1;
    return (0);
}