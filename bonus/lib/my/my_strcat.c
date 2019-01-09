/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** A function that concatenates 2 strings
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int count = 0;

    while (dest[count] != '\0')
        count++;
    for (i; src[i] != '\0'; i++)
        dest[count + i] = src[i];
    dest[count + i] = '\0';
    return (dest);
}