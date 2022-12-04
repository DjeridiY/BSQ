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
#include "../include/generating_map.h"

int string_to_int(char* stock, int k);
int get_size(char **av);
int condition_reset(map_struct_t *filling);
char *patern_finder(char **av);

void which_number(map_struct_t *map, int length)
{
    if (map->string[map->k] == '.') {
        map->tab_num[map->i][map->j] = 1;
    }
    if (map->string[map->k] == 'o') {
        map->tab_num[map->i][map->j] = 0;
    }
    map->j++;
    map->k++;
    if (map->k == length) {
        map->k = 0;
    }
}

int **filling_map_int(int **tab_num, char *string, int col)
{
    map_struct_t map;
    map.tab_num = tab_num;
    map.string = string;
    map.i = 0;
    map.j = 0;
    map.k = 0;

    int length = my_strlen(map.string);

    while (map.i < col) {
        while (map.j < col) {
            which_number(&map, length);
        }
        map.j = 0;
        map.i++;
    }
    return map.tab_num;
}

char **filling_map(char **tab, char *string, int col)
{
    map_struct_t filling;
    int i = 0;
    int j = 0;
    filling.k = 0;
    filling.length = my_strlen(string);

    while (tab[i] != 0) {
        while (j < col) {
            tab[i][j] = string[filling.k];
            filling.k++;
            j++;
            condition_reset(&filling);
        }
        j = 0;
        i++;
    }
    return tab;
}

void **generate_tab_char_int(char **av, bsq_struct_t *data)
{
    char *patern = patern_finder(av);
    int size = get_size(av);
    char **tab; int **tab_num;
    data->col = data->lines = size;

    tab = malloc(sizeof(char *) * (data->lines + 1));
    tab[data->lines] = 0;
    tab_num = malloc(sizeof(int *) * (data->lines + 1));
    tab_num[data->lines] = 0;
    for (int i = 0; i < data->lines; i++) {
        tab[i] = malloc(sizeof(char) * (data->col + 1));
        tab[i][data->col] = '\0';
        tab_num[i] = malloc(sizeof(int) * (data->col + 1));
        tab_num[i][data->col] = (-1);
    }
    tab = filling_map(tab, patern, size);
    tab_num = filling_map_int(tab_num, patern, size);
    free(patern);
    data->tab_num = tab_num;
    data->tab = tab;
}
