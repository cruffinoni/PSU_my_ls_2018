/*
** EPITECH PROJECT, 2018
** time.h
** File description:
** 't' flag also known as time sorting.
*/

#include "my.h"
#include "ls.h"
#include "utils/folder/folder.h"
#include "utils/file/file.h"
#include "flags/time.h"

void sort_by_time(t_folder **header, t_flags flag)
{
    t_folder *current = *header;

    while (current != NULL) {
        sort_folder_by_time(&current, count_folder(current));
        sort_file_by_time(&current->hfile, count_file(current->hfile), flag);
        current = current->next;
    }
}