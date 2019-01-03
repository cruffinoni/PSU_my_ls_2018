/*
** EPITECH PROJECT, 2018
** utils.h
** File description:
** Header file for utils.c
*/

#ifndef HEADER_SRC_GETID
#define HEADER_SRC_GETID

#include <stdlib.h>
#include <stdint.h>

#define INVALID_SPECIFIER (-1)
#define is_valid_specifier(specifier) \
    (get_local_spe_index(specifier) != INVALID_SPECIFIER)
#define is_valid_extraf(specifier) \
    (get_extraf_index(specifier) != INVALID_SPECIFIER)

int get_local_spe_index(char specifier);
int get_extraf_index(char specifier);
int get_lenspe_index(char const *src, int *index);
size_t get_base_from_char(char specifier);
int get_hash_size(char specifier);

#endif