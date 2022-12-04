/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-BSQ-yanis.djeridi
** File description:
** condition_reset.c
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "../include/my.h"
#include <stdlib.h>
#include "../include/bsq.h"
#include "../include/generating_map.h"

int condition_reset(map_struct_t *filling)
{
    if (filling->k == filling->length) {
            filling->k = 0;
        }
}
