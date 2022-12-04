/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-BSQ-yanis.djeridi
** File description:
** my_str_to_int_array.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../include/my.h"
#include "../../include/generating_map.h"

int my_strlen(char const *str);
int my_show_word_array(char *const *tab);

int word_int(const char *str, char selecteur)
{
    int count = 0;
    int i = 0;
    int len = 0;
    char last_char;

    len = my_strlen(str);
    if (len > 0) {
        last_char = str[0];
    }
    for (; i <= len; i++) {
        if ((str[i] == selecteur || str[i] == '\0') && last_char != selecteur) {
            count++;
        }
        last_char = str[i];
    }
    return count;
}

int when_stop_char(map_struct_t *fint, char sel, int lines, char const *str)
{
        if (str[fint->i] == sel) {
            fint->tab_num[fint->k][fint->j] = (-1);
            if (fint->k != lines - 1) {
                fint->k++;
            } else {
                return 1;
            }
            fint->i++;
            fint->j = 0;
        }
        return 0;
}

int **filling_int(char const *str, int **newtab, char selecteur, int lines)
{
    map_struct_t fint;
    fint.i = 0;
    fint.j = 0;
    fint.k = 0;
    fint.tab_num = newtab;

    while (str[fint.i] != '\0') {
        if (when_stop_char(&fint, selecteur, lines, str) == 1)
            break;
        if (str[fint.i] == '.') {
            fint.tab_num[fint.k][fint.j] = 1;
            fint.j++;
        } else {
            fint.tab_num[fint.k][fint.j] = 0;
            fint.j++;
        }
        fint.i++;
    }
    fint.tab_num[fint.k + 1] = 0;
    return (fint.tab_num);
}

int **my_str_to_int_array(char const *str, char selecteur, int col, int lines)
{
    int i = 0;
    int **newtab;
    int length = col;
    int word = lines;

    newtab = malloc(sizeof(int *) * (word + 1));
    newtab[word] = 0;
    while (i < word) {
        newtab[i] = malloc(sizeof(int) * (length + 1));
        if (newtab[i] == NULL) {
            return NULL;
        }
        newtab[i][length] = (-1);
        i++;
    }
    newtab = filling_int(str, newtab, selecteur, word);
    return newtab;
}
