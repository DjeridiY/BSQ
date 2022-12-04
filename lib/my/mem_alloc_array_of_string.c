/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-BSQ-yanis.djeridi
** File description:
** mem_alloc_array_of_string.c
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "my.h"

char **mem_alloc_2d_array(int nb_rows , int nb_cols)
{
    int i = 0;
    char **tab;
    tab = malloc(sizeof(char *) * (nb_cols + 1));
    tab[nb_cols + 1] = NULL;

    while (i < nb_cols) {
        tab[i] = malloc(sizeof(char) * (nb_rows + 1));
        tab[i] = '\0';
        i++;
    }
    return tab;
}
