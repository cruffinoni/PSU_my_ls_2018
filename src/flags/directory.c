/*
** EPITECH PROJECT, 2018
** directory.c
** File description:
** 'd' flag also known for listing only directory (and files?)
*/

#include "my.h"
#include "ls.h"
#include "flags/long/file.h"
#include "flags/long/folder.h"
#include "utils/summary/core.h"

void display_files_title(t_file *header, t_flags flags, t_format_size format)
{
    while (header != NULL) {
        if (flags & FLAG_l)
            print_lformat_file(header, format, 1);
        else
            my_printf("%s\n", header->path);
        header = header->next;
    }
}

void display_folders_title(t_folder *header, t_flags flags,
    t_format_size format)
{
    while (header != NULL) {
        if (flags & FLAG_l)
            print_lformat_folder(header, format);
        else
            my_printf("%s\n", header->original_path);
        header = header->next;
    }
}