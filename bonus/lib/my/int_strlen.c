/*
** EPITECH PROJECT, 2018
** int_strlen.c
** File description:
** The size of an int.
*/

#include <stddef.h>

size_t int_strlen(int number)
{
    size_t result = 0;

    if (number < 0) {
        result++;
        number *= -1;
    }
    while (number > 0) {
        result++;
        number /= 10;
    }
    return (result);
}