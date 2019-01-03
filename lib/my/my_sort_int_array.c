/*
** EPITECH PROJECT, 2018
** my_sort_array.c
** File description:
** Function that sorts an integer array in ascending order.
*/

void my_sort_int_array(int *array, int size)
{
    int var = 0;
    int j = 0;

    for (int i = 1; i < size; i++) {
        var = array[i];
        for (j = i; j > 0 && array[j - 1] > var; j--)
            array[j] = array[j - 1];
        array[j] = var;
    }
}