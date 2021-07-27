/*
** EPITECH PROJECT, 2020
** include bsq
** File description:
** .
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*LIB*/
void my_putchar(char c);
int my_putstr(char const *str);
int my_getnbr(char *str);
char **my_str_to_word_array(char *str);
int my_strlen(char const *str);

/*MAIN*/
int open_read_file(char const *filepath);
void the_algorithme(char **str);
char **int_to_char(int **table, int strlen_ligne, int nbr_ligne);
char *fill_char(char *str, int *table, int x);

/*STEP1*/
int **find_the_square(int **table, int strlen_ligne);
int find_the_minim(int a, int b, int c);
int new_number(int a, int b, int c, int d);
int **mark_the_square(int **table, int x);
int find_the_max(int **table, int x);

/*CONVERSION*/
char *string_to_int(char *str);
int **char_table_to_int(char **str);
int number_line(char **str, int **table);
int *fill_int(char *str, int *table, int x);
void print_char(char **str, int x);