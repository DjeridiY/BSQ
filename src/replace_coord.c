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

int replace_coord(int result, bsq_struct_t *data)
{
    int i = 0;
    int j = 0;

    while (i < result) {
        while (j < result) {
            data->tab[data->x - i][data->y - j] = 'x';
            j++;
        }
        j = 0;
        i++;
    }
}
