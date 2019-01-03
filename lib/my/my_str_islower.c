/*
** EPITECH PROJECT, 2018
** my_str_islower.c
** File description:
** Returns if the string only contains lowercase letters
*/

static int is_lower(char c)
{
    return (c >= 'a' && c <= 'z');
}

int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_lower(str[i]))
            return (0);
    }
    return (1);
}