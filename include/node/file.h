/*
** EPITECH PROJECT, 2018
** file.h
** File description:
** Creat, edit or delete any node concersing files.
*/

#ifndef HEADER_SRC_NODE_FILE
#define HEADER_SRC_NODE_FILE

int read_files(t_folder *folder, t_ls_flags flags);
void free_files(t_file **header);

#endif