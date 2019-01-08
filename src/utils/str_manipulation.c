/*
** EPITECH PROJECT, 2018
** string_manipulation.c
** File description:
** Utils functions for manipulating strings.
*/

#include <stdlib.h>
#include "my.h"
#include "ls.h"

char *return_directory(char *full_path)
{
    int size = 0;
    char *path = NULL;

    for (int i = 0; full_path[i] != '\0'; i++) {
        if (full_path[i] == '/')
            size = i;
    }
    path = malloc(sizeof(char) * (size + 1));
    if (path == NULL)
        return (NULL);
    for (int i = 0; full_path[i] != '\0' && i < size; i++)
        path[i] = full_path[i];
    path[size] = '\0';
    if (path[0] == '\0') {
        free(path);
        path = my_strdup("./");
    }
    return (path);
}

char *get_file_name(char *full_path)
{
    int size = 0;
    char *path = NULL;
    int fp_strlen = my_strlen(full_path);

    for (int i = 0; full_path[i] != '\0'; i++) {
        if (full_path[i] == '/')
            size = i + 1;
    }
    path = malloc(sizeof(char) * fp_strlen - size + 1);
    if (path == NULL)
        return (NULL);
    for (int i = 0, j = size; full_path[j] != '\0'; i++, j++)
        path[i] = full_path[j];
    path[fp_strlen - size] = '\0';
    return (path);
}