/*
** EPITECH PROJECT, 2018
** folder.h
** File description:
** Creat, edit or delete any node concersing the folders.
*/

#include "my.h"
#include "ls.h"
#include "node/file.h"

static void move_header(t_folder **header, t_folder *new_node)
{
    new_node->next = *header;
    new_node->prev = NULL;
    new_node->hfile = NULL;
    if (*header != NULL)
        (*header)->prev = new_node;
    *header = new_node;
}

int add_folder(t_folder **last_node, char *path)
{
    t_folder *new_node = malloc(sizeof(t_folder));

    if (new_node == NULL)
        return (ERR_MALLOC);
    new_node->path = malloc(sizeof(char) * (my_strlen(path) + 1));
    my_strcpy(new_node->path, path);
    if (new_node->path == NULL) {
        free(new_node);
        return (ERR_MALLOC);
    }
    new_node->directory = opendir(path);
    if (new_node->directory == NULL) {
        free(new_node->path);
        free(new_node);
        return (ERR_FOLDER);
    }
    move_header(last_node, new_node);
    read_files(new_node);
    return (ERR_NONE);
}

void display_folders(t_folder *header)
{
    while (header != NULL) {
        my_printf("\x1B[31mFolder '%s':\x1B[0m\n", header->path);
        display_files(header->hfile);
        header = header->next;
    }
}

void delete_folders(t_folder **last_node)
{
    t_folder *next_node = *last_node;

    while (next_node != NULL) {
        next_node = (*last_node)->next;
        free_files(&(*last_node)->hfile);
        free((*last_node)->path);
        closedir((*last_node)->directory);
        free(*last_node);
        *last_node = next_node;
    }
    *last_node = NULL;
}