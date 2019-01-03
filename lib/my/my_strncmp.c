/*
** EPITECH PROJECT, 2018
** my_strncmp.c
** File description:
** Compare 2 strings at n characters
*/

#include "../../include/my.h"

static int strncmp_my_strlen(char const *s1, int n)
{
    int count = 0;

    for (int i = 0; s1[i] != '\0' && i < n; i++) {
        if (!my_isletter(s1[i]))
            return (0);
        count++;
    }
    return (count);
}

static int strncmp_cascii(char const *s1, int n)
{
    int count = 0;

    for (int i = 0; s1[i] != '\0' && i < n; i++)
        if (my_isletter(s1[i]))
            count += s1[i];
    return (count);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (strncmp_my_strlen(s1, n) != strncmp_my_strlen(s2, n))
        return (strncmp_my_strlen(s1, n) > strncmp_my_strlen(s2, n) ? -1 : 1);
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0' && i < n; i++)
        if (s1[i] != s2[i])
            return (strncmp_cascii(s1, n) > strncmp_cascii(s2, n) ? 2 : -2);
    return (0);
}