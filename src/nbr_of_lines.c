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

int error_begining(char *buffer, char *first_line, int i)
{
        if (buffer[0] >= '0' && buffer[0] <= '9') {
        my_strcat(first_line, buffer);
        free(buffer); i++;
        } else {
            my_printf("%s\n", "SIZE OF THE MAP IS NOT A NUMBER");
            exit (84);
        }
        return i;
}

int how_many_lines(int fd, bsq_struct_t *data)
{
    int i = 0;
    char *buffer;
    char *first_line = malloc(sizeof(char) * (12));
    first_line[0] = '\0';
    int lines = 0;

    while (1) {
        buffer = malloc(sizeof(char) * (2));
        buffer[1] = '\0';
        read(fd, buffer, 1);
        if (buffer[0] == '\n') {
            free(buffer);
            break;
        }
        i = error_begining(buffer, first_line, i);
    }
    data->lines = string_to_int(first_line , i);
    data->i = i;
    free(first_line);
}
