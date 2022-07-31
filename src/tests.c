#include <check.h>
#include "lib.h"
obj cordination = {0};
double temp[1024];

START_TEST(test_open_file) {
    int r1 = open_file("./3d/nofile.obj",  &cordination);
    int r2 = open_file("dragon.obj",  &cordination);
    int r3 = open_file2("./3d/nofile.obj",  &cordination);

    cordination.count_veretex = 10;
    cordination.veretex = temp;

    ck_assert_int_eq(r1, 0);
    ck_assert_int_eq(r2, 1);
    ck_assert_int_eq(r3, 0);

    start(&cordination, "dragon.obj");
    ck_assert_double_eq(cordination.count_veretex, 64666);
    finish(&cordination);
}
END_TEST

START_TEST(test_zoom) {
    double zoom_value = 3;

    cordination.count_veretex = 10;
    cordination.veretex = temp;

    zoom_plus(zoom_value, &cordination);
    ck_assert_double_eq(cordination.count_veretex, 10);

    zoom_minus(zoom_value, &cordination);
    ck_assert_double_eq(cordination.count_veretex, 10);
}
END_TEST

START_TEST(input_value_positiv_number) {
    char *test_string1 = "3.5";
    char *test_string2 = "77";
    char *test_string3 = "5.aboba";

    int r1 = check_input_value_positiv_number(test_string1);
    int r2 = check_input_value_positiv_number(test_string2);
    int r3 = check_input_value_positiv_number(test_string3);

    ck_assert_int_eq(r1, 1);
    ck_assert_int_eq(r2, 1);
    ck_assert_int_eq(r3, 0);
}
END_TEST

START_TEST(test_move) {
    double value_move_x = 3;
    double value_move_y = 5;
    double value_move_z = 7;

    int sign = 5;

    cordination.count_veretex = 10;
    cordination.veretex = temp;

    s21_move_x(value_move_x, &cordination, 0);
    ck_assert_double_eq(cordination.count_veretex, 10);
    s21_move_x(value_move_x, &cordination, sign);
    ck_assert_double_eq(cordination.count_veretex, 10);

    s21_move_y(value_move_y, &cordination, 0);
    ck_assert_double_eq(cordination.count_veretex, 10);
    s21_move_y(value_move_y, &cordination, sign);
    ck_assert_double_eq(cordination.count_veretex, 10);

    s21_move_z(value_move_z, &cordination, 0);
    ck_assert_double_eq(cordination.count_veretex, 10);
    s21_move_z(value_move_z, &cordination, sign);
    ck_assert_double_eq(cordination.count_veretex, 10);
}
END_TEST

START_TEST(test_rotate) {
    double value_rotate_x = 3;
    double value_rotate_y = 5;
    double value_rotate_z = 7;

    cordination.count_veretex = 10;
    cordination.veretex = temp;

    s21_rotate_x(value_rotate_x, &cordination);
    ck_assert_double_eq(cordination.count_veretex, 10);
    s21_rotate_y(value_rotate_y, &cordination);
    ck_assert_double_eq(cordination.count_veretex, 10);
    s21_rotate_z(value_rotate_z, &cordination);
    ck_assert_double_eq(cordination.count_veretex, 10);
}
END_TEST

START_TEST(test_correctly_size) {
    cordination.count_veretex = 10;
    cordination.veretex = temp;

    correctly_size(&cordination);
    ck_assert_double_eq(cordination.count_veretex, 10);
}
END_TEST

START_TEST(test_writing_to_file) {
    set st = {0};
    FILE *file = fopen("test.txt", "r");
    double test_value1 = 2.2;
    int test_value2 = 1;

    writing_to_file(&st);
    zapis_double(file, &test_value1);
    zapis_int(file, &test_value2);
    read_file(&st);
    fclose(file);
}
END_TEST

int main() {
    Suite *s1 = suite_create("func_result: ");
    TCase *tc1_1 = tcase_create("original: ");
    SRunner *sr = srunner_create(s1);
    int result;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, test_open_file);
    tcase_add_test(tc1_1, test_zoom);
    tcase_add_test(tc1_1, input_value_positiv_number);
    tcase_add_test(tc1_1, test_move);
    tcase_add_test(tc1_1, test_rotate);
    tcase_add_test(tc1_1, test_correctly_size);
    tcase_add_test(tc1_1, test_writing_to_file);

    srunner_run_all(sr, CK_ENV);
    result = srunner_ntests_failed(sr);
    srunner_free(sr);
    return result == 0 ? 0 : 1;
}
