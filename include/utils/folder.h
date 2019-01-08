/*
** EPITECH PROJECT, 2018
** folder.c
** File description:
** Utils functions for manipulating folders.
*/

#ifndef HEADER_SRC_UTILS_FOLDER
#define HEADER_SRC_UTILS_FOLDER

void display_folders(t_folder *header, t_flags flags);
int count_folder(t_folder *header);
void swap_node_folder(t_folder *node_a, t_folder *node_b);

#endif