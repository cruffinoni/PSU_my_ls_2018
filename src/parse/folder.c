/*
** EPITECH PROJECT, 2018
** folder.c
** File description:
** Parsing through arguments and create internally folder & files. .
*/

#include "my.h"
#include "ls.h"
#include "node.h"
#include "utils/str_manipulation.h"

static int try_add_file(t_folder *file, char *name, t_flags flags)
{
    char *edited_name = return_directory(name);
    int returned_val = ERR_NONE;

    if (edited_name == NULL)
        return (ERR_MALLOC);
    file->directory = opendir(edited_name);
    if (file->directory == NULL) {
        free(edited_name);
        return (ERR_MALLOC);
    }
    flags |= FLAGI_af;
    returned_val = add_manually_file(file, file->directory, name, flags);
    free(edited_name);
    flags = ~FLAGI_af;
    if (returned_val != ERR_NONE)
        return (ERR_MALLOC);
    return (ERR_NONE);
}

static int check_folder_name(t_folder **ptr, t_folder *file,
    char *name, t_flags *flags)
{
    char *edited_name = NULL;
    int returned_val = ERR_NONE;

    if (name[my_strlen(name) - 1] != '/')
        edited_name = my_strdupcat(name, "/");
    else
        edited_name = my_strdup(name);
    returned_val = add_folder(ptr, edited_name, name, *flags);
    free(edited_name);
    if (returned_val == ERR_FOLDER) {
        returned_val = try_add_file(file, name, *flags);
        if (returned_val != ERR_NONE)
            return (returned_val);
        *flags |= FLAGI_f;
    }
    return (returned_val);
}

int detect_folders(t_multiple_folder *folder, t_flags *flags,
    char **tab, int argc)
{
    int returned_val = ERR_NONE;

    (*folder->file)->next = NULL;
    (*folder->file)->prev = NULL;
    (*folder->file)->hfile = NULL;
    (*folder->file)->directory = NULL;
    for (int i = argc - 1; i > 0; i--) {
        if (tab[i][0] != '-')
            returned_val = check_folder_name(folder->header, (*folder->file),
                tab[i], flags);
        if (returned_val == ERR_MALLOC || returned_val == ERR_FILE)
            return (returned_val);
    }
    if (count_folder(*folder->header) < 1 && (*folder->file)->hfile == NULL)
        add_folder(folder->header, "./", ".", *flags);
    return (ERR_NONE);
}