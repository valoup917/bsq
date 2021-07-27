/*
** EPITECH PROJECT, 2021
** convserion
** File description:
** .
*/

#include <bsq.h>

int **char_table_to_int(char **str)
{
    int x = 0;
    int y = 1;
    int line = number_line(str, NULL);
    int strlen_ligne = my_strlen(str[1]);
    int **table = malloc(sizeof(int *) * line);
    while (x < (line - 1)) {
        table[x] = malloc(sizeof(int) * strlen_ligne);
        table[x] = fill_int(str[y], table[x], strlen_ligne);
        x++;
        y++;
    }
    return table;
}

int *fill_int(char *str, int *table, int x)
{
    for (int j = 0;j < x;j++) {
        if (str[j] == '1')
            table[j] = 1;
        else if (str[j] == '\n' || str[j] == '\0')
            table[j] = -1;
        else
            table[j] = str[j] - '0';
    }
    return table;
}

int number_line(char **str, int **table)
{
    int i = 0;
    if (table == NULL) {
        while (str[i]) {
            i++;
        }
        return i;
    }
    else if (str == NULL) {
        while (table[i]) {
            i++;
        }
        return i;
    }
    else
        return 0;
}

void print_char(char **str, int x)
{
    int i = 0;
    while (i < x) {
        my_putstr(str[i]);
        my_putchar('\n');
        i++;
    }
}

char *string_to_int(char *str)
{
    for (int i = 0;str[i] != '\0';i++) {
        if (str[i] == '.')
            str[i] = '1';
        else if (str[i] == 'o')
            str[i] = '0';
        else if (str[i] == '\n')
            str[i] = '\n';
        else if (str[i] < '9' || str[i] > '1')
            str[i] = str[i];
    }
    return str;
}