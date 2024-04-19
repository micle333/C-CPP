#include "s21_decimal.h"

int lengh(int a) {
  int len = 0;
  while (a % 10 > 0) {
    a = a / 10;
    len++;
  }
  return len;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int result = 0;  //  Возвращаемая ошибка
  int cap = 0;     //  Наша будущая степень
  long double superfloat = src;
  int microfloat = 0;
  if ((dst == NULL) || (superfloat == INFINITY) || (superfloat == NAN) ||
      (superfloat > 1e28) ||
      (superfloat <
       -1e28))  // Посмотрим на указатель - вдруг null? Тестим наш суперфлоат
  {
    result = 1;
  } else {  // Нулим результирующий дец
    dst->bits[0] = 0;
    dst->bits[1] = 0;
    dst->bits[2] = 0;
    dst->bits[3] = 0;
    if (superfloat < 0) {
      superfloat *= -1;
    }

    while (superfloat < 1000000)  // Следующие два вайла подрежут мантиссу до 7
                                  // цифр - нам нужны только они.
    {
      superfloat *= 10;
      cap++;
    }
    while (superfloat > 9999999) {
      superfloat /= 10;
      cap--;
    }
    microfloat =
        round(superfloat);  //  Эту инту мы будем приводить в бинарный вид

    int i = 1;
    while (microfloat != 0) {  //  Этот вайлик перегоняет в бинарь
      if (microfloat % 2 == 1) {
        touchbit(dst, i, 1);
        microfloat--;
      } else {
        touchbit(dst, i, 0);
      }
      microfloat /= 2;
      i++;
    }
    while (cap > 28) {  //  Подрезаем сверхбольшие или сверхмалые значения
      remdivx10(dst);
      cap--;
    }
    while (cap < 0) {
      x10mant(dst);
      cap++;
    }
    set_cap(dst, cap);  //   Ставим степень и бит отрицалова
    if (src < 0) {
      touchbit(dst, 128, 1);
    }
  }
  return result;
}
//   10011001001010101001010101100

int s21_truncate(s21_decimal value, s21_decimal *result) {
  while (getrank(&value) != 0) {
    divx10(&value);
  }
  *result = value;
  return 0;
}

int getrank(s21_decimal *dec) {  // Возвразщает разряд в десятичной системе
  int rank = 0;
  for (int i = 0; i < 8; i++) {
    rank += s21_getbit(dec, 113 + i) * pow(2, i);
  }
  return rank;
}

int s21_is_less(s21_decimal dec1, s21_decimal dec2) {
  int res = 0;
  if (s21_getbit(&dec1, 128) > s21_getbit(&dec2, 128)) {
    res = 1;
  } else if (s21_getbit(&dec1, 128) == s21_getbit(&dec2, 128)) {
    if (getrank(&dec1) != getrank(&dec2)) {
      normalize(&dec1, &dec2);
      if (comparison(&dec1, &dec2) == 2) res = 1;
    } else if (getrank(&dec2) == getrank(&dec1)) {
      if (comparison(&dec1, &dec2) == 2) res = 1;
    }
  }
  if (s21_getbit(&dec1, 128) && s21_getbit(&dec2, 128) &&
      !s21_is_equal(dec1, dec2))
    res = invert(res);
  return res;
}

int s21_is_less_or_equal(s21_decimal dec1, s21_decimal dec2) {
  int res = 0;
  if (s21_is_less(dec1, dec2) || s21_is_equal(dec1, dec2)) {
    res = 1;
  }
  return res;
}

int s21_is_greater(s21_decimal dec1, s21_decimal dec2) {
  int res = 0;
  if (s21_getbit(&dec1, 128) < s21_getbit(&dec2, 128)) {
    res = 1;
  } else if (s21_getbit(&dec1, 128) == s21_getbit(&dec2, 128)) {
    if (getrank(&dec1) != getrank(&dec2)) {
      normalize(&dec1, &dec2);
      if (comparison(&dec1, &dec2) == 1) res = 1;
    } else if (getrank(&dec2) == getrank(&dec1)) {
      if (comparison(&dec1, &dec2) == 1) res = 1;
    }
  }
  if (s21_getbit(&dec1, 128) && s21_getbit(&dec2, 128) &&
      !s21_is_equal(dec1, dec2))
    res = invert(res);
  return res;
}

int s21_is_greater_or_equal(s21_decimal dec1, s21_decimal dec2) {
  int res = 0;
  if (s21_is_greater(dec1, dec2) || s21_is_equal(dec1, dec2)) {
    res = 1;
  }
  return res;
}

int invert(int i) {
  int flag = 0;
  if (i == 0)
    flag = 1;
  else if (i == 1)
    flag = 0;
  return flag;
}

int s21_is_equal(s21_decimal dec1, s21_decimal dec2) {
  int res = 0;
  normalize(&dec1, &dec2);
  if (s21_getbit(&dec1, 128) == s21_getbit(&dec2, 128) &&
      getrank(&dec1) == getrank(&dec2) && comparison(&dec1, &dec2) == 3) {
    res = 1;
  }
  return res;
}

int s21_is_not_equal(s21_decimal dec1, s21_decimal dec2) {
  int res = 0;
  normalize(&dec1, &dec2);
  if (s21_getbit(&dec1, 128) != s21_getbit(&dec2, 128) ||
      getrank(&dec1) != getrank(&dec2) || comparison(&dec1, &dec2) != 3) {
    res = 1;
  }
  return res;
}

int comparison(s21_decimal *dec1, s21_decimal *dec2) {
  int res = 3;
  for (int i = 96; i > 0; i--) {
    if (s21_getbit(dec1, i) > s21_getbit(dec2, i)) {
      res = 1;
      break;
    } else if (s21_getbit(dec1, i) < s21_getbit(dec2, i)) {
      res = 2;
      break;
    }
  }
  return res;
}

unsigned int divx10(s21_decimal *dec) {
  unsigned int buffer = 0;

  int sign = getsig(dec);
  int scalenum = get_cap(dec);
  s21_decimal result = {{0, 0, 0, 0}};

  int fone = first1(dec);

  for (int i = 0; i < fone + 2; i++) {
    if (buffer >= 10) {
      sleft(&result);
      s21_touchbit(&result, 1, 1);
      buffer = buffer - 10u;
      int nbit = s21_getbit(dec, fone - i + 1);
      buffer = buffer << 1;
      buffer |= nbit;
    } else {
      sleft(&result);
      s21_touchbit(&result, 1, 0);
      int nbit = s21_getbit(dec, fone - i + 1);
      buffer = buffer << 1;
      buffer |= nbit;
    }
  }

  buffer = buffer >> 1;
  *dec = result;
  s21_touchbit(dec, 128, sign);
  set_cap(dec, scalenum - 1);

  return buffer;
}

int first1(s21_decimal *dec) {
  int first1 = -1;
  for (int i = 96; (i > 0) && (first1 == -1); i--) {
    if (s21_getbit(dec, i) == 1) {
      first1 = i;
    }
  }
  return first1;
}

void sleft(s21_decimal *dec) {
  dec->bits[2] = dec->bits[2] << 1;
  s21_touchbit(dec, 65, s21_getbit(dec, 64));
  dec->bits[1] = dec->bits[1] << 1;
  s21_touchbit(dec, 33, s21_getbit(dec, 32));
  dec->bits[0] = dec->bits[0] << 1;
}

int x10dec(s21_decimal *dec1) {
  int addbit = 0;
  int result = 0;

  s21_decimal dec3;
  dec3.bits[0] = 0;
  dec3.bits[1] = 0;
  dec3.bits[2] = 0;
  dec3.bits[3] = 0;

  if (get_cap(dec1) < 28) {
    for (int i = 1; i <= 96; i++) {
      int sum = s21_getmbit(dec1, i - 1) + s21_getmbit(dec1, i - 3) + addbit;
      if (sum == 0) {
        s21_touchbit(&dec3, i, 0);
        addbit = 0;
      }
      if (sum == 1) {
        s21_touchbit(&dec3, i, 1);
        addbit = 0;
      }
      if (sum == 2) {
        s21_touchbit(&dec3, i, 0);
        addbit = 1;
      }
      if (sum == 3) {
        s21_touchbit(&dec3, i, 1);
        addbit = 1;
      }
    }
    for (int i = 94; i <= 97; i++) {
      int sum = s21_getmbit(dec1, i) + s21_getmbit(dec1, i + 2) + addbit;
      if (sum == 0) {
        s21_touchbit(&dec3, i + 3, 0);
        addbit = 0;
      }
      if (sum == 1) {
        s21_touchbit(&dec3, i + 3, 1);
        addbit = 0;
      }
      if (sum == 2) {
        s21_touchbit(&dec3, i + 3, 0);
        addbit = 1;
      }
      if (sum == 3) {
        s21_touchbit(&dec3, i + 3, 1);
        addbit = 1;
      }
    }
    if ((s21_getbit(&dec3, 97) == 0) && (s21_getbit(&dec3, 98) == 0) &&
        (s21_getbit(&dec3, 99) == 0) && (s21_getbit(&dec3, 100) == 0)) {
      for (int i = 1; i <= 100; i++) {
        s21_touchbit(dec1, i, s21_getbit(&dec3, i));
      }
      int cap = get_cap(dec1) + 1;
      set_cap(dec1, cap);
    } else
      result = 1;
  } else
    result = 1;
  return result;
}

int getsig(s21_decimal *dec) { return s21_getbit(dec, 128); }

unsigned int remdivx10(s21_decimal *dec) {
  unsigned int buffer = 0;

  int sign = getsig(dec);
  int scalenum = get_cap(dec);
  s21_decimal result = {{0, 0, 0, 0}};

  int fone = first1(dec);

  for (int i = 0; i < fone + 2; i++) {
    if (buffer >= 10) {
      sleft(&result);
      s21_touchbit(&result, 1, 1);
      buffer = buffer - 10u;
      int nbit = s21_getbit(dec, fone - i + 1);
      buffer = buffer << 1;
      buffer |= nbit;
    } else {
      sleft(&result);
      s21_touchbit(&result, 1, 0);
      int nbit = s21_getbit(dec, fone - i + 1);
      buffer = buffer << 1;
      buffer |= nbit;
    }
  }

  buffer = buffer >> 1;
  *dec = result;
  s21_touchbit(dec, 128, sign);
  set_cap(dec, scalenum);

  return buffer;
}

int increase_mant_1(s21_decimal *dec) {
  s21_decimal res;
  res.bits[0] = 0;
  res.bits[1] = 0;
  res.bits[2] = 0;
  res.bits[3] = 0;
  int result = 1;
  int incr_ok = 0;
  int i = 1;
  while ((incr_ok == 0) && (i <= 96)) {
    if (s21_getbit(dec, i) == 1) {
      s21_touchbit(&res, i, 0);
    } else {
      s21_touchbit(&res, i, 1);
      incr_ok = 1;
    }
    i++;
  }
  while ((i <= 96)) {
    s21_touchbit(&res, i, s21_getbit(dec, i));
    i++;
  }
  if (incr_ok == 1) {
    *dec = res;
    result = 0;
  }

  return result;
}

int bank_rounding_div10(s21_decimal *dec) {
  int norm_bit = 0;
  int buffer = remdivx10(dec);
  if ((buffer > 5) || ((buffer == 5) && (s21_getbit(dec, 1) == 1))) {
    increase_mant_1(dec);
  }

  if (buffer == 5) {
    norm_bit = 1;
  }
  return norm_bit;
}

int normalize(s21_decimal *dec1, s21_decimal *dec2) {
  int cap1 = get_cap(dec1);
  int cap2 = get_cap(dec2);
  int diffcap = cap1 - cap2;
  int decok = 0;
  int norm_bit = 0;
  if (diffcap > 0) {  // Если у первого числа длиннее разрядность, т.е. степень
                      // делителя больше
    while (
        (diffcap > 0) && (cap2 < 28) &&
        (decok ==
         0)) {  // Сначала умножаем на десять второе число и дробь(+1 к разряду)
      decok = x10dec(dec2);  // Пока не забили всю мантиссу
      if (decok == 0) {
        diffcap--;
        cap2++;
      }
    }
    while (diffcap >
           0) {  // Начинаем делить второе число на десять и уменьшать степень
      norm_bit = bank_rounding_div10(dec1);
      diffcap--;
      cap1--;
    }
    while (diffcap > 0) {  // Если не нормализовали к этому моменту, то второе
                           // число просто делим на 10 с банковским округлением
      norm_bit = bank_rounding_div10(dec1);
      diffcap--;
    }
  }
  if (diffcap < 0) {  // Если у второго числа больше разрядность, т.е. выше
                      // степень делителя
    while ((diffcap < 0) && (cap1 < 28) &&
           (decok == 0)) {  // Сначала умножаем на десять число и дробь первого
                            // числа(+1 к разряду)
      decok = x10dec(dec1);
      if (decok == 0) {
        diffcap++;
        cap1++;
      }
    }
    while (diffcap <
           0) {  // Начинаем делить второе число на десять и уменьшать степень
      norm_bit = bank_rounding_div10(dec2);
      diffcap++;
      cap2--;
    }
    while (diffcap > 0) {  // Если не нормализовали к этому моменту, то второе
                           // число просто делим на 10 с банковским округлением
      norm_bit = bank_rounding_div10(dec2);
      diffcap++;
    }
  }
  set_cap(dec1, cap1);
  set_cap(dec2, cap2);
  return norm_bit;
}

int s21_getbit(s21_decimal *dec,
               int num) {  //  Возвращает бит децимала(1 или 0)
  int result = 0;
  if (num <= 32) {
    if (dec->bits[0] & (1 << (num - 1))) {
      result = 1;
    }
  }
  if ((num > 32) && (num <= 64)) {
    if (dec->bits[1] & (1 << (num - 33))) {
      result = 1;
    }
  }
  if ((num > 64) && (num <= 96)) {
    if (dec->bits[2] & (1 << (num - 65))) {
      result = 1;
    }
  }
  if (num > 96) {
    if (dec->bits[3] & (1 << (num - 97))) {
      result = 1;
    }
  }
  return result;
}

int s21_getmbit(s21_decimal *dec,
                int num) {  //  Возвращает бит мантиссы децимала(1 или 0), если
                            //  бит не из мантиссы, то ноль.
  int result = 0;
  if ((num <= 32) && (num >= 1)) {
    if (dec->bits[0] & (1 << (num - 1))) {
      result = 1;
    }
  }
  if ((num > 32) && (num <= 64)) {
    if (dec->bits[1] & (1 << (num - 33))) {
      result = 1;
    }
  }
  if ((num > 64) && (num <= 96)) {
    if (dec->bits[2] & (1 << (num - 65))) {
      result = 1;
    }
  }
  return result;
}

void s21_touchbit(s21_decimal *dec, int num,
                  int bit) {  //  Устанавливает бит в децимал(1 или 0)
  if (num <= 32) {
    if (bit == 1) {
      dec->bits[0] |= (1 << (num - 1));
    } else {
      dec->bits[0] &= ~(1 << (num - 1));
    }
  }
  if ((num > 32) && (num <= 64)) {
    if (bit == 1) {
      dec->bits[1] |= (1 << (num - 33));
    } else {
      dec->bits[1] &= ~(1 << (num - 33));
    }
  }
  if ((num > 64) && (num <= 96)) {
    if (bit == 1) {
      dec->bits[2] |= (1 << (num - 65));
    } else {
      dec->bits[2] &= ~(1 << (num - 65));
    }
  }
  if (num > 96) {
    if (bit == 1) {
      dec->bits[3] |= (1 << (num - 97));
    } else {
      dec->bits[3] &= ~(1 << (num - 97));
    }
  }
}

int getmbit(s21_decimal *dec,
            int num) {  //  Возвращает бит мантиссы децимала(1 или 0), если
                        //  бит не из мантиссы, то ноль.
  int result = 0;
  if ((num <= 32) && (num >= 1)) {
    if (dec->bits[0] & (1 << (num - 1))) {
      result = 1;
    }
  }
  if ((num > 32) && (num <= 64)) {
    if (dec->bits[1] & (1 << (num - 33))) {
      result = 1;
    }
  }
  if ((num > 64) && (num <= 96)) {
    if (dec->bits[2] & (1 << (num - 65))) {
      result = 1;
    }
  }
  return result;
}

int getbit(s21_decimal *dec,
           int num) {  //  Возвращает бит децимала(1 или 0)
  int result = 0;
  if (num <= 32) {
    if (dec->bits[0] & (1 << (num - 1))) {
      result = 1;
    }
  }
  if ((num > 32) && (num <= 64)) {
    if (dec->bits[1] & (1 << (num - 33))) {
      result = 1;
    }
  }
  if ((num > 64) && (num <= 96)) {
    if (dec->bits[2] & (1 << (num - 65))) {
      result = 1;
    }
  }
  if (num > 96) {
    if (dec->bits[3] & (1 << (num - 97))) {
      result = 1;
    }
  }
  return result;
}

int get_cap(s21_decimal *dec) {  //  Возвращает разрядность децимала или -1,
                                 //  если превышена 28
  int capacity = 1 * s21_getbit(dec, 113) + 2 * s21_getbit(dec, 114) +
                 4 * s21_getbit(dec, 115) + 8 * s21_getbit(dec, 116) +
                 16 * s21_getbit(dec, 117) + 32 * s21_getbit(dec, 118) +
                 64 * s21_getbit(dec, 119) + 168 * s21_getbit(dec, 120);
  if (capacity > 28) {
    capacity = -1;
  }
  return capacity;
}

int set_cap(s21_decimal *dec,
            int cap) {  //  Устанавливает разрядность в децимал
  for (int n = 0; n < 8; n++) {
    if (cap % 2 == 1) {
      s21_touchbit(dec, 113 + n, 1);
      cap = cap - 1;
    } else {
      s21_touchbit(dec, 113 + n, 0);
    }
    cap = cap / 2;
  }
  return 0;
}

void touchbit(s21_decimal *dec, int num,
              int bit) {  //  Устанавливает бит в децимал(1 или 0)
  if (num <= 32) {
    if (bit == 1) {
      dec->bits[0] |= (1 << (num - 1));
    } else {
      dec->bits[0] &= ~(1 << (num - 1));
    }
  }
  if ((num > 32) && (num <= 64)) {
    if (bit == 1) {
      dec->bits[1] |= (1 << (num - 33));
    } else {
      dec->bits[1] &= ~(1 << (num - 33));
    }
  }
  if ((num > 64) && (num <= 96)) {
    if (bit == 1) {
      dec->bits[2] |= (1 << (num - 65));
    } else {
      dec->bits[2] &= ~(1 << (num - 65));
    }
  }
  if (num > 96) {
    if (bit == 1) {
      dec->bits[3] |= (1 << (num - 97));
    } else {
      dec->bits[3] &= ~(1 << (num - 97));
    }
  }
}

// Преобразование из int в s21_decimal
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  if (dst == NULL) {
    return 1;
  }

  mmemset(dst, 0, sizeof(s21_decimal));
  int sign = 0;

  if (src < 0) {
    sign = 1;
    src = -src;
  }

  dst->bits[0] = src;
  if (sign) {
    dst->bits[3] |= 1U << 31;
  }

  return 0;
}

// Преобразование из s21_decimal в int
int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  if (dst == NULL) {
    return 1;
  }

  int sign = (src.bits[3] >> 31) & 1U;
  int absValue = src.bits[0];
  if (sign) {
    absValue = -absValue;
  }

  *dst = absValue;
  return 0;
}

void *mmemset(void *ptr, int value, size_t num) {
  unsigned char *p = ptr;
  for (size_t i = 0; i < num; ++i) {
    *p++ = (unsigned char)value;
  }
  return ptr;
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  result->bits[0] = 0;
  result->bits[1] = 0;
  result->bits[2] = 0;
  result->bits[3] = 0;
  int sign1 = s21_getbit(&value_1, 128);
  int sign2 = s21_getbit(&value_2, 128);
  touchbit(&value_1, 128, 0);
  touchbit(&value_2, 128, 0);
  int error = 0;
  if (sign1 == 0 && sign2 == 0) {
    error = adder(&value_1, &value_2, result);
  }
  if (sign1 == 0 && sign2 == 1) {
    if (s21_is_greater_or_equal(value_1, value_2) == 1) {
      deadder(&value_1, &value_2, result);
    } else {
      deadder(&value_2, &value_1, result);
      s21_negate(*result, result);
    }
  }
  if (sign1 == 1 && sign2 == 0) {
    if (s21_is_greater_or_equal(value_2, value_1) == 1) {
      deadder(&value_2, &value_1, result);
    } else {
      deadder(&value_1, &value_2, result);
      s21_negate(*result, result);
    }
  }
  if (sign1 == 1 && sign2 == 1) {
    error = (adder(&value_1, &value_2, result) * 2);
    s21_negate(*result, result);
  }
  return error;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  result->bits[0] = 0;
  result->bits[1] = 0;
  result->bits[2] = 0;
  result->bits[3] = 0;

  int sign1 = s21_getbit(&value_1, 128);
  int sign2 = s21_getbit(&value_2, 128);
  touchbit(&value_1, 128, 0);
  touchbit(&value_2, 128, 0);
  int error = 0;
  if (sign1 == 0 && sign2 == 0) {
    if (s21_is_greater_or_equal(value_1, value_2) == 1) {
      deadder(&value_1, &value_2, result);
    } else {
      deadder(&value_2, &value_1, result);
      // s21_negate(*result, result);
      touchbit(result, 128, 1);
    }
  }
  if (sign1 == 0 && sign2 == 1) {
    error = adder(&value_1, &value_2, result);
  }
  if (sign1 == 1 && sign2 == 0) {
    error = (adder(&value_1, &value_2, result) * 2);
    // s21_negate(*result, result);
    touchbit(result, 128, 1);
  }
  if (sign1 == 1 && sign2 == 1) {
    if (s21_is_greater_or_equal(value_2, value_1) == 1) {
      deadder(&value_2, &value_1, result);
    } else {
      deadder(&value_1, &value_2, result);
      // s21_negate(*result, result);
      touchbit(result, 128, 1);
    }
  }

  // printf("\n");
  // for (int i = 128; i > 0; i--) {
  //   printf("%d", getbit(&value_1, i));
  // }
  // printf("\n");
  // for (int i = 128; i > 0; i--) {
  //   printf("%d", getbit(&value_2, i));
  // }

  return error;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  *result = value;
  if (s21_getbit(&value, 128) == 0) {
    s21_touchbit(result, 128, 1);
  } else {
    s21_touchbit(result, 128, 0);
  }
  return 0;
}

int deadder(s21_decimal *dec1, s21_decimal *dec2, s21_decimal *dec3) {
  int norm_bit = 0;
  dec3->bits[0] = 0;
  dec3->bits[1] = 0;
  dec3->bits[2] = 0;
  dec3->bits[3] = 0;
  int error = 0;
  norm_bit = normalize(dec1, dec2);
  int sum = 0;
  int addbit = 0;
  for (int i = 1; i <= 96; i++) {
    sum = s21_getbit(dec1, i) - s21_getbit(dec2, i) - addbit;
    if (sum == 1) {
      s21_touchbit(dec3, i, 1);
      addbit = 0;
    }
    if (sum == 0) {
      s21_touchbit(dec3, i, 0);
      addbit = 0;
    }
    if (sum == -1) {
      s21_touchbit(dec3, i, 1);
      addbit = 1;
    }
    if (sum == -2) {
      s21_touchbit(dec3, i, 0);
      addbit = 1;
    }
  }
  set_cap(dec3, get_cap(dec1));
  return error;
}

int adder(s21_decimal *dec1, s21_decimal *dec2, s21_decimal *dec3) {
  int norm_bit = 0;
  dec3->bits[0] = 0;
  dec3->bits[1] = 0;
  dec3->bits[2] = 0;
  dec3->bits[3] = 0;

  susper_decimal sdec = {{0, 0, 0, 0, 0, 0, 0, 0}};
  int error = 0;
  norm_bit = normalize(dec1, dec2);
  set_cap(dec3, get_cap(dec1));
  int sum = 0;
  int addbit = 0;
  for (int i = 1; i <= 96; i++) {
    sum = getbit(dec1, i) + getbit(dec2, i) + addbit;
    if (sum == 0) {
      sd_touchbit(&sdec, i, 0);
      addbit = 0;
    }
    if (sum == 1) {
      sd_touchbit(&sdec, i, 1);
      addbit = 0;
    }
    if (sum == 2) {
      sd_touchbit(&sdec, i, 0);
      addbit = 1;
    }
    if (sum == 3) {
      sd_touchbit(&sdec, i, 1);
      addbit = 1;
    }
  }

  if (addbit == 1) {
    sd_touchbit(&sdec, 97, 1);
  }

  if (sd_getbit(&sdec, 97) == 1) {
    if ((get_cap(dec1) > 0)) {
      sd_bank_rounding_div10(&sdec);
      for (int i = 1; i <= 96; i++) {
        touchbit(dec3, i, sd_getbit(&sdec, i));
      }
      set_cap(dec3, get_cap(dec1) - 1);

    } else {
      error = 1;
    }
  }
  for (int i = 1; i <= 96; i++) {
    touchbit(dec3, i, sd_getbit(&sdec, i));
  }

  if ((norm_bit == 1) && (getbit(dec3, 1) == 1)) {
    increase_mant_1(dec3);
  }

  return error;
}

void sright(s21_decimal *dec) {
  dec->bits[0] = dec->bits[0] >> 1;
  s21_touchbit(dec, 32, s21_getbit(dec, 33));
  dec->bits[1] = dec->bits[1] >> 1;
  s21_touchbit(dec, 64, s21_getbit(dec, 65));
  dec->bits[2] = dec->bits[2] >> 1;
}

int is_zero(s21_decimal *dec) {
  int result = 0;
  if (dec->bits[0] == dec->bits[1] == dec->bits[2] == 0) {
    result = 1;
  }
  return result;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  // normalize(&value_1, &value_2);
  int error = 0;

  s21_decimal buffer = {{0, 0, 0, 0}};
  s21_decimal tempresult = {{0, 0, 0, 0}};
  result->bits[0] = 0;
  result->bits[1] = 0;
  result->bits[2] = 0;
  result->bits[3] = 0;

  int sign1 = getsig(&value_1);
  int sign2 = getsig(&value_2);
  int cap1 = get_cap(&value_1);
  int cap2 = get_cap(&value_2);
  int addcap = 0;
  s21_decimal devider = {{0, 0, 0, 0}};
  touchbit(&value_1, 128, 0);
  touchbit(&value_2, 128, 0);

  devider = value_1;
  // buffer = value_1;
  int counter = 0;
  if (is_zero(&value_2)) {
    error = 3;
  } else {
    while ((is_zero(&devider) != 1) && (counter < 29)) {
      tempresult.bits[0] = tempresult.bits[1] = tempresult.bits[2] =
          tempresult.bits[3] = 0;
      buffer.bits[0] = buffer.bits[1] = buffer.bits[2] = buffer.bits[3] = 0;
      // while (is_zero(&buffer) != 1) {
      int fone = first1(&devider);

      for (int i = 0; i < fone + 2; i++) {
        if (s21_is_greater_or_equal(
                buffer,
                value_2)) {  // s21_is_greater_or_equal buf val2
          sleft(&tempresult);
          touchbit(&tempresult, 1, 1);
          s21_sub(buffer, value_2, &buffer);  // sub buff val2
          int nbit = getbit(&devider, fone - i + 1);
          sleft(&buffer);  // lefts buff
          if ((getbit(&buffer, 1) == 1) ||
              (nbit == 1)) {  //   I 1 bit || nbit ==1 touch 1
            touchbit(&buffer, 1, 1);
          }
          //
        } else {
          sleft(&tempresult);
          touchbit(&tempresult, 1, 0);
          int nbit = getbit(&devider, fone - i + 1);
          sleft(&buffer);
          if ((getbit(&buffer, 1) == 1) ||
              (nbit == 1)) {  //   I 1 bit || nbit ==1 touch 1
            touchbit(&buffer, 1, 1);
          }
        }
      }
      sright(&buffer);  // rightshift ?
                        // for (int i = 128; i > 0; i--) {
                        //   printf("%d", getbit(&buffer, i));
                        // }
                        // printf("\n");

      // printf(" - buffer\n");
      if (is_zero(&buffer) != 1) {
        addcap++;
        x10dec(&buffer);
      }
      x10dec(result);

      adder_wo_normalize(result, &tempresult, result);
      // adder(result, &tempresult, result);

      devider = buffer;  //   Теперь делитель - это бывший остаток

      if (((cap1 - cap2 + addcap) >= 0) && (cap1 - cap2 + addcap) < 29) {  //
        set_cap(result, (cap1 - cap2 + addcap));
      }
      while ((cap1 - cap2 + addcap) < 0) {
        x10dec(result);
        addcap++;
      }
      while ((cap1 - cap2 + addcap) >= 29) {
        bank_rounding_div10(result);
        addcap--;
        counter++;
      }
    }

    set_cap(result, cap1 - cap2 + addcap);

    if (((sign1 == 0) && (sign2 == 0)) || ((sign1 == 1) && (sign2 == 1))) {
      touchbit(result, 128, 0);
    } else {
      touchbit(result, 128, 1);
    }

    // *dec = result;
    // touchbit(result, 128, sign);
    // set_cap(result, scalenum - 1); // setcap cap1-cap2 if <0 divx10 n если
    // выходим за мантиссу, то в зависимости от знака 2 или 3 в ошибку
  }
  return error;
}

int adder_wo_normalize(s21_decimal *dec1, s21_decimal *dec2,
                       s21_decimal *dec3) {
  dec3->bits[0] = 0;
  dec3->bits[1] = 0;
  dec3->bits[2] = 0;
  dec3->bits[3] = 0;
  int error = 0;
  int sum = 0;
  int addbit = 0;
  for (int i = 1; i <= 96; i++) {
    sum = s21_getbit(dec1, i) + s21_getbit(dec2, i) + addbit;
    if (sum == 0) {
      s21_touchbit(dec3, i, 0);
      addbit = 0;
    }
    if (sum == 1) {
      s21_touchbit(dec3, i, 1);
      addbit = 0;
    }
    if (sum == 2) {
      s21_touchbit(dec3, i, 0);
      addbit = 1;
    }
    if (sum == 3) {
      s21_touchbit(dec3, i, 1);
      addbit = 1;
    }
  }
  return 0;
}

void x10mant(s21_decimal *dec1) {
  int addbit = 0;

  s21_decimal dec3 = {0, 0, 0, 0};
  dec3.bits[0] = 0;
  dec3.bits[1] = 0;
  dec3.bits[2] = 0;
  dec3.bits[3] = 0;

  for (int i = 1; i <= 96; i++) {
    int sum = getmbit(dec1, i - 1) + getmbit(dec1, i - 3) + addbit;
    if (sum == 0) {
      touchbit(&dec3, i, 0);
      addbit = 0;
    }
    if (sum == 1) {
      touchbit(&dec3, i, 1);
      addbit = 0;
    }
    if (sum == 2) {
      touchbit(&dec3, i, 0);
      addbit = 1;
    }
    if (sum == 3) {
      touchbit(&dec3, i, 1);
      addbit = 1;
    }
  }
  for (int i = 94; i <= 97; i++) {
    int sum = getmbit(dec1, i) + getmbit(dec1, i + 2) + addbit;
    if (sum == 0) {
      touchbit(&dec3, i + 3, 0);
      addbit = 0;
    }
    if (sum == 1) {
      touchbit(&dec3, i + 3, 1);
      addbit = 0;
    }
    if (sum == 2) {
      touchbit(&dec3, i + 3, 0);
      addbit = 1;
    }
    if (sum == 3) {
      touchbit(&dec3, i + 3, 1);
      addbit = 1;
    }
  }
  for (int i = 1; i <= 100; i++) {
    touchbit(dec1, i, getbit(&dec3, i));
  }
}

int sd_getbit(susper_decimal *dec,
              int num) {  //  Возвращает бит супердецимала
  int result = 0;
  if ((num <= 32) && (num >= 1)) {
    if (dec->bits[0] & (1 << (num - 1))) {
      result = 1;
    }
  }
  if ((num > 32) && (num <= 64)) {
    if (dec->bits[1] & (1 << (num - 33))) {
      result = 1;
    }
  }
  if ((num > 64) && (num <= 96)) {
    if (dec->bits[2] & (1 << (num - 65))) {
      result = 1;
    }
  }
  if ((num > 96) && (num <= 128)) {
    if (dec->bits[3] & (1 << (num - 97))) {
      result = 1;
    }
  }
  if ((num > 128) && (num <= 160)) {
    if (dec->bits[4] & (1 << (num - 129))) {
      result = 1;
    }
  }
  if ((num > 160) && (num <= 192)) {
    if (dec->bits[5] & (1 << (num - 161))) {
      result = 1;
    }
  }
  if ((num > 192) && (num <= 224)) {
    if (dec->bits[6] & (1 << (num - 193))) {
      result = 1;
    }
  }
  if ((num > 224) && (num <= 256)) {
    if (dec->bits[7] & (1 << (num - 225))) {
      result = 1;
    }
  }

  return result;
}

void sd_touchbit(susper_decimal *dec, int num,
                 int bit) {  //  Устанавливает бит в децимал(1 или 0)
  if (num <= 32) {
    if (bit == 1) {
      dec->bits[0] |= (1 << (num - 1));
    } else {
      dec->bits[0] &= ~(1 << (num - 1));
    }
  }
  if ((num > 32) && (num <= 64)) {
    if (bit == 1) {
      dec->bits[1] |= (1 << (num - 33));
    } else {
      dec->bits[1] &= ~(1 << (num - 33));
    }
  }
  if ((num > 64) && (num <= 96)) {
    if (bit == 1) {
      dec->bits[2] |= (1 << (num - 65));
    } else {
      dec->bits[2] &= ~(1 << (num - 65));
    }
  }
  if ((num > 96) && (num <= 128)) {
    if (bit == 1) {
      dec->bits[3] |= (1 << (num - 97));
    } else {
      dec->bits[3] &= ~(1 << (num - 97));
    }
  }
  if ((num > 128) && (num <= 160)) {
    if (bit == 1) {
      dec->bits[4] |= (1 << (num - 129));
    } else {
      dec->bits[4] &= ~(1 << (num - 129));
    }
  }
  if ((num > 160) && (num <= 192)) {
    if (bit == 1) {
      dec->bits[5] |= (1 << (num - 161));
    } else {
      dec->bits[5] &= ~(1 << (num - 161));
    }
  }
  if ((num > 192) && (num <= 224)) {
    if (bit == 1) {
      dec->bits[6] |= (1 << (num - 193));
    } else {
      dec->bits[6] &= ~(1 << (num - 193));
    }
  }
  if ((num > 224) && (num <= 256)) {
    if (bit == 1) {
      dec->bits[7] |= (1 << (num - 225));
    } else {
      dec->bits[7] &= ~(1 << (num - 225));
    }
  }
}

int sd_first1(susper_decimal *dec) {
  int first1 = -1;
  for (int i = 256; (i > 0) && (first1 == -1); i--) {
    if (sd_getbit(dec, i) == 1) {
      first1 = i;
    }
  }
  return first1;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  susper_decimal sdec;
  sdec.bits[0] = 0;
  sdec.bits[1] = 0;
  sdec.bits[2] = 0;
  sdec.bits[3] = 0;
  sdec.bits[4] = 0;
  sdec.bits[5] = 0;
  sdec.bits[6] = 0;
  sdec.bits[7] = 0;

  result->bits[0] = 0;
  result->bits[1] = 0;
  result->bits[2] = 0;
  result->bits[3] = 0;

  // printf("\n");
  // for (int i = 128; i > 0; i--) {
  //   printf("%d", getbit(&value_1, i));
  // }
  // printf("\n");
  // for (int i = 128; i > 0; i--) {
  //   printf("%d", getbit(&value_2, i));
  // }
  // printf("\n");
  int error = 0;
  int sumcap = get_cap(&value_1) + get_cap(&value_2);
  for (int i = 1; i <= 96; i++) {
    if (getbit(&value_1, i) == 1) {
      int addbit = 0;
      for (int j = 1; j <= 96; j++) {
        int sum = sd_getbit(&sdec, j + i - 1) + getbit(&value_2, j) + addbit;
        if (sum == 0) {
          sd_touchbit(&sdec, i + j - 1, 0);
          addbit = 0;
        }
        if (sum == 1) {
          sd_touchbit(&sdec, i + j - 1, 1);
          addbit = 0;
        }
        if (sum == 2) {
          sd_touchbit(&sdec, i + j - 1, 0);
          addbit = 1;
        }
        if (sum == 3) {
          sd_touchbit(&sdec, i + j - 1, 1);
          addbit = 1;
        }
      }
      if (addbit == 1) {
        sd_touchbit(&sdec, i + 96, 1);
      }
    }
  }
  while (
      (sd_first1(&sdec) > 96) &&
      (error ==
       0)) {  //  Если супердец залезает за мантиссу обычного децимала. Режем.
    if (sumcap > 0) {
      sd_bank_rounding_div10(&sdec);
      sumcap--;
    } else {
      if (((getbit(&value_1, 128) == 1) && (getbit(&value_2, 128) == 1)) ||
          ((getbit(&value_1, 128) == 0) && (getbit(&value_2, 128) == 0))) {
        error = 1;
      } else {
        error = 2;
      }
    }
  }
  if (error == 0) {
    while (sumcap > 28)  //  Денормализуем степень, если она больше 28
    {
      sd_bank_rounding_div10(&sdec);
      sumcap--;
    }

    result->bits[0] = sdec.bits[0];
    result->bits[1] = sdec.bits[1];
    result->bits[2] = sdec.bits[2];
    set_cap(result, sumcap);
    if (((getbit(&value_1, 128) == 1) && (getbit(&value_2, 128) == 1)) ||
        ((getbit(&value_1, 128) == 0) && (getbit(&value_2, 128) == 0))) {
      touchbit(result, 128, 0);
    } else {
      touchbit(result, 128, 1);
    }
    // }
  }
  // for (int i = 128; i > 0; i--) {
  //   printf("%d", getbit(result, i));
  // }
  // printf("\n");
  // for (int i = 256; i >= 1; i--) {
  //   printf("%d", sd_getbit(&sdec, i));
  // }
  // printf("\n");
  // printf("%d\n", error);
  return error;

  // for (int i = 256; i >= 1; i--) {
  //   printf("%d", sd_getbit(&sdec, i));
  // }
  // printf("\n");
}

unsigned int sd_divx10(susper_decimal *dec) {
  unsigned int buffer = 0;

  susper_decimal result = {{0, 0, 0, 0, 0, 0, 0, 0}};
  result.bits[0] = 0;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0;
  result.bits[4] = 0;
  result.bits[5] = 0;
  result.bits[6] = 0;
  result.bits[7] = 0;

  int fone = sd_first1(dec);

  for (int i = 0; i < fone + 2; i++) {
    if (buffer >= 10) {
      sd_sleft(&result);
      sd_touchbit(&result, 1, 1);
      buffer = buffer - 10u;
      int nbit = sd_getbit(dec, fone - i + 1);
      buffer = buffer << 1;
      buffer |= nbit;
    } else {
      sd_sleft(&result);
      sd_touchbit(&result, 1, 0);
      int nbit = sd_getbit(dec, fone - i + 1);
      buffer = buffer << 1;
      buffer |= nbit;
    }
  }

  buffer = buffer >> 1;
  *dec = result;
  return buffer;
}

void sd_sleft(susper_decimal *dec) {
  dec->bits[7] = dec->bits[7] << 1;
  sd_touchbit(dec, 225, sd_getbit(dec, 224));
  dec->bits[6] = dec->bits[6] << 1;
  sd_touchbit(dec, 193, sd_getbit(dec, 192));
  dec->bits[5] = dec->bits[5] << 1;
  sd_touchbit(dec, 161, sd_getbit(dec, 160));
  dec->bits[4] = dec->bits[4] << 1;
  sd_touchbit(dec, 129, sd_getbit(dec, 128));
  dec->bits[3] = dec->bits[3] << 1;
  sd_touchbit(dec, 97, sd_getbit(dec, 96));
  dec->bits[2] = dec->bits[2] << 1;
  sd_touchbit(dec, 65, sd_getbit(dec, 64));
  dec->bits[1] = dec->bits[1] << 1;
  sd_touchbit(dec, 33, sd_getbit(dec, 32));
  dec->bits[0] = dec->bits[0] << 1;
}

void sd_bank_rounding_div10(susper_decimal *dec) {
  int buffer = sd_divx10(dec);
  if ((buffer > 5) || ((buffer == 5) && (sd_getbit(dec, 1) == 1))) {
    sd_increase_mant_1(dec);
  }
}

int sd_increase_mant_1(susper_decimal *dec) {
  susper_decimal res = {0, 0, 0, 0, 0, 0, 0, 0};
  int result = 1;
  int incr_ok = 0;
  int i = 1;
  while ((incr_ok == 0) && (i <= 256)) {
    if (sd_getbit(dec, i) == 1) {
      sd_touchbit(&res, i, 0);
    } else {
      sd_touchbit(&res, i, 1);
      incr_ok = 1;
    }
    i++;
  }
  while ((i <= 256)) {
    sd_touchbit(&res, i, sd_getbit(dec, i));
    i++;
  }
  if (incr_ok == 1) {
    *dec = res;
    result = 0;
  }

  return result;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  result->bits[0] = 0;
  result->bits[1] = 0;
  result->bits[2] = 0;
  result->bits[3] = 0;
  int remainder = 0;
  int cap = get_cap(&value);
  int sig = s21_getbit(&value, 128);
  for (int i = 0; i < cap; i++) {
    remainder = remdivx10(&value);
  }
  if (sig == 1) {
    increase_mant_1(&value);
  }

  *result = value;
  set_cap(result, 0);
  s21_touchbit(result, 128, sig);
  return 0;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  result->bits[0] = 0;
  result->bits[1] = 0;
  result->bits[2] = 0;
  result->bits[3] = 0;
  int remainder = 0;
  int cap = get_cap(&value);
  int sig = s21_getbit(&value, 128);
  for (int i = 0; i < cap; i++) {
    remainder = remdivx10(&value);
  }
  if ((remainder > 5) || ((remainder == 5) && (s21_getbit(&value, 1) == 1))) {
    increase_mant_1(&value);
  }

  *result = value;
  set_cap(result, 0);
  s21_touchbit(result, 128, sig);
  return 0;
}

int s21_from_decimal_to_float(s21_decimal dec, float *res) {
  int result = 0;
  int sign;
  double temp = 0.0;
  for (int i = 1; i < 97; i++) {
    temp += (s21_getbit(&dec, i) * pow(2, i - 1));
  }

  int exp = get_cap(&dec);
  *res = temp / pow(10, exp);

  if (s21_getbit(&dec, 128) == 1)
    sign = -1;
  else
    sign = 1;
  *res *= sign;
  return result;
}
