/*
** EPITECH PROJECT, 2018
** my_compute_square_root.c
** File description:
** Return the square root of a nbr.
*/

#include "../../include/my.h"

int my_compute_square_root(int nb)
{
    int app = 0;

    if (nb < 0)
        return (0);
    while (my_compute_power_rec(app+10, 2) < nb)
        app += 10;
    while (my_compute_power_rec(++app, 2) < nb);
    return (my_compute_power_rec(app, 2) != nb ? 0 : app);
}