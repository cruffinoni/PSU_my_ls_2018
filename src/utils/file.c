/*
** EPITECH PROJECT, 2018
** file.c
** File description:
** Utils functions for manipulating files.
*/

#include <time.h>
#include "my.h"
#include "ls.h"
#include "utils/folder.h"

static void print_file(t_file *file)
{
    if (file->dirent->d_name[0] != '.') {
        // char *date = ctime(&file->stat.st_mtime);
        if (file->dirent->d_type == DT_DIR)
            my_printf("\x1B[32m%s\x1B[0m\n", file->dirent->d_name);
        else
            my_printf("%s\n", file->dirent->d_name);
    }
}

int count_file(t_file *header)
{
    int return_val = 0;

    while (header != NULL) {
        // if (header->dirent->d_name[0] != '.' && header->subf == NULL)
        return_val++;
        header = header->next;
    }
    return (return_val);
}

void swap_node_file(t_file *node_a, t_file *node_b)
{
    node_a->next = node_b->next;
    node_b->prev = node_a->prev;
    if (node_a->next != NULL)
        node_a->next->prev = node_a;
    if (node_b->prev != NULL)
        node_b->prev->next = node_b;
    node_a->prev = node_b;
    node_b->next = node_a;
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
            my_putchar('\n');
            display_folders(base->subf, flags);
        }
        base = base->next;
    }
}