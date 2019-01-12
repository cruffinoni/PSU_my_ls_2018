/*
** EPITECH PROJECT, 2018
** file.c
** File description:
** Utils functions for manipulating files.
*/

#include "my.h"
#include "ls.h"
#include "flags/long/file.h"
#include "utils/folder/folder.h"
#include "utils/summary/core.h"

static void print_file(t_file *file, t_flags flags, t_format_size size)
{
    if (file->dirent->d_name[0] == '.')
        return;
    if (flags & FLAG_l) {
        if (flags & FLAGI_f)
            print_lformat_file(file, size, 1);
        else
            print_lformat_file(file, size, 0);
    }
    else
        my_printf("%s\n", file->dirent->d_name);
}

int count_file(t_file *header)
{
    int return_val = 0;

    while (header != NULL) {
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

void display_files(t_file *header, t_flags flags)
{
    t_file *base = header;
    t_format_size size = get_file_format_size(header);

    while (header != NULL) {
        print_file(header, flags, size);
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