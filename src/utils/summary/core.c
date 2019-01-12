/*
** EPITECH PROJECT, 2018
** file.c
** File description:
** Summary of different aspects.
*/

#include "ls.h"

t_format_size diff_fsize(t_format_size format1, t_format_size format2)
{
    t_format_size new_format = {0, 0, 0, 0};

    new_format.nblink = format1.nblink > format2.nblink ? format1.nblink :
    format2.nblink;
    new_format.size = format1.size > format2.size ? format1.size :
    format2.size;
    new_format.asize = format1.asize > format2.asize ? format1.asize :
    format2.asize;
    new_format.gsize = format1.gsize > format2.gsize ? format1.gsize :
    format2.gsize;
    return (new_format);
}