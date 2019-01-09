/*
** EPITECH PROJECT, 2018
** my_find_prime_sup.c
** File description:
** Return the smallest prime number.
*/

#include "../../include/my.h"

int my_find_prime_sup(int nb)
{
    int primenb = 0;
    int i = nb;

    while (primenb != 1)
        primenb = my_is_prime(i++);
    primenb = --i;
    return (primenb);
}