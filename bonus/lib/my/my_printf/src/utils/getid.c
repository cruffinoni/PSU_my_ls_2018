/*
** EPITECH PROJECT, 2018
** getid.c
** File description:
** Every functions which allows us to get an id from a char
*/

#include <stdlib.h>
#include "getid.h"

int get_local_spe_index(char specifier)
{
    switch (specifier) {
        case 'i':
        case 'd': return (0);
        case 'u': return (1);
        case 'x': return (2);
        case 'X': return (3);
        case 'o': return (4);
        case 'b': return (5);
        case 'p': return (6);
        case 'c': return (7);
        case 's': return (8);
        case 'S': return (9);
        default: return (INVALID_SPECIFIER);
    }
}

int get_extraf_index(char specifier)
{
    switch (specifier) {
        case '-': return (0);
        case '+': return (1);
        case '#': return (2);
        default: return (INVALID_SPECIFIER);
    }
}

int get_hash_size(char specifier)
{
    switch (specifier) {
        case 'x':
        case 'X': return (2);
        case 'o': return (1);
    }
    return (0);
}

int get_lenspe_index(char const *src, int *index)
{
    switch (src[*index + 1]) {
        case 'h':
            *index = *index + 1;
            if (src[*index + 1] == 'h') {
                *index = *index + 1;
                return (1);
            }
            return (2);
        case 'l':
            *index = *index + 1;
            if (src[*index + 1] == 'l') {
                *index = *index + 1;
                return (3);
            }
            return (4);
        case 'j': return (5);
        case 'z': return (6);
        case 't': return (7);
        default: return (INVALID_SPECIFIER);
    }
}

size_t get_base_from_char(char specifier)
{
    switch (specifier) {
        case 'b': return (2);
        case 'o': return (8);
        case 'x':
        case 'X': return (16);
        default: return (10);
    }
}