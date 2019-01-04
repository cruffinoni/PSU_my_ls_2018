/*
** EPITECH PROJECT, 2018
** file.h
** File description:
** Create, edit or delete any node concersing files.
*/

#include "my.h"
#include "ls.h"
#include "node/folder.h"

static int add_file(t_folder *folder, t_dirent *dirent, t_stat stat,
    t_ls_flags flags, char *path)
{
    t_file *new_node = malloc(sizeof(t_file));
    char *ptr = NULL;

    if (new_node == NULL)
        return (ERR_MALLOC);
    new_node->stat = stat;
    new_node->dirent = dirent;
    new_node->next = folder->hfile;
    new_node->prev = NULL;
    // my_printf("Flags: %b & dirent: %i/%i from: '%s' from '%s'\n", flags, new_node->dirent->d_type, DT_DIR,
        // folder->path, dirent->d_name);
    if ((flags & FLAG_R) && new_node->dirent->d_type == DT_DIR && dirent->d_name[0] != '.') {
        // my_printf("Trying to add the folder: '%s'\n", path);
        ptr = path;
        path = my_strdupcat(path, "/");
        free(ptr);
        add_folder(&new_node->subf, path, path, flags);
    }
    else
        new_node->subf = NULL;
    if (folder->hfile != NULL)
        (folder->hfile)->prev = new_node;
    folder->hfile = new_node;
    free(path);
    return (ERR_NONE);
}

int read_files(t_folder *folder, t_ls_flags flags)
{
    t_dirent *file = readdir(folder->directory);
    t_stat file_stat;
    int returned_val = 0;
    char *new_string = my_strdupcat(folder->path, file->d_name);

    // printf("The original path is: '%s' + '%s' = '%s'\n", folder->path, file->d_name, new_string);
    returned_val = stat(new_string, &file_stat);
    while (file != NULL && returned_val != -1) {
        if (add_file(folder, file, file_stat, flags, new_string) != ERR_NONE)
            return (ERR_MALLOC);
        file = readdir(folder->directory);
        if (file != NULL) {
            new_string = my_strdupcat(folder->path, file->d_name);
            if (new_string == NULL)
                return (ERR_MALLOC);
            returned_val = stat(new_string, &file_stat);
        }
    }
    return (ERR_NONE);
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