/*
** EPITECH PROJECT, 2018
** folder.h
** File description:
** Creat, edit or delete any node concersing the folders.
*/

#include "ls.h"

int add_folder(t_folder **last_node, char *path)
{
    t_folder *new_node = malloc(sizeof(t_folder));

    if (new_node == NULL)
        return (ERR_MALLOC);
    new_node->directory = opendir(path);
    if (new_node->directory == NULL) {
        free (new_node);
        return (ERR_FOLDER);
    }
    new_node->next = *last_node;
    new_node->prev = NULL;
    if (*last_node != NULL)
        (*last_node)->prev = new_node;
    *last_node = new_node;
    return (ERR_NONE);
}
/*
int delete_folder(t_folder **last_node)
{

}*/