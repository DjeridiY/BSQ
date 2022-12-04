/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-BSQ-yanis.djeridi
** File description:
** error_case.c
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "../include/my.h"
#include <stdlib.h>
#include "../include/bsq.h"
#include <unistd.h>

int error_case_av(int ac, char **av)
{
    if (ac == 1) {
        my_printf("%s\n", "NOT ENOUGH ARGUMENT");
        exit (84);
    }
    if (open(av[1], O_RDONLY) < 0) {
        my_printf("%s\n", "THIS FILE DOESN'T EXIST OR ITS NOT ADAPTED");
        exit (84);
    }
}
