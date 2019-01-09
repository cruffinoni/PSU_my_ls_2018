/*
** EPITECH PROJECT, 2018
** directory.c
** File description:
** 'd' flag also known for listing only directory (and files?)
*/

#include "my.h"
#include "ls.h"
#include "flags/long.h"
#include "utils/file.h"

void display_files_title(t_file *header, t_flags flags)
{
    t_format_size size = {get_bigger_nblk(header), get_bigger_file(header)};

    while (header != NULL) {
        if (flags & FLAG_l)
            print_long_format(header, size);
        else
            my_printf("%s\n", header->path);
        header = header->next;
    }
}

void display_folders_title(t_folder *header)
{
    while (header != NULL) {
        my_printf("%s\n", header->original_path);
        header = header->next;
    }
}