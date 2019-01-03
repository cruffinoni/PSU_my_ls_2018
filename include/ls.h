/*
** EPITECH PROJECT, 2018
** ls.h
** File description:
** Main header file with the structure for the project my_ls.
*/

#ifndef HEADER_SRC_MY_LS
#define HEADER_SRC_MY_LS

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include "errors.h"

typedef struct stat t_stat;
typedef struct dirent t_dirent;

typedef struct s_file_data
{
    char *path;
    t_dirent *dirent;
    t_stat stat;
    struct s_file_data *next;
    struct s_file_data *prev;
} t_file;

typedef struct s_folder_data
{
    char *path;
    DIR *directory;
    struct s_file_data *hfile;
    struct s_folder_data *next;
    struct s_folder_data *prev;
} t_folder;

#endif