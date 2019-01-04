/*
** EPITECH PROJECT, 2018
** flags.c
** File description:
** That file will parse arguments to find flags.
*/

#include "my.h"
#include "ls.h"
#include "node.h"

static t_ls_flags find_flags(char *str)
{
    t_ls_flags flags = 0;

    for (int i = 1; str[i] != '\0'; i++) {
        switch (str[i]) {
            case 'l': flags |= FLAG_l;
            break;
            case 'R': flags |= FLAG_R;
            break;
            case 'd': flags |= FLAG_d;
            break;
            case 'r': flags |= FLAG_r;
            break;
            case 't': flags |= FLAG_t;
            break;
            default: my_printf("my_ls: Invalid option: '%c'\n", str[i]);
            exit(84);
        }
    }
    return (flags);
}

t_ls_flags detect_flags(char **tab, int args)
{
    t_ls_flags flags = 0;

    for (int i = 0; i < args; i++) {
        if (tab[i][0] == '-')
            flags |= find_flags(tab[i]);
    }
    return (flags);
}