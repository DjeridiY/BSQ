/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-BSQ-yanis.djeridi
** File description:
** replace_coord.c
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "../include/my.h"
#include <stdlib.h>
#include "../include/bsq.h"

int program_find(int result, bsq_struct_t *data, int x, int y)
{
    while (y < data->col) {
        if (data->tab_num[x][y] == result) {
            data->x = x;
            data->y = y;
            return 0;
        }
        y++;
    }
    return 1;
}

int search_coord(int result, bsq_struct_t *data)
{
    int x = 0;
    int y = 0;

    while (x < data->lines) {
            if (program_find(result, data, x, y) == 0) {
                return 0;
            }
        y = 0;
        x++;
    }
}
