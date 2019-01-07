/*
** EPITECH PROJECT, 2018
** folder.c
** File description:
** Utils functions for manipulating folders..
*/

#include <stddef.h>
#include "my.h"
#include "ls.h"
#include "node.h"
#include "utils/file.h"

static int count_folder_from_file(t_file *first_file)
{
    int count = 0;

    while (first_file != NULL) {
        if (first_file->subf != NULL)
            count++;
        first_file = first_file->next;
    }
    return (count);
}

static size_t get_folder_size(t_file *header)
{
    size_t total = 0;

    while (header != NULL) {
        if (header->dirent->d_name[0] != '.') {
            total += (header->stat.st_size + header->stat.st_blksize - 1) /
                header->stat.st_blksize * (header->stat.st_blksize / 1024);
        }
        header = header->next;
    }
    return (total);
}

void swap_node_folder(t_folder *node_a, t_folder *node_b)
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

int count_folder(t_folder *header)
{
    int return_val = 0;

    while (header != NULL) {
        return_val += count_folder_from_file(header->hfile) + 1;
        header = header->next;
    }
    return (return_val);
}

void display_folders(t_folder *header, t_ls_flags flags)
{
    int total_folders = count_folder(header);

    while (header != NULL) {
        if (total_folders >= 2 || (flags & FLAG_R))
            my_printf("\x1B[31m%s:\x1B[0m\n", header->original_path);
        if (flags & FLAG_l)
            my_printf("total %li\n", get_folder_size(header->hfile));
        display_files(header->hfile, flags);
        header = header->next;
        if (header != NULL)
            my_putchar('\n');
    }
}