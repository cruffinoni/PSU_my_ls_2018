/*
** EPITECH PROJECT, 2018
** file.h
** File description:
** Create, edit or delete any node concersing files.
*/

#include "my.h"
#include "ls.h"
#include "node/folder.h"
#include "utils/str_manipulation.h"

static int add_subfolder(t_flags flags, t_file *node, char *path)
{
    char *ptr = NULL;

    node->subf = NULL;
    node->parent_dir = NULL;
    if ((flags & FLAG_R) && node->dirent->d_type == DT_DIR &&
        node->dirent->d_name[0] != '.') {
        ptr = my_strdupcat(path, "/");
        if (ptr == NULL)
            return (ERR_MALLOC);
        add_folder(&(node->subf), ptr, path, flags);
        free(ptr);
    }
    return (ERR_NONE);
}

int add_file(t_folder *folder, t_dirent *dirent, t_flags flags, char *path)
{
    t_file *new_node = malloc(sizeof(t_file));

    if (new_node == NULL)
        return (ERR_MALLOC);
    new_node->path = my_strdup(path);
    stat(path, &new_node->stat);
    new_node->dirent = dirent;
    if (add_subfolder(flags, new_node, path) != ERR_NONE) {
        free(new_node);
        return (ERR_MALLOC);
    }
    if (flags & FLAGI_af)
        new_node->parent_dir = folder->directory;
    new_node->next = folder->hfile;
    new_node->prev = NULL;
    if (folder->hfile != NULL)
        folder->hfile->prev = new_node;
    folder->hfile = new_node;
    return (ERR_NONE);
}

int read_files(t_folder *folder, t_flags flags)
{
    t_dirent *file = readdir(folder->directory);
    t_stat file_stat;
    int returned_val = 0;
    char *new_string = my_strdupcat(folder->path, file->d_name);

    returned_val = stat(new_string, &file_stat);
    while (file != NULL && returned_val != -1) {
        free(new_string);
        new_string = my_strdupcat(folder->path, file->d_name);
        if (new_string == NULL)
            return (ERR_MALLOC);
        returned_val = stat(new_string, &file_stat);
        if (add_file(folder, file, flags, new_string) != ERR_NONE) {
            free(new_string);
            return (ERR_MALLOC);
        }
        file = readdir(folder->directory);
    }
    free(new_string);
    return (ERR_NONE);
}

int add_manually_file(t_folder *ptr, DIR *dir, char *folder, t_flags flags)
{
    t_dirent *file = readdir(dir);
    char *f_name = get_file_name(folder);

    while (file != NULL) {
        if (!my_strcmp(file->d_name, f_name)) {
            free(f_name);
            return (add_file(ptr, file, flags, folder));
        }
        file = readdir(dir);
    }
    my_putstr(folder);
    return (ERR_FILE);
}

void free_files(t_file **header)
{
    t_file *next_node = *header;

    while (next_node != NULL) {
        next_node = (*header)->next;
        if ((*header)->subf != NULL)
            delete_folders(&(*header)->subf);
        if ((*header)->parent_dir != NULL)
            closedir((*header)->parent_dir);
        free((*header)->path);
        free(*header);
        *header = next_node;
    }
    *header = NULL;
}