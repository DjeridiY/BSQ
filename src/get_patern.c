/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-BSQ-yanis.djeridi
** File description:
** get_patern.c
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

char *get_patern(char **av)
{
    int i = 0;

    int test = my_strlen(av[2]);
    char *string = malloc(sizeof(char) * (test + 1));
    string[test] = '\0';
    while (i != test) {
        string[i] = av[2][i];
        i++;
    }
    return string;
}

char *patern_finder(char **av)
{
    char *patern = get_patern(av);
    int p = 0;

    if (my_strlen(patern) == 0)
        exit (84);
    while (patern[p] != '\0') {
        if (patern[p] != '\0' && patern[p] != 'o' &&
            patern[p] != '.' && patern[p] != '\n' ) {
                my_printf("%s\n", "CHARACTER NOT ALLOWED");
                exit (84);
        }
        p++;
    }
    return patern;
}
