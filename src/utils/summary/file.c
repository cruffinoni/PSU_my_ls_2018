/*
** EPITECH PROJECT, 2018
** file.c
** File description:
** Summary of different aspects.
*/

#include <sys/types.h>
#include <grp.h>
#include <pwd.h>
#include "my.h"
#include "ls.h"

size_t get_bigger_file(t_file *file)
{
    size_t max_size = 0;
    size_t size = 0;

    while (file != NULL) {
        if (file->dirent->d_name[0] != '.')
            size = int_strlen(file->stat.st_size);
        if (size > max_size)
            max_size = size;
        file = file->next;
    }
    return (max_size);
}

size_t get_file_bigger_nblk(t_file *file)
{
    size_t max_size = 0;
    size_t size = 0;

    while (file != NULL) {
        if (file->dirent->d_name[0] != '.')
            size = int_strlen(file->stat.st_nlink);
        if (size > max_size)
            max_size = size;
        file = file->next;
    }
    return (max_size);
}

size_t get_file_bigger_aname(t_file *file)
{
    size_t max_size = 0;
    size_t size = 0;
    struct passwd *pinfo = NULL;

    while (file != NULL) {
        if (file->dirent->d_name[0] != '.')
            pinfo = getpwuid(file->stat.st_gid);
        else
            pinfo = NULL;
        if (pinfo != NULL)
            size = my_strlen(pinfo->pw_name);
        if (size > max_size)
            max_size = size;
        file = file->next;
    }
    return (max_size);
}

size_t get_file_bigger_gname(t_file *file)
{
    size_t max_size = 0;
    size_t size = 0;
    struct group *pinfo = NULL;

    while (file != NULL) {
        if (file->dirent->d_name[0] != '.')
            pinfo = getgrgid(file->stat.st_gid);
        else
            pinfo = NULL;
        if (pinfo != NULL)
            size = my_strlen(pinfo->gr_name);
        if (size > max_size)
            max_size = size;
        file = file->next;
    }
    return (max_size);
}

t_format_size get_file_format_size(t_file *file)
{
    t_format_size format = {get_file_bigger_nblk(file),
        get_bigger_file(file), get_file_bigger_aname(file),
        get_file_bigger_gname(file)};
    return (format);
}