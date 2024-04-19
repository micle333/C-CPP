#include <check.h>

#include "s21_decimal.h"

/* ADD */
START_TEST(test_add_1) {
  s21_decimal a = {{12345, 3, 0, 0}};
  s21_decimal b = {{54321, 0, 0, 0}};
  s21_decimal c = {{0, 0, 0, 0}};
  int res = s21_add(a, b, &c);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(c.bits[0], 66666);
  ck_assert_int_eq(c.bits[1], 3);
  ck_assert_int_eq(c.bits[2], 0);
  ck_assert_int_eq(c.bits[3], 0);
}
END_TEST

START_TEST(test_add_2) {
  s21_decimal a = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal b = {{1, 0, 0, 0}};
  s21_decimal c = {{0, 0, 0, 0}};
  int res = s21_add(a, b, &c);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(c.bits[0], 0);
  ck_assert_int_eq(c.bits[1], 1);
  ck_assert_int_eq(c.bits[2], 0);
  ck_assert_int_eq(c.bits[3], 0);
}
END_TEST

START_TEST(test_add_3) {
  s21_decimal a = {{56, 4294967295, 0, 2147483648}};
  s21_decimal b = {{69, 1, 0, 2147483648}};
  s21_decimal c = {{0, 0, 0, 0}};
  int res = s21_add(a, b, &c);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(c.bits[0], 125);
  ck_assert_int_eq(c.bits[1], 0);
  ck_assert_int_eq(c.bits[2], 1);
  ck_assert_int_eq(c.bits[3], 2147483648);
}
END_TEST

START_TEST(test_add_4) {
  s21_decimal a = {{4294967295, 4294967295, 4294967295, 2147483648}};
  s21_decimal b = {{429, 0, 0, 2147483648}};
  s21_decimal c = {{0, 0, 0, 0}};
  int res = s21_add(a, b, &c);
  ck_assert_int_eq(res, 2);
}
END_TEST

START_TEST(test_add_5) {
  s21_decimal a = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal b = {{405, 0, 0, 0}};
  s21_decimal c = {{0, 0, 0, 0}};
  int res = s21_add(a, b, &c);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_add_6) {
  s21_decimal a = {{1234, 5678, 1000, 0}};
  s21_decimal b = {{23, 123, 8, 2147483648}};
  s21_decimal c = {{0, 0, 0, 0}};
  int res = s21_add(a, b, &c);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(c.bits[0], 1211);
  ck_assert_int_eq(c.bits[1], 5555);
  ck_assert_int_eq(c.bits[2], 992);
  ck_assert_int_eq(c.bits[3], 0);
}
END_TEST

START_TEST(test_add_7) {
  s21_decimal a = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal b = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal c = {{0, 0, 0, 0}};
  int res = s21_add(a, b, &c);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(c.bits[0], 0x00000000);
  ck_assert_int_eq(c.bits[1], 0x00000000);
  ck_assert_int_eq(c.bits[2], 0x00000000);
  ck_assert_int_eq(c.bits[3], 0x00000000);
}
END_TEST

START_TEST(test_add_8) {
  s21_decimal a = {{0x00000183, 0x00000000, 0x00000000, 0x00020000}};
  s21_decimal b = {{0x00004DA6, 0x00000000, 0x00000000, 0x00020000}};
  s21_decimal c = {{0, 0, 0, 0}};
  int res = s21_add(a, b, &c);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(c.bits[0], 0x00004F29);
  ck_assert_int_eq(c.bits[1], 0x00000000);
  ck_assert_int_eq(c.bits[2], 0x00000000);
  ck_assert_int_eq(c.bits[3], 0x00020000);
}
END_TEST

START_TEST(test_add_9) {
  s21_decimal a = {{0x77D5E3AA, 0x0000011C, 0x00000000, 0x00060000}};
  s21_decimal b = {{0x00212155, 0x00000000, 0x00000000, 0x00070000}};
  s21_decimal c = {{0, 0, 0, 0}};
  int res = s21_add(a, b, &c);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(c.bits[0], 0xAE7C05F9);
  ck_assert_int_eq(c.bits[1], 0x00000B1C);
  ck_assert_int_eq(c.bits[2], 0x00000000);
  ck_assert_int_eq(c.bits[3], 0x00070000);
}
END_TEST

START_TEST(test_add_10) {
  s21_decimal a = {{0b11111111111111111111111111111111,
                    0b11111111111111111111111111111111,
                    0b11111111111111111111111111111111, 0}};
  s21_decimal b = {{1, 0, 0, 0}};
  s21_decimal c = {{0, 0, 0, 0}};
  int res = s21_add(a, b, &c);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_add_11) {
  s21_decimal a = {{0b11111111111111111111111111111111,
                    0b11111111111111111111111111111111,
                    0b11111111111111111111111111111111, 0}};
  s21_decimal b = {{1, 0, 0, 0}};
  s21_decimal c = {{0, 0, 0, 0}};
  s21_touchbit(&a, 128, 1);
  int res = s21_add(a, b, &c);
  ck_assert_int_eq(res, 0);
}
END_TEST

/* SUB */
START_TEST(test_sub_1) {
  s21_decimal a = {{55, 5432, 0, 0}};
  s21_decimal b = {{22, 5422, 0, 0}};
  s21_decimal c = {{0, 0, 0, 0}};
  int res = s21_sub(a, b, &c);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(c.bits[0], 33);
  ck_assert_int_eq(c.bits[1], 10);
  ck_assert_int_eq(c.bits[2], 0);
  ck_assert_int_eq(c.bits[3], 0);
}
END_TEST

START_TEST(test_sub_2) {
  s21_decimal a = {{25, 1234, 0, 0}};
  s21_decimal b = {{50, 1334, 0, 0}};
  s21_decimal c = {{0, 0, 0, 0}};
  int res = s21_sub(a, b, &c);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(c.bits[0], 25);
  ck_assert_int_eq(c.bits[1], 100);
  ck_assert_int_eq(c.bits[2], 0);
  ck_assert_int_eq(c.bits[3], 2147483648);
}
END_TEST

START_TEST(test_sub_4) {
  s21_decimal a = {{175, 0, 0, 2147483648}};
  s21_decimal b = {{60, 0, 0, 0}};
  s21_decimal c = {{0, 0, 0, 0}};
  int res = s21_sub(a, b, &c);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(c.bits[0], 235);
  ck_assert_int_eq(c.bits[1], 0);
  ck_assert_int_eq(c.bits[2], 0);
  ck_assert_int_eq(c.bits[3], 2147483648);
}
END_TEST

START_TEST(test_sub_5) {
  s21_decimal a = {{60, 0, 0, 2147483648}};
  s21_decimal b = {{1000, 0, 0, 0}};
  s21_decimal c = {{0, 0, 0, 0}};
  int res = s21_sub(a, b, &c);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(c.bits[0], 1060);
  ck_assert_int_eq(c.bits[1], 0);
  ck_assert_int_eq(c.bits[2], 0);
  ck_assert_int_eq(c.bits[3], 2147483648);
}
END_TEST

START_TEST(test_sub_6) {
  s21_decimal a = {{65, 1, 0, 0}};
  s21_decimal b = {{42, 5, 0, 2147483648}};
  s21_decimal c = {{0, 0, 0, 0}};
  int res = s21_sub(a, b, &c);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(c.bits[0], 107);
  ck_assert_int_eq(c.bits[1], 6);
  ck_assert_int_eq(c.bits[2], 0);
  ck_assert_int_eq(c.bits[3], 0);
}
END_TEST

START_TEST(test_sub_7) {
  s21_decimal a = {{65, 1234, 0, 0}};
  s21_decimal b = {{423, 5, 2, 2147483648}};
  s21_decimal c = {{0, 0, 0, 0}};
  int res = s21_sub(a, b, &c);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(c.bits[0], 488);
  ck_assert_int_eq(c.bits[1], 1239);
  ck_assert_int_eq(c.bits[2], 2);
  ck_assert_int_eq(c.bits[3], 0);
}
END_TEST

START_TEST(test_sub_8) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 2147483648}};
  s21_decimal b = {{4, 4, 12, 0}};
  s21_decimal c = {{0, 0, 0, 0}};
  int res = s21_sub(a, b, &c);
  ck_assert_int_eq(res, 2);
}
END_TEST

START_TEST(test_sub_9) {
  s21_decimal a = {{6, 8, 0, 196608}};
  s21_decimal b = {{12, 2, 0, 524288}};
  s21_decimal c = {{0, 0, 0, 0}};
  int res = s21_sub(a, b, &c);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(c.bits[0], 599988);
  ck_assert_int_eq(c.bits[1], 799998);
  ck_assert_int_eq(c.bits[2], 0);
  ck_assert_int_eq(c.bits[3], 524288);
}
END_TEST

START_TEST(test_sub_10) {
  s21_decimal a = {{450, 0, 0, 983040}};
  s21_decimal b = {{3, 0, 0, 131072}};
  s21_decimal c = {{0, 0, 0, 0}};
  int res = s21_sub(a, b, &c);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(c.bits[0], 3948404286);
  ck_assert_int_eq(c.bits[1], 6984);
  ck_assert_int_eq(c.bits[2], 0);
  ck_assert_int_eq(c.bits[3], 2148466688);
}
END_TEST

START_TEST(test_sub_11) {
  s21_decimal a = {{0x00000183, 0x00000000, 0x00000000, 0x00020000}};
  s21_decimal b = {{0x00004DA6, 0x00000000, 0x00000000, 0x00020000}};
  s21_decimal c = {{0, 0, 0, 0}};
  int res = s21_sub(a, b, &c);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(c.bits[0], 0x00004C23);
  ck_assert_int_eq(c.bits[1], 0x00000000);
  ck_assert_int_eq(c.bits[2], 0x00000000);
  ck_assert_int_eq(c.bits[3], 0x80020000);
}
END_TEST

/* DIV */
START_TEST(test_div_1) {
  int n1 = 10;
  int n2 = 5;
  int res = 0;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal c = {0};
  s21_from_int_to_decimal(n1, &a);
  s21_from_int_to_decimal(n2, &b);

  s21_div(a, b, &c);

  s21_from_decimal_to_int(c, &res);
  ck_assert_int_eq(res, 2);
}
END_TEST

START_TEST(test_div_2) {
  int n1 = 123456;
  int n2 = 2;
  int res = 0;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal c = {0};
  s21_from_int_to_decimal(n1, &a);
  s21_from_int_to_decimal(n2, &b);
  s21_div(a, b, &c);
  s21_from_decimal_to_int(c, &res);
  ck_assert_int_eq(res, 61728);
}
END_TEST

START_TEST(test_div_3) {
  int n1 = 2;
  int n2 = 2;
  int res = 0;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal c = {0};
  s21_from_int_to_decimal(n1, &a);
  s21_from_int_to_decimal(n2, &b);
  s21_div(a, b, &c);
  s21_from_decimal_to_int(c, &res);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_div_4) {
  int n1 = 0;
  int n2 = 5;
  int res = 0;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal c = {0};
  s21_from_int_to_decimal(n1, &a);
  s21_from_int_to_decimal(n2, &b);
  s21_div(a, b, &c);
  s21_from_decimal_to_int(c, &res);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_div_5) {
  int res = 0;
  s21_decimal a = {{10000, 0, 0, 0}};
  s21_decimal b = {{200, 0, 0, 0}};
  s21_decimal c = {0};

  s21_div(a, b, &c);

  s21_from_decimal_to_int(c, &res);
  ck_assert_float_eq_tol(res, 50, 6);
}
END_TEST

START_TEST(test_div_6) {
  s21_decimal a = {{1110, 0, 0, 0}};
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal c = {0};
  int res = s21_div(a, b, &c);
  ck_assert_int_eq(res, 3);
}
END_TEST

START_TEST(test_div_7) {
  s21_decimal a = {{100, 0, 0, 0}};
  s21_decimal b = {{50, 0, 0, 0}};
  s21_decimal c = {{0, 0, 0, 0}};
  s21_div(a, b, &c);
  ck_assert_int_eq(c.bits[0], 2);
  ck_assert_int_eq(c.bits[1], 0);
  ck_assert_int_eq(c.bits[2], 0);
  ck_assert_int_eq(c.bits[3], 0);
}
END_TEST

START_TEST(test_div_8) {
  int n1 = 2;
  int n2 = 2;
  int res = 0;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal c = {0};
  s21_from_int_to_decimal(n1, &a);
  s21_from_int_to_decimal(n2, &b);
  s21_div(a, b, &c);
  s21_from_decimal_to_int(c, &res);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_div_9) {
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal c = {0};
  ck_assert_int_eq(s21_div(a, b, &c), 3);
}
END_TEST

/* MUL */
START_TEST(test_mul_1) {
  s21_decimal a = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal b = {{2, 0, 0, 0}};
  s21_decimal c = {{0}};
  ck_assert_int_eq(0, s21_mul(a, b, &c));
}
END_TEST

START_TEST(test_mul_2) {
  s21_decimal a = {{2, 0, 0, 0}};
  s21_decimal b = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal c = {{0, 0, 0, 0}};
  ck_assert_int_eq(0, s21_mul(a, b, &c));
}
END_TEST

START_TEST(test_mul_3) {
  s21_decimal a = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal b = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal c = {{0}};
  ck_assert_int_eq(0, s21_mul(a, b, &c));
}
END_TEST

START_TEST(test_mul_4) {
  s21_decimal a = {{2, 0, 0, 0}};
  s21_decimal b = {{2, 0, 0, 0}};
  s21_decimal c = {{0}};
  ck_assert_int_eq(0, s21_mul(a, b, &c));
}
END_TEST

START_TEST(test_mul_5) {
  s21_decimal a = {{8, 0, 0, 0}};
  s21_decimal b = {{2, 0, 0, 0}};
  s21_decimal c = {{0}};
  ck_assert_int_eq(0, s21_mul(a, b, &c));
}
END_TEST

START_TEST(test_mul_6) {
  s21_decimal a = {{2, 0, 0, 0}};
  s21_decimal b = {{8, 0, 0, 0}};
  s21_decimal c = {{0}};
  ck_assert_int_eq(0, s21_mul(a, b, &c));
}
END_TEST

START_TEST(test_mul_7) {
  s21_decimal a = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal b = {{2, 0, 0, 0}};
  s21_decimal c = {{0}};
  ck_assert_int_eq(0, s21_mul(a, b, &c));
}
END_TEST

START_TEST(test_mul_8) {
  s21_decimal a = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal b = {{8, 0, 0, 0}};
  s21_decimal c = {{0}};
  ck_assert_int_eq(0, s21_mul(a, b, &c));
  ck_assert_int_eq(16, c.bits[0]);
}
END_TEST

START_TEST(test_mul_9) {
  s21_decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal c = {{0}};
  ck_assert_int_eq(0, s21_mul(a, b, &c));
}
END_TEST

START_TEST(test_mul_10) {
  s21_decimal a = {{5, 0, 0, 0}};
  s21_decimal b = {{7, 0, 0, 0}};
  s21_decimal c = {{0, 0, 0, 0}};
  s21_decimal d = {{35, 0, 0, 0}};
  int res = s21_mul(a, b, &c);
  ck_assert_int_eq(s21_is_equal(c, d), 1);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_mul_11) {
  s21_decimal a, b;
  s21_decimal c = {0};
  int n1 = -32768;
  int n2 = 32768;
  int n3 = 0;
  s21_from_int_to_decimal(n1, &a);
  s21_from_int_to_decimal(n2, &b);
  s21_mul(a, b, &c);
  s21_from_decimal_to_int(c, &n3);
  ck_assert_int_eq(n3, -1073741824);
}
END_TEST

START_TEST(test_mul_12) {
  int n1 = -10;
  int n2 = -10;
  int n3 = 100;
  int res = 0;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal c = {0};
  s21_from_int_to_decimal(n1, &a);
  s21_from_int_to_decimal(n2, &b);
  s21_mul(a, b, &c);
  s21_from_decimal_to_int(c, &res);
  ck_assert_int_eq(res, n3);
}
END_TEST

START_TEST(test_mul_13) {
  int n1 = 10;
  int n2 = 20;
  int n3 = 200;
  int res = 0;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal c = {0};
  s21_from_int_to_decimal(n1, &a);
  s21_from_int_to_decimal(n2, &b);
  s21_mul(a, b, &c);
  s21_from_decimal_to_int(c, &res);
  ck_assert_int_eq(res, n3);
}
END_TEST

START_TEST(test_mul_14) {
  int n1 = -10;
  int n2 = 20;
  int n3 = -200;
  int res = 0;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal c = {0};
  s21_from_int_to_decimal(n1, &a);
  s21_from_int_to_decimal(n2, &b);
  s21_mul(a, b, &c);
  s21_from_decimal_to_int(c, &res);
  ck_assert_int_eq(res, n3);
}
END_TEST

START_TEST(test_mul_15) {
  int n1 = 9403;
  int n2 = 202;
  int res = 0;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal c = {0};
  s21_from_int_to_decimal(n1, &a);
  s21_from_int_to_decimal(n2, &b);
  s21_mul(a, b, &c);
  s21_from_decimal_to_int(c, &res);
  ck_assert_int_eq(res, 1899406);
}
END_TEST

START_TEST(test_mul_16) {
  int n1 = -32768;
  int n2 = 2;
  int res = 0;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal c = {0};
  s21_from_int_to_decimal(n1, &a);
  s21_from_int_to_decimal(n2, &b);
  s21_mul(a, b, &c);
  s21_from_decimal_to_int(c, &res);
  ck_assert_int_eq(res, -65536);
}
END_TEST

START_TEST(test_mul_17) {
  int n1 = -32768;
  int n2 = 32768;
  int res = 0;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal c = {0};
  s21_from_int_to_decimal(n1, &a);
  s21_from_int_to_decimal(n2, &b);
  s21_mul(a, b, &c);
  s21_from_decimal_to_int(c, &res);
  ck_assert_int_eq(res, -1073741824);
}
END_TEST

START_TEST(test_mul_19) {
  int res = 0;
  s21_decimal a = {0};
  s21_decimal b = {0};
  a.bits[0] = 0b11111111111111111111111111111111;
  a.bits[1] = 0b11111111111111111111111111111111;
  a.bits[2] = 0b11111111111111111111111111111111;
  b.bits[0] = 0b11111111111111111111111111111111;
  b.bits[1] = 0b11111111111111111111111111111111;
  b.bits[2] = 0b11111111111111111111111111111111;
  a.bits[3] = 0;
  s21_decimal c = {0};
  res = s21_mul(a, b, &c);
  ck_assert_int_eq(res, 1);
}
END_TEST

/* EQUAL */
START_TEST(test_is_equal_1) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 1, 0}};
  int res = s21_is_equal(a, b);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_equal_2) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 1, 0}};
  s21_touchbit(&a, 128, 1);
  s21_touchbit(&b, 128, 1);
  int res1 = s21_is_equal(a, b);
  ck_assert_int_eq(res1, 1);
}
END_TEST

START_TEST(test_is_equal_3) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 1, 0}};
  s21_touchbit(&b, 128, 1);
  int res = s21_is_equal(a, b);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_equal_4) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 1, 0}};
  s21_touchbit(&a, 128, 1);
  int res = s21_is_equal(a, b);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_equal_5) {
  s21_decimal a = {{0, 52, 1, 0}};
  s21_decimal b = {{0, 0, 1, 0}};
  int res = s21_is_equal(a, b);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_equal_6) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{1747, 0, 1, 0}};
  int res = s21_is_equal(a, b);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_equal_7) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{1747, 0, 1, 0}};
  s21_touchbit(&a, 128, 1);
  int res = s21_is_equal(a, b);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_equal_8) {
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_touchbit(&a, 1, 3);
  s21_touchbit(&b, 1, 3);
  int res = s21_is_equal(a, b);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_equal_9) {
  s21_decimal a = {0};
  s21_decimal b = {0};
  set_cap(&a, 3);
  set_cap(&b, 3);
  int res = s21_is_equal(a, b);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_equal_10) {
  s21_decimal a = {0};
  s21_decimal b = {0};
  int res = s21_is_equal(a, b);
  ck_assert_int_eq(res, 1);
}
END_TEST

/* GREATER OR EQUAL */
START_TEST(test_is_greater_or_equal_1) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 2, 0}};
  int res = s21_is_greater_or_equal(a, b);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_greater_or_equal_2) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 2, 0}};
  int res = s21_is_greater_or_equal(b, a);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_greater_or_equal_3) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 1, 0}};
  int res = s21_is_greater_or_equal(b, a);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_greater_or_equal_4) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 2, 0}};
  s21_touchbit(&a, 128, 1);
  s21_touchbit(&b, 128, 1);
  int res = s21_is_greater_or_equal(a, b);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_greater_or_equal_5) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 2, 0}};
  s21_touchbit(&a, 128, 1);
  s21_touchbit(&b, 128, 1);
  int res = s21_is_greater_or_equal(b, a);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_greater_or_equal_6) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 1, 0}};
  s21_touchbit(&a, 128, 1);
  s21_touchbit(&b, 128, 1);
  int res = s21_is_greater_or_equal(b, a);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_greater_or_equal_7) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 1, 0}};
  s21_touchbit(&a, 128, 1);
  int res = s21_is_greater_or_equal(a, b);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_greater_or_equal_8) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 1, 0}};
  s21_touchbit(&b, 128, 1);
  int res = s21_is_greater_or_equal(a, b);
  ck_assert_int_eq(res, 1);
}
END_TEST

/* GREATER */
START_TEST(test_is_greater_1) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 2, 0}};
  int res = s21_is_greater(a, b);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_greater_2) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 2, 0}};
  int res = s21_is_greater(b, a);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_greater_3) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 1, 0}};
  int res = s21_is_greater(b, a);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_greater_4) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 2, 0}};
  s21_touchbit(&a, 128, 1);
  s21_touchbit(&b, 128, 1);
  int res = s21_is_greater(a, b);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_greater_5) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 2, 0}};
  s21_touchbit(&a, 128, 1);
  s21_touchbit(&b, 128, 1);
  int res = s21_is_greater(b, a);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_greater_6) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 1, 0}};
  s21_touchbit(&a, 128, 1);
  s21_touchbit(&b, 128, 1);
  int res = s21_is_greater(b, a);
  ck_assert_int_eq(res, 0);
}
END_TEST

/* LESS OR EQUAL */
START_TEST(test_is_less_or_equal_1) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 2, 0}};
  int res = s21_is_less_or_equal(a, b);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_less_or_equal_2) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 2, 0}};
  int res = s21_is_less_or_equal(b, a);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_less_or_equal_3) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 1, 0}};
  int res = s21_is_less_or_equal(b, a);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_less_or_equal_4) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 2, 0}};
  s21_touchbit(&a, 128, 1);
  s21_touchbit(&b, 128, 1);
  int res = s21_is_less_or_equal(a, b);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_less_or_equal_5) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 2, 0}};
  s21_touchbit(&a, 128, 1);
  s21_touchbit(&b, 128, 1);
  int res = s21_is_less_or_equal(b, a);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_less_or_equal_6) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 1, 0}};
  s21_touchbit(&a, 128, 1);
  s21_touchbit(&b, 128, 1);
  int res = s21_is_less_or_equal(b, a);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_less_or_equal_7) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 1, 0}};
  s21_touchbit(&a, 128, 1);
  int res = s21_is_less_or_equal(a, b);
  ck_assert_int_eq(res, 1);
}
END_TEST

/* LESS */
START_TEST(test_is_less_1) {
  s21_decimal a = {{4294967295, 0, 0, 0}};
  s21_decimal b = {{0, 1, 0, 0}};
  int res = s21_is_less(a, b);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_less_2) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 2, 0}};
  int res = s21_is_less(b, a);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_less_3) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 1, 0}};
  int res = s21_is_less(b, a);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_less_4) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 2, 0}};
  s21_touchbit(&a, 128, 1);
  s21_touchbit(&b, 128, 1);
  int res = s21_is_less(a, b);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_less_5) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 2, 0}};
  s21_touchbit(&a, 128, 1);
  s21_touchbit(&b, 128, 1);
  int res = s21_is_less(b, a);
  ck_assert_int_eq(res, 1);
}
END_TEST

/* NOT EQUAL */
START_TEST(test_is_not_equal_1) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 1, 0}};
  int res = s21_is_not_equal(a, b);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_not_equal_2) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 1, 0}};
  s21_touchbit(&a, 128, 1);
  s21_touchbit(&b, 128, 1);
  int res = s21_is_not_equal(a, b);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_is_not_equal_3) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 1, 0}};
  s21_touchbit(&b, 128, 1);
  int res = s21_is_not_equal(a, b);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_not_equal_4) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 1, 0}};
  s21_touchbit(&a, 128, 1);
  int res = s21_is_not_equal(a, b);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_is_not_equal_5) {
  s21_decimal a = {{0, 52, 1, 0}};
  s21_decimal b = {{0, 0, 1, 0}};
  int res = s21_is_not_equal(a, b);
  ck_assert_int_eq(res, 1);
}
END_TEST

/* FROM DECIMAL TO FLOAT */
START_TEST(from_decimal_to_float_1) {
  s21_decimal a;
  float res = 0.0;
  a.bits[0] = 1234567;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 3;
  s21_from_decimal_to_float(a, &res);
  ck_assert_float_eq_tol(res, 1234.567, 1e7);
}
END_TEST

START_TEST(from_decimal_to_float_2) {
  s21_decimal a;
  float res = 0.0;
  a.bits[0] = 0b11111111111111111111111111111111;
  a.bits[1] = 0b11111111111111111111111111111111;
  a.bits[2] = 0b11111111111111111111111111111111;
  a.bits[3] = 0;
  ck_assert_int_eq(s21_from_decimal_to_float(a, &res), 0);
  ck_assert_float_eq(res, 79228162514264337593543950336.0f);
}
END_TEST

START_TEST(from_decimal_to_float_3) {
  s21_decimal a;
  float res = 0.0;
  a.bits[0] = 457865;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 2147483648;
  set_cap(&a, 3);
  ck_assert_int_eq(s21_from_decimal_to_float(a, &res), 0);
  ck_assert_float_eq(res, -457.865);
}
END_TEST

START_TEST(from_decimal_to_float_4) {
  s21_decimal a;
  float res = 0.0;
  a.bits[0] = 1905;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 2147483648;
  ck_assert_int_eq(s21_from_decimal_to_float(a, &res), 0);
  ck_assert_float_eq(res, -1905);
}
END_TEST

START_TEST(from_decimal_to_float_5) {
  s21_decimal a;
  float res = 0.0;
  a.bits[0] = 0xFFFFF;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0;
  ck_assert_int_eq(s21_from_decimal_to_float(a, &res), 0);
  ck_assert_float_eq(res, 1048575);
}
END_TEST

START_TEST(from_decimal_to_float_6) {
  s21_decimal a;
  float res = 0.0;
  a.bits[0] = 4364764;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 2147483648;
  set_cap(&a, 8);
  ck_assert_int_eq(s21_from_decimal_to_float(a, &res), 0);
  ck_assert_float_eq_tol(res, -0.4364764, 1e7);
}
END_TEST

START_TEST(from_decimal_to_float_7) {
  s21_decimal a;
  float res = 0.0;
  a.bits[0] = INT_MAX;
  a.bits[1] = INT_MAX;
  a.bits[2] = 0;
  a.bits[3] = 0;
  ck_assert_int_eq(s21_from_decimal_to_float(a, &res), 0);
  ck_assert_float_eq(res, pow(2, 63) - 1);
}
END_TEST

START_TEST(from_decimal_to_float_8) {
  s21_decimal a;
  float res = 0.0;
  a.bits[0] = 378492087;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0;
  set_cap(&a, 10);
  ck_assert_int_eq(s21_from_decimal_to_float(a, &res), 0);
  ck_assert_float_eq(res, 0.0378492087);
}
END_TEST

START_TEST(from_decimal_to_float_9) {
  s21_decimal a;
  float res = 0.0;
  a.bits[0] = 2021;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 2147483648;
  set_cap(&a, 28);
  ck_assert_int_eq(s21_from_decimal_to_float(a, &res), 0);
  ck_assert_float_eq(res, -2.021e-25);
}
END_TEST

START_TEST(from_decimal_to_float_10) {
  s21_decimal a;
  float res = 0.0;
  a.bits[0] = 0;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 2147483648;
  ck_assert_int_eq(s21_from_decimal_to_float(a, &res), 0);
  ck_assert_float_eq(res, -0);
}
END_TEST

START_TEST(from_decimal_to_float_11) {
  s21_decimal a;
  float res = 0.0;
  a.bits[0] = 0b11111111111111111111111111111111;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 2147483648;
  ck_assert_int_eq(s21_from_decimal_to_float(a, &res), 0);
  ck_assert_float_eq(res, -4294967295);
}
END_TEST

START_TEST(from_decimal_to_float_12) {
  s21_decimal a;
  float res = 0.0;
  a.bits[0] = 0b11111111111111111111111111111111;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 2147483648;
  ck_assert_int_eq(s21_from_decimal_to_float(a, &res), 0);
  ck_assert_float_eq(res, -4294967295);
}
END_TEST

START_TEST(from_decimal_to_float_13) {
  s21_decimal a;
  float res = 0.0;
  a.bits[0] = INT_MAX;
  a.bits[1] = INT_MAX;
  a.bits[2] = INT_MAX;
  a.bits[3] = 0;
  ck_assert_int_eq(s21_from_decimal_to_float(a, &res), 0);
  ck_assert_float_eq(res, pow(2, 95) - 1);
}
END_TEST

START_TEST(from_decimal_to_float_14) {
  s21_decimal a;
  float res = 0.0;
  a.bits[0] = 0b00000000010100111001000011000010;
  a.bits[1] = 0b00000000000000000000000000000000;
  a.bits[2] = 0b00000000000000000000000000000000;
  a.bits[3] = 0b00000000000000010000000000000000;
  ck_assert_int_eq(s21_from_decimal_to_float(a, &res), 0);
  ck_assert_float_eq_tol(res, 54675.46, 1e7);
}
END_TEST

START_TEST(from_decimal_to_float_15) {
  s21_decimal a;
  float res = 0.0;
  a.bits[0] = 0b00000000000000001011010101110101;
  a.bits[1] = 0b00000000000000000000000000000000;
  a.bits[2] = 0b00000000000000000000000000000000;
  a.bits[3] = 0b10000000000001010000000000000000;
  ck_assert_int_eq(s21_from_decimal_to_float(a, &res), 0);
  ck_assert_float_eq(res, -0.46453);
}
END_TEST

START_TEST(from_decimal_to_float_16) {
  s21_decimal a;
  float res = 0;
  a.bits[0] = 0b01100101101110011011001110011111;
  a.bits[1] = 0b00000000000000000000000010000011;
  a.bits[2] = 0b00000000000000000000000000000000;
  a.bits[3] = 0b00000000000010010000000000000000;
  s21_from_decimal_to_float(a, &res);
  ck_assert_float_eq_tol(res, 564.3473, 1e7);
}
END_TEST

/* FROM DECIMAL TO INT */
START_TEST(from_decimal_to_int_1) {
  s21_decimal a;
  int n = 0;
  int res = 0;
  a.bits[0] = INT_MAX;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0;
  res = s21_from_decimal_to_int(a, &n);
  ck_assert_uint_eq(n, 2147483647);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(from_decimal_to_int_2) {
  s21_decimal a;
  int n = 0;
  int res = 0;
  a.bits[0] = 133141;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0;
  res = s21_from_decimal_to_int(a, &n);
  ck_assert_int_eq(n, 133141);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(from_decimal_to_int_4) {
  s21_decimal a;
  int n = 0;
  int res = 0;
  a.bits[0] = 123451234;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 2147483648;
  res = s21_from_decimal_to_int(a, &n);
  ck_assert_int_eq(n, -123451234);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(from_decimal_to_int_5) {
  s21_decimal a;
  int n = 0;
  int res = 0;
  a.bits[0] = 18;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 2147483648;
  res = s21_from_decimal_to_int(a, &n);
  ck_assert_int_eq(n, -18);
  ck_assert_int_eq(res, 0);
}
END_TEST

/* FROM FLOAT TO DECIMAL */
START_TEST(from_float_to_decimal_1) {
  s21_decimal a = {{3212000, 0, 0, 2147745792}};
  s21_decimal b = {{0, 0, 0, 0}};
  float n = -321.2;
  int res = s21_from_float_to_decimal(n, &b);
  ck_assert_int_eq(b.bits[0], a.bits[0]);
  ck_assert_int_eq(b.bits[1], a.bits[1]);
  ck_assert_int_eq(b.bits[2], a.bits[2]);
  ck_assert_int_eq(b.bits[3], a.bits[3]);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(from_float_to_decimal_2) {
  s21_decimal a = {{3212000, 0, 0, 262144}};
  s21_decimal b = {{0, 0, 0, 0}};
  float n = 321.2;
  int res = s21_from_float_to_decimal(n, &b);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(b.bits[i], a.bits[i]);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(from_float_to_decimal_3) {
  s21_decimal a = {{0x13255310, 0, 0, 0}};
  s21_decimal b = {{0, 0, 0, 0}};
  float n = 321213143.8323;
  int res = s21_from_float_to_decimal(n, &b);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(b.bits[i], a.bits[i]);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(from_float_to_decimal_4) {
  s21_decimal a = {{0xC7238000, 0x9472ED75, 0x0000020F, 0}};
  s21_decimal b = {0};
  float n = 9732131234575756436473.323123474;
  int res = s21_from_float_to_decimal(n, &b);
  ck_assert_int_eq(b.bits[0], a.bits[0]);
  ck_assert_int_eq(b.bits[1], a.bits[1]);
  ck_assert_int_eq(b.bits[2], a.bits[2]);
  ck_assert_int_eq(b.bits[3], a.bits[3]);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(from_float_to_decimal_5) {
  s21_decimal a = {{0x006FE484, 0, 0, 0x00050000}};
  s21_decimal b = {0};
  float n = 73.329959999;
  int res = s21_from_float_to_decimal(n, &b);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(b.bits[i], a.bits[i]);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(from_float_to_decimal_6) {
  s21_decimal a = {{3000000, 0, 0, 589824}};
  s21_decimal b = {0};
  float n = 0.003;
  int res = s21_from_float_to_decimal(n, &b);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(b.bits[i], a.bits[i]);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(from_float_to_decimal_7) {
  s21_decimal a = {{3123450, 0, 0, 589824}};
  s21_decimal b = {0};
  float n = 0.00312345;
  int res = s21_from_float_to_decimal(n, &b);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(b.bits[i], a.bits[i]);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(from_float_to_decimal_8) {
  s21_decimal a = {{3123960, 0, 0, 917504}};
  s21_decimal b = {0};
  float n = 0.00000003123959595945;
  int res = s21_from_float_to_decimal(n, &b);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(b.bits[i], a.bits[i]);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(from_float_to_decimal_9) {
  s21_decimal a = {{0x008F532B, 0, 0, 0x00180000}};
  s21_decimal b = {0};
  float n = 0.0000000000000000093929383838292;
  int res = s21_from_float_to_decimal(n, &b);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(b.bits[i], a.bits[i]);
  ck_assert_int_eq(res, 0);
}
END_TEST

/* FROM INT TO DECIMAL */
START_TEST(from_int_to_decimal_1) {
  s21_decimal a;
  s21_from_int_to_decimal(0, &a);
  ck_assert_int_eq(a.bits[0], 0);
  ck_assert_int_eq(a.bits[1], 0);
  ck_assert_int_eq(a.bits[2], 0);
  ck_assert_int_eq(a.bits[3], 0);
}
END_TEST

START_TEST(from_int_to_decimal_2) {
  s21_decimal a;
  s21_from_int_to_decimal(-1, &a);
  ck_assert_int_eq(a.bits[0], 1);
  ck_assert_int_eq(a.bits[1], 0);
  ck_assert_int_eq(a.bits[2], 0);
  ck_assert_int_eq((int)a.bits[3], -2147483648);
}
END_TEST

START_TEST(from_int_to_decimal_3) {
  s21_decimal a;
  s21_from_int_to_decimal(1, &a);
  ck_assert_int_eq(a.bits[0], 1);
  ck_assert_int_eq(a.bits[1], 0);
  ck_assert_int_eq(a.bits[2], 0);
  ck_assert_int_eq(a.bits[3], 0);
}
END_TEST

START_TEST(from_int_to_decimal_4) {
  s21_decimal a;
  s21_from_int_to_decimal(-2147483648, &a);
  ck_assert_int_eq((int)a.bits[0], -2147483648);
  ck_assert_int_eq(a.bits[1], 0);
  ck_assert_int_eq(a.bits[2], 0);
  ck_assert_int_eq((int)a.bits[3], -2147483648);
}
END_TEST

START_TEST(from_int_to_decimal_5) {
  s21_decimal a;
  s21_from_int_to_decimal(123456789, &a);
  ck_assert_int_eq((int)a.bits[0], 123456789);
  ck_assert_int_eq(a.bits[1], 0);
  ck_assert_int_eq(a.bits[2], 0);
  ck_assert_int_eq(a.bits[3], 0);
}
END_TEST

/* FLOOR */
START_TEST(test_floor_1) {
  s21_decimal a;
  a.bits[0] = 0;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0;
  s21_decimal b;
  b.bits[0] = 0;
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = 0;
  s21_floor(a, &a);
  ck_assert_float_eq(a.bits[0], b.bits[0]);
  ck_assert_float_eq(a.bits[1], b.bits[1]);
  ck_assert_float_eq(a.bits[2], b.bits[2]);
  ck_assert_float_eq(a.bits[3], b.bits[3]);
}
END_TEST

START_TEST(test_floor_2) {
  s21_decimal a;
  a.bits[0] = 1;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0;
  s21_decimal b;
  b.bits[0] = 1;
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = 0;
  s21_floor(a, &a);
  ck_assert_float_eq(a.bits[0], b.bits[0]);
  ck_assert_float_eq(a.bits[1], b.bits[1]);
  ck_assert_float_eq(a.bits[2], b.bits[2]);
  ck_assert_float_eq(a.bits[3], b.bits[3]);
}
END_TEST

START_TEST(test_floor_3) {
  s21_decimal a;
  a.bits[0] = 123;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0;
  set_cap(&a, 1);
  s21_decimal b;
  b.bits[0] = 12;
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = 0;
  s21_floor(a, &a);
  ck_assert_float_eq(a.bits[0], b.bits[0]);
  ck_assert_float_eq(a.bits[1], b.bits[1]);
  ck_assert_float_eq(a.bits[2], b.bits[2]);
  ck_assert_float_eq(a.bits[3], b.bits[3]);
}
END_TEST

START_TEST(test_floor_4) {
  s21_decimal a;
  a.bits[0] = 123;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 2147483648;
  set_cap(&a, 1);
  s21_decimal b;
  b.bits[0] = 13;
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = 2147483648;
  s21_floor(a, &a);
  ck_assert_float_eq(a.bits[0], b.bits[0]);
  ck_assert_float_eq(a.bits[1], b.bits[1]);
  ck_assert_float_eq(a.bits[2], b.bits[2]);
  ck_assert_float_eq(a.bits[3], b.bits[3]);
}
END_TEST

/* NEGATE */
START_TEST(test_negate_1) {
  s21_decimal a = {0};
  s21_decimal b;
  ck_assert_int_eq(0, s21_negate(a, &b));
}
END_TEST

START_TEST(test_negate_2) {
  s21_decimal a = {{2, 0, 0, 0}};
  s21_decimal b = {0};
  ck_assert_int_eq(0, s21_negate(a, &b));
}
END_TEST

START_TEST(test_negate_3) {
  s21_decimal a = {{2, 0, 0, ~(-1 / 2)}};
  s21_decimal b = {0};
  ck_assert_int_eq(0, s21_negate(a, &b));
}
END_TEST

START_TEST(test_negate_4) {
  s21_decimal a = {{0, 0, 0, ~(-1 / 2)}};
  s21_decimal b = {0};
  ck_assert_int_eq(0, s21_negate(a, &b));
}
END_TEST

/* ROUND */
START_TEST(test_round_1) {
  s21_decimal a;
  a.bits[0] = 165;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0;
  set_cap(&a, 1);
  s21_decimal b;
  b.bits[0] = 16;
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = 0;
  s21_round(a, &a);
  ck_assert_int_eq(a.bits[0], b.bits[0]);
  ck_assert_int_eq(a.bits[1], b.bits[1]);
  ck_assert_int_eq(a.bits[2], b.bits[2]);
  ck_assert_int_eq(a.bits[3], b.bits[3]);
}
END_TEST

START_TEST(test_round_2) {
  s21_decimal a;
  a.bits[0] = 165;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 2147483648;
  set_cap(&a, 1);
  s21_decimal b;
  b.bits[0] = 16;
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = 2147483648;
  s21_round(a, &a);
  ck_assert_int_eq(a.bits[0], b.bits[0]);
  ck_assert_int_eq(a.bits[1], b.bits[1]);
  ck_assert_int_eq(a.bits[2], b.bits[2]);
  ck_assert_int_eq(a.bits[3], b.bits[3]);
}
END_TEST

START_TEST(test_round_3) {
  s21_decimal a;
  a.bits[0] = INT_MAX;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0;
  s21_decimal b;
  b.bits[0] = INT_MAX;
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = 0;
  s21_round(a, &a);
  ck_assert_int_eq(a.bits[0], b.bits[0]);
  ck_assert_int_eq(a.bits[1], b.bits[1]);
  ck_assert_int_eq(a.bits[2], b.bits[2]);
  ck_assert_int_eq(a.bits[3], b.bits[3]);
}
END_TEST

START_TEST(test_round_4) {
  s21_decimal a;
  a.bits[0] = 5;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 2147483648;
  set_cap(&a, 1);
  s21_decimal b;
  b.bits[0] = 0;
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = 2147483648;
  s21_round(a, &a);
  ck_assert_int_eq(a.bits[0], b.bits[0]);
  ck_assert_int_eq(a.bits[1], b.bits[1]);
  ck_assert_int_eq(a.bits[2], b.bits[2]);
  ck_assert_int_eq(a.bits[3], b.bits[3]);
}
END_TEST

START_TEST(test_round_5) {
  s21_decimal a;
  a.bits[0] = 3;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 2147483648;
  set_cap(&a, 1);
  s21_decimal b;
  b.bits[0] = 0;
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = 2147483648;
  s21_round(a, &a);
  ck_assert_int_eq(a.bits[0], b.bits[0]);
  ck_assert_int_eq(a.bits[1], b.bits[1]);
  ck_assert_int_eq(a.bits[2], b.bits[2]);
  ck_assert_int_eq(a.bits[3], b.bits[3]);
}
END_TEST

/* TRUNCATE */
START_TEST(test_truncate_1) {
  s21_decimal a;
  a.bits[0] = 211;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0;
  set_cap(&a, 1);
  s21_decimal b;
  b.bits[0] = 21;
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = 0;
  s21_truncate(a, &a);
  ck_assert_int_eq(a.bits[0], b.bits[0]);
  ck_assert_int_eq(a.bits[1], b.bits[1]);
  ck_assert_int_eq(a.bits[2], b.bits[2]);
  ck_assert_int_eq(a.bits[3], b.bits[3]);
}
END_TEST

START_TEST(test_truncate_2) {
  s21_decimal a;
  a.bits[0] = 165;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 2147483648;
  set_cap(&a, 1);
  s21_decimal b;
  b.bits[0] = 16;
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = 2147483648;
  s21_truncate(a, &a);
  ck_assert_float_eq(a.bits[0], b.bits[0]);
  ck_assert_float_eq(a.bits[1], b.bits[1]);
  ck_assert_float_eq(a.bits[2], b.bits[2]);
  ck_assert_float_eq(a.bits[3], b.bits[3]);
}
END_TEST

START_TEST(test_truncate_3) {
  s21_decimal a;
  a.bits[0] = 2147443413;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0;
  set_cap(&a, 7);
  float n = 214.7443413;
  s21_decimal b;
  b.bits[0] = (int)trunc(n);
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = 0;
  s21_truncate(a, &a);
  ck_assert_int_eq(a.bits[0], b.bits[0]);
  ck_assert_int_eq(a.bits[1], b.bits[1]);
  ck_assert_int_eq(a.bits[2], b.bits[2]);
  ck_assert_int_eq(a.bits[3], b.bits[3]);
}
END_TEST

START_TEST(test_truncate_4) {
  s21_decimal a;
  a.bits[0] = 1000000;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0;
  set_cap(&a, 6);
  s21_truncate(a, &a);
  s21_decimal b;
  b.bits[0] = 1;
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = 0;
  ck_assert_int_eq(a.bits[0], b.bits[0]);
  ck_assert_int_eq(a.bits[1], b.bits[1]);
  ck_assert_int_eq(a.bits[2], b.bits[2]);
  ck_assert_int_eq(a.bits[3], b.bits[3]);
}
END_TEST

START_TEST(test_truncate_5) {
  s21_decimal a;
  a.bits[0] = -1;
  a.bits[1] = -1;
  a.bits[2] = -1;
  a.bits[3] = 0;
  set_cap(&a, 28);
  s21_decimal b;
  b.bits[0] = 7;
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = 0;
  s21_truncate(a, &a);
  ck_assert_float_eq(a.bits[0], b.bits[0]);
  ck_assert_float_eq(a.bits[1], b.bits[1]);
  ck_assert_float_eq(a.bits[2], b.bits[2]);
  ck_assert_float_eq(a.bits[3], b.bits[3]);
}
END_TEST

Suite *example_create() {
  Suite *suite = suite_create("TESTS");

  TCase *tcase_add = tcase_create("ADD");
  tcase_add_test(tcase_add, test_add_1);
  tcase_add_test(tcase_add, test_add_2);
  tcase_add_test(tcase_add, test_add_3);
  tcase_add_test(tcase_add, test_add_4);
  tcase_add_test(tcase_add, test_add_5);
  tcase_add_test(tcase_add, test_add_6);
  tcase_add_test(tcase_add, test_add_7);
  tcase_add_test(tcase_add, test_add_8);
  tcase_add_test(tcase_add, test_add_9);
  tcase_add_test(tcase_add, test_add_10);
  tcase_add_test(tcase_add, test_add_11);
  suite_add_tcase(suite, tcase_add);

  TCase *tcase_sub = tcase_create("SUB");
  tcase_add_test(tcase_sub, test_sub_1);
  tcase_add_test(tcase_sub, test_sub_2);
  tcase_add_test(tcase_sub, test_sub_4);
  tcase_add_test(tcase_sub, test_sub_5);
  tcase_add_test(tcase_sub, test_sub_6);
  tcase_add_test(tcase_sub, test_sub_7);
  tcase_add_test(tcase_sub, test_sub_8);
  tcase_add_test(tcase_sub, test_sub_9);
  tcase_add_test(tcase_sub, test_sub_10);
  tcase_add_test(tcase_sub, test_sub_11);
  suite_add_tcase(suite, tcase_sub);

  TCase *tcase_div = tcase_create("DIV");
  tcase_add_test(tcase_div, test_div_1);
  tcase_add_test(tcase_div, test_div_2);
  tcase_add_test(tcase_div, test_div_3);
  tcase_add_test(tcase_div, test_div_4);
  tcase_add_test(tcase_div, test_div_5);
  tcase_add_test(tcase_div, test_div_6);
  tcase_add_test(tcase_div, test_div_7);
  tcase_add_test(tcase_div, test_div_8);
  tcase_add_test(tcase_div, test_div_9);
  suite_add_tcase(suite, tcase_div);

  TCase *tcase_mul = tcase_create("MUL");
  tcase_add_test(tcase_mul, test_mul_1);
  tcase_add_test(tcase_mul, test_mul_2);
  tcase_add_test(tcase_mul, test_mul_3);
  tcase_add_test(tcase_mul, test_mul_4);
  tcase_add_test(tcase_mul, test_mul_5);
  tcase_add_test(tcase_mul, test_mul_6);
  tcase_add_test(tcase_mul, test_mul_7);
  tcase_add_test(tcase_mul, test_mul_8);
  tcase_add_test(tcase_mul, test_mul_9);
  tcase_add_test(tcase_mul, test_mul_10);
  tcase_add_test(tcase_mul, test_mul_11);
  tcase_add_test(tcase_mul, test_mul_12);
  tcase_add_test(tcase_mul, test_mul_13);
  tcase_add_test(tcase_mul, test_mul_14);
  tcase_add_test(tcase_mul, test_mul_15);
  tcase_add_test(tcase_mul, test_mul_16);
  tcase_add_test(tcase_mul, test_mul_17);
  tcase_add_test(tcase_mul, test_mul_19);
  suite_add_tcase(suite, tcase_mul);

  TCase *tcase_equal = tcase_create("EQUAL");
  tcase_add_test(tcase_equal, test_is_equal_1);
  tcase_add_test(tcase_equal, test_is_equal_2);
  tcase_add_test(tcase_equal, test_is_equal_3);
  tcase_add_test(tcase_equal, test_is_equal_4);
  tcase_add_test(tcase_equal, test_is_equal_5);
  tcase_add_test(tcase_equal, test_is_equal_6);
  tcase_add_test(tcase_equal, test_is_equal_7);
  tcase_add_test(tcase_equal, test_is_equal_8);
  tcase_add_test(tcase_equal, test_is_equal_9);
  tcase_add_test(tcase_equal, test_is_equal_10);
  suite_add_tcase(suite, tcase_equal);

  TCase *tcase_is_greater_or_equal = tcase_create("GREATER_OR_EQUAL");
  tcase_add_test(tcase_is_greater_or_equal, test_is_greater_or_equal_1);
  tcase_add_test(tcase_is_greater_or_equal, test_is_greater_or_equal_2);
  tcase_add_test(tcase_is_greater_or_equal, test_is_greater_or_equal_3);
  tcase_add_test(tcase_is_greater_or_equal, test_is_greater_or_equal_4);
  tcase_add_test(tcase_is_greater_or_equal, test_is_greater_or_equal_5);
  tcase_add_test(tcase_is_greater_or_equal, test_is_greater_or_equal_6);
  tcase_add_test(tcase_is_greater_or_equal, test_is_greater_or_equal_7);
  tcase_add_test(tcase_is_greater_or_equal, test_is_greater_or_equal_8);
  suite_add_tcase(suite, tcase_is_greater_or_equal);

  TCase *tcase_is_greater = tcase_create("GREATER");
  tcase_add_test(tcase_is_greater, test_is_greater_1);
  tcase_add_test(tcase_is_greater, test_is_greater_2);
  tcase_add_test(tcase_is_greater, test_is_greater_3);
  tcase_add_test(tcase_is_greater, test_is_greater_4);
  tcase_add_test(tcase_is_greater, test_is_greater_5);
  tcase_add_test(tcase_is_greater, test_is_greater_6);
  suite_add_tcase(suite, tcase_is_greater);

  TCase *tcase_is_less_or_equal = tcase_create("LESS_OR_EQUAL");
  tcase_add_test(tcase_is_less_or_equal, test_is_less_or_equal_1);
  tcase_add_test(tcase_is_less_or_equal, test_is_less_or_equal_2);
  tcase_add_test(tcase_is_less_or_equal, test_is_less_or_equal_3);
  tcase_add_test(tcase_is_less_or_equal, test_is_less_or_equal_4);
  tcase_add_test(tcase_is_less_or_equal, test_is_less_or_equal_5);
  tcase_add_test(tcase_is_less_or_equal, test_is_less_or_equal_6);
  tcase_add_test(tcase_is_less_or_equal, test_is_less_or_equal_7);
  suite_add_tcase(suite, tcase_is_less_or_equal);

  TCase *tcase_is_less = tcase_create("LESS");
  tcase_add_test(tcase_is_less, test_is_less_1);
  tcase_add_test(tcase_is_less, test_is_less_2);
  tcase_add_test(tcase_is_less, test_is_less_3);
  tcase_add_test(tcase_is_less, test_is_less_4);
  tcase_add_test(tcase_is_less, test_is_less_5);
  suite_add_tcase(suite, tcase_is_less);

  TCase *tcase_not_equal = tcase_create("NOT_EQUAL");
  tcase_add_test(tcase_not_equal, test_is_not_equal_1);
  tcase_add_test(tcase_not_equal, test_is_not_equal_2);
  tcase_add_test(tcase_not_equal, test_is_not_equal_3);
  tcase_add_test(tcase_not_equal, test_is_not_equal_4);
  tcase_add_test(tcase_not_equal, test_is_not_equal_5);
  suite_add_tcase(suite, tcase_not_equal);

  TCase *tcase_dtof = tcase_create("FROM DECIMAL TO FLOAT");
  tcase_add_test(tcase_dtof, from_decimal_to_float_1);
  tcase_add_test(tcase_dtof, from_decimal_to_float_2);
  tcase_add_test(tcase_dtof, from_decimal_to_float_3);
  tcase_add_test(tcase_dtof, from_decimal_to_float_4);
  tcase_add_test(tcase_dtof, from_decimal_to_float_5);
  tcase_add_test(tcase_dtof, from_decimal_to_float_6);
  tcase_add_test(tcase_dtof, from_decimal_to_float_7);
  tcase_add_test(tcase_dtof, from_decimal_to_float_8);
  tcase_add_test(tcase_dtof, from_decimal_to_float_9);
  tcase_add_test(tcase_dtof, from_decimal_to_float_10);
  tcase_add_test(tcase_dtof, from_decimal_to_float_11);
  tcase_add_test(tcase_dtof, from_decimal_to_float_12);
  tcase_add_test(tcase_dtof, from_decimal_to_float_13);
  tcase_add_test(tcase_dtof, from_decimal_to_float_14);
  tcase_add_test(tcase_dtof, from_decimal_to_float_15);
  tcase_add_test(tcase_dtof, from_decimal_to_float_16);
  suite_add_tcase(suite, tcase_dtof);

  TCase *tcase_dtoi = tcase_create("FROM_DECIMAL_TO_INT");
  tcase_add_test(tcase_dtoi, from_decimal_to_int_1);
  tcase_add_test(tcase_dtoi, from_decimal_to_int_2);
  tcase_add_test(tcase_dtoi, from_decimal_to_int_4);
  tcase_add_test(tcase_dtoi, from_decimal_to_int_5);
  suite_add_tcase(suite, tcase_dtoi);

  TCase *tcase_ftod = tcase_create("FROM_FLOAT_TO_DECIMAL");
  tcase_add_test(tcase_ftod, from_float_to_decimal_1);
  tcase_add_test(tcase_ftod, from_float_to_decimal_2);
  tcase_add_test(tcase_ftod, from_float_to_decimal_3);
  tcase_add_test(tcase_ftod, from_float_to_decimal_4);
  tcase_add_test(tcase_ftod, from_float_to_decimal_5);
  tcase_add_test(tcase_ftod, from_float_to_decimal_6);
  tcase_add_test(tcase_ftod, from_float_to_decimal_7);
  tcase_add_test(tcase_ftod, from_float_to_decimal_8);
  tcase_add_test(tcase_ftod, from_float_to_decimal_9);
  suite_add_tcase(suite, tcase_ftod);

  TCase *tcase_itod = tcase_create("FROM_INT_TO_DECIMAL");
  tcase_add_test(tcase_itod, from_int_to_decimal_1);
  tcase_add_test(tcase_itod, from_int_to_decimal_2);
  tcase_add_test(tcase_itod, from_int_to_decimal_3);
  tcase_add_test(tcase_itod, from_int_to_decimal_4);
  tcase_add_test(tcase_itod, from_int_to_decimal_5);
  suite_add_tcase(suite, tcase_itod);

  TCase *tcase_floor = tcase_create("FLOOR");
  tcase_add_test(tcase_floor, test_floor_1);
  tcase_add_test(tcase_floor, test_floor_2);
  tcase_add_test(tcase_floor, test_floor_3);
  tcase_add_test(tcase_floor, test_floor_4);
  suite_add_tcase(suite, tcase_floor);

  TCase *tcase_negate = tcase_create("NEGATE");
  tcase_add_test(tcase_negate, test_negate_1);
  tcase_add_test(tcase_negate, test_negate_2);
  tcase_add_test(tcase_negate, test_negate_3);
  tcase_add_test(tcase_negate, test_negate_4);
  suite_add_tcase(suite, tcase_negate);

  TCase *tcase_round = tcase_create("ROUND");
  tcase_add_test(tcase_round, test_round_1);
  tcase_add_test(tcase_round, test_round_2);
  tcase_add_test(tcase_round, test_round_3);
  tcase_add_test(tcase_round, test_round_4);
  tcase_add_test(tcase_round, test_round_5);
  suite_add_tcase(suite, tcase_round);

  TCase *tcase_truncate = tcase_create("TRUNCATE");
  tcase_add_test(tcase_truncate, test_truncate_1);
  tcase_add_test(tcase_truncate, test_truncate_2);
  tcase_add_test(tcase_truncate, test_truncate_3);
  tcase_add_test(tcase_truncate, test_truncate_4);
  tcase_add_test(tcase_truncate, test_truncate_5);
  suite_add_tcase(suite, tcase_truncate);

  return suite;
}

int main() {
  Suite *s = example_create();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int count = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
