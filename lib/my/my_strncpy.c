/*
** EPITECH PROJECT, 2018
** my_strncpy.c
** File description:
** Copy n characters from a string to another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && n > i) {
        dest[i] = src[i];
        i++;
    }
    if (i < n)
        dest[i] = '\0';
    return (dest);
}