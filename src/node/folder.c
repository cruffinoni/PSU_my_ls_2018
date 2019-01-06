/*
** EPITECH PROJECT, 2018
** folder.c
** File description:
** Creat, edit or delete any node concersing the folders.
*/

#include <stdio.h>
#include "my.h"
#include "ls.h"
#include "node/file.h"
#include "utils/folder.h"

static void move_header(t_folder **header, t_folder *new_node)
{
    new_node->next = *header;
    new_node->prev = NULL;
    new_node->hfile = NULL;
    if ((*header) != NULL)
        (*header)->prev = new_node;
    *header = new_node;
}

static int add_paths(t_folder *node, char *path, char *original_path)
{
    node->path = my_strdup(path);
    node->original_path = my_strdup(original_path);
    if (node->path == NULL || node->original_path == NULL) {
        if (node->path != NULL)
            free(node->path);
        if (node->original_path != NULL)
            free(node->original_path);
        free(node);
        return (ERR_MALLOC);
    }
    if (stat(node->path, &node->stat) < 0) {
        free(node->path);
        free(node->original_path);
        free(node);
        return (ERR_MALLOC);
    }
    return (ERR_NONE);
}

int add_folder(t_folder **last_node, char *path, char *original_path,
    t_ls_flags flags)
{
    t_folder *new_node = malloc(sizeof(t_folder));

    if (new_node == NULL)
        return (ERR_MALLOC);
    if (add_paths(new_node, path, original_path) != ERR_NONE)
        return (ERR_MALLOC);
    new_node->directory = opendir(path);
    if (new_node->directory == NULL) {
        perror("add_folder");
        free(new_node->path);
        free(new_node);
        return (ERR_FOLDER);
    }
    move_header(last_node, new_node);
    read_files(new_node, flags);
    return (ERR_NONE);
}

void delete_folders(t_folder **last_node)
{
    t_folder *next_node = *last_node;

    while (next_node != NULL) {
        next_node = (*last_node)->next;
        free_files(&(*last_node)->hfile);
        free((*last_node)->original_path);
        free((*last_node)->path);
        closedir((*last_node)->directory);
        free(*last_node);
        *last_node = next_node;
    }
    *last_node = NULL;
}