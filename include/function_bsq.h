/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** header prototype function
*/

#include "bsq.h"

#ifndef FUNCTION_BSQ_H_
    #define FUNCTION_BSQ_H_

int how_many_lines(int fd, bsq_struct_t *data);
int how_many_col(char **av, bsq_struct_t *data);
int file_to_tab(char **av, bsq_struct_t *data);
int resolve_map(bsq_struct_t *data);
int search_coord(int result, bsq_struct_t *data);
int replace_coord(int result, bsq_struct_t *data);
int error_case_av(int ac, char **av);
void **generate_tab_char(char **av, bsq_struct_t *data);
void **generate_tab_char_int(char **av, bsq_struct_t *data);

#endif /* FUNCTION_BSQ_H_ */
