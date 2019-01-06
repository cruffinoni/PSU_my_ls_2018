/*
** EPITECH PROJECT, 2018
** time.h
** File description:
** 't' flag also known as time sorting.
*/

#include "my.h"
#include "ls.h"
#include "node.h"
#include "utils/folder.h"

static void check_swap_folder(t_folder **header, t_folder *current)
{
    if (current->stat.st_mtime < current->next->stat.st_mtime) {
        if (current->prev == NULL)
            *header = current->next;
        swap_node_folder(current, current->next);
    }
}

static void sort_folder_by_time(t_folder **header, int folder_size)
{
    t_folder *next_node = *header;
    t_folder *current = *header;
    int original_size = folder_size;

    if (original_size <= 0)
        return;
    while (current != NULL && current->next != NULL && folder_size-- > 0) {
        next_node = next_node->next;
        check_swap_folder(header, current);
        current = next_node;
    }
    sort_folder_by_time(header, --original_size);
}

void sort_by_time(t_folder **header)
{
    t_folder *current = *header;

    while (current != NULL) {
        my_printf("Folder: '%s' w/ time: %li (%p)\n", current->path, current->stat.st_mtime, current);
        current = current->next;
    }
    my_printf("There is %i folders\n", count_folder(*header));
    sort_folder_by_time(header, count_folder(*header));
}