/*
** EPITECH PROJECT, 2018
** big_len.h
** File description:
** Handle unsigned big int.
*/

#ifndef HEADER_SRC_USIGNEDINT_BIG_INT
#define HEADER_SRC_USIGNEDINT_BIG_INT

#include "../../my_printf.h"

int type_uintmax_t(va_list args, t_local_spe specifier_infos);
int type_sizet(va_list args, t_local_spe specifier_infos);
int type_unptrdiff_t(va_list args, t_local_spe specifier_infos);

#endif