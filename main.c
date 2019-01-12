/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main file for the project my_ls.
*/

#include <string.h>
#include "my.h"
#include "ls.h"
#include "node.h"
#include "parse.h"
#include "flags/reverse.h"
#include "flags/time.h"
#include "flags/directory.h"
#include "utils/file/file.h"
#include "utils/summary/core.h"

static void operand_flags(t_folder **main, t_folder **file, t_flags flags)
{
    if (flags & FLAG_t) {
        sort_by_time(main, flags);
        sort_by_time(file, flags);
    }
    if (flags & FLAG_r) {
        reverse_all_folder_content(main);
        reverse_all_folder_content(file);
    }
}

static void display_results(t_folder **main, t_folder **file, t_flags flags)
{
    t_format_size folder_size = get_folder_format_size(*main);
    t_format_size file_size = get_file_format_size((*file)->hfile);
    t_format_size bigger = diff_fsize(folder_size, file_size);

    if (flags & FLAG_d) {
        display_files_title((*file)->hfile, flags, bigger);
        display_folders_title(*main, flags, bigger);
        return;
    }
    flags |= FLAGI_f;
    display_files((*file)->hfile, flags);
    if ((*file)->hfile != NULL && *main != NULL)
        my_putchar('\n');
    else
        flags &= ~FLAGI_f;
    display_folders(*main, flags);
}

int main(int ac, char **av)
{
    t_folder *header = NULL;
    t_folder *inline_file = malloc(sizeof(t_folder));
    t_flags flags = 0;

    if (inline_file == NULL)
        return (ERR_INIT);
    flags = detect_flags(av, ac);
    if (detect_folders(&header, &inline_file, &flags, av, ac) != ERR_NONE)
        return (ERR_INIT);
    operand_flags(&header, &inline_file, flags);
    display_results(&header, &inline_file, flags);
    delete_folders(&header);
    free_files(&inline_file->hfile);
    free(inline_file);
    return (ERR_NONE);
}