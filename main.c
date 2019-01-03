/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main file for the project my_ls.
*/

#include "ls.h"
#include "node/file.h"
#include "node/folder.h"

int main(int ac, char **av)
{
    t_folder *header = NULL;

    if (add_folder(&header, "./") != ERR_NONE)
        return (84);
    if (add_folder(&header, "./tests/") != ERR_NONE)
        return (84);
    if (add_folder(&header, "./lib/") != ERR_NONE)
        return (84);
    display_folders(header);
    delete_folders(&header);
    return (0);
}