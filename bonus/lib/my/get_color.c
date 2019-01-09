/*
** EPITECH PROJECT, 2018
** get_color.c
** File description:
** Return a color as int from RGB.
*/

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    return (red << 16 | green << 8 | blue);
}