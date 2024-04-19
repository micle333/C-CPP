/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "smart_calc.check" instead.
 */

#include <check.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <complex.h>
#include <string.h>
#include "untitled_try/smart_calc.h"

START_TEST(s21_smart_calc_1)
{
const char * mainString = "2+2";
ck_assert_str_eq("4", s21_smart_calc(mainString, 99.9));

}
END_TEST

START_TEST(s21_smart_calc_2)
{
const char * mainString = "-2+2";
ck_assert_str_eq("0", s21_smart_calc(mainString, 99.9));

}
END_TEST

START_TEST(s21_smart_calc_3)
{
const char * mainString = "-(2+2)";
ck_assert_str_eq("-4", s21_smart_calc(mainString, 99.9));

}
END_TEST

START_TEST(s21_smart_calc_4)
{
const char * mainString = "-(2+2)*2.2";
ck_assert_str_eq("-8.8", s21_smart_calc(mainString, 99.9));

}
END_TEST

START_TEST(s21_smart_calc_5)
{
const char * mainString = "-2+(2*2-2)";
ck_assert_str_eq("0", s21_smart_calc(mainString, 99.9));

}
END_TEST

START_TEST(s21_smart_calc_6)
{
const char * mainString = "2-4+2*(2+4)";
ck_assert_str_eq("10", s21_smart_calc(mainString, 99.9));

}
END_TEST

START_TEST(s21_smart_calc_7)
{
const char * mainString = "-7*(2-1)";
ck_assert_str_eq("-7", s21_smart_calc(mainString, 99.9));

}
END_TEST

START_TEST(s21_smart_calc_8)
{
const char * mainString = "(-2+4)";
ck_assert_str_eq("2", s21_smart_calc(mainString, 99.9));

}
END_TEST

START_TEST(s21_smart_calc_9)
{
const char * mainString = "(-2*2)";
ck_assert_str_eq("-4", s21_smart_calc(mainString, 99.9));

}
END_TEST

START_TEST(s21_smart_calc_10)
{
const char * mainString = "2*2";
ck_assert_str_eq("4", s21_smart_calc(mainString, 99.9));

}
END_TEST

START_TEST(s21_smart_calc_11)
{
const char * mainString = "2/2";
ck_assert_str_eq("1", s21_smart_calc(mainString, 99.9));

}
END_TEST

START_TEST(s21_smart_calc_12)
{
const char * mainString = "2-2";
ck_assert_str_eq("0", s21_smart_calc(mainString, 99.9));

}
END_TEST

START_TEST(s21_smart_calc_13)
{
const char * mainString = "2^3-1";
ck_assert_str_eq("7", s21_smart_calc(mainString, 99.9));

}
END_TEST

START_TEST(s21_smart_calc_14)
{
const char * mainString = "2-4+2*(2+x)";
ck_assert_str_eq("10", s21_smart_calc(mainString, 4));

}
END_TEST

START_TEST(s21_smart_calc_15)
{
const char * mainString = "x-4+2*(2+4)";
ck_assert_str_eq("10", s21_smart_calc(mainString, 2));

}
END_TEST

START_TEST(s21_smart_calc_16)
{
const char * mainString = "sin(0)";
ck_assert_str_eq("0", s21_smart_calc(mainString, 99.9));

}
END_TEST

START_TEST(s21_smart_calc_17)
{
const char * mainString = "-sin(0.5)";
ck_assert_str_eq("-0.4794255", s21_smart_calc(mainString, 4));

}
END_TEST

START_TEST(s21_smart_calc_18)
{
const char * mainString = "cos(0)";
ck_assert_str_eq("1", s21_smart_calc(mainString, 2));

}
END_TEST

START_TEST(s21_smart_calc_19)
{
const char * mainString = "cos(1)";
ck_assert_str_eq("0.5403023", s21_smart_calc(mainString, 2));

}
END_TEST

START_TEST(s21_smart_calc_20)
{
const char * mainString = "mod(-1)";
ck_assert_str_eq("1", s21_smart_calc(mainString, 2));

}
END_TEST

START_TEST(s21_smart_calc_21)
{
const char * mainString = "mod(cos(2))";
ck_assert_str_eq("0.4161468", s21_smart_calc(mainString, 2));

}
END_TEST

START_TEST(s21_smart_calc_22)
{
const char * mainString = "-3^2";
ck_assert_str_eq("9", s21_smart_calc(mainString, 2));

}
END_TEST

START_TEST(s21_smart_calc_23)
{
const char * mainString = "2/4";
ck_assert_str_eq("0.5", s21_smart_calc(mainString, 2));

}
END_TEST

START_TEST(s21_smart_calc_24)
{
const char * mainString = "2/ 4*2-100";
ck_assert_str_eq("-99", s21_smart_calc(mainString, 2));

}
END_TEST

START_TEST(s21_smart_calc_25)
{
const char * mainString = "log(10)";
ck_assert_str_eq("1", s21_smart_calc(mainString, 2));

}
END_TEST

START_TEST(s21_smart_calc_26)
{
const char * mainString = "asin(0)";
ck_assert_str_eq("0", s21_smart_calc(mainString, 2));

}
END_TEST

START_TEST(s21_smart_calc_27)
{
const char * mainString = "acos(1)";
ck_assert_str_eq("0", s21_smart_calc(mainString, 2));

}
END_TEST

START_TEST(s21_smart_calc_28)
{
const char * mainString = "atan(1)";
ck_assert_str_eq("0.7853982", s21_smart_calc(mainString, 2));

}
END_TEST

START_TEST(s21_smart_calc_29)
{
const char * mainString = "ln(10)";
ck_assert_str_eq("2.302585", s21_smart_calc(mainString, 2));

}
END_TEST

START_TEST(s21_smart_calc_30)
{
const char * mainString = "sqrt(4)";
ck_assert_str_eq("2", s21_smart_calc(mainString, 2));

}
END_TEST

START_TEST(s21_smart_calc_31)
{
const char * mainString = "ln(10)";
ck_assert_str_eq("2.302585", s21_smart_calc(mainString, 2));

}
END_TEST

START_TEST(s21_smart_calc_32)
{
const char * mainString = "(1-2+4(2";
ck_assert_str_eq("ERROR", s21_smart_calc(mainString, 2));

}
END_TEST

START_TEST(s21_smart_calc_33)
{
const char * mainString = "tan(2)";
ck_assert_str_eq("-2.18504", s21_smart_calc(mainString, 2));

}
END_TEST

START_TEST(s21_smart_calc_34)
{
const char * mainString = "ctg(2)";
ck_assert_str_eq("-0.4576576", s21_smart_calc(mainString, 2));

}
END_TEST

START_TEST(s21_smart_calc_35)
{
const char * mainString = "1/0";
ck_assert_str_eq("ERROR", s21_smart_calc(mainString, 2));

}
END_TEST

START_TEST(s21_smart_calc_36)
{
const char * mainString = "2 + 3 * (4 / 2) ^ 2 + sin(0)";
ck_assert_str_eq("14", s21_smart_calc(mainString, 2));

}
END_TEST

START_TEST(s21_smart_calc_37)
{
const char * mainString = "sqrt(9) - log(1) + tan(0)";
ck_assert_str_eq("3", s21_smart_calc(mainString, 2));

}
END_TEST

START_TEST(s21_smart_calc_38)
{
const char * mainString = "cos(0) * log(1) - tan(0)";
ck_assert_str_eq("0", s21_smart_calc(mainString, 2));

}
END_TEST

START_TEST(s21_smart_calc_39)
{
const char * mainString = "6-3*9-(28.45))-29^3)-(45)";
ck_assert_str_eq("ERROR", s21_smart_calc(mainString, 2));

}
END_TEST

START_TEST(s21_smart_calc_40)
{
const char * mainString = "mod(mod((-1)*x))";
ck_assert_double_eq(9.0, s21_smart_calc_double(mainString, 9));

//checkmk clean_mode=1 smart_calc.check > s21_SmartCalc_tests.c
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, s21_smart_calc_1);
    tcase_add_test(tc1_1, s21_smart_calc_2);
    tcase_add_test(tc1_1, s21_smart_calc_3);
    tcase_add_test(tc1_1, s21_smart_calc_4);
    tcase_add_test(tc1_1, s21_smart_calc_5);
    tcase_add_test(tc1_1, s21_smart_calc_6);
    tcase_add_test(tc1_1, s21_smart_calc_7);
    tcase_add_test(tc1_1, s21_smart_calc_8);
    tcase_add_test(tc1_1, s21_smart_calc_9);
    tcase_add_test(tc1_1, s21_smart_calc_10);
    tcase_add_test(tc1_1, s21_smart_calc_11);
    tcase_add_test(tc1_1, s21_smart_calc_12);
    tcase_add_test(tc1_1, s21_smart_calc_13);
    tcase_add_test(tc1_1, s21_smart_calc_14);
    tcase_add_test(tc1_1, s21_smart_calc_15);
    tcase_add_test(tc1_1, s21_smart_calc_16);
    tcase_add_test(tc1_1, s21_smart_calc_17);
    tcase_add_test(tc1_1, s21_smart_calc_18);
    tcase_add_test(tc1_1, s21_smart_calc_19);
    tcase_add_test(tc1_1, s21_smart_calc_20);
    tcase_add_test(tc1_1, s21_smart_calc_21);
    tcase_add_test(tc1_1, s21_smart_calc_22);
    tcase_add_test(tc1_1, s21_smart_calc_23);
    tcase_add_test(tc1_1, s21_smart_calc_24);
    tcase_add_test(tc1_1, s21_smart_calc_25);
    tcase_add_test(tc1_1, s21_smart_calc_26);
    tcase_add_test(tc1_1, s21_smart_calc_27);
    tcase_add_test(tc1_1, s21_smart_calc_28);
    tcase_add_test(tc1_1, s21_smart_calc_29);
    tcase_add_test(tc1_1, s21_smart_calc_30);
    tcase_add_test(tc1_1, s21_smart_calc_31);
    tcase_add_test(tc1_1, s21_smart_calc_32);
    tcase_add_test(tc1_1, s21_smart_calc_33);
    tcase_add_test(tc1_1, s21_smart_calc_34);
    tcase_add_test(tc1_1, s21_smart_calc_35);
    tcase_add_test(tc1_1, s21_smart_calc_36);
    tcase_add_test(tc1_1, s21_smart_calc_37);
    tcase_add_test(tc1_1, s21_smart_calc_38);
    tcase_add_test(tc1_1, s21_smart_calc_39);
    tcase_add_test(tc1_1, s21_smart_calc_40);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
