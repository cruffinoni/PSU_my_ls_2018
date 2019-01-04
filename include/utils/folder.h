/*
** EPITECH PROJECT, 2018
** folder.c
** File description:
** Utils functions for manipulating folders..
*/

#ifndef HEADER_SRC_UTILS_FOLDER
#define HEADER_SRC_UTILS_FOLDER

char *get_folder_from_path(char *path);
void display_folders(t_folder *header, t_ls_flags flags);
int count_folder(t_folder *header);

#endif