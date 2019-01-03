/*
** EPITECH PROJECT, 2018
** print_string.h
** File description:
** Print functions for string only
*/

#ifndef HEADER_SRC_PRINTSTR
#define HEADER_SRC_PRINTSTR

#include "../../my_printf.h"

int print_string(char *string, int *count, int escape_char, t_local_spe spe);
int print_char_ite(int count, char c);
void put_char_base(int number, int upper_case);

#endif