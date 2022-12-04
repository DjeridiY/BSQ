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

int word_char(const char *str, char selecteur)
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

int when_stop(map_struct_t *fill, char selecteur, int lines, char const *str)
{
        if (str[fill->i] == selecteur) {
            fill->tab[fill->k][fill->j] = '\0';
            if (fill->k != lines - 1) {
                fill->k++;
            } else {
                return 1;
            }
            fill->i++;
            fill->j = 0;
        }
        return 0;
}

char **filling_char(char const *str, char **newtab, char selecteur, int lines)
{
    map_struct_t fill;
    fill.i = 0;
    fill.j = 0;
    fill.k = 0;
    fill.tab = newtab;

    while (str[fill.i] != '\0') {
        if (when_stop(&fill, selecteur, lines, str) == 1) {
            break;
        }
        fill.tab[fill.k][fill.j] = str[fill.i];
        fill.j++;
        fill.i++;
    }
    fill.tab[fill.k + 1] = 0;
    return (fill.tab);
}

char **my_str_to_char_array(char const *str, char selecteur, int col, int lines)
{
    int i = 0;
    char **newtab;
    int length = col;
    int word = lines;

    newtab = malloc(sizeof(char *) * (word + 1));
    if (newtab == NULL) {
        return NULL;
    }
    newtab[word] = 0;
    while (i < word) {
        newtab[i] = malloc(sizeof(char) * (length + 1));
        if (newtab[i] == NULL) {
            return NULL;
        }
        newtab[i][length] = '\0';
        i++;
    }
    newtab = filling_char(str, newtab, selecteur, word);
    return newtab;
}
