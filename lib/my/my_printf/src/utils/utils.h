/*
** EPITECH PROJECT, 2018
** utils.h
** File description:
** Header file for utils.c
*/

#ifndef HEADER_SRC_UTILS
#define HEADER_SRC_UTILS

#include <stdlib.h>
#include <stdint.h>

int uint_len(uintptr_t number);
int uint_count_base(uintptr_t nbr, int *count, size_t base);
int int_len(intptr_t number, size_t base);
int int_count(intptr_t nbr, int *count);

#endif