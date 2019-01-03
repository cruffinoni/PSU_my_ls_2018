/*
** EPITECH PROJECT, 2018
** is_letter.c
** File description:
** Return 0 or 1 if c is a letter.
*/

int my_isletter(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}