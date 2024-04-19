#include <check.h>
#include <string.h>

#include "s21_string.h"

/* ADD */
START_TEST(test_sscanf_1) {
  int a1;
  int a2;
  //   long double ld1;
  //   long double ld2;
  char *str = "16776 567";
  char *format = "%d %*d";
  sscanf(str, format, &a1);
  s21_sscanf(str, format, &a2);
  ck_assert_int_eq(a1, a2);

  //   char str1[20];
  //   char str2[20];
  str = "16776 567";
  format = "%*s %d";
  //   sscanf(str, format, &a1);
  //   s21_sscanf(str, format, &a2);
  ck_assert_int_eq(sscanf(str, format, &a1), s21_sscanf(str, format, &a2));
  // printf("\n\n%d\n\n", a1);
  ck_assert_int_eq(a1, a2);

  int b1;
  int b2;
  float bi1;
  float bi2;
  long double am1;
  long double am2;
  str = "1.2543 567";
  format = "%Lf %d";
  ck_assert_int_eq(sscanf(str, format, &am1, &b1),
                   s21_sscanf(str, format, &am2, &b2));
  // printf("\n\n%d\n\n", b1);
  // printf("\n\n%d\n\n", b2);
  ck_assert_int_eq(am1, am2);
  ck_assert_int_eq(b1, b2);

  float f1;
  float f2;
  str = "1.234 567 876";
  format = "%f %d %d";
  ck_assert_int_eq(sscanf(str, format, &f1, &a1, &b1),
                   s21_sscanf(str, format, &f2, &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(f1, f2);

  long double lf1;
  long double lf2;
  str = "1.234 567 876";
  format = "%Lf %d %d";
  ck_assert_int_eq(sscanf(str, format, &lf1, &a1, &b1),
                   s21_sscanf(str, format, &lf2, &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(lf1, lf2);

  str = "1.234 567 876";
  format = "%Le %d %d";
  ck_assert_int_eq(sscanf(str, format, &lf1, &a1, &b1),
                   s21_sscanf(str, format, &lf2, &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(lf1, lf2);

  str = "1.234 567 876";
  format = "%LE %d %d";
  ck_assert_int_eq(sscanf(str, format, &lf1, &a1, &b1),
                   s21_sscanf(str, format, &lf2, &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(lf1, lf2);

  str = "1.234 567 876";
  format = "%Lg %d %d";
  ck_assert_int_eq(sscanf(str, format, &lf1, &a1, &b1),
                   s21_sscanf(str, format, &lf2, &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(lf1, lf2);

  str = "1.234 567 876";
  format = "%LG %d %d";
  ck_assert_int_eq(sscanf(str, format, &lf1, &a1, &b1),
                   s21_sscanf(str, format, &lf2, &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(lf1, lf2);

  str = "1.234 567 876";
  format = "%4LG %d %d";
  ck_assert_int_eq(sscanf(str, format, &lf1, &a1, &b1),
                   s21_sscanf(str, format, &lf2, &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(lf1, lf2);

  long int li1;
  long int li2;
  str = "1263213423234434 567 876";
  format = "%li %d %d";
  ck_assert_int_eq(sscanf(str, format, &li1, &a1, &b1),
                   s21_sscanf(str, format, &li2, &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(li1, li2);

  str = "1263213423234434 567 876";
  format = "%ld %d %d";
  ck_assert_int_eq(sscanf(str, format, &li1, &a1, &b1),
                   s21_sscanf(str, format, &li2, &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(li1, li2);

  str = "1263213423234434 567 876";
  format = "%lo %d %d";
  ck_assert_int_eq(sscanf(str, format, &li1, &a1, &b1),
                   s21_sscanf(str, format, &li2, &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(li1, li2);

  str = "-1263213423234434 567 876";
  format = "%lo %d %d";
  ck_assert_int_eq(sscanf(str, format, &li1, &a1, &b1),
                   s21_sscanf(str, format, &li2, &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(li1, li2);

  long int li3 = 0;
  long int li4 = 0;
  str = "126321 567 876";
  format = "%lx %d %d";
  ck_assert_int_eq(sscanf(str, format, &li3, &a1, &b1),
                   s21_sscanf(str, format, &li4, &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(li3, li4);
  li3 = 0;
  li4 = 0;

  str = "126321 567 876";
  format = "%lX %d %d";
  ck_assert_int_eq(sscanf(str, format, &li3, &a1, &b1),
                   s21_sscanf(str, format, &li4, &a2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(li3, li4);

  unsigned int u1;
  unsigned int u2;
  str = "126321 567 876";
  format = "%u %d";
  ck_assert_int_eq(sscanf(str, format, &u1, &b1),
                   s21_sscanf(str, format, &u2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);

  str = "126321 567 876";
  format = "%lu %d";
  ck_assert_int_eq(sscanf(str, format, &u1, &b1),
                   s21_sscanf(str, format, &u2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);

  str = "126321 567 876";
  format = "%hu %d";
  ck_assert_int_eq(sscanf(str, format, &u1, &b1),
                   s21_sscanf(str, format, &u2, &b2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);

  long unsigned int lu1;
  long unsigned int lu2;
  str = "126321 567 876";
  format = "%lu %d";
  ck_assert_int_eq(sscanf(str, format, &lu1, &b1),
                   s21_sscanf(str, format, &lu2, &b2));
  ck_assert_int_eq(lu1, lu2);
  ck_assert_int_eq(b1, b2);
  lu1 = 0;
  lu2 = 0;

  str = "-1623542534 56";
  format = "%lu %d";
  ck_assert_int_eq(sscanf(str, format, &lu1, &b1),
                   s21_sscanf(str, format, &lu2, &b2));
  ck_assert_int_eq(lu1, lu2);
  ck_assert_int_eq(b1, b2);

  short int si1;
  short int si2;
  str = "-16235 56";
  format = "%hi %d";
  ck_assert_int_eq(sscanf(str, format, &si1, &b1),
                   s21_sscanf(str, format, &si2, &b2));
  ck_assert_int_eq(si1, si2);
  ck_assert_int_eq(b1, b2);
  si1 = 0;
  si2 = 0;

  str = "-1623 56";
  format = "%hd %d";
  ck_assert_int_eq(sscanf(str, format, &si1, &b1),
                   s21_sscanf(str, format, &si2, &b2));
  ck_assert_int_eq(si1, si2);
  ck_assert_int_eq(b1, b2);
  si1 = 0;
  si2 = 0;

  str = "-1623 56";
  format = "%5hd %d";
  ck_assert_int_eq(sscanf(str, format, &si1, &b1),
                   s21_sscanf(str, format, &si2, &b2));
  ck_assert_int_eq(si1, si2);
  ck_assert_int_eq(b1, b2);
  si1 = 0;
  si2 = 0;

  str = "-1623 56";
  b1 = 0;
  b2 = 0;
  format = "%ho %d";
  ck_assert_int_eq(sscanf(str, format, &si1, &b1),
                   s21_sscanf(str, format, &si2, &b2));
  ck_assert_int_eq(si1, si2);
  ck_assert_int_eq(b1, b2);

  str = "-13abc 56";
  b1 = 0;
  b2 = 0;
  format = "%hx %d";
  ck_assert_int_eq(sscanf(str, format, &si1, &b1),
                   s21_sscanf(str, format, &si2, &b2));
  ck_assert_int_eq(si1, si2);
  ck_assert_int_eq(b1, b2);
  si1 = 0;
  si2 = 0;

  str = "-13abc 56";
  b1 = 0;
  b2 = 0;
  si1 = 0;
  si2 = 0;
  format = "%hX %d";
  ck_assert_int_eq(sscanf(str, format, &si1, &b1),
                   s21_sscanf(str, format, &si2, &b2));
  ck_assert_int_eq(si1, si2);
  ck_assert_int_eq(b1, b2);

  int h1 = 0, h2 = 0;
  // b1 = 0; b2 = 0;
  str = "-13abc";
  format = "%X";
  ck_assert_int_eq(sscanf(str, format, &h1), s21_sscanf(str, format, &h2));
  ck_assert_int_eq(h1, h2);

  str = "-13abc mam 56";
  format = "%x mam %d";
  ck_assert_int_eq(sscanf(str, format, &h1, &b1),
                   s21_sscanf(str, format, &h2, &b2));
  ck_assert_int_eq(h1, h2);
  ck_assert_int_eq(b1, b2);
  h1 = 0;
  h2 = 0;

  str = "1763 mam 56";
  format = "%o mam %d";
  ck_assert_int_eq(sscanf(str, format, &h1, &b1),
                   s21_sscanf(str, format, &h2, &b2));
  ck_assert_int_eq(h1, h2);
  ck_assert_int_eq(b1, b2);

  char c1, c2;
  c1 = 0, c2 = 0;
  str = "1 2 mam56";
  format = "%*c %c mam %d";
  ck_assert_int_eq(sscanf(str, format, &c1, &b1),
                   s21_sscanf(str, format, &c2, &b2));
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(b1, b2);

  c1 = 0, c2 = 0;
  str = "1  2mam56";
  format = "%*c  %cmam %d";
  ck_assert_int_eq(sscanf(str, format, &c1, &b1),
                   s21_sscanf(str, format, &c2, &b2));
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(b1, b2);

  float fl1, fl2;
  str = "1.2345 mam56";
  format = "%f mam %d";
  ck_assert_int_eq(sscanf(str, format, &fl1, &b1),
                   s21_sscanf(str, format, &fl2, &b2));
  ck_assert_int_eq(fl1, fl2);
  ck_assert_int_eq(b1, b2);
  f1 = 0;
  f2 = 0;

  str = "1.2345 mam56";
  format = "%e mam %d";
  ck_assert_int_eq(sscanf(str, format, &fl1, &b1),
                   s21_sscanf(str, format, &fl2, &b2));
  ck_assert_int_eq(fl1, fl2);
  ck_assert_int_eq(b1, b2);
  f1 = 0;
  f2 = 0;

  str = "1.2345 mam56";
  format = "%E mam %d";
  ck_assert_int_eq(sscanf(str, format, &fl1, &b1),
                   s21_sscanf(str, format, &fl2, &b2));
  ck_assert_int_eq(fl1, fl2);
  ck_assert_int_eq(b1, b2);
  fl1 = 0;
  fl2 = 0;

  float g1, g2;
  char *str1 = "1.2345";
  char *format1 = "%g";
  ck_assert_int_eq(sscanf(str1, format1, &g1), s21_sscanf(str1, format1, &g2));
  ck_assert_int_eq(g1, g2);

  b1 = 0;
  b2 = 0;
  str = "1.2345 mam 56";
  format = "%G mam %d";
  ck_assert_int_eq(sscanf(str, format, &fl1, &b1),
                   s21_sscanf(str, format, &fl2, &b2));
  ck_assert_int_eq(fl1, fl2);

  str = "1.2345 %mam56";
  format = "%3f %%mam %d";
  ck_assert_int_eq(sscanf(str, format, &fl1, &b1),
                   s21_sscanf(str, format, &fl2, &b2));
  ck_assert_int_eq(fl1, fl2);
  ck_assert_int_eq(b1, b2);
  f1 = 0;
  f2 = 0;

  str = "1.2345 %%mam56";
  format = "%3f %%%%mam %d";
  ck_assert_int_eq(sscanf(str, format, &fl1, &b1),
                   s21_sscanf(str, format, &fl2, &b2));
  ck_assert_int_eq(fl1, fl2);
  ck_assert_int_eq(b1, b2);
  f1 = 0;
  f2 = 0;
}
END_TEST

START_TEST(test_formd_1) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%010d>", 12);
  s21 = s21_sprintf(str_2, "<%010d>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formd_2) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%010d>", -12);
  s21 = s21_sprintf(str_2, "<%010d>", -12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formd_3) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+10d>", 12);
  s21 = s21_sprintf(str_2, "<%+10d>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formd_4) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+10d>", -12);
  s21 = s21_sprintf(str_2, "<%+10d>", -12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formd_5) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%0-10d>", 12);
  s21 = s21_sprintf(str_2, "<%0-10d>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formd_6) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%0-10d>", 12);
  s21 = s21_sprintf(str_2, "<%0-10d>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formd_7) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%0-+10d>", 12);
  s21 = s21_sprintf(str_2, "<%0-+10d>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formd_8) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-010d>", 12);
  s21 = s21_sprintf(str_2, "<%-010d>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formd_9) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+3d>", 1212);
  s21 = s21_sprintf(str_2, "<%+3d>", 1212);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formd_10) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-5d>", -121212);
  s21 = s21_sprintf(str_2, "<%-5d>", -121212);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formd_11) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<% 10d>", 128989);
  s21 = s21_sprintf(str_2, "<% 10d>", 128989);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formd_12) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<% .d>", 128989);
  s21 = s21_sprintf(str_2, "<% .d>", 128989);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formd_13) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<% 2.d>", -1289891212);
  s21 = s21_sprintf(str_2, "<% 2.d>", -1289891212);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formd_14) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-02.3d>", 1);
  s21 = s21_sprintf(str_2, "<%-02.3d>", 1);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formd_15) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-02.3d>", 0);
  s21 = s21_sprintf(str_2, "<%-02.3d>", 0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formd_16) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%07.3d>", 0);
  s21 = s21_sprintf(str_2, "<%07.3d>", 0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formd_17) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%07.15d>", 0);
  s21 = s21_sprintf(str_2, "<%07.15d>", 0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formd_18) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+07.7d>", 1);
  s21 = s21_sprintf(str_2, "<%+07.7d>", 1);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formd_19) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+-07.3d>", 0);
  s21 = s21_sprintf(str_2, "<%+-07.3d>", 0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formd_20) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-07.3d>", 123);
  s21 = s21_sprintf(str_2, "<%-07.3d>", 123);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST
START_TEST(test_formd_21) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+02.3d>", -12);
  s21 = s21_sprintf(str_2, "<%+02.3d>", -12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formd_22) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+02.3hd>", -12);
  s21 = s21_sprintf(str_2, "<%+02.3hd>", -12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formd_25) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%010d>", -0);
  s21 = s21_sprintf(str_2, "<%010d>", -0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formd_26) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%010d>", -1);
  s21 = s21_sprintf(str_2, "<%010d>", -1);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_1) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-1.4f>", 128989.0);
  s21 = s21_sprintf(str_2, "<%-1.4f>", 128989.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_2) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%- 2.f>", 128989.12);
  s21 = s21_sprintf(str_2, "<%- 2.f>", 128989.12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_3) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-+ 2.0f>", -0.0);
  s21 = s21_sprintf(str_2, "<%-+ 2.0f>", -0.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_4) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-+0 2.f>", 1.123456);
  s21 = s21_sprintf(str_2, "<%-+0 2.f>", 1.123456);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_5) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%20.2f>", -0.128989);
  s21 = s21_sprintf(str_2, "<%20.2f>", -0.128989);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_6) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%02.20f>", 0.0);
  s21 = s21_sprintf(str_2, "<%02.20f>", 0.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_7) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-2.6f>", 128989.1, 128989.0);
  s21 = s21_sprintf(str_2, "<%-2.6f>", 128989.1);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_8) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+2.f>", -12.12121212121212121212);
  s21 = s21_sprintf(str_2, "<%+2.f>", -12.12121212121212121212);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_9) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+01.2f>", -1.12);
  s21 = s21_sprintf(str_2, "<%+01.2f>", -1.12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_10) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<% 2.4f>", -123.123128989);
  s21 = s21_sprintf(str_2, "<% 2.4f>", -123.123128989);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_11) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-2.8f>", 123.123128989);
  s21 = s21_sprintf(str_2, "<%-2.8f>", 123.123128989);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_12) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%02.f>", -123.123128989);
  s21 = s21_sprintf(str_2, "<%02.f>", -123.123128989);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_13) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-+0 2.3f>", -128989.1234);
  s21 = s21_sprintf(str_2, "<%-+0 2.3f>", -128989.1234);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_14) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  long double ld = -0.1234;
  ori = sprintf(str_1, "<%-02.3Lf>", ld);
  s21 = s21_sprintf(str_2, "<%-02.3Lf>", ld);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_15) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%23.15f>", 323.120);
  s21 = s21_sprintf(str_2, "<%23.15f>", 323.120);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_16) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-10.4f>",
                0.0000000000000000000000000000000000000000000000001);
  s21 = s21_sprintf(str_2, "<%-10.4f>",
                    0.0000000000000000000000000000000000000000000000001);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_17) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%10.f>", 128989.124);
  s21 = s21_sprintf(str_2, "<%10.f>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_18) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  long double ld = 128989.124;
  ori = sprintf(str_1, "<%5Lf>", ld);
  s21 = s21_sprintf(str_2, "<%5Lf>", ld);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_19) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  long double ld = 0;
  ori = sprintf(str_1, "<%05Lf>", ld);
  s21 = s21_sprintf(str_2, "<%05Lf>", ld);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_20) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-5f>", 0.0);
  s21 = s21_sprintf(str_2, "<%-5f>", 0.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_21) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+5fL>", 0.0);
  s21 = s21_sprintf(str_2, "<%+5fL>", 0.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_22) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%#4.0f>", 12.0);
  s21 = s21_sprintf(str_2, "<%#4.0f>", 12.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_23) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-#4.0f>", 12.0);
  s21 = s21_sprintf(str_2, "<%-#4.0f>", 12.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_24) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%014.8f>", -0.0001234999);
  s21 = s21_sprintf(str_2, "<%014.8f>", -0.0001234999);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_25) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%#04.0f>", 12.0);
  s21 = s21_sprintf(str_2, "<%#04.0f>", 12.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formf_26) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%#04.0f>", 121212121.0);
  s21 = s21_sprintf(str_2, "<%#04.0f>", 121212121.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formo_1) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%010o>", 12);
  s21 = s21_sprintf(str_2, "<%010o>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formo_2) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%010d>", -12);
  s21 = s21_sprintf(str_2, "<%010d>", -12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formo_3) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+10o>", 12);
  s21 = s21_sprintf(str_2, "<%+10o>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formo_4) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%#+10o>", -12);
  s21 = s21_sprintf(str_2, "<%#+10o>", -12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formo_5) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%0-10o>", 12);
  s21 = s21_sprintf(str_2, "<%0-10o>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formo_6) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%#0-10o>", 12);
  s21 = s21_sprintf(str_2, "<%#0-10o>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formo_7) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%0-+10o>", 12);
  s21 = s21_sprintf(str_2, "<%0-+10o>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formo_8) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-010o>", 12);
  s21 = s21_sprintf(str_2, "<%-010o>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formo_9) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+3o>", 1212);
  s21 = s21_sprintf(str_2, "<%+3o>", 1212);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formo_10) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-5o>", -121212);
  s21 = s21_sprintf(str_2, "<%-5o>", -121212);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formo_11) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<% 10o>", 128989);
  s21 = s21_sprintf(str_2, "<% 10o>", 128989);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formo_12) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<% .o>", 128989);
  s21 = s21_sprintf(str_2, "<% .o>", 128989);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formo_13) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<% #2.o>", -1289891212);
  s21 = s21_sprintf(str_2, "<% #2.o>", -1289891212);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formo_14) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-02.3o>", 1);
  s21 = s21_sprintf(str_2, "<%-02.3o>", 1);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formo_15) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-02.3o>", 0);
  s21 = s21_sprintf(str_2, "<%-02.3o>", 0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formo_16) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%07.3o>", 0);
  s21 = s21_sprintf(str_2, "<%07.3o>", 0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formo_17) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%07.15o>", 0);
  s21 = s21_sprintf(str_2, "<%07.15o>", 0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formo_18) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+07.7o>", 1);
  s21 = s21_sprintf(str_2, "<%+07.7o>", 1);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formo_19) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+-07.3o>", 0);
  s21 = s21_sprintf(str_2, "<%+-07.3o>", 0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formo_20) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-07.3o>", 123);
  s21 = s21_sprintf(str_2, "<%-07.3o>", 123);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST
START_TEST(test_formo_21) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+02.3o>", -12);
  s21 = s21_sprintf(str_2, "<%+02.3o>", -12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formu_1) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%010u>", 12);
  s21 = s21_sprintf(str_2, "<%010u>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formu_2) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%010u>", -12);
  s21 = s21_sprintf(str_2, "<%010u>", -12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formu_3) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+10u>", 12);
  s21 = s21_sprintf(str_2, "<%+10u>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formu_4) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%#+10u>", -12);
  s21 = s21_sprintf(str_2, "<%#+10u>", -12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formu_5) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%0-10u>", 12);
  s21 = s21_sprintf(str_2, "<%0-10u>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formu_6) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%#0-10u>", 12);
  s21 = s21_sprintf(str_2, "<%#0-10u>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formu_7) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%0-+10u>", 12);
  s21 = s21_sprintf(str_2, "<%0-+10u>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formu_8) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-010u>", 12);
  s21 = s21_sprintf(str_2, "<%-010u>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formu_9) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+3u>", 1212);
  s21 = s21_sprintf(str_2, "<%+3u>", 1212);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formu_10) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-5u>", -121212);
  s21 = s21_sprintf(str_2, "<%-5u>", -121212);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formu_11) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<% 10u>", 128989);
  s21 = s21_sprintf(str_2, "<% 10u>", 128989);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formu_12) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<% .u>", 128989);
  s21 = s21_sprintf(str_2, "<% .u>", 128989);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formu_13) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<% #2.u>", -1289891212);
  s21 = s21_sprintf(str_2, "<% #2.u>", -1289891212);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formu_14) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-02.3u>", 1);
  s21 = s21_sprintf(str_2, "<%-02.3u>", 1);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formu_15) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-02.3u>", 0);
  s21 = s21_sprintf(str_2, "<%-02.3u>", 0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formu_16) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%07.3u>", 0);
  s21 = s21_sprintf(str_2, "<%07.3u>", 0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formu_17) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%07.15u>", 0);
  s21 = s21_sprintf(str_2, "<%07.15u>", 0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formu_18) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+07.7u>", 1);
  s21 = s21_sprintf(str_2, "<%+07.7u>", 1);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formu_19) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+-07.3u>", 0);
  s21 = s21_sprintf(str_2, "<%+-07.3u>", 0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formu_20) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-07.3u>", 123);
  s21 = s21_sprintf(str_2, "<%-07.3u>", 123);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST
START_TEST(test_formu_21) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+02.3u>", -12);
  s21 = s21_sprintf(str_2, "<%+02.3u>", -12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formx_1) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  sprintf(str_1, "<%010x>", 12);
  s21_sprintf(str_2, "<%010x>", 12);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formx_2) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%010x>", -12);
  s21 = s21_sprintf(str_2, "<%010x>", -12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formx_3) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+10x>", 12);
  s21 = s21_sprintf(str_2, "<%+10x>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formx_4) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%#+10x>", -12);
  s21 = s21_sprintf(str_2, "<%#+10x>", -12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formx_5) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%0-10x>", 12);
  s21 = s21_sprintf(str_2, "<%0-10x>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formx_6) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%#0-10x>", 12);
  s21 = s21_sprintf(str_2, "<%#0-10x>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formx_7) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%0-+10x>", 12);
  s21 = s21_sprintf(str_2, "<%0-+10x>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formx_8) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-010x>", 12);
  s21 = s21_sprintf(str_2, "<%-010x>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formx_9) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+3x>", 1212);
  s21 = s21_sprintf(str_2, "<%+3x>", 1212);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formx_10) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-5x>", -121212);
  s21 = s21_sprintf(str_2, "<%-5x>", -121212);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formx_11) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<% 10x>", 128989);
  s21 = s21_sprintf(str_2, "<% 10x>", 128989);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formx_12) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<% .x>", 128989);
  s21 = s21_sprintf(str_2, "<% .x>", 128989);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formx_13) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<% #2.x>", -1289891212);
  s21 = s21_sprintf(str_2, "<% #2.x>", -1289891212);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formx_14) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-02.3x>", 1);
  s21 = s21_sprintf(str_2, "<%-02.3x>", 1);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formx_15) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-02.3x>", 0);
  s21 = s21_sprintf(str_2, "<%-02.3x>", 0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formx_16) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%#07.3x>", 0);
  s21 = s21_sprintf(str_2, "<%#07.3x>", 0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formx_17) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%07.15x>", 0);
  s21 = s21_sprintf(str_2, "<%07.15x>", 0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formx_18) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+07.7x>", 1);
  s21 = s21_sprintf(str_2, "<%+07.7x>", 1);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formx_19) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+-07.3x>", 0);
  s21 = s21_sprintf(str_2, "<%+-07.3x>", 0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formx_20) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-07.3x>", 123);
  s21 = s21_sprintf(str_2, "<%-07.3x>", 123);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST
START_TEST(test_formx_21) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+02.3x>", -12);
  s21 = s21_sprintf(str_2, "<%+02.3x>", -12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formX_1) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%010X>", 12);
  s21 = s21_sprintf(str_2, "<%010X>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formX_2) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%010X>", -12);
  s21 = s21_sprintf(str_2, "<%010X>", -12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formX_3) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+10X>", 12);
  s21 = s21_sprintf(str_2, "<%+10X>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formX_4) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%#+10X>", -12);
  s21 = s21_sprintf(str_2, "<%#+10X>", -12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formX_5) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%0-10X>", 12);
  s21 = s21_sprintf(str_2, "<%0-10X>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formX_6) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%#0-10X>", 12);
  s21 = s21_sprintf(str_2, "<%#0-10X>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formX_7) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%0-+10X>", 12);
  s21 = s21_sprintf(str_2, "<%0-+10X>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formX_8) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-010X>", 12);
  s21 = s21_sprintf(str_2, "<%-010X>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formX_9) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+3X>", 1212);
  s21 = s21_sprintf(str_2, "<%+3X>", 1212);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formX_10) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-5X>", -121212);
  s21 = s21_sprintf(str_2, "<%-5X>", -121212);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formX_11) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<% 10X>", 128989);
  s21 = s21_sprintf(str_2, "<% 10X>", 128989);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formX_12) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<% .X>", 128989);
  s21 = s21_sprintf(str_2, "<% .X>", 128989);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formX_13) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<% #2.X>", -1289891212);
  s21 = s21_sprintf(str_2, "<% #2.X>", -1289891212);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formX_14) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-02.3X>", 1);
  s21 = s21_sprintf(str_2, "<%-02.3X>", 1);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formX_15) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-02.3X>", 0);
  s21 = s21_sprintf(str_2, "<%-02.3X>", 0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formX_16) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%#07.3X>", 0);
  s21 = s21_sprintf(str_2, "<%#07.3X>", 0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formX_17) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%07.15X>", 0);
  s21 = s21_sprintf(str_2, "<%07.15X>", 0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formX_18) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+07.7X>", 1);
  s21 = s21_sprintf(str_2, "<%+07.7X>", 1);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formX_19) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+-07.3X>", 0);
  s21 = s21_sprintf(str_2, "<%+-07.3X>", 0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formX_20) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-07.3x>", 123);
  s21 = s21_sprintf(str_2, "<%-07.3x>", 123);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST
START_TEST(test_formX_21) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+02.3X>", -12);
  s21 = s21_sprintf(str_2, "<%+02.3X>", -12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_1) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-1.4e>", 128989.1);
  s21 = s21_sprintf(str_2, "<%-1.4e>", 128989.1);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_2) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-01.4e>", 128989.0);
  s21 = s21_sprintf(str_2, "<%-01.4e>", 128989.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_3) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-17.4e>", 128989.12);
  s21 = s21_sprintf(str_2, "<%-17.4e>", 128989.12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_4) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-1.14e>", 128989.124);
  s21 = s21_sprintf(str_2, "<%-1.14e>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_5) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-1.4e>", 0.0);
  s21 = s21_sprintf(str_2, "<%-1.4e>", 0.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_6) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-01.4e>", 0.0);
  s21 = s21_sprintf(str_2, "<%-01.4e>", 0.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_7) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-+10.4e>", 128989.0);
  s21 = s21_sprintf(str_2, "<%-+10.4e>", 128989.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_8) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-+1.15e>", 128989.0);
  s21 = s21_sprintf(str_2, "<%-+1.15e>", 128989.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_9) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-1.4e>", 1289898768.0);
  s21 = s21_sprintf(str_2, "<%-1.4e>", 1289898768.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_10) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-1.4e>",
                0.0000000000000000000000000000000000000000000000001);
  s21 = s21_sprintf(str_2, "<%-1.4e>",
                    0.0000000000000000000000000000000000000000000000001);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_11) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-01.4e>",
                0.0000000000000000000000000000000000000000000000001);
  s21 = s21_sprintf(str_2, "<%-01.4e>",
                    0.0000000000000000000000000000000000000000000000001);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_12) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-10.4e>",
                0.0000000000000000000000000000000000000000000000001);
  s21 = s21_sprintf(str_2, "<%-10.4e>",
                    0.0000000000000000000000000000000000000000000000001);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_13) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-1.0e>",
                0.0000000000000000000000000000000000000000000000001);
  s21 = s21_sprintf(str_2, "<%-1.0e>",
                    0.0000000000000000000000000000000000000000000000001);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_14) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%- 10.8e>", 128989.124);
  s21 = s21_sprintf(str_2, "<%- 10.8e>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_15) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-+10.8e>", 128989.124);
  s21 = s21_sprintf(str_2, "<%-+10.8e>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_16) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%10.8e>", 128989.124);
  s21 = s21_sprintf(str_2, "<%10.8e>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_17) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%10.14e>", 128989.124);
  s21 = s21_sprintf(str_2, "<%10.14e>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_18) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%010.8e>", 128989.124);
  s21 = s21_sprintf(str_2, "<%010.8e>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_19) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+010.8e>", 128989.124);
  s21 = s21_sprintf(str_2, "<%+010.8e>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_20) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+ 10.8e>", 128989.124);
  s21 = s21_sprintf(str_2, "<%+ 10.8e>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_21) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%10.e>", 128989.124);
  s21 = s21_sprintf(str_2, "<%10.e>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_22) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%10e>", 128989.124);
  s21 = s21_sprintf(str_2, "<%10e>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_23) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%5e>", 128989.124);
  s21 = s21_sprintf(str_2, "<%5e>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_24) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%0.8e>", 128989.124);
  s21 = s21_sprintf(str_2, "<%0.8e>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_25) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+8e>", 128989.124);
  s21 = s21_sprintf(str_2, "<%+8e>", 128989.124);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_26) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<% 8e>", 128989.124);
  s21 = s21_sprintf(str_2, "<% 8e>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_27) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%10.8e>", -128989.124);
  s21 = s21_sprintf(str_2, "<%10.8e>", -128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_28) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-10.8e>", -128989.124);
  s21 = s21_sprintf(str_2, "<%-10.8e>", -128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_29) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<% 10.8e>", -128989.124);
  s21 = s21_sprintf(str_2, "<% 10.8e>", -128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_30) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+-010.8e>", -128989.124);
  s21 = s21_sprintf(str_2, "<%+-010.8e>", -128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_31) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%0.8e>", -128989.124);
  s21 = s21_sprintf(str_2, "<%0.8e>", -128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_32) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-10.8e>", -128989.124);
  s21 = s21_sprintf(str_2, "<%-10.8e>", -128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_33) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%23.15e>", 323.120);
  s21 = s21_sprintf(str_2, "<%23.15e>", 323.120);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_34) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%#4.0e>", 12.0);
  s21 = s21_sprintf(str_2, "<%#4.0e>", 12.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_35) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%23.15e>", 0.0);
  s21 = s21_sprintf(str_2, "<%23.15e>", 0.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forme_36) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-#23.0e>", 0.0);
  s21 = s21_sprintf(str_2, "<%-#23.0e>", 0.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_1) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-1.4E>", 128989.1);
  s21 = s21_sprintf(str_2, "<%-1.4E>", 128989.1);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_2) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-01.4E>", 128989.0);
  s21 = s21_sprintf(str_2, "<%-01.4E>", 128989.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_3) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-17.4E>", 128989.12);
  s21 = s21_sprintf(str_2, "<%-17.4E>", 128989.12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_4) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-1.14E>", 128989.124);
  s21 = s21_sprintf(str_2, "<%-1.14E>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_5) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-1.4E>", 0.0);
  s21 = s21_sprintf(str_2, "<%-1.4E>", 0.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_6) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-01.4E>", 0.0);
  s21 = s21_sprintf(str_2, "<%-01.4E>", 0.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_7) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-+10.4E>", 128989.0);
  s21 = s21_sprintf(str_2, "<%-+10.4E>", 128989.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_8) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-+1.15E>", 128989.0);
  s21 = s21_sprintf(str_2, "<%-+1.15E>", 128989.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_9) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-1.4E>", 1289898768.0);
  s21 = s21_sprintf(str_2, "<%-1.4E>", 1289898768.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_10) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-1.4E>",
                0.0000000000000000000000000000000000000000000000001);
  s21 = s21_sprintf(str_2, "<%-1.4E>",
                    0.0000000000000000000000000000000000000000000000001);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_11) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-01.4E>",
                0.0000000000000000000000000000000000000000000000001);
  s21 = s21_sprintf(str_2, "<%-01.4E>",
                    0.0000000000000000000000000000000000000000000000001);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_12) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-10.4E>",
                0.0000000000000000000000000000000000000000000000001);
  s21 = s21_sprintf(str_2, "<%-10.4E>",
                    0.0000000000000000000000000000000000000000000000001);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_13) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-1.0E>",
                0.0000000000000000000000000000000000000000000000001);
  s21 = s21_sprintf(str_2, "<%-1.0E>",
                    0.0000000000000000000000000000000000000000000000001);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_14) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%- 10.8E>", 128989.124);
  s21 = s21_sprintf(str_2, "<%- 10.8E>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_15) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-+10.8E>", 128989.124);
  s21 = s21_sprintf(str_2, "<%-+10.8E>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_16) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%10.8E>", 128989.124);
  s21 = s21_sprintf(str_2, "<%10.8E>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_17) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%10.14E>", 128989.124);
  s21 = s21_sprintf(str_2, "<%10.14E>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_18) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%010.8E>", 128989.124);
  s21 = s21_sprintf(str_2, "<%010.8E>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_19) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+010.8E>", 128989.124);
  s21 = s21_sprintf(str_2, "<%+010.8E>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_20) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+ 10.8E>", 128989.124);
  s21 = s21_sprintf(str_2, "<%+ 10.8E>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_21) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%10.E>", 128989.124);
  s21 = s21_sprintf(str_2, "<%10.E>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_22) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%10E>", 128989.124);
  s21 = s21_sprintf(str_2, "<%10E>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_23) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%5E>", 128989.124);
  s21 = s21_sprintf(str_2, "<%5E>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_24) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%0.8E>", 128989.124);
  s21 = s21_sprintf(str_2, "<%0.8E>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_25) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+8E>", 128989.124);
  s21 = s21_sprintf(str_2, "<%+8E>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_26) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<% 8E>", 128989.124);
  s21 = s21_sprintf(str_2, "<% 8E>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_27) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%10.8E>", -128989.124);
  s21 = s21_sprintf(str_2, "<%10.8E>", -128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_28) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-10.8E>", -128989.124);
  s21 = s21_sprintf(str_2, "<%-10.8E>", -128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_29) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<% 10.8E>", -128989.124);
  s21 = s21_sprintf(str_2, "<% 10.8E>", -128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_30) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+-010.8E>", -128989.124);
  s21 = s21_sprintf(str_2, "<%+-010.8E>", -128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_31) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%0.8E>", -128989.124);
  s21 = s21_sprintf(str_2, "<%0.8E>", -128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_32) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-10.8E>", -128989.124);
  s21 = s21_sprintf(str_2, "<%-10.8E>", -128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_33) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%23.15E>", 323.120);
  s21 = s21_sprintf(str_2, "<%23.15E>", 323.120);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formE_34) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%23.15E>", 0.0);
  s21 = s21_sprintf(str_2, "<%23.15E>", 0.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_1) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-1.4g>", 128989.0);
  s21 = s21_sprintf(str_2, "<%-1.4g>", 128989.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_2) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%- 2.g>", 128989.12);
  s21 = s21_sprintf(str_2, "<%- 2.g>", 128989.12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_3) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-+ 2.0g>", -0.0);
  s21 = s21_sprintf(str_2, "<%-+ 2.0g>", -0.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_4) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-+0 2.g>", 1.123456);
  s21 = s21_sprintf(str_2, "<%-+0 2.g>", 1.123456);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_5) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%20.2g>", -0.128989);
  s21 = s21_sprintf(str_2, "<%20.2g>", -0.128989);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_6) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%02.20g>", 0.0);
  s21 = s21_sprintf(str_2, "<%02.20g>", 0.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_7) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-2.6g>", 128989.1, 128989.0);
  s21 = s21_sprintf(str_2, "<%-2.6g>", 128989.1);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_8) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+2.g>", -12.12121212121212121212);
  s21 = s21_sprintf(str_2, "<%+2.g>", -12.12121212121212121212);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_9) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+01.2g>", -1.12);
  s21 = s21_sprintf(str_2, "<%+01.2g>", -1.12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_10) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<% 2.4g>", -123.123128989);
  s21 = s21_sprintf(str_2, "<% 2.4g>", -123.123128989);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_11) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-2.8g>", 123.123128989);
  s21 = s21_sprintf(str_2, "<%-2.8g>", 123.123128989);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_12) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%02.g>", -123.123128989);
  s21 = s21_sprintf(str_2, "<%02.g>", -123.123128989);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_13) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-+0 2.3g>", -128989.1234);
  s21 = s21_sprintf(str_2, "<%-+0 2.3g>", -128989.1234);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_14) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-02.3g>", -0.1234);
  s21 = s21_sprintf(str_2, "<%-02.3g>", -0.1234);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_15) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%23.15g>", 323.120);
  s21 = s21_sprintf(str_2, "<%23.15g>", 323.120);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_16) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-10.4g>",
                0.0000000000000000000000000000000000000000000000001);
  s21 = s21_sprintf(str_2, "<%-10.4g>",
                    0.0000000000000000000000000000000000000000000000001);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_17) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%10.g>", 128989.124);
  s21 = s21_sprintf(str_2, "<%10.g>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_18) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%5g>", 128989.124);
  s21 = s21_sprintf(str_2, "<%5g>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_19) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%05g>", 0.0);
  s21 = s21_sprintf(str_2, "<%05g>", 0.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_20) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-5g>", 0.0);
  s21 = s21_sprintf(str_2, "<%-5g>", 0.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_21) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+5g>", 0.0);
  s21 = s21_sprintf(str_2, "<%+5g>", 0.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_22) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%#4.0g>", 12.0);
  s21 = s21_sprintf(str_2, "<%#4.0g>", 12.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_23) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-#4.0g>", 12.0);
  s21 = s21_sprintf(str_2, "<%-#4.0g>", 12.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_24) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%014.8g>", -0.0001234999);
  s21 = s21_sprintf(str_2, "<%014.8g>", -0.0001234999);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formg_25) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%#04.0g>", 12.0);
  s21 = s21_sprintf(str_2, "<%#04.0g>", 12.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_1) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-1.4G>", 128989.1);
  s21 = s21_sprintf(str_2, "<%-1.4G>", 128989.1);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_2) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-01.4G>", 128989.0);
  s21 = s21_sprintf(str_2, "<%-01.4G>", 128989.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_3) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-17.4G>", 128989.12);
  s21 = s21_sprintf(str_2, "<%-17.4G>", 128989.12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_4) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-1.14G>", 128989.124);
  s21 = s21_sprintf(str_2, "<%-1.14G>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_5) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-1.4G>", 0.0);
  s21 = s21_sprintf(str_2, "<%-1.4G>", 0.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_6) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-01.4G>", 0.0);
  s21 = s21_sprintf(str_2, "<%-01.4G>", 0.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_7) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-+10.4G>", 128989.0);
  s21 = s21_sprintf(str_2, "<%-+10.4G>", 128989.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_8) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-+1.15G>", 128989.0);
  s21 = s21_sprintf(str_2, "<%-+1.15G>", 128989.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_9) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-1.4G>", 1289898768.0);
  s21 = s21_sprintf(str_2, "<%-1.4G>", 1289898768.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_10) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-1.4G>",
                0.0000000000000000000000000000000000000000000000001);
  s21 = s21_sprintf(str_2, "<%-1.4G>",
                    0.0000000000000000000000000000000000000000000000001);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_11) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-01.4G>",
                0.0000000000000000000000000000000000000000000000001);
  s21 = s21_sprintf(str_2, "<%-01.4G>",
                    0.0000000000000000000000000000000000000000000000001);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_12) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-10.4G>",
                0.0000000000000000000000000000000000000000000000001);
  s21 = s21_sprintf(str_2, "<%-10.4G>",
                    0.0000000000000000000000000000000000000000000000001);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_13) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-1.0G>",
                0.0000000000000000000000000000000000000000000000001);
  s21 = s21_sprintf(str_2, "<%-1.0G>",
                    0.0000000000000000000000000000000000000000000000001);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_14) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%- 10.8G>", 128989.124);
  s21 = s21_sprintf(str_2, "<%- 10.8G>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_15) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-+10.8G>", 128989.124);
  s21 = s21_sprintf(str_2, "<%-+10.8G>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_16) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%10.8G>", 128989.124);
  s21 = s21_sprintf(str_2, "<%10.8G>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_17) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%10.14G>", 128989.124);
  s21 = s21_sprintf(str_2, "<%10.14G>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_18) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%010.8G>", 128989.124);
  s21 = s21_sprintf(str_2, "<%010.8G>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_19) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+010.8G>", 128989.124);
  s21 = s21_sprintf(str_2, "<%+010.8G>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_20) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+ 10.8G>", 128989.124);
  s21 = s21_sprintf(str_2, "<%+ 10.8G>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_21) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%10.G>", 128989.124);
  s21 = s21_sprintf(str_2, "<%10.G>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_22) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%10G>", 128989.124);
  s21 = s21_sprintf(str_2, "<%10G>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_23) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%5G>", 128989.124);
  s21 = s21_sprintf(str_2, "<%5G>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_24) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%0.8G>", 128989.124);
  s21 = s21_sprintf(str_2, "<%0.8G>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_25) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+8G>", 128989.124);
  s21 = s21_sprintf(str_2, "<%+8G>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_26) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<% 8G>", 128989.124);
  s21 = s21_sprintf(str_2, "<% 8G>", 128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_27) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%10.8G>", -128989.124);
  s21 = s21_sprintf(str_2, "<%10.8G>", -128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_28) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-10.8G>", -128989.124);
  s21 = s21_sprintf(str_2, "<%-10.8G>", -128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_29) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<% 10.8G>", -128989.124);
  s21 = s21_sprintf(str_2, "<% 10.8G>", -128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_30) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+-010.8G>", -128989.124);
  s21 = s21_sprintf(str_2, "<%+-010.8G>", -128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_31) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%0.8G>", -128989.124);
  s21 = s21_sprintf(str_2, "<%0.8G>", -128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_32) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-10.8G>", -128989.124);
  s21 = s21_sprintf(str_2, "<%-10.8G>", -128989.124);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_33) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%23.15G>", 323.120);
  s21 = s21_sprintf(str_2, "<%23.15G>", 323.120);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formG_34) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%23.15G>", 0.0);
  s21 = s21_sprintf(str_2, "<%23.15G>", 0.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formc_1) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-0c>", 'R');
  s21 = s21_sprintf(str_2, "<%-0c>", 'R');
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formc_2) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-12c>", 'R');
  s21 = s21_sprintf(str_2, "<%-12c>", 'R');
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formc_3) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%0c>", 'R');
  s21 = s21_sprintf(str_2, "<%0c>", 'R');
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formc_4) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-12.4c>", 'R');
  s21 = s21_sprintf(str_2, "<%-12.4c>", 'R');
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formc_5) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-4.12c>", 'R');
  s21 = s21_sprintf(str_2, "<%-4.12c>", 'R');
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formc_6) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%12.4c>", 'R');
  s21 = s21_sprintf(str_2, "<%12.4c>", 'R');
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formc_7) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%4.12c>", 'R');
  s21 = s21_sprintf(str_2, "<%4.12c>", 'R');
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formc_8) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%0.12c>", 'R');
  s21 = s21_sprintf(str_2, "<%0.12c>", 'R');
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formc_9) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-.12c>", 'R');
  s21 = s21_sprintf(str_2, "<%-.12c>", 'R');
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formc_10) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%c>", 23);
  s21 = s21_sprintf(str_2, "<%c>", 23);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formc_11) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%c>", '\n');
  s21 = s21_sprintf(str_2, "<%c>", '\n');
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

// START_TEST(test_formc_12) {
//   char str_1[128] = {'\0'};
//   char str_2[128] = {'\0'};
//   int ori = 0;
//   int s21 = 0;
//   ori = sprintf(str_1, "<%012c>", 'R');
//   s21 = s21_sprintf(str_2, "<%012c>", 'R');
//   ck_assert_int_eq(ori, s21);
//   ck_assert_str_eq(str_1, str_2);
// }
// END_TEST

START_TEST(test_forms_1) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%012s>", "err");
  s21 = s21_sprintf(str_2, "<%012s>", "err");
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forms_2) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-12s>", "err");
  s21 = s21_sprintf(str_2, "<%-12s>", "err");
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forms_3) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-2.4s>", "error");
  s21 = s21_sprintf(str_2, "<%-2.4s>", "error");
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forms_4) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-4.2s>", "error");
  s21 = s21_sprintf(str_2, "<%-4.2s>", "error");
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forms_5) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-.4s>", "error");
  s21 = s21_sprintf(str_2, "<%-.4s>", "error");
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forms_6) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-2.s>", "error");
  s21 = s21_sprintf(str_2, "<%-2.s>", "error");
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forms_7) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%01.2s>", "Rer er");
  s21 = s21_sprintf(str_2, "<%01.2s>", "Rer er");
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forms_8) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%04.2s>", 's');
  s21 = s21_sprintf(str_2, "<%04.2s>", 's');
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forms_9) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%012.12s>", 'R');
  s21 = s21_sprintf(str_2, "<%012.12s>", 'R');
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forms_10) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%0s>", "Rer");
  s21 = s21_sprintf(str_2, "<%0s>", "Rer");
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forms_11) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%1.2s>", 'R');
  s21 = s21_sprintf(str_2, "<%1.2s>", 'R');
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_forms_12) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%.12s>", 'R');
  s21 = s21_sprintf(str_2, "<%.12s>", 'R');
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formp_1) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%010p>", 12);
  s21 = s21_sprintf(str_2, "<%010p>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

// START_TEST(test_formp_3) {
//   char str_1[128] = {'\0'};
//   char str_2[128] = {'\0'};
//   int ori = 0;
//   int s21 = 0;
//   ori = sprintf(str_1, "<%+10p>", 12);
//   s21 = s21_sprintf(str_2, "<%+10p>", 12);
//   ck_assert_int_eq(ori, s21);
//   ck_assert_str_eq(str_1, str_2);
// }
// END_TEST

START_TEST(test_formp_5) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%0-10p>", 12);
  s21 = s21_sprintf(str_2, "<%0-10p>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formp_6) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%#0-10p>", 12);
  s21 = s21_sprintf(str_2, "<%#0-10p>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

// START_TEST(test_formp_7) {
//   char str_1[128] = {'\0'};
//   char str_2[128] = {'\0'};
//   int ori = 0;
//   int s21 = 0;
//   ori = sprintf(str_1, "<%0-+10p>", 12);
//   s21 = s21_sprintf(str_2, "<%0-+10p>", 12);
//   ck_assert_int_eq(ori, s21);
//   ck_assert_str_eq(str_1, str_2);
// }
// END_TEST

START_TEST(test_formp_8) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-010p>", 12);
  s21 = s21_sprintf(str_2, "<%-010p>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

// START_TEST(test_formp_9) {
//   char str_1[128] = {'\0'};
//   char str_2[128] = {'\0'};
//   int ori = 0;
//   int s21 = 0;
//   ori = sprintf(str_1, "<%+3p>", 1212);
//   s21 = s21_sprintf(str_2, "<%+3p>", 1212);
//   ck_assert_int_eq(ori, s21);
//   ck_assert_str_eq(str_1, str_2);
// }
// END_TEST

START_TEST(test_formp_11) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<% 10p>", 128989);
  s21 = s21_sprintf(str_2, "<% 10p>", 128989);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

// START_TEST(test_formp_12) {
//   char str_1[128] = {'\0'};
//   char str_2[128] = {'\0'};
//   int ori = 0;
//   int s21 = 0;
//   ori = sprintf(str_1, "<% .p>", 128989);
//   s21 = s21_sprintf(str_2, "<% .p>", 128989);
//   ck_assert_int_eq(ori, s21);
//   ck_assert_str_eq(str_1, str_2);
// }
// END_TEST

START_TEST(test_formp_14) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-02.3p>", 1);
  s21 = s21_sprintf(str_2, "<%-02.3p>", 1);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

// START_TEST(test_formp_15) {
//   char str_1[128] = {'\0'};
//   char str_2[128] = {'\0'};
//   int ori = 0;
//   int s21 = 0;
//   ori = sprintf(str_1, "<%-02.3p>", 0);
//   s21 = s21_sprintf(str_2, "<%-02.3p>", 0);
//   ck_assert_int_eq(ori, s21);
//   ck_assert_str_eq(str_1, str_2);
// }
// END_TEST

// START_TEST(test_formp_16) {
//   char str_1[128] = {'\0'};
//   char str_2[128] = {'\0'};
//   int ori = 0;
//   int s21 = 0;
//   ori = sprintf(str_1, "<%#07.3p>", 0);
//   s21 = s21_sprintf(str_2, "<%#07.3p>", 0);
//   ck_assert_int_eq(ori, s21);
//   ck_assert_str_eq(str_1, str_2);
// }
// END_TEST

// START_TEST(test_formp_17) {
//   char str_1[128] = {'\0'};
//   char str_2[128] = {'\0'};
//   int ori = 0;
//   int s21 = 0;
//   ori = sprintf(str_1, "<%07.15p>", 0);
//   s21 = s21_sprintf(str_2, "<%07.15p>", 0);
//   ck_assert_int_eq(ori, s21);
//   ck_assert_str_eq(str_1, str_2);
// }
// END_TEST

// START_TEST(test_formp_18) {
//   char str_1[128] = {'\0'};
//   char str_2[128] = {'\0'};
//   int ori = 0;
//   int s21 = 0;
//   ori = sprintf(str_1, "<%+07.7p>", 1);
//   s21 = s21_sprintf(str_2, "<%+07.7p>", 1);
//   ck_assert_int_eq(ori, s21);
//   ck_assert_str_eq(str_1, str_2);
// }
// END_TEST

// START_TEST(test_formp_19) {
//   char str_1[128] = {'\0'};
//   char str_2[128] = {'\0'};
//   int ori = 0;
//   int s21 = 0;
//   ori = sprintf(str_1, "<%+-07.3p>", 0);
//   s21 = s21_sprintf(str_2, "<%+-07.3p>", 0);
//   ck_assert_int_eq(ori, s21);
//   ck_assert_str_eq(str_1, str_2);
// }
// END_TEST

START_TEST(test_formp_20) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-07.3p>", 123);
  s21 = s21_sprintf(str_2, "<%-07.3p>", 123);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formi_1) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%010i>", 12);
  s21 = s21_sprintf(str_2, "<%010i>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formi_2) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%010i>", -12);
  s21 = s21_sprintf(str_2, "<%010i>", -12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formi_3) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+10i>", 12);
  s21 = s21_sprintf(str_2, "<%+10i>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formi_4) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+10i>", -12);
  s21 = s21_sprintf(str_2, "<%+10i>", -12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formi_5) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%0-10li>", 12);
  s21 = s21_sprintf(str_2, "<%0-10li>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formi_6) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%0-10hi>", 12);
  s21 = s21_sprintf(str_2, "<%0-10hi>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formi_7) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%0-+10i>", 12);
  s21 = s21_sprintf(str_2, "<%0-+10i>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formi_8) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-010i>", 12);
  s21 = s21_sprintf(str_2, "<%-010i>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formi_9) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+3i>", 1212);
  s21 = s21_sprintf(str_2, "<%+3i>", 1212);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_formi_10) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-5i>", -121212);
  s21 = s21_sprintf(str_2, "<%-5i>", -121212);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_form_prc_1) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%010%>", 12);
  s21 = s21_sprintf(str_2, "<%010%>", 12);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_form_prc_2) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%+3%>", 1212);
  s21 = s21_sprintf(str_2, "<%+3%>", 1212);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_form_prc_3) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-5%>", -121212);
  s21 = s21_sprintf(str_2, "<%-5%>", -121212);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_exam_1) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%2.0f123%*.*f45%8.c>", 0.0, 3, 5, 1.7, 'd');
  s21 = s21_sprintf(str_2, "<%2.0f123%*.*f45%8.c>", 0.0, 3, 5, 1.7, 'd');
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_exam_2) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%*.*d>", -1, 2, 3);
  s21 = s21_sprintf(str_2, "<%*.*d>", -1, 2, 3);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_exam_3) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%*.*df>", 1, 2, 3);
  s21 = s21_sprintf(str_2, "<%*.*df>", 1, 2, 3);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_exam_4) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%*s>", 13, "error");
  s21 = s21_sprintf(str_2, "<%*s>", 13, "error");
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_exam_5) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-+ 2.0f>", 0.0);
  s21 = s21_sprintf(str_2, "<%-+ 2.0f>", 0.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_exam_6) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-+ 2.0f%12d>", 0.0, 123);
  s21 = s21_sprintf(str_2, "<%-+ 2.0f%12d>", 0.0, 123);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(test_exam_7) {
  char str_1[128] = {'\0'};
  char str_2[128] = {'\0'};
  int ori = 0;
  int s21 = 0;
  ori = sprintf(str_1, "<%-12.*o,%-+2.0f>", 7, 12, 0.0);
  s21 = s21_sprintf(str_2, "<%-12.*o,%-+2.0f>", 7, 12, 0.0);
  ck_assert_int_eq(ori, s21);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(strchr1) {
  // first occurrence of a valid character
  char target = 'l';
  char str1[255] = "hello world";
  ck_assert_ptr_eq(strchr(str1, target), s21_strchr(str1, target));
}
END_TEST

START_TEST(strchr2) {
  // first occurrence of invalid character is NULL
  char str1[255] = "hello world";
  char target = 'z';
  ck_assert_ptr_eq(strchr(str1, target), s21_strchr(str1, target));
}
END_TEST

START_TEST(strchr3) {
  // first occurrence of invalid character is NULL
  char target = 'z';
  char str3[255] = "";
  ck_assert_ptr_eq(strchr(str3, target), s21_strchr(str3, target));
}
END_TEST

START_TEST(strrchr1) {
  // first occurrence of a valid character
  char target = 'o';
  char str2[255] = "hello school";
  ck_assert_ptr_eq(strrchr(str2, target), s21_strrchr(str2, target));
}
END_TEST

START_TEST(strrchr2) {
  // first occurrence of a valid character
  char target = 'l';
  char str2[255] = "hello school";
  ck_assert_ptr_eq(strrchr(str2, target), s21_strrchr(str2, target));
}
END_TEST

START_TEST(strrchr3) {
  // first occurrence of invalid character is NULL
  char target = ' ';
  char str2[255] = "hello school";
  ck_assert_ptr_eq(strrchr(str2, target), s21_strrchr(str2, target));
}
END_TEST

START_TEST(strpbrk1) {
  // first occurrence of a valid character
  char str1[255] = "hello world";
  char str2[255] = "hello school";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk2) {
  // first occurrence of invalid character is NULL
  char str1[255] = "hello world";
  char str4[255] = "s21_school";
  ck_assert_ptr_eq(strpbrk(str1, str4), s21_strpbrk(str1, str4));
}
END_TEST

START_TEST(strpbrk3) {
  // first occurrence of invalid character is NULL
  char str1[255] = "hello world";
  char str3[255] = "";
  ck_assert_ptr_eq(strpbrk(str1, str3), s21_strpbrk(str1, str3));
}
END_TEST

START_TEST(strncmp1) {
  // first occurrence of a valid character
  size_t n = 3;
  char str1[255] = "hello world";
  char str2[255] = "hello school";
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp2) {
  // first occurrence of a valid character
  char str1[255] = "hello world";
  char str2[255] = "hello school";
  size_t n = 7;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp3) {
  // first occurrence of invalid character is NULL
  size_t n = 3;
  char str1[255] = "hello world";
  char str4[255] = "s21_school";
  ck_assert_int_eq(strncmp(str1, str4, n), s21_strncmp(str1, str4, n));
}
END_TEST

START_TEST(to_upper1) {
  // first occurrence of a valid character
  char str1[255] = "hello world";
  char str_up[255] = "HELLO WORLD";
  char *str_check = s21_to_upper(str1);
  ck_assert_str_eq(str_up, str_check);
}
END_TEST

START_TEST(to_upper2) {
  // first occurrence of a valid character
  char str_up[255] = "HELLO WORLD";
  char *str_check = s21_to_upper(str_up);
  ck_assert_str_eq(str_up, str_check);
}
END_TEST

START_TEST(to_upper3) {
  // first occurrence of a valid character
  char str_up[255] = "12345";
  char *str_check = s21_to_upper(str_up);
  ck_assert_str_eq(str_up, str_check);
}
END_TEST

START_TEST(to_lower1) {
  // first occurrence of a valid character
  char str_up[255] = "HELLO WORLD";
  char str1[255] = "hello world";
  char *str_check = s21_to_lower(str_up);
  ck_assert_str_eq(str1, str_check);
}
END_TEST

START_TEST(to_lower2) {
  // first occurrence of a valid character
  char str1[255] = "hello world";
  char *str_check = s21_to_lower(str1);
  ck_assert_str_eq(str1, str_check);
}
END_TEST

START_TEST(to_lower3) {
  // first occurrence of a valid character
  char str_up[255] = "12345";
  char *str_check = s21_to_lower(str_up);
  ck_assert_str_eq(str_up, str_check);
}
END_TEST

START_TEST(strcspn1) {
  // first occurrence of a valid character
  char str1[255] = "hello world";
  char str2[255] = "hello school";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn2) {
  // first occurrence of a valid character
  char str1[255] = "hello world";
  char str4[255] = "s21_school";
  ck_assert_int_eq(strcspn(str1, str4), s21_strcspn(str1, str4));
}
END_TEST

START_TEST(strtok1) {
  // first occurrence of invalid character
  char test[10] = "/";
  char str5[255] = "tabt1/tcdt2/teft3/tght4";
  ck_assert_ptr_eq(strtok(str5, test), s21_strtok(str5, test));
}
END_TEST

START_TEST(strtok2) {
  // first occurrence of invalid character
  char test[10] = "/";
  char str3[255] = "";
  ck_assert_ptr_eq(strtok(str3, test), s21_strtok(str3, test));
}
END_TEST

START_TEST(strtok3) {
  // first occurrence of invalid character
  char test[10] = ".";
  char str5[255] = "tabt1/tcdt2/teft3/tght4";
  ck_assert_ptr_eq(strtok(str5, test), s21_strtok(str5, test));
}
END_TEST

Suite *example_create() {
  Suite *suite = suite_create("TESTS");

  TCase *tcase_add = tcase_create("ADD");
  tcase_add_test(tcase_add, test_sscanf_1);
  suite_add_tcase(suite, tcase_add);

  TCase *tcase_d = tcase_create("FORM_d");
  tcase_add_test(tcase_d, test_formd_1);
  tcase_add_test(tcase_d, test_formd_2);
  tcase_add_test(tcase_d, test_formd_3);
  tcase_add_test(tcase_d, test_formd_4);
  tcase_add_test(tcase_d, test_formd_5);
  tcase_add_test(tcase_d, test_formd_6);
  tcase_add_test(tcase_d, test_formd_7);
  tcase_add_test(tcase_d, test_formd_8);
  tcase_add_test(tcase_d, test_formd_9);
  tcase_add_test(tcase_d, test_formd_10);
  tcase_add_test(tcase_d, test_formd_11);
  tcase_add_test(tcase_d, test_formd_12);
  tcase_add_test(tcase_d, test_formd_13);
  tcase_add_test(tcase_d, test_formd_14);
  tcase_add_test(tcase_d, test_formd_15);
  tcase_add_test(tcase_d, test_formd_16);
  tcase_add_test(tcase_d, test_formd_17);
  tcase_add_test(tcase_d, test_formd_18);
  tcase_add_test(tcase_d, test_formd_19);
  tcase_add_test(tcase_d, test_formd_20);
  tcase_add_test(tcase_d, test_formd_21);
  tcase_add_test(tcase_d, test_formd_22);
  tcase_add_test(tcase_d, test_formd_25);
  tcase_add_test(tcase_d, test_formd_26);
  suite_add_tcase(suite, tcase_d);

  TCase *tcase_f = tcase_create("FORM_f");
  tcase_add_test(tcase_f, test_formf_1);
  tcase_add_test(tcase_f, test_formf_2);
  tcase_add_test(tcase_f, test_formf_4);
  tcase_add_test(tcase_f, test_formf_5);
  tcase_add_test(tcase_f, test_formf_6);
  tcase_add_test(tcase_f, test_formf_7);
  tcase_add_test(tcase_f, test_formf_8);
  tcase_add_test(tcase_f, test_formf_9);
  tcase_add_test(tcase_f, test_formf_10);
  tcase_add_test(tcase_f, test_formf_11);
  tcase_add_test(tcase_f, test_formf_12);
  tcase_add_test(tcase_f, test_formf_13);
  tcase_add_test(tcase_f, test_formf_14);
  tcase_add_test(tcase_f, test_formf_15);
  tcase_add_test(tcase_f, test_formf_16);
  tcase_add_test(tcase_f, test_formf_17);
  tcase_add_test(tcase_f, test_formf_18);
  tcase_add_test(tcase_f, test_formf_19);
  tcase_add_test(tcase_f, test_formf_20);
  tcase_add_test(tcase_f, test_formf_21);
  tcase_add_test(tcase_f, test_formf_22);
  tcase_add_test(tcase_f, test_formf_23);
  tcase_add_test(tcase_f, test_formf_24);
  tcase_add_test(tcase_f, test_formf_25);
  tcase_add_test(tcase_f, test_formf_26);
  suite_add_tcase(suite, tcase_f);

  TCase *tcase_o = tcase_create("FORM_o");
  tcase_add_test(tcase_o, test_formo_1);
  tcase_add_test(tcase_o, test_formo_2);
  tcase_add_test(tcase_o, test_formo_3);
  tcase_add_test(tcase_o, test_formo_4);
  tcase_add_test(tcase_o, test_formo_5);
  tcase_add_test(tcase_o, test_formo_6);
  tcase_add_test(tcase_o, test_formo_7);
  tcase_add_test(tcase_o, test_formo_8);
  tcase_add_test(tcase_o, test_formo_9);
  tcase_add_test(tcase_o, test_formo_10);
  tcase_add_test(tcase_o, test_formo_11);
  tcase_add_test(tcase_o, test_formo_12);
  tcase_add_test(tcase_o, test_formo_13);
  tcase_add_test(tcase_o, test_formo_14);
  tcase_add_test(tcase_o, test_formo_15);
  tcase_add_test(tcase_o, test_formo_16);
  tcase_add_test(tcase_o, test_formo_17);
  tcase_add_test(tcase_o, test_formo_18);
  tcase_add_test(tcase_o, test_formo_19);
  tcase_add_test(tcase_o, test_formo_20);
  tcase_add_test(tcase_o, test_formo_21);
  suite_add_tcase(suite, tcase_o);

  TCase *tcase_u = tcase_create("FORM_u");
  tcase_add_test(tcase_u, test_formu_1);
  tcase_add_test(tcase_u, test_formu_2);
  tcase_add_test(tcase_u, test_formu_3);
  tcase_add_test(tcase_u, test_formu_4);
  tcase_add_test(tcase_u, test_formu_5);
  tcase_add_test(tcase_u, test_formu_6);
  tcase_add_test(tcase_u, test_formu_7);
  tcase_add_test(tcase_u, test_formu_8);
  tcase_add_test(tcase_u, test_formu_9);
  tcase_add_test(tcase_u, test_formu_10);
  tcase_add_test(tcase_u, test_formu_11);
  tcase_add_test(tcase_u, test_formu_12);
  tcase_add_test(tcase_u, test_formu_13);
  tcase_add_test(tcase_u, test_formu_14);
  tcase_add_test(tcase_u, test_formu_15);
  tcase_add_test(tcase_u, test_formu_16);
  tcase_add_test(tcase_u, test_formu_17);
  tcase_add_test(tcase_u, test_formu_18);
  tcase_add_test(tcase_u, test_formu_19);
  tcase_add_test(tcase_u, test_formu_20);
  tcase_add_test(tcase_u, test_formu_21);
  suite_add_tcase(suite, tcase_u);

  TCase *tcase_x = tcase_create("FORM_x");
  tcase_add_test(tcase_x, test_formx_1);
  tcase_add_test(tcase_x, test_formx_2);
  tcase_add_test(tcase_x, test_formx_3);
  tcase_add_test(tcase_x, test_formx_4);
  tcase_add_test(tcase_x, test_formx_5);
  tcase_add_test(tcase_x, test_formx_6);
  tcase_add_test(tcase_x, test_formx_7);
  tcase_add_test(tcase_x, test_formx_8);
  tcase_add_test(tcase_x, test_formx_9);
  tcase_add_test(tcase_x, test_formx_10);
  tcase_add_test(tcase_x, test_formx_11);
  tcase_add_test(tcase_x, test_formx_12);
  tcase_add_test(tcase_x, test_formx_13);
  tcase_add_test(tcase_x, test_formx_14);
  tcase_add_test(tcase_x, test_formx_15);
  tcase_add_test(tcase_x, test_formx_16);
  tcase_add_test(tcase_x, test_formx_17);
  tcase_add_test(tcase_x, test_formx_18);
  tcase_add_test(tcase_x, test_formx_19);
  tcase_add_test(tcase_x, test_formx_20);
  tcase_add_test(tcase_x, test_formx_21);
  suite_add_tcase(suite, tcase_x);

  TCase *tcase_X = tcase_create("FORM_X");
  tcase_add_test(tcase_X, test_formX_1);
  tcase_add_test(tcase_X, test_formX_2);
  tcase_add_test(tcase_X, test_formX_3);
  tcase_add_test(tcase_X, test_formX_4);
  tcase_add_test(tcase_X, test_formX_5);
  tcase_add_test(tcase_X, test_formX_6);
  tcase_add_test(tcase_X, test_formX_7);
  tcase_add_test(tcase_X, test_formX_8);
  tcase_add_test(tcase_X, test_formX_9);
  tcase_add_test(tcase_X, test_formX_10);
  tcase_add_test(tcase_X, test_formX_11);
  tcase_add_test(tcase_X, test_formX_12);
  tcase_add_test(tcase_X, test_formX_13);
  tcase_add_test(tcase_X, test_formX_14);
  tcase_add_test(tcase_X, test_formX_15);
  tcase_add_test(tcase_X, test_formX_16);
  tcase_add_test(tcase_X, test_formX_17);
  tcase_add_test(tcase_X, test_formX_18);
  tcase_add_test(tcase_X, test_formX_19);
  tcase_add_test(tcase_X, test_formX_20);
  tcase_add_test(tcase_X, test_formX_21);
  suite_add_tcase(suite, tcase_X);

  TCase *tcase_e = tcase_create("FORM_e");
  tcase_add_test(tcase_e, test_forme_1);
  tcase_add_test(tcase_e, test_forme_2);
  tcase_add_test(tcase_e, test_forme_3);
  tcase_add_test(tcase_e, test_forme_4);
  tcase_add_test(tcase_e, test_forme_5);
  tcase_add_test(tcase_e, test_forme_6);
  tcase_add_test(tcase_e, test_forme_7);
  tcase_add_test(tcase_e, test_forme_8);
  tcase_add_test(tcase_e, test_forme_9);
  tcase_add_test(tcase_e, test_forme_10);
  tcase_add_test(tcase_e, test_forme_11);
  tcase_add_test(tcase_e, test_forme_12);
  tcase_add_test(tcase_e, test_forme_13);
  tcase_add_test(tcase_e, test_forme_14);
  tcase_add_test(tcase_e, test_forme_15);
  tcase_add_test(tcase_e, test_forme_16);
  tcase_add_test(tcase_e, test_forme_17);
  tcase_add_test(tcase_e, test_forme_18);
  tcase_add_test(tcase_e, test_forme_19);
  tcase_add_test(tcase_e, test_forme_20);
  tcase_add_test(tcase_e, test_forme_21);
  tcase_add_test(tcase_e, test_forme_22);
  tcase_add_test(tcase_e, test_forme_23);
  tcase_add_test(tcase_e, test_forme_24);
  tcase_add_test(tcase_e, test_forme_25);
  tcase_add_test(tcase_e, test_forme_26);
  tcase_add_test(tcase_e, test_forme_27);
  tcase_add_test(tcase_e, test_forme_28);
  tcase_add_test(tcase_e, test_forme_29);
  tcase_add_test(tcase_e, test_forme_30);
  tcase_add_test(tcase_e, test_forme_31);
  tcase_add_test(tcase_e, test_forme_32);
  tcase_add_test(tcase_e, test_forme_33);
  tcase_add_test(tcase_e, test_forme_34);
  tcase_add_test(tcase_e, test_forme_35);
  tcase_add_test(tcase_e, test_forme_36);
  suite_add_tcase(suite, tcase_e);

  TCase *tcase_E = tcase_create("FORM_E");
  tcase_add_test(tcase_E, test_formE_1);
  tcase_add_test(tcase_E, test_formE_2);
  tcase_add_test(tcase_E, test_formE_3);
  tcase_add_test(tcase_E, test_formE_4);
  tcase_add_test(tcase_E, test_formE_5);
  tcase_add_test(tcase_E, test_formE_6);
  tcase_add_test(tcase_E, test_formE_7);
  tcase_add_test(tcase_E, test_formE_8);
  tcase_add_test(tcase_E, test_formE_9);
  tcase_add_test(tcase_E, test_formE_10);
  tcase_add_test(tcase_E, test_formE_11);
  tcase_add_test(tcase_E, test_formE_12);
  tcase_add_test(tcase_E, test_formE_13);
  tcase_add_test(tcase_E, test_formE_14);
  tcase_add_test(tcase_E, test_formE_15);
  tcase_add_test(tcase_E, test_formE_16);
  tcase_add_test(tcase_E, test_formE_17);
  tcase_add_test(tcase_E, test_formE_18);
  tcase_add_test(tcase_E, test_formE_19);
  tcase_add_test(tcase_E, test_formE_20);
  tcase_add_test(tcase_E, test_formE_21);
  tcase_add_test(tcase_E, test_formE_22);
  tcase_add_test(tcase_E, test_formE_23);
  tcase_add_test(tcase_E, test_formE_24);
  tcase_add_test(tcase_E, test_formE_25);
  tcase_add_test(tcase_E, test_formE_26);
  tcase_add_test(tcase_E, test_formE_27);
  tcase_add_test(tcase_E, test_formE_28);
  tcase_add_test(tcase_E, test_formE_29);
  tcase_add_test(tcase_E, test_formE_30);
  tcase_add_test(tcase_E, test_formE_31);
  tcase_add_test(tcase_E, test_formE_32);
  tcase_add_test(tcase_E, test_formE_33);
  tcase_add_test(tcase_E, test_formE_34);
  suite_add_tcase(suite, tcase_E);

  TCase *tcase_g = tcase_create("FORM_g");
  tcase_add_test(tcase_g, test_formg_1);
  tcase_add_test(tcase_g, test_formg_2);
  tcase_add_test(tcase_g, test_formg_4);
  tcase_add_test(tcase_g, test_formg_5);
  tcase_add_test(tcase_g, test_formg_6);
  tcase_add_test(tcase_g, test_formg_7);
  tcase_add_test(tcase_g, test_formg_8);
  tcase_add_test(tcase_g, test_formg_9);
  tcase_add_test(tcase_g, test_formg_10);
  tcase_add_test(tcase_g, test_formg_11);
  tcase_add_test(tcase_g, test_formg_12);
  tcase_add_test(tcase_g, test_formg_13);
  tcase_add_test(tcase_g, test_formg_14);
  tcase_add_test(tcase_g, test_formg_15);
  tcase_add_test(tcase_g, test_formg_16);
  tcase_add_test(tcase_g, test_formg_17);
  tcase_add_test(tcase_g, test_formg_18);
  tcase_add_test(tcase_g, test_formg_19);
  tcase_add_test(tcase_g, test_formg_20);
  tcase_add_test(tcase_g, test_formg_21);
  tcase_add_test(tcase_g, test_formg_22);
  tcase_add_test(tcase_g, test_formg_23);
  tcase_add_test(tcase_g, test_formg_24);
  tcase_add_test(tcase_g, test_formg_25);
  suite_add_tcase(suite, tcase_g);

  TCase *tcase_G = tcase_create("FORM_G");
  tcase_add_test(tcase_G, test_formG_1);
  tcase_add_test(tcase_G, test_formG_2);
  tcase_add_test(tcase_G, test_formG_3);
  tcase_add_test(tcase_G, test_formG_4);
  tcase_add_test(tcase_G, test_formG_5);
  tcase_add_test(tcase_G, test_formG_6);
  tcase_add_test(tcase_G, test_formG_7);
  tcase_add_test(tcase_G, test_formG_8);
  tcase_add_test(tcase_G, test_formG_9);
  tcase_add_test(tcase_G, test_formG_10);
  tcase_add_test(tcase_G, test_formG_11);
  tcase_add_test(tcase_G, test_formG_12);
  tcase_add_test(tcase_G, test_formG_13);
  tcase_add_test(tcase_G, test_formG_14);
  tcase_add_test(tcase_G, test_formG_15);
  tcase_add_test(tcase_G, test_formG_16);
  tcase_add_test(tcase_G, test_formG_17);
  tcase_add_test(tcase_G, test_formG_18);
  tcase_add_test(tcase_G, test_formG_19);
  tcase_add_test(tcase_G, test_formG_20);
  tcase_add_test(tcase_G, test_formG_21);
  tcase_add_test(tcase_G, test_formG_22);
  tcase_add_test(tcase_G, test_formG_23);
  tcase_add_test(tcase_G, test_formG_24);
  tcase_add_test(tcase_G, test_formG_25);
  tcase_add_test(tcase_G, test_formG_26);
  tcase_add_test(tcase_G, test_formG_27);
  tcase_add_test(tcase_G, test_formG_28);
  tcase_add_test(tcase_G, test_formG_29);
  tcase_add_test(tcase_G, test_formG_30);
  tcase_add_test(tcase_G, test_formG_31);
  tcase_add_test(tcase_G, test_formG_32);
  tcase_add_test(tcase_G, test_formG_33);
  tcase_add_test(tcase_G, test_formG_34);
  suite_add_tcase(suite, tcase_G);

  TCase *tcase_c = tcase_create("FORM_c");
  tcase_add_test(tcase_c, test_formc_1);
  tcase_add_test(tcase_c, test_formc_2);
  tcase_add_test(tcase_c, test_formc_3);
  tcase_add_test(tcase_c, test_formc_4);
  tcase_add_test(tcase_c, test_formc_5);
  tcase_add_test(tcase_c, test_formc_6);
  tcase_add_test(tcase_c, test_formc_7);
  tcase_add_test(tcase_c, test_formc_8);
  tcase_add_test(tcase_c, test_formc_9);
  tcase_add_test(tcase_c, test_formc_10);
  tcase_add_test(tcase_c, test_formc_11);
  // tcase_add_test(tcase_c, test_formc_12);

  suite_add_tcase(suite, tcase_c);

  TCase *tcase_s = tcase_create("FORM_s");
  tcase_add_test(tcase_s, test_forms_1);
  tcase_add_test(tcase_s, test_forms_2);
  tcase_add_test(tcase_s, test_forms_3);
  tcase_add_test(tcase_s, test_forms_4);
  tcase_add_test(tcase_s, test_forms_5);
  tcase_add_test(tcase_s, test_forms_6);
  tcase_add_test(tcase_s, test_forms_7);
  tcase_add_test(tcase_s, test_forms_8);
  tcase_add_test(tcase_s, test_forms_9);
  tcase_add_test(tcase_s, test_forms_10);
  tcase_add_test(tcase_s, test_forms_11);
  tcase_add_test(tcase_s, test_forms_12);

  suite_add_tcase(suite, tcase_c);

  TCase *tcase_p = tcase_create("FORM_p");
  tcase_add_test(tcase_p, test_formp_1);
  // tcase_add_test(tcase_p, test_formp_3);
  tcase_add_test(tcase_p, test_formp_5);
  tcase_add_test(tcase_p, test_formp_6);
  // tcase_add_test(tcase_p, test_formp_7);
  tcase_add_test(tcase_p, test_formp_8);
  // tcase_add_test(tcase_p, test_formp_9);
  tcase_add_test(tcase_p, test_formp_11);
  // tcase_add_test(tcase_p, test_formp_12);
  tcase_add_test(tcase_p, test_formp_14);
  // tcase_add_test(tcase_p, test_formp_15);
  // tcase_add_test(tcase_p, test_formp_16);
  // tcase_add_test(tcase_p, test_formp_17);
  // tcase_add_test(tcase_p, test_formp_18);
  // tcase_add_test(tcase_p, test_formp_19);
  tcase_add_test(tcase_p, test_formp_20);
  suite_add_tcase(suite, tcase_p);

  TCase *tcase_i = tcase_create("FORM_i");
  tcase_add_test(tcase_i, test_formi_1);
  tcase_add_test(tcase_i, test_formi_2);
  tcase_add_test(tcase_i, test_formi_3);
  tcase_add_test(tcase_i, test_formi_4);
  tcase_add_test(tcase_i, test_formi_5);
  tcase_add_test(tcase_i, test_formi_6);
  tcase_add_test(tcase_i, test_formi_7);
  tcase_add_test(tcase_i, test_formi_8);
  tcase_add_test(tcase_i, test_formi_9);
  tcase_add_test(tcase_i, test_formi_10);
  suite_add_tcase(suite, tcase_i);

  TCase *tcase_prc = tcase_create("FORM_prc");
  tcase_add_test(tcase_prc, test_formi_1);
  tcase_add_test(tcase_prc, test_formi_2);
  tcase_add_test(tcase_prc, test_formi_3);
  suite_add_tcase(suite, tcase_prc);

  TCase *tcase_exam = tcase_create("FORM_exam");
  tcase_add_test(tcase_exam, test_exam_1);
  tcase_add_test(tcase_exam, test_exam_2);
  tcase_add_test(tcase_exam, test_exam_3);
  tcase_add_test(tcase_exam, test_exam_4);
  tcase_add_test(tcase_exam, test_exam_5);
  tcase_add_test(tcase_exam, test_exam_6);
  tcase_add_test(tcase_exam, test_exam_7);
  suite_add_tcase(suite, tcase_exam);

  TCase *tc1_1 = tcase_create("Core");
  tcase_add_test(tc1_1, strchr1);
  tcase_add_test(tc1_1, strchr2);
  tcase_add_test(tc1_1, strchr3);
  tcase_add_test(tc1_1, strrchr1);
  tcase_add_test(tc1_1, strrchr2);
  tcase_add_test(tc1_1, strrchr3);
  tcase_add_test(tc1_1, strpbrk1);
  tcase_add_test(tc1_1, strpbrk2);
  tcase_add_test(tc1_1, strpbrk3);
  tcase_add_test(tc1_1, strncmp1);
  tcase_add_test(tc1_1, strncmp2);
  tcase_add_test(tc1_1, strncmp3);
  tcase_add_test(tc1_1, to_upper1);
  tcase_add_test(tc1_1, to_upper2);
  tcase_add_test(tc1_1, to_upper3);
  tcase_add_test(tc1_1, to_lower1);
  tcase_add_test(tc1_1, to_lower2);
  tcase_add_test(tc1_1, to_lower3);
  tcase_add_test(tc1_1, strcspn1);
  tcase_add_test(tc1_1, strcspn2);
  tcase_add_test(tc1_1, strtok1);
  tcase_add_test(tc1_1, strtok2);
  tcase_add_test(tc1_1, strtok3);
  suite_add_tcase(suite, tc1_1);

  return suite;
}

int main() {
  Suite *s = example_create();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int count = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;

  // Suite *s1 = suite_create("Core");
  // TCase *tc1_1 = tcase_create("Core");
  // SRunner *sr = srunner_create(s1);
  // int nf;

  // suite_add_tcase(s1, tc1_1);
  // tcase_add_test(tc1_1, strchr1);
  // tcase_add_test(tc1_1, strchr2);
  // tcase_add_test(tc1_1, strchr3);
  // tcase_add_test(tc1_1, strrchr1);
  // tcase_add_test(tc1_1, strrchr2);
  // tcase_add_test(tc1_1, strrchr3);
  // tcase_add_test(tc1_1, strpbrk1);
  // tcase_add_test(tc1_1, strpbrk2);
  // tcase_add_test(tc1_1, strpbrk3);
  // tcase_add_test(tc1_1, strncmp1);
  // tcase_add_test(tc1_1, strncmp2);
  // tcase_add_test(tc1_1, strncmp3);
  // tcase_add_test(tc1_1, to_upper1);
  // tcase_add_test(tc1_1, to_upper2);
  // tcase_add_test(tc1_1, to_upper3);
  // tcase_add_test(tc1_1, to_lower1);
  // tcase_add_test(tc1_1, to_lower2);
  // tcase_add_test(tc1_1, to_lower3);
  // tcase_add_test(tc1_1, strcspn1);
  // tcase_add_test(tc1_1, strcspn2);
  // tcase_add_test(tc1_1, strtok1);
  // tcase_add_test(tc1_1, strtok2);
  // tcase_add_test(tc1_1, strtok3);

  // srunner_run_all(sr, CK_ENV);
  // nf = srunner_ntests_failed(sr);
  // srunner_free(sr);

  // return nf == 0 ? 0 : 1;
}
