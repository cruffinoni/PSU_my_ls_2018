/*
** EPITECH PROJECT, 2018
** folder.c
** File description:
** Utils functions for manipulating folders..
*/

#include "my.h"
#include "ls.h"
#include "node/file.h"

// /home/cruffinoni/delivery/PSU/PSU_my_ls_2018/

int count_folders(t_folder *header)
{
    int return_val = 0;

    while (header != NULL) {
        if (header->hfile != NULL)
            return_val += 2;
        else
            return_val++;
        header = header->next;
    }
    return (return_val);
}

void display_folders(t_folder *header, t_ls_flags flags)
{
    int total_folders = count_folders(header);

    while (header != NULL) {
        if (total_folders >= 2)
            my_printf("\x1B[31m%s:\x1B[0m\n", header->original_path);
        display_files(header->hfile, flags);
        header = header->next;
        if (header != NULL)
            my_putchar('\n');
    }
}