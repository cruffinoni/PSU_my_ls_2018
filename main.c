/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main file for the project my_ls.
*/

#include "my.h"
#include "ls.h"
#include "node.h"
#include "parse.h"

int main(int ac, char **av)
{
    t_folder *header = NULL;
    t_display_flags flags = 0;

    flags = detect_flags(av, ac);
    my_printf("\x1B[34mFlags detected: %b\x1B[0m\n", flags);
    if (detect_folders(&header, av, ac) != ERR_NONE)
        return (84);
    display_folders(header);
    delete_folders(&header);
    return (0);
}