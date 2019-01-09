/*
** EPITECH PROJECT, 2018
** my_is_prime.c
** File description:
** A function that returns 1 if the number is prime and 0 if not.
*/

int my_is_prime(int nb)
{
    if (nb <= 1)
        return (0);
    if (nb % 2 == 0)
        return (nb == 2);
    for (int i = 3; i * i <= nb; i += 2) {
        if (nb % i == 0)
            return (0);
    }
    return (1);
}