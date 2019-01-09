/*
** EPITECH PROJECT, 2018
** small_len.h
** File description:
** Handle unsigned small int.
*/

#ifndef HEADER_SRC_USIGNEDINT_SMALL_INT
#define HEADER_SRC_USIGNEDINT_SMALL_INT

#include "../../my_printf.h"

int type_uschar(va_list args, t_local_spe specifier_infos);
int type_ushort(va_list args, t_local_spe specifier_infos);
int type_unint(va_list args, t_local_spe specifier_infos);
int type_unlong(va_list args, t_local_spe specifier_infos);
int type_unllong(va_list args, t_local_spe specifier_infos);

#endif