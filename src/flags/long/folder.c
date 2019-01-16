/*
** EPITECH PROJECT, 2018
** long.c
** File description:
** 'l' flag also known as long listing format
*/

#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <grp.h>
#include <pwd.h>
#include "my.h"
#include "ls.h"

static void print_file_permissions(t_folder *folder)
{
    my_putchar('d');
    my_putchar(folder->stat.st_mode & S_IRUSR ? 'r' : '-');
    my_putchar(folder->stat.st_mode & S_IWUSR ? 'w' : '-');
    my_putchar(folder->stat.st_mode & S_IXUSR ? 'x' : '-');
    my_putchar(folder->stat.st_mode & S_IRGRP ? 'r' : '-');
    my_putchar(folder->stat.st_mode & S_IWGRP ? 'w' : '-');
    my_putchar(folder->stat.st_mode & S_IXGRP ? 'x' : '-');
    my_putchar(folder->stat.st_mode & S_IROTH ? 'r' : '-');
    my_putchar(folder->stat.st_mode & S_IWOTH ? 'w' : '-');
    my_putchar(folder->stat.st_mode & S_IXOTH ? 'x' : '-');
}

static char *format_date(t_folder *folder)
{
    char *str = malloc(sizeof(char) * (11 + 2));
    char *date = ctime(&folder->stat.st_mtime);

    if (str == NULL)
        return (NULL);
    for (int i = 4, j = 0; i <= (11 + 4); i++, j++)
        str[j] = date[i];
    str[12] = '\0';
    return (str);
}

static int format_folder_name(t_folder *folder, char *date,
    t_format_size bsize)
{
    struct group *ginfo = getgrgid(folder->stat.st_gid);
    struct passwd *pinfo = getpwuid(folder->stat.st_uid);

    if (ginfo == NULL || pinfo == NULL)
        return (ERR_MALLOC);
    print_file_permissions(folder);
        my_printf(". %i %s %s %i %s %s", folder->stat.st_nlink, ginfo->gr_name,
            pinfo->pw_name, folder->stat.st_size, date, folder->original_path);
    return (ERR_NONE);
}

void print_lformat_folder(t_folder *folder, t_format_size bsize)
{
    char *date = format_date(folder);

    if (date == NULL)
        return;
    if (format_folder_name(folder, date, bsize) != ERR_NONE) {
        free(date);
        return;
    }
    my_putchar('\n');
    free(date);
}