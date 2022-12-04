/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-BSQ-yanis.djeridi
** File description:
** generate_map.c
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

int get_size(char **av)
{
    int length = 0; char *str; int i = 0;

    length = my_strlen(av[1]);
    str = malloc(sizeof(char) * (length + 1));
    str[length] = '\0';
    while (i != length) {
        if (av[1][i] == '-') {
            my_printf("%s\n", "INVALID SIZE");
            exit (84);
        }
        if (av[1][i] >= '0' && av[1][i] <= '9') {
        str[i] = av[1][i];
        i++;
        } else {
            my_printf("%s\n", "INVALID ARGUMENT");
            exit (84);
        }
    }
    int m = string_to_int(str, length);
    free(str); return m;
}
