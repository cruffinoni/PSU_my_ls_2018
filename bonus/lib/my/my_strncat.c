/*
** EPITECH PROJECT, 2018
** my_strcnat.c
** File description:
** A function that concatenates 2 strings at n chars
*/

char *my_strncat(char *dest, char const *src, int n)
{
    for (int i = 0, j = 0; src[i] != '\0' && n > i; j++) {
        if (dest[j] == '\0') {
            dest[j] = src[i];
            i++;
        }
    }
    return (dest);
}