/*
** EPITECH PROJECT, 2018
** ls.h
** File description:
** Main header file with the structure for the project my_ls.
*/

#ifndef HEADER_SRC_MY_LS
#define HEADER_SRC_MY_LS

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include "errors.h"

typedef struct stat t_stat;
typedef struct dirent t_dirent;

typedef struct s_file_data {
    DIR *parent_dir;
    char *path;
    t_dirent *dirent;
    t_stat stat;
    struct s_file_data *next;
    struct s_file_data *prev;
    struct s_folder_data *subf;
} t_file;

typedef struct s_folder_data {
    DIR *directory;
    char *path;
    char *original_path;
    t_stat stat;
    struct s_file_data *hfile;
    struct s_folder_data *next;
    struct s_folder_data *prev;
} t_folder;

typedef enum e_display_flags {
    FLAG_l = 0b1,
    FLAG_R = 0b10,
    FLAG_d = 0b100,
    FLAG_r = 0b1000,
    FLAG_t = 0b10000,
    FLAGI_f = 0b100000,
    FLAGI_af = 0b1000000
} t_flags;

typedef struct s_long_format_size
{
    size_t nblink;
    size_t size;
    size_t asize;
    size_t gsize;
} t_format_size;

#endif