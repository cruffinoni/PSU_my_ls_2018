/*
** EPITECH PROJECT, 2018
** file.c
** File description:
** Utils functions for manipulating files.
*/

#include <time.h>
#include "my.h"
#include "ls.h"
#include "flags/long.h"
#include "utils/folder.h"

size_t get_bigger_file(t_file *file)
{
    size_t max_size = 0;
    size_t size = 0;

    while (file != NULL) {
        if (file->dirent->d_name[0] != '.')
            size = int_strlen(file->stat.st_size);
        if (size > max_size)
            max_size = size;
        file = file->next;
    }
    return (max_size);
}

size_t get_bigger_nblk(t_file *file)
{
    size_t max_size = 0;
    size_t size = 0;

    while (file != NULL) {
        if (file->dirent->d_name[0] != '.')
            size = int_strlen(file->stat.st_nlink);
        if (size > max_size)
            max_size = size;
        file = file->next;
    }
    return (max_size);
}

static void print_file(t_file *file, t_flags flags, t_format_size size)
{
    if (file->dirent->d_name[0] == '.')
        return;
    if (flags & FLAG_l)
        print_long_format(file, size);
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
    t_format_size size = {get_bigger_nblk(header), get_bigger_file(header)};

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