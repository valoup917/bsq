/*
** EPITECH PROJECT, 2020
** main
** File description:
** .
*/

#include <bsq.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 84;
    else if (open_read_file(argv[1]) == 84)
        return 84;
    else
        return 0;
}

int open_read_file(char const *filepath)
{
    struct stat buf;
    char *string;
    int fd = open(filepath, O_RDONLY);
    char **str;

    if (fd == -1)
        return 84;
    if (stat(filepath, &buf) < 0)
        return 84;
    string = malloc(sizeof(char)*(buf.st_size+1));
    if (read(fd, string, buf.st_size) == -1)
        return 84;
    string[buf.st_size] = '\0';
    string = string_to_int(string);
    str = my_str_to_word_array(string);
    the_algorithme(str);
    close(fd);
    free(str);
    return 0;
}

void the_algorithme(char **str)
{
    int nbr_ligne = my_getnbr(str[0]);
    int strlen_ligne = my_strlen(str[1]);
    int **table = char_table_to_int(str);
    char **new;

    table = find_the_square(table, strlen_ligne);
    table = mark_the_square(table, strlen_ligne);
    new = int_to_char(table, strlen_ligne, nbr_ligne);
    print_char(new, nbr_ligne);
    free(new);
}

char **int_to_char(int **table, int strlen_ligne, int nbr_ligne)
{
    char **str = malloc(sizeof(char *)*nbr_ligne);
    for (int i = 0;i < nbr_ligne;i++) {
        str[i] = malloc(sizeof(char)*(strlen_ligne+1));
        str[i] = fill_char(str[i], table[i], strlen_ligne);
    }
    return str;
}

char *fill_char(char *str, int *table, int x)
{
    int j = 0;
    for (; j < x; j++) {
        if (table[j] == -1)
            str[j] = 'x';
        else if (table[j] == 0)
            str[j] = 'o';
        else
            str[j] = '.';
    }
    str[j + 1] = '\0';
    return str;
}