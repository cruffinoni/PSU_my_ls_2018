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

static void print_file_type(t_file *file)
{
    switch (file->dirent->d_type) {
        case DT_UNKNOWN: my_putchar('?');
        break;
        case DT_LNK: my_putchar('l');
        break;
        case DT_DIR: my_putchar('d');
        break;
        case DT_CHR: my_putchar('c');
        break;
        case DT_FIFO: my_putchar('p');
        break;
        case DT_SOCK: my_putchar('s');
        break;
        case DT_BLK: my_putchar('b');
        break;
        default: my_putchar('-');
    }
}

static void print_file_permissions(t_file *file)
{
    print_file_type(file);
    my_putchar(file->stat.st_mode & S_IRUSR ? 'r' : '-');
    my_putchar(file->stat.st_mode & S_IWUSR ? 'w' : '-');
    my_putchar(file->stat.st_mode & S_IXUSR ? 'x' : '-');
    my_putchar(file->stat.st_mode & S_IRGRP ? 'r' : '-');
    my_putchar(file->stat.st_mode & S_IWGRP ? 'w' : '-');
    my_putchar(file->stat.st_mode & S_IXGRP ? 'x' : '-');
    my_putchar(file->stat.st_mode & S_IROTH ? 'r' : '-');
    my_putchar(file->stat.st_mode & S_IWOTH ? 'w' : '-');
    if (file->stat.st_mode & S_ISVTX)
        my_putchar('T');
    else
        my_putchar(file->stat.st_mode & S_IXOTH ? 'x' : '-');
}

static char *format_date(t_file *file)
{
    char *str = malloc(sizeof(char) * (11 + 2));
    char *date = ctime(&file->stat.st_mtime);

    if (str == NULL)
        return (NULL);
    for (int i = 4, j = 0; i <= (11 + 4); i++, j++)
        str[j] = date[i];
    str[12] = '\0';
    return (str);
}

static int format_folder_name(t_file *file, char *date, t_format_size bsize,
    int force_path)
{
    struct group *ginfo = getgrgid(file->stat.st_gid);
    struct passwd *pinfo = getpwuid(file->stat.st_uid);

    if (ginfo == NULL || pinfo == NULL)
        return (ERR_MALLOC);
    print_file_permissions(file);
    if (force_path)
        my_printf(" %*i %*s %*s %*i %s %s", bsize.nblink, file->stat.st_nlink,
        bsize.gsize, ginfo->gr_name, bsize.asize, pinfo->pw_name, bsize.size,
        file->stat.st_size, date, file->path);
    else
        my_printf(" %*i %*s %*s %*i %s %s", bsize.nblink, file->stat.st_nlink,
        bsize.gsize, ginfo->gr_name, bsize.asize, pinfo->pw_name, bsize.size,
        file->stat.st_size, date, file->dirent->d_name);
    return (ERR_NONE); //
}

void print_lformat_file(t_file *file, t_format_size bsize, int force_path)
{
    char *date = format_date(file);
    char link[256];
    int return_val = readlink(file->path, link, 255);

    if (return_val < 0 && file->dirent->d_type == DT_LNK)
        return;
    link[return_val] = '\0';
    if (date == NULL)
        return;
    if (format_folder_name(file, date, bsize, force_path) != ERR_NONE) {
        free(date);
        return;
    }
    if (file->dirent->d_type == DT_LNK)
        my_printf(" -> %s", link);
    my_putchar('\n');
    free(date);
}