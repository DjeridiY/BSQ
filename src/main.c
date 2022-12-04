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
#include "../include/function_bsq.h"

void free_function(char **tab)
{
    for (int o = 0; tab[o] != 0; o++) {
        free(tab[o]);
    }
    free(tab);
}

void free_function_int(int **tab)
{
    for (int o = 0; tab[o] != NULL; o++) {
        free(tab[o]);
    }
    free(tab);
}

void print_tab(bsq_struct_t *data)
{
    int i = 0;

    while (data->tab[i] != 0) {
        write(1, data->tab[i], data->col);
        write(1, "\n", 1);
        i++;
    }
}

int error_case_too_many(int ac)
{
    if (ac == 1 || ac > 3) {
        my_printf("%s\n", "NUMBER OF ARGUMENT ITS NOT RIGHT");
        exit (84);
    }
}

int main(int ac, char **av)
{
    bsq_struct_t data;
    int fd = 0; int result = 0;
    char *buffer;

    if (ac == 2) {
    error_case_av(ac, av);
    fd = open(av[1], O_RDONLY);
    how_many_lines(fd, &data);
    how_many_col(av, &data);
    file_to_tab(av, &data);
    }
    if (ac == 3)
        generate_tab_char_int(av, &data);
    error_case_too_many(ac);
    result = resolve_map(&data);
    search_coord(result, &data);
    replace_coord(result, &data);
    print_tab(&data);
    free_function_int(data.tab_num);
    free_function(data.tab); close(fd);
}
