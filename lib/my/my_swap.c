/*
** EPITECH PROJECT, 2018
** my_swap.c
** File description:
** Swap two variables's value.
*/

void my_swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}