/*
** EPITECH PROJECT, 2018
** integer.h
** File description:
** Header file for integer.c
*/

#ifndef HEADER_SRC_SIGNEDINT_SMALL_INT
#define HEADER_SRC_SIGNEDINT_SMALL_INT

#include "../../my_printf.h"

int type_schar(va_list args, t_local_spe specifier_infos);
int type_short(va_list args, t_local_spe specifier_infos);
int type_int(va_list args, t_local_spe specifier_infos);
int type_long(va_list args, t_local_spe specifier_infos);
int type_llong(va_list args, t_local_spe specifier_infos);

#endif