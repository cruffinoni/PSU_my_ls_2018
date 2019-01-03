/*
** EPITECH PROJECT, 2018
** my_str_isprint.c
** File description:
** Returns if the string is printable.
*/

static int is_printable(char c)
{
    return (c >= 32 && c <= 126);
}

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_printable(str[i]))
            return (0);
    }
    return (1);
}