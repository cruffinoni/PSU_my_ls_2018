/*
** EPITECH PROJECT, 2018
** time.h
** File description:
** 't' flag also known as time sorting - Folder exclusive
*/

#include "ls.h"
#include "utils/file.h"
#include "flags/time.h"

static void find_folder_by_file(t_file **header, t_flags flag)
{
    t_file *current = *header;

    while (current != NULL) {
        if (current->subf != NULL)
            sort_by_time(&current->subf, flag);
        current = current->next;
    }
}

static int check_swap_file(t_file **header, t_file *current)
{
    if (current->stat.st_mtime < current->next->stat.st_mtime) {
        if (current->prev == NULL)
            *header = current->next;
        swap_node_file(current, current->next);
        return (1);
    }
    return (0);
}

void sort_file_by_time(t_file **header, int total_file, t_flags flag)
{
    t_file *next_node = *header;
    t_file *current = *header;
    int original_size = total_file;

    if (original_size <= 0) {
        if (flag & FLAG_R)
            find_folder_by_file(header, flag);
        return;
    }
    while (current != NULL && current->next != NULL && total_file-- > 0) {
        next_node = next_node->next;
        if (check_swap_file(header, current) > 0)
            next_node = next_node->next;
        current = next_node;
    }
    sort_file_by_time(header, --original_size, flag);
}