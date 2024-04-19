#ifndef MATH_H
#define MATH_H

#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned int bits[8];
} susper_decimal;

typedef struct {
  unsigned int bits[4];
} s21_decimal;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal dec1, s21_decimal dec2);
int s21_is_less_or_equal(s21_decimal dec1, s21_decimal dec2);
int s21_is_greater(s21_decimal dec1, s21_decimal dec2);
int s21_is_greater_or_equal(s21_decimal dec1, s21_decimal dec2);
int s21_is_equal(s21_decimal dec1, s21_decimal dec2);
int s21_is_not_equal(s21_decimal dec1, s21_decimal dec2);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

int s21_getbit(s21_decimal *dec, int num);
int s21_getmbit(s21_decimal *dec, int num);
void s21_touchbit(s21_decimal *dec, int num, int bit);
int get_cap(s21_decimal *dec);
int set_cap(s21_decimal *dec, int cap);
int getrank(s21_decimal *dec);
int x10dec(s21_decimal *dec1);
int comparison(s21_decimal *dec1, s21_decimal *dec2);

int getmbit(s21_decimal *dec, int num);
int getbit(s21_decimal *dec, int num);
void touchbit(s21_decimal *dec, int num, int bit);

int bank_rounding_div10(s21_decimal *dec);
void sleft(s21_decimal *dec);
unsigned int divx10(s21_decimal *dec);
int getsig(s21_decimal *dec);
unsigned int remdivx10(s21_decimal *dec);
int increase_mant_1(s21_decimal *dec);
int normalize(s21_decimal *dec1, s21_decimal *dec2);
int invert(int i);
int first1(s21_decimal *dec);
int deadder(s21_decimal *dec1, s21_decimal *dec2, s21_decimal *dec3);
void *mmemset(void *ptr, int value, size_t num);
int adder(s21_decimal *dec1, s21_decimal *dec2, s21_decimal *dec3);
void sright(s21_decimal *dec);
int is_zero(s21_decimal *dec);
int adder_wo_normalize(s21_decimal *dec1, s21_decimal *dec2, s21_decimal *dec3);

int sd_getbit(susper_decimal *dec, int num);
void sd_touchbit(susper_decimal *dec, int num, int bit);
int sd_first1(susper_decimal *dec);
unsigned int sd_divx10(susper_decimal *dec);
void sd_sleft(susper_decimal *dec);
void sd_bank_rounding_div10(susper_decimal *dec);
int sd_increase_mant_1(susper_decimal *dec);
int lengh(int a);
void x10mant(s21_decimal *dec1);

void DecToBin(int n, int i, s21_decimal *dec);

int s21_get_exp(s21_decimal dec);

#endif