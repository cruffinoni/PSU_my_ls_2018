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
        if (file->subf != NULL)
            my_printf("\x1B[34m%s\x1B[0m\n", file->dirent->d_name);
        else
            my_printf("%s\n", file->dirent->d_name);
    }
}

void display_files(t_file *header, t_ls_flags flags)
{
    t_file *base = header;

    while (header != NULL) {
        // my_printf("\nFile's name: '%s'\n", header->dirent->d_name);
        // my_printf("Last modification: %i\n", header->stat.st_mtime);
        // my_printf("File size: %i bytes\n", header->stat.st_size);
        // my_printf("Inode number (from dirent): %i\n", header->dirent->d_ino);
        // my_printf("Inode number (from stat): %i\n", header->stat.st_ino);
        print_file(header);
        header = header->next;
    }
    while (base != NULL) {
        if (base->dirent->d_name[0] != '.' && base->subf != NULL) {
            my_putchar('\n');
            display_folders(base->subf, flags);
        }
        base = base->next;
    }
}