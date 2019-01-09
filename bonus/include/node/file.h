/*
** EPITECH PROJECT, 2018
** file.h
** File description:
** Creat, edit or delete any node concersing files.
*/

#ifndef HEADER_SRC_NODE_FILE
#define HEADER_SRC_NODE_FILE

int read_files(t_folder *folder, t_flags flags);
void free_files(t_file **header);
int add_file(t_folder *folder, t_dirent *dirent, t_flags flags, char *path);
int add_manually_file(t_folder *ptr, DIR *dir, char *folder, t_flags flags);

#endif