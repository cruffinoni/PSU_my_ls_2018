/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** Return the len of a string.
*/

int my_strlen(char const *str)
{
    int count = 0;

    while (*str != '\0') {
        count++;
        str++;
    }
    return (count);
}