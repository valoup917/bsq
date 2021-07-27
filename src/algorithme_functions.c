/*
** EPITECH PROJECT, 2020
** step 1
** File description:
** .
*/

#include <bsq.h>

int **mark_the_square(int **table, int x)
{
    int max = find_the_max(table, x);
    int a = 0;
    int b = 0;
    int b2 = b;

    for (;table[a];b++) {
        if (b == x) {
            a++;
            b = 0;
        } if (table[a][b] == max)
            break;
    }
    for (int i = 0; i != max; i++) {
        b2 = b;
        for (int j = 0; j != max;j++) {
            table[a][b2] = -1;
            b2 = b2 - 1;
        }
        a = a - 1;
    }
    return table;
}

int find_the_max(int **table, int x)
{
    int max = 0;
    int i = 0;

    while (table[i]) {
        for (int n = 0;n < x;n++)
            if (table[i][n] > max)
                max = table[i][n];
        i++;
    }
    return max;
}

int **find_the_square(int **table, int strlen_ligne)
{
    int a;
    int b;
    int c;
    int d;

    int line = number_line(NULL, table);

    for (int x = 1;x < line;x++) {
        for (int y = 1;y < strlen_ligne;y++) {
            a = table[x - 1][y - 1];
            b = table[x - 1][y];
            c = table[x][y - 1];
            d = table[x][y];
            table[x][y] = new_number(a, b, c, d);
        }
    }
    return table;
}

int new_number(int a, int b, int c, int d)
{
    int new = 0;
    int minimum = find_the_minim(a, b, c);
    if (d == 0)
        return 0;
    else
        new = d + minimum;
    return new;
}

int find_the_minim(int a, int b, int c)
{
    if (a <= b && a <= c)
        return a;
    if (b <= a && b <= c)
        return b;
    if (c <= a && c <= b)
        return c;
    if (c == a && a == b)
        return a;
    return 0;
}