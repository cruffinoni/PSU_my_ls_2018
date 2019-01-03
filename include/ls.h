/*
** EPITECH PROJECT, 2018
** ls.h
** File description:
** Main header file with the structure for the project my_ls.
*/

#ifndef HEADER_SRC_MY_LS
#define HEADER_SRC_MY_LS

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include "errors.h"

typedef struct s_file_data
{
    struct dirent stat;
    struct stat stat;
    struct s_file_data *next;
    struct s_file_data *prev;
} t_file;

typedef struct s_folder_data
{
    DIR *directory;
    struct s_file_data *next;
    struct s_file_data *prev;
} t_folder;

#endif