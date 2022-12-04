/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-BSQ-yanis.djeridi
** File description:
** resolve_map.c
*/

#include "../include/bsq.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "../include/my.h"
#include <stdlib.h>

int min_coord(int **memory, int i, int j)
{
    int right = memory[i][j - 1];
    int down = memory[i - 1][j];
    int down_right = memory[i - 1][j - 1];

    if (right < down && right < down_right) {
        return (right);
    } else if (down < down_right) {
        return (down);
    } else {
        return (down_right);
    }
}

int find_biggest_square(int **memory, int i, int j, int result)
{
    if (i == 0 || j == 0) {
        } else if (memory[i][j] > 0) {
            memory[i][j] = 1 + min_coord(memory, i, j);
        }
        if (memory[i][j] > result) {
            result = memory[i][j];
        }
    return result;
}

int resolve_map(bsq_struct_t *data)
{

    int **memory = data->tab_num;
    int result = 0;
    int i = 0;
    int j = 0;

    while (i < data->lines) {
        while (j < data->col) {
            result = find_biggest_square(memory, i, j, result);
            j++;
        }
        j = 0;
        i++;
    }
    return result;
}
