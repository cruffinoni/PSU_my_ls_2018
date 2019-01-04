/*
** EPITECH PROJECT, 2018
** folder.h
** File description:
** Creat, edit or delete any node concersing the folders.
*/

#ifndef HEADER_SRC_NODE_FOLDER
#define HEADER_SRC_NODE_FOLDER

int add_folder(t_folder **last_node, char *path, char *original_path,
    t_ls_flags flags);
void display_folders(t_folder *header, t_ls_flags flags);
void delete_folders(t_folder **last_node);
int count_folders(t_folder *header);

#endif