/*
** EPITECH PROJECT, 2018
** my_compute_power_it.c
** File description:
** Raise nb to power p by recursive method.
*/

int my_compute_power_rec(int nb, int p)
{
    long result = 1;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    result = my_compute_power_rec(nb, p - 1) * nb;
    return (result);
}