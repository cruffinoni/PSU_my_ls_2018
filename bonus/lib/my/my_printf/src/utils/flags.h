/*
** EPITECH PROJECT, 2018
** utils.h
** File description:
** Header file for utils.c
*/

#ifndef HEADER_SRC_UTILS_FLAGS
#define HEADER_SRC_UTILS_FLAGS

#define GFLAG_INVALID_VALUE     (0b1)
#define FLAG_ACC_IS_ZERO        (0b10)
#define FLAG_IS_NEGATIVE        (0b100)

#include <stddef.h>
int compute_gflag(int value, size_t flag);

#endif