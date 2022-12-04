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
#include <sys/stat.h>
#include "../include/bsq.h"

int string_to_int(char* stock, int k);
char **mem_alloc_2d_array(int nb_rows , int nb_cols);
int **my_str_to_int_array(char const *str, char selecteur, int col, int lines);
char **my_str_to_char_array(char const *str, char selecteur,
int col, int lines);

int error_case_character(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] != '\0' && str[i] != 'o' &&
        str[i] != '.' && str[i] != '\n' ) {
            my_printf("%s\n", "FILE DOESN'T HAVE RIGHT ARGUMENT IN");
            exit (84);
        }
        i++;
    }
}

int error_case_empty(char *buffer)
{
    if (buffer == NULL) {
        my_printf("%s\n", "THIS FILE IS EMPTY");
        exit (84);
    }
}

int skip_first_line(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\n') {
        if (buffer[i] >= '0' && buffer[i] <= '9') {
        i++;
        } else {
            my_printf("%s\n", "THE FILE DOESN'T HAVE THE RIGHT FORMATING");
        }
    }
    return i + 1;
}

int error_in_file(char *buffer, int m, bsq_struct_t *data)
{
    if (my_strlen(buffer + m) != (data->col * data->lines + data->lines)) {
        my_printf("%s\n", "ERROR IN FILE");
        exit (84);
    }
}

int file_to_tab(char **av, bsq_struct_t *data)
{
    struct stat sb; stat(av[1], &sb);
    int m = 0; int b = 0;
    int i = data->i + 1;
    int nbr_of_char = sb.st_size;
    int fd = open(av[1], O_RDONLY);
    int **tab; char **tab_char;
    char *buffer = malloc(sizeof(char) * (nbr_of_char + 2));

    buffer[nbr_of_char + 1] = '\0';
    read(fd, buffer, (nbr_of_char));
    error_case_empty(buffer);
    m = skip_first_line(buffer);
    error_case_character(buffer + m);
    error_in_file(buffer, m, data);
    tab = my_str_to_int_array(buffer + m, '\n', data->col, data->lines);
    tab_char = my_str_to_char_array(buffer + m, '\n', data->col, data->lines);
    free(buffer);
    data->tab_num = tab;
    data->tab = tab_char;
    close(fd);
}
