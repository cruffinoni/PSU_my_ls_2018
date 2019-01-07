/*
** EPITECH PROJECT, 2018
** long.c
** File description:
** 'l' flag also known as long listing format
*/

#include <time.h>
#include <sys/types.h>
#include <grp.h>
#include <pwd.h>
#include "my.h"
#include "ls.h"

static void print_file_permissions(t_file *file)
{
    my_putchar(file->dirent->d_type == DT_DIR ? 'd' : '-');
    my_putchar(file->stat.st_mode & S_IRUSR ? 'r' : '-');
    my_putchar(file->stat.st_mode & S_IWUSR ? 'w' : '-');
    my_putchar(file->stat.st_mode & S_IXUSR ? 'x' : '-');
    my_putchar(file->stat.st_mode & S_IRGRP ? 'r' : '-');
    my_putchar(file->stat.st_mode & S_IWGRP ? 'w' : '-');
    my_putchar(file->stat.st_mode & S_IXGRP ? 'x' : '-');
    my_putchar(file->stat.st_mode & S_IROTH ? 'r' : '-');
    my_putchar(file->stat.st_mode & S_IWOTH ? 'w' : '-');
    my_putchar(file->stat.st_mode & S_IXOTH ? 'x' : '-');
}

static char *format_date(t_file *file)
{
    char *str = malloc(sizeof(char) * (11 + 1));
    char *date = ctime(&file->stat.st_mtime);

    if (str == NULL)
        return (NULL);
    for (int i = 4, j = 0; i <= (11 + 4); i++, j++)
        str[j] = date[i];
    str[11 + 1] = '\0';
    return (str);
}

void print_long_format(t_file *file, int longer_size)
{
    struct group *ginfo = getgrgid(file->stat.st_gid);
    struct passwd *pinfo = getpwuid(file->stat.st_gid);
    char *date = format_date(file);

    if (ginfo == NULL || pinfo == NULL || date == NULL)
        return;
    print_file_permissions(file);
    if (file->dirent->d_type != DT_DIR) {
        my_printf(". %i %s %s %*i %s %s\n", file->stat.st_nlink,
        ginfo->gr_name, pinfo->pw_name, longer_size, file->stat.st_size, date,
        file->dirent->d_name);
    }
    else {
        my_printf(". %i %s %s %*i %s \x1B[32m%s\x1B[0m\n", file->stat.st_nlink,
        ginfo->gr_name, pinfo->pw_name, longer_size, file->stat.st_size, date,
        file->dirent->d_name);
    }
}