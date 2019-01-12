/*
** EPITECH PROJECT, 2018
** summary.c
** folder description:
** Summary of different aspects.
*/

#include <sys/types.h>
#include <grp.h>
#include <pwd.h>
#include "my.h"
#include "ls.h"

size_t get_bigger_folder(t_folder *folder)
{
    size_t max_size = 0;
    size_t size = 0;

    while (folder != NULL) {
        size = int_strlen(folder->stat.st_size);
        if (size > max_size)
            max_size = size;
        folder = folder->next;
    }
    return (max_size);
}

size_t get_folder_bigger_nblk(t_folder *folder)
{
    size_t max_size = 0;
    size_t size = 0;

    while (folder != NULL) {
        size = int_strlen(folder->stat.st_nlink);
        if (size > max_size)
            max_size = size;
        folder = folder->next;
    }
    return (max_size);
}

size_t get_folder_bigger_aname(t_folder *folder)
{
    size_t max_size = 0;
    size_t size = 0;
    struct passwd *pinfo = NULL;

    while (folder != NULL) {
        pinfo = getpwuid(folder->stat.st_gid);
        size = my_strlen(pinfo->pw_name);
        if (size > max_size)
            max_size = size;
        folder = folder->next;
    }
    return (max_size);
}

size_t get_folder_bigger_gname(t_folder *folder)
{
    size_t max_size = 0;
    size_t size = 0;
    struct group *pinfo = NULL;

    while (folder != NULL) {
        pinfo = getgrgid(folder->stat.st_gid);
        size = my_strlen(pinfo->gr_name);
        if (size > max_size)
            max_size = size;
        folder = folder->next;
    }
    return (max_size);
}

t_format_size get_folder_format_size(t_folder *folder)
{
    t_format_size format = {get_folder_bigger_nblk(folder),
        get_bigger_folder(folder), get_folder_bigger_aname(folder),
        get_folder_bigger_gname(folder)};
    return (format);
}