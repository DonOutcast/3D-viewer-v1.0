#ifndef SRC_LIB_H_
#define SRC_LIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#define SIZE 1000
#define CORRECTLY 1
#define ERROR 0

typedef struct obg {
    unsigned int count_veretex;
    double *veretex;
    unsigned int count_index;
    unsigned int *index;
}obj;

typedef struct settings {
     double red;
     double green;
     double blue;
     double redl;
     double greenl;
     double bluel;
     double redv;
     double greenv;
     double bluev;
     int projection_type;
     int line_type;
     int vert_type;
     int vert_size;
     double thickness;
} set;

int open_file(char *path, obj *cordination);
int check_v(char *str);
int check_input_value(const char *str_x);
int check_f(char *str);
int check_number_top(char *str);
int open_file2(char *path, obj *cordination);
void parsing_v(char *str, obj *coordination, int *k);
void parsing_f(char *str, obj *coordination, int *l);
void start(obj *coordination, char *path);
void zoom_plus(double value_zoom, obj *coordination);
void zoom_minus(double value_zoom, obj *coordination);
int check_input_value_positiv_number(char *str_x);
void s21_move_x(double value_move_x, obj *coordination, int sign);
void s21_move_y(double value_move_y, obj *coordination, int sign);
void s21_move_z(double value_move_z, obj *coordination, int sign);
void s21_rotate_x(double value_rotate_x, obj *coordination);
void s21_rotate_y(double value_rotate_y, obj *coordination);
void s21_rotate_z(double value_rotate_z, obj *coordination);
void correctly_size(obj *coordination);
void writing_to_file(set *info);
int read_file(set *info);
void zapis_double(FILE *f, double *s);
void zapis_int(FILE *f, int *s);
void finish(obj *coordination);

#endif  // SRC_LIB_H_
