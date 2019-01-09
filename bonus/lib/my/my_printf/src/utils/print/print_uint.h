/*
** EPITECH PROJECT, 2018
** print_uint.c
** File description:
** Print functions for unsigned int only
*/

#ifndef HEADER_SRC_PRINT_UINT
#define HEADER_SRC_PRINT_UINT

#include <stdint.h>
#include "../../my_printf.h"

int print_extraf(t_local_spe spe_inf, int is_uint, int is_neg);
int uint_print_nbr(uintptr_t nbr, int *count, int upper_case, size_t base);

#endif