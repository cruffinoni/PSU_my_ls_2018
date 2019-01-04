/*
** EPITECH PROJECT, 2018
** file.h
** File description:
** Creat, edit or delete any node concersing files.
*/

#ifndef HEADER_SRC_NODE_FILE
#define HEADER_SRC_NODE_FILE

int add_file(t_file **last_node, t_dirent *dirent, t_stat stat);
int read_files(t_folder *folder);
void display_files(t_file *header, t_display_flags flags);
void free_files(t_file **header);

#endif