/*
** EPITECH PROJECT, 2018
** file.c
** File description:
** Utils functions for manipulating files.
*/

#include "my.h"
#include "ls.h"
#include "utils/folder.h"

static void print_file(t_file *file)
{
    if (file->dirent->d_name[0] != '.') {
        if (file->dirent->d_type == DT_DIR)
            my_printf("\x1B[32m%s\x1B[0m\n", file->dirent->d_name);
        else
            my_printf("%s\n", file->dirent->d_name);
    }
}

void display_files(t_file *header, t_ls_flags flags)
{
    t_file *base = header;

    while (header != NULL) {
        print_file(header);
        header = header->next;
    }
    while (base != NULL) {
        if (base->dirent->d_name[0] != '.' && base->subf != NULL) {
            // my_printf("\n\x1B[31m-%s:\x1B[0m\n", base->subf->original_path);
            my_putchar('\n');
            display_folders(base->subf, flags);
        }
        base = base->next;
    }
}