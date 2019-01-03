/*
** EPITECH PROJECT, 2018
** file.h
** File description:
** Create, edit or delete any node concersing files.
*/

#include "my.h"
#include "ls.h"

int add_file(t_file **last_node, t_dirent *dirent, t_stat stat)
{
    t_file *new_node = malloc(sizeof(t_file));

    if (new_node == NULL)
        return (ERR_MALLOC);
    new_node->stat = stat;
    new_node->dirent = dirent;
    new_node->next = *last_node;
    new_node->prev = NULL;
    if (*last_node != NULL)
        (*last_node)->prev = new_node;
    *last_node = new_node;
    return (ERR_NONE);
}

int read_files(t_folder *folder)
{
    t_dirent *current_file = readdir(folder->directory);
    t_stat current_stat;
    int returned_val = 0;
    char *new_string = my_strdupcat(folder->path, current_file->d_name);

    returned_val = stat(new_string, &current_stat);
    while (current_file != NULL && returned_val != -1) {
        if (add_file(&folder->hfile, current_file, current_stat) != ERR_NONE)
            return (ERR_MALLOC);
        current_file = readdir(folder->directory);
        free(new_string);
        if (current_file != NULL) {
            new_string = my_strdupcat(folder->path, current_file->d_name);
            if (new_string == NULL)
                return (ERR_MALLOC);
            returned_val = stat(new_string, &current_stat);
        }
    }
    return (ERR_NONE);
}

void display_files(t_file *header)
{
    while (header != NULL) {
        // my_printf("\nFile's name: '%s'\n", header->dirent->d_name);
        // my_printf("File size: %i bytes\n", header->stat.st_size);
        // my_printf("Inode number (from dirent): %i\n", header->dirent->d_ino);
        // my_printf("Inode number (from stat): %i\n", header->stat.st_ino);

        my_printf("%s\n", header->dirent->d_name);
        header = header->next;
    }
}

void free_files(t_file **header)
{
    t_file *next_node = *header;

    while (next_node != NULL) {
        next_node = (*header)->next;
        free(*header);
        *header = next_node;
    }
    *header = NULL;
}