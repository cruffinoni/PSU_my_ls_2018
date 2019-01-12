/*
** EPITECH PROJECT, 2018
** directory.c
** File description:
** 'd' flag also known for listing only directory (and files?)
*/

#ifndef HEADER_SRC_FLAGS_DIRECTORY
#define HEADER_SRC_FLAGS_DIRECTORY

#include "ls.h"

void display_files_title(t_file *header, t_flags flags, t_format_size format);
void display_folders_title(t_folder *header, t_flags flags,
    t_format_size format);

#endif