/*
** EPITECH PROJECT, 2018
** integer.h
** File description:
** Header file for integer.c
*/

#ifndef HEADER_SRC_SIGNEDINT_BIG_INT
#define HEADER_SRC_SIGNEDINT_BIG_INT

#include "../../my_printf.h"

int type_intmax_t(va_list args, t_local_spe specifier_infos);
int type_ssize_t(va_list args, t_local_spe specifier_infos);
int type_ptrdiff_t(va_list args, t_local_spe specifier_infos);

#endif