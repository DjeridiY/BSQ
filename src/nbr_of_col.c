/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-BSQ-yanis.djeridi
** File description:
** main.c
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "../include/my.h"
#include <stdlib.h>
#include "../include/bsq.h"

int string_to_int(char* stock, int k);

int how_many_col(char **av, bsq_struct_t *data)
{
    int i = data->i + 1;
    char *buffer;
    int b = 0;
    int fd = open(av[1], O_RDONLY);

    buffer = malloc(sizeof(char) * (i));
    read(fd, buffer, i);
    free(buffer);
    while (1) {
        buffer = malloc(sizeof(char) * (2));
        buffer[1] = '\0';
        read(fd, buffer, 1);
        if (buffer[0] != '\n') {
            b++;
            free(buffer);
        } else {
            free(buffer);
            break;
        }
    } data->col = b;
}
