#include "lib.h"

void start(obj *cordination , char *path) {
    if (open_file(path, cordination)) {
        cordination->veretex = (double *) calloc(cordination->count_veretex * 3 , sizeof(double));
        cordination->index = (unsigned int *) calloc(cordination->count_index , sizeof(unsigned int));
        if (open_file2(path, cordination)) {
            correctly_size(cordination);
        }
    }
}

void finish(obj *coordination) {
    if (coordination->count_veretex) {
        free(coordination->veretex);
        coordination->veretex = NULL;
    }
    if (coordination->index) {
        free(coordination->index);
        coordination->index = NULL;
    }
}

int open_file(char *path, obj *cordination) {
    int res_code = 1;
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("No such file or dirictory\n");
        res_code = 0;
    } else {
        char str[SIZE];
        while (fgets(str, SIZE - 1, file)) {
            if ((str[strlen(str) - 1] == '\n') || (str[strlen(str) - 1] == 13))
                str[strlen(str) - 1] = '\0';
            if (check_v(str)) {
                cordination->count_veretex++;
            }
            if (check_f(str)) {
                cordination->count_index += check_f(str);
            }
        }
        fclose(file);
    }
    cordination->count_index *= 2;
    return res_code;
}

int check_v(char *str) {
    int res_code = ERROR;
    if (str[0] == 'v' && str[1] == ' ') {
        res_code = CORRECTLY;
        int j = 0;
        for (size_t i = 2; i < strlen(str); i++) {
            char tmp[SIZE];
            while (((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-' ||
            str[i] == '.') && i < strlen(str)) {
                tmp[j] = str[i];
                j++;
                i++;
            }
            tmp[j] = '\0';
            if (!check_input_value(tmp)) {
                res_code = ERROR;
                break;
            }
            j = 0;
        }
    }
    return res_code;
}

int check_input_value(const char *str_x) {
    int res_code = 1;
    int i = 0, flag_point = 0;
    while (str_x[i] != '\0') {
        if ((str_x[i] == '+' || str_x[i] == '-') && i != 0) {
            res_code = 0;
        } else if (str_x[i] < '0' && str_x[i] != '+' && str_x[i] != '-' && str_x[i] != '.') {
            res_code = 0;
        } else if (str_x[i] > '9') {
            res_code = 0;
        }
        if (str_x[i] == '.') {
            if (flag_point) {
                res_code = 0;
            }
            if (str_x[i - 1] == '+' || str_x[i - 1] == '-') {
                res_code = 0;
            }
            flag_point = 1;
        }
        i++;
    }
    return res_code;
}
int check_f(char *str) {
    int count = 0;
    if (str[0] == 'f' && str[1] == ' ') {
        char tmp[SIZE];
        int j = 0;
        for (size_t i = 2; i < strlen(str); i++) {
            while (((str[i] >= '0' && str[i] <= '9') || str[i] == '/') && i < strlen(str)) {
                tmp[j] = str[i];
                j++;
                i++;
            }
            tmp[j] = '\0';
            if (check_number_top(tmp)) {
                count++;
            } else {
                count = 0;
                break;
            }
            j = 0;
        }
    }
    return count;
}

int check_number_top(char *str) {
    int res_code = CORRECTLY;
    size_t i = 0, countslash = 0;
    while (str[i]) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '/') {
            res_code = ERROR;
        }
        if (str[i] == '/') {
            countslash++;
        }
        if (countslash > 2) {
            res_code = ERROR;
            break;
        }
        i++;
    }
    return res_code;
}

int open_file2(char *path, obj *cordination) {
    int res_code = 1;
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("No such file or dirictory\n");
        res_code = 0;
    } else {
        char str[SIZE];
        int k = 0, l = 0;
        while (fgets(str, SIZE - 1, file)) {
            if (str[strlen(str) - 1] == '\n')
                str[strlen(str) - 1] = '\0';
            if (check_v(str)) {
                parsing_v(str, cordination, &k);
            }
            if (check_f(str)) {
                parsing_f(str, cordination, &l);
            }
        }
    fclose(file);
    }
    return res_code;
}

void parsing_v(char *str, obj *coordination, int *k) {
    int j = 0, marker = 0;
    double s1 = 0;
    for (size_t i = 2; i < strlen(str); i++) {
        char tmp[SIZE];
        while (i < strlen(str)   && (str[i] != ' ')) {
            tmp[j] = str[i];
            j++;
            i++;
            marker = 1;
        }
        if (marker) {
            tmp[j] = '\0';
            sscanf(tmp, "%lf", &s1);
            coordination->veretex[*k] = s1;
            (*k)++;
            j = 0;
        }
    }
}
void parsing_f(char *str, obj *coordination, int *l) {
    int j = 0, count = 0, flag = 0, f = 0;
    double s1 = 0, s = 0;
    for (size_t i = 2; i < strlen(str); i++) {
        int marker = 0;
        char tmp[SIZE];
        while (((str[i] >= '0' && str[i] <= '9') || str[i] == '/') && i < strlen(str)) {
            tmp[j] = str[i];
            j++;
            i++;
            marker = 1;
        }
        if (marker) {
            char tmp2[SIZE];
            count++;
            tmp[j] = '\0';
            j = 0;
            for (size_t k = 0; k < strlen(tmp); k++) {
                if (tmp[k] == '/')
                    flag = 1;
            }
            if (flag) {
                while (tmp[j] != '/') {
                    tmp2[j] = tmp[j];
                    j++;
                }
            } else {
                while (tmp[j]) {
                    tmp2[j] = tmp[j];
                    j++;
                }
            }
            tmp2[j] = '\0';
            sscanf(tmp2, "%lf", &s1);
            coordination->index[*l] = s1 - 1;
            (*l)++;
            if (count > 1) {
                coordination->index[*l] = s1 - 1;
                      (*l)++;
            }
            if (count == 1) {
                sscanf(tmp2, "%lf", &s);
                f = 1;
            }
            j = 0;
            flag = 0;
        }
    }
    if (f) {
        coordination->index[*l] = s - 1;
        (*l)++;
    }
}

void correctly_size(obj *coordination) {
    double max = fabs(coordination->veretex[0]);
    for (unsigned int i = 0; i < coordination->count_veretex * 3; i++) {
        if (fabs(coordination->veretex[i]) > max)
            max = fabs(coordination->veretex[i]);
    }
    if (max > 1) {
        for (unsigned int i = 0; i < coordination->count_veretex * 3; i++) {
            coordination->veretex[i] *= 0.9 / max;
        }
    } else if (max < 1) {
        int k = 1 / max;
        for (unsigned int i = 0; i < coordination->count_veretex * 3; i++) {
            coordination->veretex[i] *= k;
        }
    }
}

void zoom_plus(double value_zoom, obj *coordination) {
        for (unsigned i = 0; i < coordination->count_veretex * 3; i++) {
        coordination->veretex[i] *= value_zoom;
    }
}
void zoom_minus(double value_zoom, obj *coordination) {
        for (unsigned i = 0; i < coordination->count_veretex * 3; i++) {
        coordination->veretex[i] /= value_zoom;
    }
}

int check_input_value_positiv_number(char *str_x) {
    int res_code = 1;
    int i = 0, flag_point = 0;
    while (str_x[i]) {
        if (str_x[i] < '0' && str_x[i] != '.') {
            res_code = 0;
        } else if (str_x[i] > '9') {
            res_code = 0;
        }
        if (str_x[i] == '.') {
            if (flag_point) {
                res_code = 0;
            }
            if (i == 0) {
                res_code = 0;
            }
            flag_point = 1;
        }
        i++;
    }
    return res_code;
}

void s21_move_x(double value_move_x, obj *coordination, int sign) {
    for (unsigned i = 0; i < coordination->count_veretex * 3; i++) {
        if (i % 3 == 0) {
            if (sign)
                coordination->veretex[i] += value_move_x;
            else
                coordination->veretex[i] -= value_move_x;
        }
    }
}

void s21_move_y(double value_move_y, obj *coordination, int sign) {
    for (unsigned i = 0; i < coordination->count_veretex * 3; i++) {
        if (i % 3 == 1) {
            if (sign)
                coordination->veretex[i] += value_move_y;
            else
                coordination->veretex[i] -= value_move_y;
        }
    }
}

void s21_move_z(double value_move_z, obj *coordination, int sign) {
    for (unsigned i = 0; i < coordination->count_veretex * 3; i++) {
        if (i % 3 == 2) {
            if (sign)
                coordination->veretex[i] += value_move_z;
            else
                coordination->veretex[i] -= value_move_z;
        }
    }
}

void s21_rotate_x(double value_rotate_x, obj *coordination) {
    for (unsigned i = 0; i < coordination->count_veretex * 3; i++) {
        if (i % 3 == 0) {
            double tmp_y = coordination->veretex[i + 1];
            double tmp_z = coordination->veretex[i + 2];
                coordination->veretex[i + 1] = cos(value_rotate_x) * tmp_y + sin(value_rotate_x) * tmp_z;
                coordination->veretex[i + 2] = -sin(value_rotate_x) * tmp_y + cos(value_rotate_x) * tmp_z;
        }
    }
}

void s21_rotate_y(double value_rotate_y, obj *coordination) {
    for (unsigned i = 0; i < coordination->count_veretex * 3; i++) {
        if (i % 3 == 0) {
            double tmp_x = coordination->veretex[i];
            double tmp_z = coordination->veretex[i + 2];
            coordination->veretex[i] = cos(value_rotate_y) * tmp_x + sin(value_rotate_y) * tmp_z;
            coordination->veretex[i + 2] = -sin(value_rotate_y) * tmp_x + cos(value_rotate_y) * tmp_z;
        }
    }
}

void s21_rotate_z(double value_rotate_z, obj *coordination) {
    for (unsigned i = 0; i < coordination->count_veretex * 3; i++) {
        if (i % 3 == 0) {
            double tmp_x = coordination->veretex[i];
            double tmp_y = coordination->veretex[i + 1];
            coordination->veretex[i] = cos(value_rotate_z) * tmp_x - sin(value_rotate_z) * tmp_y;
            coordination->veretex[i + 1] = sin(value_rotate_z) * tmp_x + cos(value_rotate_z) * tmp_y;
        }
    }
}

void writing_to_file(set *info) {
    FILE *f;
    f = fopen("settings.txt", "w");
    fprintf(f, "%lf\n", info->red);
    fprintf(f, "%lf\n", info->green);
    fprintf(f, "%lf\n", info->blue);
    fprintf(f, "%lf\n", info->redl);
    fprintf(f, "%lf\n", info->greenl);
    fprintf(f, "%lf\n", info->bluel);
    fprintf(f, "%lf\n", info->redv);
    fprintf(f, "%lf\n", info->greenv);
    fprintf(f, "%lf\n", info->bluev);
    fprintf(f, "%d\n", info->projection_type);
    fprintf(f, "%d\n", info->line_type);
    fprintf(f, "%d\n", info->vert_type);
    fprintf(f, "%d\n", info->vert_size);
    fprintf(f, "%lf\n", info->thickness);
    fclose(f);
}

void zapis_double(FILE *f, double *s) {
    char str[100];
    fgets(str, 100 - 1, f);
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
    sscanf(str, "%lf", s);
}

void zapis_int(FILE *f, int *s) {
    char str[100];
    fgets(str, 100 - 1, f);
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
    sscanf(str, "%d", s);
}
int read_file(set *info) {
    double s = 0;
    int s1 = 0, marker = 1;
    FILE *f;
    if ((f = fopen("settings.txt", "r")) == NULL) {
        marker = 0;
    } else {
        zapis_double(f, &s);
        info->red = s;
        zapis_double(f, &s);
        info->green = s;
        zapis_double(f, &s);
        info->blue = s;
        zapis_double(f, &s);
        info->redl = s;
        zapis_double(f, &s);
        info->greenl = s;
        zapis_double(f, &s);
        info->bluel = s;
        zapis_double(f, &s);
        info->redv = s;
        zapis_double(f, &s);
        info->greenv = s;
        zapis_double(f, &s);
        info->bluev = s;
        zapis_int(f, &s1);
        info->projection_type = s1;
        zapis_int(f, &s1);
        info->line_type = s1;
        zapis_int(f, &s1);
        info->vert_type = s1;
        zapis_int(f, &s1);
        info->vert_size = s1;
        zapis_double(f, &s);
        info->thickness = s;
        fclose(f);
    }
    return marker;
}


// int main() {
// obj cordination = {0};
// start(&cordination, "/Users/richesse/Downloads/Logo_S21.obj");
// int num = cordination.count_veretex * 3;
// for (int i = 0; i < num; i++)
// printf("%f\n", cordination.veretex[i]);
// for (unsigned int j = 0; j < cordination.count_index; j++) {
// printf("%d\n", cordination.index[j]);
// printf("c %d\n", cordination.index[j]);
// }
// finish(&cordination);
//     return 0;
// }
