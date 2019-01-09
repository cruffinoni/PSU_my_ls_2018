/*
** EPITECH PROJECT, 2018
** my_str_upper.c
** File description:
** Returns if the string only contains upercase letters
*/

static int is_upper(char c)
{
    return (c >= 'A' && c <= 'Z');
}

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_upper(str[i]))
            return (0);
    }
    return (1);
}