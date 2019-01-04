/*
** EPITECH PROJECT, 2018
** reverse.h
** File description:
** 'r' flag also known as reverse.
*/

#include "my.h"
#include "ls.h"
#include "node/file.h"

static void reverse_folder_order(t_folder **header)
{
    t_folder *next_node = *header;
    t_folder *current = *header;
    t_folder *tempo = NULL;

    while (next_node != NULL) {
        current = next_node;
        next_node = next_node->next;
        tempo = current->prev;
        current->prev = current->next;
        current->next = tempo;
    }
    *header = current;
}

static void reverse_file_order(t_file **header)
{
    t_file *next_node = *header;
    t_file *current = *header;
    t_file *tempo = NULL;

    while (next_node != NULL) {
        current = next_node;
        next_node = next_node->next;
        tempo = current->prev;
        current->prev = current->next;
        current->next = tempo;
    }
    *header = current;
}

void reverse_all_folder_content(t_folder **header)
{
    t_folder *next_node = NULL;

    reverse_folder_order(header);
    next_node = *header;
    while (next_node != NULL) {
        reverse_file_order(&next_node->hfile);
        next_node = next_node->next;
    }
}