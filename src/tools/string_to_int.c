/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-BSQ-yanis.djeridi
** File description:
** string_to_int.c
*/

int string_to_int(char* stock, int k)
{
    int number = 0;
    int i = 1;
    int m = 0;

    k = k - 1;
    while (k >= 0) {
        number = stock[k];
        number = number - 48;
        m = m + (number * i);
        i = i * 10;
        k--;
    }
    return m;
}
