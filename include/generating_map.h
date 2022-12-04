/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** header prototype function
*/

#ifndef MAP_H_
    #define MAP_H_

typedef struct map {
    int **tab_num;
    char **tab;
    char *string;
    int k;
    int i;
    int j;
    int length;
} map_struct_t;

#endif /* MAP_H_ */
