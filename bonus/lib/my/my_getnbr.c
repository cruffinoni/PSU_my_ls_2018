/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** Find a number in a string and return a pointer to the first invalid char.
*/

#include "my.h"

static int check_minus(char const *str, int *index, int *minus)
{
    if (str[*index] == '-')
        *minus = *minus * -1;
    else if (str[*index] != '+')
        return (0);
}

int my_getnbr(char const *str)
{
    int max_lt = my_strlen(str);
    long nb = 0;
    int minus = 1;
    int index = -1;

    while (!my_isnumber(str[++index]))
        if (!check_minus(str, &index, &minus))
            return (0);
    index--;
    while (index++ <= max_lt) {
        if ('0' <= str[index] && str[index] <= '9')
            nb = nb * 10 + (str[index] - '0');
        else
            return (nb * minus);
    }
    return (2147483648 < nb || nb < -2147483648 ? 0 : nb * minus);
}