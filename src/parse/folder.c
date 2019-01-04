/*
** EPITECH PROJECT, 2018
** folder.c
** File description:
** Parsing through arguments and create internally folder & files. .
*/

#include "my.h"
#include "ls.h"
#include "node.h"

static int check_folder_name(t_folder **ptr, char *name)
{
    char *edited_name = NULL;
    int returned_val = ERR_NONE;

    if (name[my_strlen(name) - 1] != '/')
        edited_name = my_strdupcat(name, "/");
    else
        edited_name = my_strdup(name);
    returned_val = add_folder(ptr, edited_name);
    free(edited_name);
    return (returned_val);
}

int detect_folders(t_folder **header, char **tab, int argc)
{
    int returned_val = ERR_NONE;

    if (argc < 2) {
        add_folder(header, "./");
        return (ERR_NONE);
    }
    for (int i = argc - 1; i > 0; i--) {
        if (tab[i][0] != '-')
            returned_val = check_folder_name(header, tab[i]);
        else
            returned_val = ERR_NONE;
        if (returned_val != ERR_NONE)
            return (returned_val);
    }
    return (ERR_NONE);
}