#include "s21_string.h"

#define MAX_ERRLIST 107
#define MIN_ERRLIST -1
#define ERROR "Unknown error: "

const char *maserror[] = {"Undefined error: 0",
                          "Operation not permitted",
                          "No such file or directory",
                          "No such process",
                          "Interrupted system call",
                          "Input/output error",
                          "Device not configured",
                          "Argument list too long",
                          "Exec format error",
                          "Bad file descriptor",
                          "No child processes",
                          "Resource deadlock avoided",
                          "Cannot allocate memory",
                          "Permission denied",
                          "Bad address",
                          "Block device required",
                          "Resource busy",
                          "File exists",
                          "Cross-device link",
                          "Operation not supported by device",
                          "Not a directory",
                          "Is a directory",
                          "Invalid argument",
                          "Too many open files in system",
                          "Too many open files",
                          "Inappropriate ioctl for device",
                          "Text file busy",
                          "File too large",
                          "No space left on device",
                          "Illegal seek",
                          "Read-only file system",
                          "Too many links",
                          "Broken pipe",
                          "Numerical argument out of domain",
                          "Result too large",
                          "Resource temporarily unavailable",
                          "Operation now in progress",
                          "Operation already in progress",
                          "Socket operation on non-socket",
                          "Destination address required",
                          "Message too long",
                          "Protocol wrong type for socket",
                          "Protocol not available",
                          "Protocol not supported",
                          "Socket type not supported",
                          "Operation not supported",
                          "Protocol family not supported",
                          "Address family not supported by protocol family",
                          "Address already in use",
                          "Can't assign requested address",
                          "Network is down",
                          "Network is unreachable",
                          "Network dropped connection on reset",
                          "Software caused connection abort",
                          "Connection reset by peer",
                          "No buffer space available",
                          "Socket is already connected",
                          "Socket is not connected",
                          "Can't send after socket shutdown",
                          "Too many references: can't splice",
                          "Operation timed out",
                          "Connection refused",
                          "Too many levels of symbolic links",
                          "File name too long",
                          "Host is down",
                          "No route to host",
                          "Directory not empty",
                          "Too many processes",
                          "Too many users",
                          "Disc quota exceeded",
                          "Stale NFS file handle",
                          "Too many levels of remote in path",
                          "RPC struct is bad",
                          "RPC version wrong",
                          "RPC prog. not avail",
                          "Program version wrong",
                          "Bad procedure for program",
                          "No locks available",
                          "Function not implemented",
                          "Inappropriate file type or format",
                          "Authentication error",
                          "Need authenticator",
                          "Device power is off",
                          "Device error",
                          "Value too large to be stored in data type",
                          "Bad executable (or shared library)",
                          "Bad CPU type in executable",
                          "Shared library version mismatch",
                          "Malformed Mach-o file",
                          "Operation canceled",
                          "Identifier removed",
                          "No message of desired type",
                          "Illegal byte sequence",
                          "Attribute not found",
                          "Bad message",
                          "EMULTIHOP (Reserved)",
                          "No message available on STREAM",
                          "ENOLINK (Reserved)",
                          "No STREAM resources",
                          "Not a STREAM",
                          "Protocol error",
                          "STREAM ioctl timeout",
                          "Operation not supported on socket",
                          "Policy not found",
                          "State not recoverable",
                          "Previous owner died",
                          "Interface output queue is full"};

int s21_atoi(const char *str) {
  int result = 0;
  int sign = 1;
  int overflow = 0;

  while (*str == ' ') str++;

  if (*str == '-') {
    str++;
    sign = -1;
  }

  if (*str == '+') {
    str++;
  }

  while (*str && *str >= '0' && *str <= '9') {
    result = result * 10 + (*str - '0');
    if (result < 0) {
      overflow = 1;
      break;
    }
    str++;
  }
  if (overflow)
    result = sign > 0 ? INT32_MAX : INT32_MIN;
  else
    result *= sign;

  return result;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int s21_sprintf(char *str, const char *format, ...) {
  va_list factor;
  va_start(factor, format);
  int char_counter = 0;
  int buffermod = 0;
  int long_mode = 0;
  int str_len = 1;
  int buff_len = 1;
  char buffer[2048];
  char tstr[10] = {'\0'};
  int argument = 0;
  str_len = str_len + buff_len;
  str_len -= 1;

  for (const char *c = format; *c; c++) {
    if (buffermod == 0) {
      switch (*c) {
        case '%':
          buffermod = 1;
          clean_buffer(buffer);
          buff_len = 0;
          c++;
          break;
        default:
          str_len++;
          s21_strncat(str, c, 1);
          char_counter++;
          break;
      }
    }
    if (buffermod == 1) {
      switch (*c) {
        case 'p':
          char_counter =
              char_counter + form_p(str, buffer, va_arg(factor, int));
          bl_mod_off(&buffermod, &long_mode);
          break;
        case 'd':
          char_counter =
              char_counter + form_d(str, buffer, va_arg(factor, int));
          bl_mod_off(&buffermod, &long_mode);
          break;
        case 'i':
          char_counter =
              char_counter + form_d(str, buffer, va_arg(factor, int));
          bl_mod_off(&buffermod, &long_mode);
          break;
        case 'x':
          char_counter =
              char_counter + form_x(str, buffer, va_arg(factor, int));
          bl_mod_off(&buffermod, &long_mode);
          break;
        case 'X':
          char_counter =
              char_counter + form_X(str, buffer, va_arg(factor, int));
          bl_mod_off(&buffermod, &long_mode);
          break;
        case 'u':
          char_counter =
              char_counter + form_u(str, buffer, va_arg(factor, unsigned int));
          bl_mod_off(&buffermod, &long_mode);
          break;
        case 'c':
          char_counter =
              char_counter + form_c(str, buffer, va_arg(factor, int));
          bl_mod_off(&buffermod, &long_mode);
          break;
        case 's':
          char_counter =
              char_counter + form_s(str, buffer, va_arg(factor, char *));
          bl_mod_off(&buffermod, &long_mode);
          break;
        case '*':
          argument = va_arg(factor, int);
          int_to_string(tstr, argument);
          s21_strcat(buffer, tstr);
          break;
        case 'g':
          char_counter =
              char_counter + form_g(str, buffer, va_arg(factor, double));
          bl_mod_off(&buffermod, &long_mode);
          break;
        case '%':
          char_counter = char_counter + form_c(str, buffer, '%');
          bl_mod_off(&buffermod, &long_mode);
          break;
        case 'G':
          char_counter =
              char_counter + form_G(str, buffer, va_arg(factor, double));
          bl_mod_off(&buffermod, &long_mode);
          break;
        case 'e':
          if (long_mode) {
            char_counter =
                char_counter + form_e(str, buffer, va_arg(factor, long double));
          } else {
            char_counter =
                char_counter + form_e(str, buffer, va_arg(factor, double));
          }
          bl_mod_off(&buffermod, &long_mode);
          break;
        case 'E':
          if (long_mode) {
            char_counter =
                char_counter + form_E(str, buffer, va_arg(factor, long double));
          } else {
            char_counter =
                char_counter + form_E(str, buffer, va_arg(factor, double));
          }
          bl_mod_off(&buffermod, &long_mode);
          break;
        case 'o':
          char_counter =
              char_counter + form_o(str, buffer, va_arg(factor, int));
          bl_mod_off(&buffermod, &long_mode);
          break;
        case 'L':
          long_mode = 1;
          break;
        case 'f':
          if (long_mode) {
            char_counter =
                char_counter + form_f(str, buffer, va_arg(factor, long double));
          } else {
            char_counter =
                char_counter + form_f(str, buffer, va_arg(factor, double));
          }
          bl_mod_off(&buffermod, &long_mode);
          break;
        default:
          buff_len++;
          s21_strncat(buffer, c, 1);
          break;
      }
    }
  }
  va_end(factor);

  return char_counter;
}

void int_to_string(char *tstr, int argument) {
  if (argument < 0) {
    argument *= -1;
  }

  for (int i = 0; i < 10; i++) {
    tstr[i] = '\0';
  }
  int len = lenint(argument) - 1;
  for (int i = len; i >= 0; i--) {
    tstr[i] = (argument % 10) + 48;
    argument /= 10;
  }
}

int form_p(char *str, char *buff, int factor) {
  syntx synt = {{0, 0, 0, 0, 0}, {0, 0}, {0, 0}, {0, 0, 0}};
  char result_buffer[256] = {'\0'};
  int buffpointer = 0;
  long tempfactor = factor;
  // int wight = 1;
  // int lenght = 1;
  synt_parser(&synt, buff);

  if (tempfactor < 0) {
    tempfactor = tempfactor + 4294967296;
  }

  if (synt.lenght.l == 1) {
    while (tempfactor > 4294967295) {
      tempfactor = tempfactor - 4294967295;
    }
    while (tempfactor < 0) {
      tempfactor = tempfactor + 4294967296;
    }
  }

  if (synt.lenght.h == 1) {
    while (tempfactor > 32767) {
      tempfactor = tempfactor - 65536;
    }

    while (tempfactor < 0) {
      tempfactor = tempfactor + 65536;
    }
  }

  if (synt.flags.minus == 1) {
    from_p_minus(synt, result_buffer, &buffpointer, tempfactor, 'p');
  } else {
    from_p_plus(synt, result_buffer, &buffpointer, tempfactor, 'p');
  }
  s21_strcat(str, result_buffer);
  return buffpointer;
}

void from_p_minus(syntx synt, char *result_buffer, int *buffpointer,
                  long tempfactor, char type) {
  int len_int = len_hex(tempfactor);  //  Длинна аргумента

  if (type == 'p') {
    touch_null(result_buffer, buffpointer);

    result_buffer[*buffpointer] = 'x';
    *buffpointer = *buffpointer + 1;
  }

  for (int i = *buffpointer;
       i < synt.accuracy.num - len_int + (synt.flags.sharp) + 2;
       i++) {  //  Добить пробелами до ширины
    touch_null(result_buffer, buffpointer);
  }

  print_hex(result_buffer, buffpointer, len_int, tempfactor, type);
  // *buffpointer = *buffpointer + len_int;

  for (int i = *buffpointer; i < synt.width.num;
       i++) {  //  Добить пробелами до ширины
    touch_space(result_buffer, buffpointer);
  }
}

void from_p_plus(syntx synt, char *result_buffer, int *buffpointer,
                 long tempfactor, char type) {
  if (synt.flags.nul == 1) {
    int len_int = len_hex(tempfactor);
    if (synt.accuracy.num != 0) {
      for (int i = 0; (i < synt.width.num - len_int -
                               ((tempfactor < 0) || (synt.flags.plus)) - 1) &&
                      (i < synt.width.num - synt.accuracy.num -
                               ((tempfactor < 0) || (synt.flags.plus)) - 2);
           i++) {  //  Добить спэйсами до ширины
        touch_space(result_buffer, buffpointer);
      }
    }
    if (type == 'p') {
      touch_null(result_buffer, buffpointer);
      result_buffer[*buffpointer] = 'x';
      *buffpointer = *buffpointer + 1;
    }
    for (int i = *buffpointer;  //  Длинна аргумента
         (i < synt.width.num - len_int - (synt.flags.sharp));
         i++) {  //  Добить нулями до ширины
      touch_null(result_buffer, buffpointer);
    }
    for (int i = *buffpointer;
         i < synt.accuracy.num - len_int - (synt.flags.sharp) -
                 (tempfactor == 0) + 2;
         i++) {  //  Добить нулями до ширины
      touch_null(result_buffer, buffpointer);
    }
    if (tempfactor == 0) {
      touch_null(result_buffer, buffpointer);
    }
    print_hex(result_buffer, buffpointer, len_int, tempfactor, type);
  } else {
    if (tempfactor < 0) {
      tempfactor = tempfactor + 4294967296;
    }
    int len_int = len_hex(tempfactor);  //  Длинна аргумента
    for (int i = *buffpointer;
         (i < synt.width.num - len_int - (synt.flags.sharp * 2) - 2) &&
         (i < synt.width.num - synt.accuracy.num - 2);
         i++) {  //  Добить пробелами до ширины
      touch_space(result_buffer, buffpointer);
    }
    for (int i = 0; i < synt.accuracy.num - len_int - synt.flags.sharp;
         i++) {  //  Добить нулями до ширины
      touch_null(result_buffer, buffpointer);
    }
    if (tempfactor == 0) {
      touch_null(result_buffer, buffpointer);
    }
    if (type == 'p') {
      touch_null(result_buffer, buffpointer);
      result_buffer[*buffpointer] = 'x';
      *buffpointer = *buffpointer + 1;
    }
    print_hex(result_buffer, buffpointer, len_int, tempfactor, type);
  }
}

int form_s(char *str, char *buff, char *factor) {
  syntx synt = {{0, 0, 0, 0, 0}, {0, 0}, {0, 0}, {0, 0, 0}};
  char result_buffer[256] = {'\0'};
  int buffpointer = 0;
  char *tempfactor = factor;
  // int wight = 1;
  // int lenght = 1;
  synt_parser(&synt, buff);

  if (synt.flags.minus == 1) {
    from_s_minus(synt, result_buffer, &buffpointer, tempfactor);
  } else {
    from_s_plus(synt, result_buffer, &buffpointer, tempfactor);
  }
  s21_strcat(str, result_buffer);
  return buffpointer;
}

void from_s_minus(syntx synt, char *result_buffer, int *buffpointer,
                  char *tempfactor) {
  // int len = strlen(tempfactor);
  for (int i = 0; i < synt.accuracy.num; i++) {
    result_buffer[*buffpointer] = tempfactor[i];
    *buffpointer = *buffpointer + 1;
  }

  for (int i = *buffpointer; i < synt.width.num;
       i++) {  //  Добить пробелами до ширины
    touch_space(result_buffer, buffpointer);
  }
}

void from_s_plus(syntx synt, char *result_buffer, int *buffpointer,
                 char *tempfactor) {
  int len = s21_strlen(tempfactor);
  if (synt.flags.nul == 1) {  //  Слева нули

    for (int i = 0; i < synt.width.num - len;
         i++) {  //  Добить нулями до ширины
      result_buffer[i] = '0';
      *buffpointer = *buffpointer + 1;
    }
    if (synt.accuracy.num > 0) {
      for (int i = *buffpointer; i < synt.width.num - synt.accuracy.num;
           i++) {  //  Добить нулями до ширины
        result_buffer[i] = '0';
        *buffpointer = *buffpointer + 1;
      }
    }

  } else {
    for (int i = 0; i < synt.width.num - len;
         i++) {  //  Добить нулями до ширины
      result_buffer[i] = ' ';
      *buffpointer = *buffpointer + 1;
    }

    if (synt.accuracy.num > 0) {
      for (int i = *buffpointer; i < synt.width.num - synt.accuracy.num;
           i++) {  //  Добить нулями до ширины
        result_buffer[i] = ' ';
        *buffpointer = *buffpointer + 1;
      }
    }
  }
  int n = 0;
  for (int i = *buffpointer; i < synt.width.num; i++) {
    result_buffer[i] = tempfactor[n];
    n++;
    *buffpointer = *buffpointer + 1;
  }
}

int form_c(char *str, char *buff, int factor) {
  syntx synt = {{0, 0, 0, 0, 0}, {0, 0}, {0, 0}, {0, 0, 0}};
  char result_buffer[256] = {'\0'};
  int buffpointer = 0;
  long tempfactor = factor;
  // int wight = 1;
  // int lenght = 1;
  synt_parser(&synt, buff);

  if (synt.flags.minus == 1) {
    from_c_minus(synt, result_buffer, &buffpointer, tempfactor);
  } else {
    from_c_plus(synt, result_buffer, &buffpointer, tempfactor);
  }
  s21_strcat(str, result_buffer);
  return buffpointer;
}

void from_c_minus(syntx synt, char *result_buffer, int *buffpointer,
                  int tempfactor) {
  result_buffer[*buffpointer] = tempfactor;
  *buffpointer = *buffpointer + 1;

  for (int i = *buffpointer; i < synt.width.num;
       i++) {  //  Добить пробелами до ширины
    touch_space(result_buffer, buffpointer);
  }
}

void from_c_plus(syntx synt, char *result_buffer, int *buffpointer,
                 int tempfactor) {
  if (synt.flags.nul == 1) {  //  Слева нули

    for (int i = 0; i < synt.width.num - 1; i++) {  //  Добить нулями до ширины
      touch_null(result_buffer, buffpointer);
    }

  } else {
    for (int i = 0; i < synt.width.num - 1; i++) {  //  Добить нулями до ширины
      touch_space(result_buffer, buffpointer);
    }
  }
  result_buffer[*buffpointer] = tempfactor;
  *buffpointer = *buffpointer + 1;
}

int form_e(char *str, char *buff, double factor) {
  syntx synt = {{0, 0, 0, 0, 0}, {0, 0}, {0, 0}, {0, 0, 0}};
  synt.accuracy.num = 6;
  char result_buffer[256] = {'\0'};
  int buffpointer = 0;
  double tempfactor = factor;
  synt_parser(&synt, buff);

  if (synt.flags.minus == 1) {
    form_e_minus(synt, result_buffer, &buffpointer, tempfactor, 'e');
  } else {
    form_e_plus(synt, result_buffer, &buffpointer, tempfactor, 'e');
  }
  s21_strcat(str, result_buffer);
  return buffpointer;
}

int form_E(char *str, char *buff, double factor) {
  syntx synt = {{0, 0, 0, 0, 0}, {0, 0}, {0, 0}, {0, 0, 0}};
  synt.accuracy.num = 6;
  char result_buffer[256] = {'\0'};
  int buffpointer = 0;
  double tempfactor = factor;
  synt_parser(&synt, buff);

  if (synt.flags.minus == 1) {
    form_e_minus(synt, result_buffer, &buffpointer, tempfactor, 'E');
  } else {
    form_e_plus(synt, result_buffer, &buffpointer, tempfactor, 'E');
  }
  s21_strcat(str, result_buffer);
  return buffpointer;
}

int form_e_minus(syntx synt, char *result_buffer, int *buffpointer,
                 double tempfactor, char type) {
  int res_cap = 0;

  //  Sign

  sign_e(synt, result_buffer, buffpointer, &tempfactor);

  //  Normalization

  int emer_counter = 0;

  if (tempfactor != 0) {
    e_normalization(&tempfactor, &emer_counter);
  }

  res_cap = print_e(synt, result_buffer, buffpointer, &tempfactor,
                    &emer_counter, type);

  //  Space to weight

  for (int i = *buffpointer; i < synt.width.num; i++) {
    result_buffer[*buffpointer] = ' ';
    *buffpointer = *buffpointer + 1;
  }
  return res_cap;
}

int form_e_plus(syntx synt, char *result_buffer, int *buffpointer,
                double tempfactor, char type) {
  int emer_counter = 0;
  int div_min_one_flag = 0;
  int res_cap = 0;
  if (synt.flags.nul == 1) {  //  For null flag
    sign_e(synt, result_buffer, buffpointer, &tempfactor);
    if (tempfactor != 0) {  //  Normalization
      e_normalization(&tempfactor, &emer_counter);
    }
    int len_cap = lenint(emer_counter);
    if (len_cap < 2) {
      len_cap = 2;
    }
    int num_of_zero = synt.width.num - *buffpointer - len_cap - 2 -
                      synt.accuracy.num - 2;  //  Zerrrro!

    if (synt.accuracy.num == 0) {
      num_of_zero++;
    }
    for (int i = 0; i < (num_of_zero); i++) {
      result_buffer[*buffpointer] = '0';
      *buffpointer = *buffpointer + 1;
    }
  } else {  //  Для пробелов
    if (tempfactor < 0) {
      tempfactor *= -1;
      div_min_one_flag = 1;
    }
    if (tempfactor != 0) {  //  Normalization
      e_normalization(&tempfactor, &emer_counter);
    }
    int len_cap = lenint(emer_counter);
    if (len_cap < 2) {
      len_cap = 2;
    }
    if (div_min_one_flag == 1) {
      tempfactor *= -1;
    }

    int num_of_spaces =
        synt.width.num -
        ((tempfactor < 0) || (synt.flags.plus) || (synt.flags.space)) -
        len_cap - 2 - synt.accuracy.num - 2;  //   OuterSpaces
    if (synt.accuracy.num == 0) {
      num_of_spaces++;
    }
    for (int i = 0; i < (num_of_spaces); i++) {
      result_buffer[*buffpointer] = ' ';
      *buffpointer = *buffpointer + 1;
    }
    sign_e(synt, result_buffer, buffpointer, &tempfactor);
  }
  res_cap = print_e(synt, result_buffer, buffpointer, &tempfactor,
                    &emer_counter, type);
  return res_cap;
}

int form_g(char *str, char *buff, double factor) {
  syntx synt = {{0, 0, 0, 0, 0}, {0, 0}, {0, 0}, {0, 0, 0}};
  synt.accuracy.num = 6;
  char result_buffer[256] = {'\0'};
  int buffpointer = 0;
  double tempfactor = factor;
  int res_cap = 0;
  synt_parser(&synt, buff);

  if (synt.flags.minus == 1) {
    res_cap = form_e_minus(synt, result_buffer, &buffpointer, tempfactor, 'g');
  } else {
    res_cap = form_e_plus(synt, result_buffer, &buffpointer, tempfactor, 'g');
  }

  if ((res_cap >= -4) && (res_cap <= synt.accuracy.num)) {
    clean_buffer(result_buffer);
    buffpointer = 0;
    tempfactor = factor;
    if (synt.flags.minus == 1) {
      form_f_minus(synt, result_buffer, &buffpointer, tempfactor, 'g');
    } else {
      form_f_plus(synt, result_buffer, &buffpointer, tempfactor, 'g');
    }
  }

  s21_strcat(str, result_buffer);
  return buffpointer;
}

int form_G(char *str, char *buff, double factor) {
  syntx synt = {{0, 0, 0, 0, 0}, {0, 0}, {0, 0}, {0, 0, 0}};
  synt.accuracy.num = 6;
  char result_buffer[256] = {'\0'};
  int buffpointer = 0;
  double tempfactor = factor;
  int res_cap = 0;
  synt_parser(&synt, buff);

  if (synt.flags.minus == 1) {
    res_cap = form_e_minus(synt, result_buffer, &buffpointer, tempfactor, 'G');
  } else {
    res_cap = form_e_plus(synt, result_buffer, &buffpointer, tempfactor, 'G');
  }

  if ((res_cap >= -4) && (res_cap < synt.accuracy.num)) {
    clean_buffer(result_buffer);
    buffpointer = 0;
    tempfactor = factor;
    if (synt.flags.minus == 1) {
      form_f_minus(synt, result_buffer, &buffpointer, tempfactor, 'G');
    } else {
      form_f_plus(synt, result_buffer, &buffpointer, tempfactor, 'G');
    }
  }

  s21_strcat(str, result_buffer);
  return buffpointer;
}

int form_X(char *str, char *buff, int factor) {
  syntx synt = {{0, 0, 0, 0, 0}, {0, 0}, {0, 0}, {0, 0, 0}};
  char result_buffer[256] = {'\0'};
  int buffpointer = 0;
  long tempfactor = factor;
  // int wight = 1;
  // int lenght = 1;
  synt_parser(&synt, buff);

  if (tempfactor < 0) {
    tempfactor = tempfactor + 4294967296;
  }

  if (synt.lenght.l == 1) {
    while (tempfactor > 4294967295) {
      tempfactor = tempfactor - 4294967295;
    }
    while (tempfactor < 0) {
      tempfactor = tempfactor + 4294967296;
    }
  }

  if (synt.lenght.h == 1) {
    while (tempfactor > 32767) {
      tempfactor = tempfactor - 65536;
    }

    while (tempfactor < 0) {
      tempfactor = tempfactor + 65536;
    }
  }

  if (synt.flags.minus == 1) {
    from_x_minus(synt, result_buffer, &buffpointer, tempfactor, 'X');
  } else {
    from_x_plus(synt, result_buffer, &buffpointer, tempfactor, 'X');
  }
  s21_strcat(str, result_buffer);
  return buffpointer;
}
int form_x(char *str, char *buff, int factor) {
  syntx synt = {{0, 0, 0, 0, 0}, {0, 0}, {0, 0}, {0, 0, 0}};
  char result_buffer[256] = {'\0'};
  int buffpointer = 0;
  long tempfactor = factor;
  // int wight = 1;
  // int lenght = 1;
  synt_parser(&synt, buff);

  if (tempfactor < 0) {
    tempfactor = tempfactor + 4294967296;
  }

  if (synt.lenght.l == 1) {
    while (tempfactor > 4294967295) {
      tempfactor = tempfactor - 4294967295;
    }
    while (tempfactor < 0) {
      tempfactor = tempfactor + 4294967296;
    }
  }

  if (synt.lenght.h == 1) {
    while (tempfactor > 32767) {
      tempfactor = tempfactor - 65536;
    }

    while (tempfactor < 0) {
      tempfactor = tempfactor + 65536;
    }
  }

  if (synt.flags.minus == 1) {
    from_x_minus(synt, result_buffer, &buffpointer, tempfactor, 'x');
  } else {
    from_x_plus(synt, result_buffer, &buffpointer, tempfactor, 'x');
  }
  s21_strcat(str, result_buffer);
  return buffpointer;
}

int form_o(char *str, char *buff, int factor) {
  syntx synt = {{0, 0, 0, 0, 0}, {0, 0}, {0, 0}, {0, 0, 0}};
  char result_buffer[256] = {'\0'};
  int buffpointer = 0;
  long tempfactor = factor;
  // int wight = 1;
  // int lenght = 1;
  synt_parser(&synt, buff);

  if (tempfactor < 0) {
    tempfactor = tempfactor + 4294967296;
  }

  if (synt.lenght.l == 1) {
    while (tempfactor > 4294967295) {
      tempfactor = tempfactor - 4294967295;
    }
    while (tempfactor < 0) {
      tempfactor = tempfactor + 4294967296;
    }
  }

  if (synt.lenght.h == 1) {
    while (tempfactor > 32767) {
      tempfactor = tempfactor - 65536;
    }

    while (tempfactor < 0) {
      tempfactor = tempfactor + 65536;
    }
  }

  if (synt.flags.minus == 1) {
    from_o_minus(synt, result_buffer, &buffpointer, tempfactor);
  } else {
    from_o_plus(synt, result_buffer, &buffpointer, tempfactor);
  }
  s21_strcat(str, result_buffer);
  return buffpointer;
}

int form_u(char *str, char *buff, unsigned int factor) {
  syntx synt = {{0, 0, 0, 0, 0}, {0, 0}, {0, 0}, {0, 0, 0}};
  char result_buffer[256] = {'\0'};
  int buffpointer = 0;
  long tempfactor = factor;
  // int wight = 1;
  // int lenght = 1;
  synt_parser(&synt, buff);

  if (synt.lenght.l == 1) {
    while (tempfactor > 4294967295) {
      tempfactor = tempfactor - 4294967295;
    }
    while (tempfactor < 0) {
      tempfactor = tempfactor + 4294967296;
    }
  }

  if (synt.lenght.h == 1) {
    while (tempfactor > 32767) {
      tempfactor = tempfactor - 65536;
    }

    while (tempfactor < -32768) {
      tempfactor = tempfactor + 65536;
    }
  }

  if (synt.flags.minus == 1) {
    from_u_minus(synt, result_buffer, &buffpointer, tempfactor);
  } else {
    from_u_plus(synt, result_buffer, &buffpointer, tempfactor);
  }
  s21_strcat(str, result_buffer);
  return buffpointer;
}

int form_f(char *str, char *buff, double factor) {
  syntx synt = {{0, 0, 0, 0, 0}, {0, 0}, {0, 0}, {0, 0, 0}};
  synt.accuracy.num = 6;
  char result_buffer[256] = {'\0'};
  int buffpointer = 0;
  double tempfactor = factor;
  synt_parser(&synt, buff);

  if (synt.flags.minus == 1) {
    form_f_minus(synt, result_buffer, &buffpointer, tempfactor, 'f');
  } else {
    form_f_plus(synt, result_buffer, &buffpointer, tempfactor, 'f');
  }
  s21_strcat(str, result_buffer);
  return buffpointer;
}

int form_d(char *str, char *buff, int factor) {
  syntx synt = {{0, 0, 0, 0, 0}, {0, 0}, {0, 0}, {0, 0, 0}};
  char result_buffer[256] = {'\0'};
  int buffpointer = 0;
  long tempfactor = factor;
  // int wight = 1;
  // int lenght = 1;
  synt_parser(&synt, buff);

  if (synt.lenght.l == 1) {
    while (tempfactor > 4294967295) {
      tempfactor = tempfactor - 4294967295;
    }
    while (tempfactor < 0) {
      tempfactor = tempfactor + 4294967296;
    }
  }

  if (synt.lenght.h == 1) {
    while (tempfactor > 32767) {
      tempfactor = tempfactor - 65536;
    }

    while (tempfactor < -32768) {
      tempfactor = tempfactor + 65536;
    }
  }

  if (synt.flags.minus == 1) {
    from_d_minus(synt, result_buffer, &buffpointer, tempfactor);
  } else {
    from_d_plus(synt, result_buffer, &buffpointer, tempfactor);
  }
  s21_strcat(str, result_buffer);
  return buffpointer;
}

void clean_buffer(char *str) {
  for (int i = 0; i < 256; i++) {
    str[i] = '\0';
  }
}

void synt_parser(syntx *synt, char *buff) {
  int i = 0;
  int mod = 0;  //  Режим парсера
  while (buff[i] != '\0') {
    if (mod == 0) {  //  Парсим флаги
      switch (buff[i]) {
        case '+':
          synt->flags.plus = 1;
          synt->flags.space = 0;
          break;
        case '-':
          synt->flags.minus = 1;
          synt->flags.nul = 0;
          break;
        case ' ':
          if (synt->flags.plus == 0) {
            synt->flags.space = 1;
          }
          break;
        case '#':
          synt->flags.sharp = 1;
          break;
        case '0':
          synt->flags.nul = 1;
          break;
        default:
          mod++;
          break;
      }
    }
    if (mod == 1) {
      if ((buff[i] >= 48) && (buff[i] <= 57)) {
        synt->width.num = synt->width.num * 10 + (buff[i] - 48);
      } else {
        mod++;
      }
    }
    if (mod == 2) {
      if (buff[i] == '.') {
        i++;
        mod++;
        synt->accuracy.num = 0;
      } else {
        mod = mod + 2;
      }
    }
    if (mod == 3) {
      if ((buff[i] >= 48) && (buff[i] <= 57)) {
        synt->accuracy.num = synt->accuracy.num * 10 + (buff[i] - 48);
      } else {
        mod++;
      }
    }
    if (mod == 4) {
      switch (buff[i]) {
        case 76:
          synt->lenght.L = 1;
          break;
        case 108:
          synt->lenght.l = 1;
          break;
        case 104:
          synt->lenght.h = 1;
          break;
        default:
          break;
      }
    }
    i++;
  }
}

int lenint(long tempfactor) {
  int len = 0;
  if (tempfactor < 0) {
    tempfactor *= -1;
  }

  while (tempfactor != 0) {
    tempfactor = (long)(tempfactor / 10);
    len++;
  }
  return len;
}

void from_d_minus(syntx synt, char *result_buffer, int *buffpointer,
                  long tempfactor) {
  int is_signed = 0;
  if (synt.flags.plus == 1) {
    if (tempfactor >= 0) {
      is_signed = touch_plus(result_buffer, buffpointer);

    } else {
      is_signed = touch_minus(result_buffer, buffpointer);
    }
  } else {
    if (synt.flags.space == 1) {
      is_signed = touch_space(result_buffer, buffpointer);
    }
  }
  if (tempfactor < 0) {
    tempfactor *= -1;
    is_signed = touch_minus(result_buffer, buffpointer);
  }

  int len_int = lenint(tempfactor);  //  Длинна аргумента

  for (int i = *buffpointer; i < synt.accuracy.num - len_int + is_signed;
       i++) {  //  Добить нулями до ширины
    touch_null(result_buffer, buffpointer);
  }

  print_dec(result_buffer, buffpointer, len_int, tempfactor);
  // *buffpointer = *buffpointer + len_int;

  for (int i = *buffpointer; i < synt.width.num;
       i++) {  //  Добить пробелами до ширины
    touch_space(result_buffer, buffpointer);
  }
}

void from_d_plus(syntx synt, char *result_buffer, int *buffpointer,
                 long tempfactor) {
  int is_signed = 0;
  if (synt.flags.nul == 1) {
    form_d_plus_null(synt, &tempfactor, result_buffer, buffpointer, is_signed);
  } else {
    int len_int = lenint(tempfactor);  //  Длинна аргумента
    int is_signed = 0;
    is_signed = ((tempfactor < 0) || (synt.flags.plus));
    for (int i = *buffpointer;
         (i < synt.width.num - len_int - is_signed) &&
         (i < synt.width.num - synt.accuracy.num - is_signed);
         i++) {  //  Добить пробелами до ширины
      touch_space(result_buffer, buffpointer);
    }

    if ((synt.flags.space == 1) && (is_signed == 0) && (*buffpointer == 0)) {
      is_signed = touch_space(result_buffer, buffpointer);
    }
    if ((synt.flags.plus == 1) && (tempfactor >= 0)) {
      is_signed = touch_plus(result_buffer, buffpointer);
    }
    if (tempfactor < 0) {
      is_signed = touch_minus(result_buffer, buffpointer);
    }
    if (tempfactor < 0) {
      tempfactor *= -1;
    }

    for (int i = 0; i < synt.accuracy.num - len_int;
         i++) {  //  Добить нулями до ширины
      touch_null(result_buffer, buffpointer);
    }
    if (len_int == 0) {
      touch_null(result_buffer, buffpointer);
    }

    print_dec(result_buffer, buffpointer, len_int, tempfactor);
  }
}

void form_f_minus(syntx synt, char *result_buffer, int *buffpointer,
                  double tempfactor, char type) {
  int int_part = 0;
  double fract_patr = 0;
  int real_acc = 0;
  if ((tempfactor >= 0) && (synt.flags.plus == 1)) {
    touch_plus(result_buffer, buffpointer);
  }
  if (tempfactor < 0) {
    touch_minus(result_buffer, buffpointer);
  }
  if ((tempfactor >= 0) && (synt.flags.plus == 0) && (synt.flags.space == 1)) {
    touch_space(result_buffer, buffpointer);
  }
  if (tempfactor < 0) {
    tempfactor *= -1;
  }
  if (tempfactor < 1) {
    touch_null(result_buffer, buffpointer);
  }
  int_part = (int)tempfactor;
  fract_patr = tempfactor - int_part;
  int len_int =
      lenint(int_part);  //  Кладем интовую часть  //  Длинна аргумента
  print_dec(result_buffer, buffpointer, len_int, tempfactor);
  if ((type == 'f') && (synt.accuracy.num > 0)) {  //  Точка
    result_buffer[*buffpointer] = '.';
    *buffpointer = *buffpointer + 1;
  }
  if (((type == 'g') || (type == 'G')) && (synt.accuracy.num > 0) &&
      (len_int != synt.accuracy.num)) {
    result_buffer[*buffpointer] = '.';
    *buffpointer = *buffpointer + 1;
  }
  if (type == 'f') {  //  Ассюраси вбиваем
    for (int i = 0; i < synt.accuracy.num; i++) {
      print_fract(result_buffer, buffpointer, &fract_patr, &real_acc);
    }
  }
  if ((type == 'g') || (type == 'G')) {
    for (int i = 0; i < synt.accuracy.num - len_int;
         i++) {  //    Может быть косячок при лен_инт == 0.
      print_fract(result_buffer, buffpointer, &fract_patr, &real_acc);
    }
  }
  if (((int)(fract_patr * 10)) >= 5) {  //  Костылик для округления
    result_buffer[*buffpointer - 1] = result_buffer[*buffpointer - 1] + 1;
  }
  //  Округляем это добро "nf cerf hf,jntn bvtyyj nfr b yb[thf vtyznm yt ,ele.
  while (result_buffer[*buffpointer - 1] == 58) {
    result_buffer[*buffpointer - 2] = result_buffer[*buffpointer - 2] + 1;
    result_buffer[*buffpointer - 1] = 48;
    *buffpointer = *buffpointer - 1;
    real_acc--;
  }
  for (int i = real_acc; i < synt.accuracy.num; i++) {  //   Вот наши нолики
    touch_null(result_buffer, buffpointer);
  }
  if ((type == 'g') || (type == 'G')) {
    while (result_buffer[*buffpointer - 1] == '0') {
      result_buffer[*buffpointer - 1] = '\0';
      *buffpointer = *buffpointer - 1;
    }
  }
  if (result_buffer[*buffpointer - 1] == '.') {
    result_buffer[*buffpointer - 1] = '\0';
    *buffpointer = *buffpointer - 1;
  }
  if ((synt.flags.sharp) && (synt.accuracy.num == 0)) {
    result_buffer[*buffpointer] = '.';
    *buffpointer = *buffpointer + 1;
  }
  for (int i = *buffpointer; i < synt.width.num; i++) {
    touch_space(result_buffer, buffpointer);
  }
}

void form_f_plus(syntx synt, char *result_buffer, int *buffpointer,
                 double tempfactor, char type) {
  long int int_part = 0;
  double fract_patr = 0;
  int real_acc = 0;
  int bit_for_sign = 0;
  int_part = (long int)tempfactor;
  fract_patr = tempfactor - int_part;
  int len_int =
      lenint(int_part);  //  Кладем интовую часть  //  Длинна аргумента
  if (synt.flags.nul == 1) {
    form_f_plus_null(synt, result_buffer, &tempfactor, buffpointer, &len_int,
                     &bit_for_sign, type);
  } else {
    form_f_plus_space(synt, result_buffer, buffpointer, &tempfactor, &len_int,
                      type);
  }
  if (tempfactor < 0) {  //   целую часть
    tempfactor *= -1;
  }
  if (tempfactor < 1) {
    touch_null(result_buffer, buffpointer);
  }
  int_part = (long int)tempfactor;
  fract_patr = tempfactor - int_part;
  print_dec(result_buffer, buffpointer, len_int, tempfactor);
  if (synt.accuracy.num > 0) {
    form_f_fractal(synt, result_buffer, buffpointer, &fract_patr, type,
                   &real_acc, &len_int);
  } else if (synt.flags.sharp) {
    result_buffer[*buffpointer] = '.';
    *buffpointer = *buffpointer + 1;
  }
}

void buff_shift_right(char *result_buffer, int *buffpointer, char shift_type) {
  if (shift_type == ' ') {
    for (int i = *buffpointer; i > 0; i--) {
      result_buffer[i] = result_buffer[i - 1];
    }
    *buffpointer = *buffpointer + 1;
    result_buffer[0] = ' ';
  }
  if (shift_type == '0') {
    for (int i = *buffpointer; i > 1; i--) {
      result_buffer[i] = result_buffer[i - 1];
    }
    *buffpointer = *buffpointer + 1;
    result_buffer[1] = '0';
  }
}

int touch_minus(char *result_buffer, int *buffpointer) {
  result_buffer[*buffpointer] = '-';
  *buffpointer = *buffpointer + 1;
  return 1;
}

int touch_plus(char *result_buffer, int *buffpointer) {
  result_buffer[*buffpointer] = '+';
  *buffpointer = *buffpointer + 1;
  return 1;
}

int touch_space(char *result_buffer, int *buffpointer) {
  result_buffer[*buffpointer] = ' ';
  *buffpointer = *buffpointer + 1;
  return 1;
}
int touch_null(char *result_buffer, int *buffpointer) {
  result_buffer[*buffpointer] = '0';
  *buffpointer = *buffpointer + 1;
  return 1;
}

void print_dec(char *result_buffer, int *buffpointer, int len_int,
               long tempfactor) {
  for (int i = *buffpointer + len_int - 1; i >= *buffpointer;
       i--) {  //  Подпихиваем цифры с конца
    result_buffer[i] = (tempfactor % 10) + 48;
    tempfactor /= 10;
  }
  *buffpointer = *buffpointer + len_int;
}

void print_oct(char *result_buffer, int *buffpointer, int len_int,
               long tempfactor) {
  for (int i = *buffpointer + len_int - 1; i >= *buffpointer;
       i--) {  //  Подпихиваем цифры с конца
    result_buffer[i] = (tempfactor % 8) + 48;
    tempfactor /= 8;
  }
  *buffpointer = *buffpointer + len_int;
}

int len_oct(long tempfactor) {
  int len = 0;
  while (tempfactor != 0) {
    tempfactor = (long)(tempfactor / 8);
    len++;
  }
  return len;
}

void from_o_minus(syntx synt, char *result_buffer, int *buffpointer,
                  long tempfactor) {
  int len_int = len_oct(tempfactor);  //  Длинна аргумента

  for (int i = *buffpointer;
       i < synt.accuracy.num - len_int + (synt.flags.sharp);
       i++) {  //  Добить пробелами до ширины
    touch_null(result_buffer, buffpointer);
  }
  if (synt.flags.sharp) {
    touch_null(result_buffer, buffpointer);
  }
  print_oct(result_buffer, buffpointer, len_int, tempfactor);

  for (int i = *buffpointer; i < synt.width.num;
       i++) {  //  Добить пробелами до ширины
    touch_space(result_buffer, buffpointer);
  }
}

void from_o_plus(syntx synt, char *result_buffer, int *buffpointer,
                 long tempfactor) {
  if (synt.flags.nul == 1) {
    int len_int = len_oct(tempfactor);

    if (synt.accuracy.num != 0) {
      for (int i = 0; (i < synt.width.num - len_int -
                               ((tempfactor < 0) || (synt.flags.plus))) &&
                      (i < synt.width.num - synt.accuracy.num -
                               ((tempfactor < 0) || (synt.flags.plus)));
           i++) {  //  Добить спэйсами до ширины
        touch_space(result_buffer, buffpointer);
      }
    }

    //  Длинна аргумента
    for (int i = *buffpointer; (i < synt.width.num - len_int -
                                        (tempfactor == 0) - (synt.flags.sharp));
         i++) {  //  Добить нулями до ширины
      touch_null(result_buffer, buffpointer);
    }
    for (int i = *buffpointer; i < synt.accuracy.num - len_int -
                                       (tempfactor == 0) - (synt.flags.sharp);
         i++) {  //  Добить нулями до ширины
      touch_null(result_buffer, buffpointer);
    }

    if (len_int == 0) {
      touch_null(result_buffer, buffpointer);
    }
    if (synt.flags.sharp) {
      touch_null(result_buffer, buffpointer);
    }
    print_oct(result_buffer, buffpointer, len_int, tempfactor);
  } else {
    if (tempfactor < 0) {
      tempfactor = tempfactor + 4294967296;
    }
    int len_int = len_oct(tempfactor);  //  Длинна аргумента
    for (int i = *buffpointer;
         (i < synt.width.num - len_int - (synt.flags.sharp)) &&
         (i < synt.width.num - synt.accuracy.num);
         i++) {  //  Добить пробелами до ширины
      touch_space(result_buffer, buffpointer);
    }

    for (int i = 0; i < synt.accuracy.num - len_int - synt.flags.sharp;
         i++) {  //  Добить нулями до ширины
      touch_null(result_buffer, buffpointer);
    }
    if (len_int == 0) {
      touch_null(result_buffer, buffpointer);
    }
    if (synt.flags.sharp) {
      touch_null(result_buffer, buffpointer);
    }

    print_oct(result_buffer, buffpointer, len_int, tempfactor);
  }
}

void from_u_minus(syntx synt, char *result_buffer, int *buffpointer,
                  long tempfactor) {
  int is_signed = 0;

  int len_int = lenint(tempfactor);  //  Длинна аргумента

  for (int i = *buffpointer; i < synt.accuracy.num - len_int + is_signed;
       i++) {  //  Добить пробелами до ширины
    touch_null(result_buffer, buffpointer);
  }

  print_dec(result_buffer, buffpointer, len_int, tempfactor);
  // *buffpointer = *buffpointer + len_int;

  for (int i = *buffpointer; i < synt.width.num;
       i++) {  //  Добить пробелами до ширины
    touch_space(result_buffer, buffpointer);
  }
}

void from_u_plus(syntx synt, char *result_buffer, int *buffpointer,
                 long tempfactor) {
  if (synt.flags.nul == 1) {  //  Слева нули
    int len_int = lenint(tempfactor);

    if (synt.accuracy.num != 0) {
      for (int i = 0; (i < synt.width.num - len_int -
                               ((tempfactor < 0) || (synt.flags.plus))) &&
                      (i < synt.width.num - synt.accuracy.num -
                               ((tempfactor < 0) || (synt.flags.plus)));
           i++) {  //  Добить спэйсами до ширины
        touch_space(result_buffer, buffpointer);
      }
    }
    //   Ставим знак

    if ((synt.flags.space == 1) && (synt.flags.plus == 0) &&
        (tempfactor >= 0)) {
      touch_space(result_buffer, buffpointer);
    }
    //  Длинна аргумента
    for (int i = *buffpointer;
         (i < synt.width.num - len_int - (tempfactor == 0));
         i++) {  //  Добить нулями до ширины
      touch_null(result_buffer, buffpointer);
    }
    for (int i = *buffpointer;
         i < synt.accuracy.num - len_int - (tempfactor == 0);
         i++) {  //  Добить нулями до ширины
      touch_null(result_buffer, buffpointer);
    }
    if (len_int == 0) {
      touch_null(result_buffer, buffpointer);
    }

    print_dec(result_buffer, buffpointer, len_int, tempfactor);
  } else {
    int len_int = lenint(tempfactor);  //  Длинна аргумента

    for (int i = *buffpointer; (i < synt.width.num - len_int) &&
                               (i < synt.width.num - synt.accuracy.num);
         i++) {  //  Добить пробелами до ширины
      touch_space(result_buffer, buffpointer);
    }

    for (int i = 0; i < synt.accuracy.num - len_int;
         i++) {  //  Добить нулями до ширины
      touch_null(result_buffer, buffpointer);
    }
    if (len_int == 0) {
      touch_null(result_buffer, buffpointer);
    }

    print_dec(result_buffer, buffpointer, len_int, tempfactor);
  }
}

void from_x_minus(syntx synt, char *result_buffer, int *buffpointer,
                  long tempfactor, char type) {
  int len_int = len_hex(tempfactor);  //  Длинна аргумента

  for (int i = *buffpointer;
       i < synt.accuracy.num - len_int + (synt.flags.sharp);
       i++) {  //  Добить пробелами до ширины
    touch_null(result_buffer, buffpointer);
  }
  if ((synt.flags.sharp && tempfactor != 0)) {
    touch_null(result_buffer, buffpointer);

    result_buffer[*buffpointer] = type;
    *buffpointer = *buffpointer + 1;
  }
  if (type == 'p') {
    touch_null(result_buffer, buffpointer);

    result_buffer[*buffpointer] = 'x';
    *buffpointer = *buffpointer + 1;
  }

  print_hex(result_buffer, buffpointer, len_int, tempfactor, type);
  // *buffpointer = *buffpointer + len_int;

  for (int i = *buffpointer; i < synt.width.num;
       i++) {  //  Добить пробелами до ширины
    touch_space(result_buffer, buffpointer);
  }
}

void from_x_plus(syntx synt, char *result_buffer, int *buffpointer,
                 long tempfactor, char type) {
  if (synt.flags.nul == 1) {
    int len_int = len_hex(tempfactor);

    if (synt.accuracy.num != 0) {
      for (int i = 0; (i < synt.width.num - len_int -
                               ((tempfactor < 0) || (synt.flags.plus))) &&
                      (i < synt.width.num - synt.accuracy.num -
                               ((tempfactor < 0) || (synt.flags.plus)));
           i++) {  //  Добить спэйсами до ширины
        touch_space(result_buffer, buffpointer);
      }
    }

    //  Длинна аргумента
    for (int i = *buffpointer;
         (i < synt.width.num - len_int - (synt.flags.sharp));
         i++) {  //  Добить нулями до ширины
      touch_null(result_buffer, buffpointer);
    }
    for (int i = *buffpointer; i < synt.accuracy.num - len_int -
                                       (synt.flags.sharp) - (tempfactor == 0);
         i++) {  //  Добить нулями до ширины
      touch_null(result_buffer, buffpointer);
    }

    if (synt.flags.sharp && tempfactor != 0) {
      touch_null(result_buffer, buffpointer);
      result_buffer[*buffpointer] = type;
      *buffpointer = *buffpointer + 1;
    }
    if (type == 'p') {
      touch_null(result_buffer, buffpointer);
      result_buffer[*buffpointer] = 'x';
      *buffpointer = *buffpointer + 1;
    }
    if (tempfactor == 0) {
      touch_null(result_buffer, buffpointer);
    }
    print_hex(result_buffer, buffpointer, len_int, tempfactor, type);
  } else {
    if (tempfactor < 0) {
      tempfactor = tempfactor + 4294967296;
    }
    int len_int = len_hex(tempfactor);  //  Длинна аргумента
    for (int i = *buffpointer;
         (i < synt.width.num - len_int - (synt.flags.sharp * 2)) &&
         (i < synt.width.num - synt.accuracy.num);
         i++) {  //  Добить пробелами до ширины
      touch_space(result_buffer, buffpointer);
    }

    for (int i = 0; i < synt.accuracy.num - len_int - synt.flags.sharp;
         i++) {  //  Добить нулями до ширины
      touch_null(result_buffer, buffpointer);
    }
    if (tempfactor == 0) {
      touch_null(result_buffer, buffpointer);
    }
    if (synt.flags.sharp && tempfactor != 0) {
      touch_null(result_buffer, buffpointer);
      result_buffer[*buffpointer] = type;
      *buffpointer = *buffpointer + 1;
    }
    if (type == 'p') {
      touch_null(result_buffer, buffpointer);
      result_buffer[*buffpointer] = 'x';
      *buffpointer = *buffpointer + 1;
    }

    print_hex(result_buffer, buffpointer, len_int, tempfactor, type);
  }
}

int len_hex(long tempfactor) {
  int len = 0;
  while (tempfactor != 0) {
    tempfactor = (long)(tempfactor / 16);
    len++;
  }
  return len;
}

void print_hex(char *result_buffer, int *buffpointer, int len_int,
               long tempfactor, char type) {
  char next_char;
  int shift = 39;
  if (type == 'X') {
    shift = 7;
  }

  for (int i = *buffpointer + len_int - 1; i >= *buffpointer;
       i--) {  //  Подпихиваем цифры с конца
    next_char = (tempfactor % 16) + 48;
    if (next_char > 57) {
      next_char = next_char + shift;
    }

    result_buffer[i] = next_char;
    tempfactor /= 16;
  }
  *buffpointer = *buffpointer + len_int;
}

void e_normalization(double *tempfactor, int *emer_counter) {
  while ((*tempfactor < 1) && (*emer_counter < 324)) {
    *tempfactor = (*tempfactor * 10);
    *emer_counter = (*emer_counter + 1);
    ;
  }

  while ((*tempfactor > 10) && (*emer_counter > -324)) {
    *tempfactor = *tempfactor / 10;
    *emer_counter = *emer_counter - 1;
  }
}

int print_e(syntx synt, char *result_buffer, int *buffpointer,
            double *tempfactor, int *emer_counter, char type) {
  int int_part = (int)*tempfactor;
  double fract_patr = *tempfactor - int_part;
  print_e_printer(synt, tempfactor, result_buffer, buffpointer, type, &int_part,
                  &fract_patr);

  //  Rounding 9.999999 etc

  round_e(result_buffer, buffpointer, &int_part, tempfactor, emer_counter);

  int result_cap = *emer_counter * -1;

  if ((type == 'g') || (type == 'G')) {
    while (result_buffer[*buffpointer - 1] == '0') {
      result_buffer[*buffpointer - 1] = '\0';
      *buffpointer = *buffpointer - 1;
    }
  }

  if (((type == 'g') || (type == 'G')) &&
      (result_buffer[*buffpointer - 1] == '.') && (synt.flags.sharp == 0)) {
    result_buffer[*buffpointer - 1] = '\0';
    *buffpointer = *buffpointer - 1;
  }
  //  Print e
  if ((type == 'e') || (type == 'g')) {
    result_buffer[*buffpointer] = 'e';
  } else {
    result_buffer[*buffpointer] = 'E';
  }

  *buffpointer = *buffpointer + 1;

  //  Print cap sig

  if (*emer_counter <= 0) {
    result_buffer[*buffpointer] = '+';
    *buffpointer = *buffpointer + 1;
  } else {
    result_buffer[*buffpointer] = '-';
    *buffpointer = *buffpointer + 1;
  }

  //  Print cap

  if (*emer_counter < 0) {
    *emer_counter = *emer_counter * -1;
  }

  int len_cap = lenint(*emer_counter);

  if (len_cap < 2) {
    result_buffer[*buffpointer] = '0';
    *buffpointer = *buffpointer + 1;
  }

  if (len_cap < 1) {
    result_buffer[*buffpointer] = '0';
    *buffpointer = *buffpointer + 1;
  }

  for (int i = len_cap - 1; i >= 0; i--) {
    result_buffer[*buffpointer + i] = (*emer_counter % 10) + 48;
    *emer_counter = (int)(*emer_counter / 10);
  }
  *buffpointer = *buffpointer + len_cap;

  return result_cap;
}

void sign_e(syntx synt, char *result_buffer, int *buffpointer,
            double *tempfactor) {
  if ((*tempfactor >= 0) && (synt.flags.plus == 1)) {
    touch_plus(result_buffer, buffpointer);
  }
  if (*tempfactor < 0) {
    touch_minus(result_buffer, buffpointer);
  }
  if ((*tempfactor >= 0) && (synt.flags.plus == 0) && (synt.flags.space == 1)) {
    touch_space(result_buffer, buffpointer);
  }
  if (*tempfactor < 0) {
    *tempfactor = *tempfactor * -1;
  }
}

void round_e(char *result_buffer, int *buffpointer, int *int_part,
             double *tempfactor, int *emer_counter) {
  *int_part = (int)*tempfactor;

  if (*int_part >= 5) {
    result_buffer[*buffpointer - 1] = (result_buffer[*buffpointer - 1] + 1);
  }
  int lshift = -1;
  while (result_buffer[*buffpointer + lshift] == 58) {
    result_buffer[*buffpointer + lshift] = 48;
    lshift--;
    result_buffer[*buffpointer + lshift] =
        result_buffer[*buffpointer + lshift] + 1;
  }

  if (result_buffer[*buffpointer + lshift] == '/') {
    if (result_buffer[*buffpointer + lshift - 1] == 57) {
      result_buffer[*buffpointer + lshift - 1] = 49;
      *emer_counter = *emer_counter - 1;
    } else {
      result_buffer[*buffpointer + lshift - 1] =
          result_buffer[*buffpointer + lshift - 1] + 1;
    }
    result_buffer[*buffpointer + lshift] = '.';
  }
}

//////////////////////////////////////////////////////////
////////////////   S   S   C    A   N   F   //////////////
//////////////////////////////////////////////////////////

tok mtoken = {0, 0, '0', '0'};

void clear_mtoken() {
  mtoken.flag = 0;
  mtoken.wight = 0;
  mtoken.height = '0';
  mtoken.specif = '0';
}

int s21_sscanf(char *str, const char *format, ...) {
  int result = 0;
  int ret = 0;
  char *f = (char *)malloc(sizeof(format));
  ;
  s21_strcpy(f, format);
  char *st = str;
  va_list ap;
  va_start(ap, format);
  while (!token(&st, &f) && result == 0) {
    // printf("flag :%d\n", mtoken.flag);
    // printf("Num  :%d\n", mtoken.wight);
    // printf("Num  :%c\n", mtoken.height);
    // printf("Num  :%c\n", mtoken.specif);
    if (flag_parser(&st, ap, &ret)) result = 1;
    clear_mtoken();
  }
  return ret;
}

int flag_parser(char **st, va_list ap, int *ret) {
  char *buffer = *st;
  int result = 0;
  if (mtoken.height == 'h') {
    if (mtoken.specif == 'u') {
      short unsigned int *i =
          (short unsigned int *)malloc(sizeof(short unsigned int));
      if (!mtoken.flag) {
        i = va_arg(ap, short unsigned int *);
        if (short_unsigned_int_parser(st, i))
          (*ret)++;
        else
          result = 1;
      } else
        (short_unsigned_int_parser(st, i));
    } else {
      short int *i = (short int *)malloc(sizeof(short int));
      if (!mtoken.flag) {
        i = va_arg(ap, short int *);
        if (short_int_parser(st, i))
          (*ret)++;
        else
          result = 1;
      } else
        short_int_parser(st, i);
    }
  } else if (mtoken.height == 'l') {
    if (mtoken.specif == 'u') {
      long unsigned int *i =
          (long unsigned int *)malloc(sizeof(long unsigned int));
      if (!mtoken.flag) {
        i = va_arg(ap, long unsigned int *);
        if (long_unsigned_int_parser(st, i))
          (*ret)++;
        else
          result = 1;
      } else
        long_unsigned_int_parser(st, i);
    } else {
      long int *i = (long int *)malloc(sizeof(long int));
      if (!mtoken.flag) {
        i = va_arg(ap, long int *);
        if (long_int_parser(st, i))
          (*ret)++;
        else
          result = 1;
      } else
        long_int_parser(st, i);
    }
  } else if (mtoken.height == 'L') {
    long double *i = (long double *)malloc(sizeof(long double));
    if (!mtoken.flag) {
      i = va_arg(ap, long double *);
      if (long_double_parser(st, i))
        (*ret)++;
      else
        result = 1;
    } else
      long_double_parser(st, i);

  } else if ((mtoken.specif == 'f' || mtoken.specif == 'e' ||
              mtoken.specif == 'E' || mtoken.specif == 'g' ||
              mtoken.specif == 'G') &&
             mtoken.height == '0') {
    float *i = (float *)malloc(sizeof(float));
    if (!mtoken.flag) {
      i = va_arg(ap, float *);
      if (float_parser(st, i))
        (*ret)++;
      else
        result = 1;
    } else
      float_parser(st, i);
  } else if (mtoken.specif == 'd') {
    int *i = (int *)malloc(sizeof(int));
    if (!mtoken.flag) {
      i = va_arg(ap, int *);
      if (int_parser(st, i))
        (*ret)++;
      else
        result = 1;
    } else
      int_parser(st, i);
  } else if ((mtoken.specif == 's' || mtoken.specif == 'c') &&
             mtoken.height == '0') {
    char *i = (char *)malloc(sizeof(char));
    if (!mtoken.flag) {
      i = va_arg(ap, char *);
      if (str_parser(st, &i))
        (*ret)++;
      else
        result = 1;
    } else
      str_parser(st, &i);
  } else if (mtoken.specif == 'u') {
    unsigned int *i = (unsigned int *)malloc(sizeof(unsigned int));
    if (!mtoken.flag) {
      i = va_arg(ap, unsigned int *);
      if (unsigned_int_parser(st, i))
        (*ret)++;
      else
        result = 1;
    } else
      unsigned_int_parser(st, i);
  } else if (mtoken.specif == 'o') {
    int *i = (int *)malloc(sizeof(int));
    if (!mtoken.flag) {
      i = va_arg(ap, int *);
      if (octal_parser(st, i))
        (*ret)++;
      else
        result = 1;
    } else
      octal_parser(st, i);
  } else if (mtoken.specif == 'x' || mtoken.specif == 'X') {
    int *i = (int *)malloc(sizeof(int));
    if (!mtoken.flag) {
      i = va_arg(ap, int *);
      if (hexal_parser(st, i))
        (*ret)++;
      else
        result = 1;
    } else
      hexal_parser(st, i);
  } else if (mtoken.specif == 'p') {
    void *i = (void *)malloc(sizeof(void));
    if (!mtoken.flag) {
      i = va_arg(ap, void *);
      if (p_parser(st, i))
        (*ret)++;
      else
        result = 1;
    } else
      p_parser(st, i);
  } else if (mtoken.specif == 'n') {
    int *i = (int *)malloc(sizeof(int));
    if (!mtoken.flag) {
      (*ret)++;
      i = va_arg(ap, int *);
    }
    *i = s21_strlen(buffer) - s21_strlen(*st);

  } else
    result = 1;
  return result;
}

int long_double_parser(
    char **str,
    long double *res) {  // считывает из входящей строки число типа float
  delete_spaces(str);
  *res = 0;
  int stop = 0, error = 1, devider = 0, exp = 1, number = 1, sign = 1;
  if (mtoken.wight == 0) number = -1000;

  if (47 < **str && **str < 58) {
    *res = **str - '0';
    (*str)++;
  } else if (**str == '-') {
    sign = -1;
    (*str)++;
  } else {
    stop = 1;
    error = 0;
  }
  while (stop == 0 && number < mtoken.wight) {
    if (47 < **str && **str < 58) {
      *res *= 10;
      *res += **str - '0';
      (*str)++;
      number++;
      if (devider) exp *= 10;
    } else if (**str == '.' && 6 < **str + 1 && **str + 1 < 58) {
      devider = 1;
      (*str)++;
      number++;
    } else
      stop = 1;
  }
  if (error) {
    *res /= exp;
    *res *= sign;
  }
  return error;
}

int short_int_parser(char **str, short int *res) {
  *res = 0;  // считывает из входящей строки число типа int
  delete_spaces(str);
  int stop = 0, error = 1, number = 1, sign = 1;
  int temp = 0;

  if (mtoken.specif == 'x' || mtoken.specif == 'X') {
    hexal_parser(str, &temp);
    *res = (short int)temp;
  } else if (mtoken.specif == 'o') {
    octal_parser(str, &temp);
    *res = (short int)temp;
  } else {
    if (mtoken.wight == 0) number = -1000;
    if (47 < **str && **str < 58) {
      *res = **str - '0';
      (*str)++;
    } else if (**str == '-') {
      sign = -1;
      (*str)++;
    } else {
      stop = 1;
      error = 0;
    }
    while (stop == 0 && number < mtoken.wight) {
      if (47 < **str && **str < 58) {
        *res *= 10;
        *res += **str - '0';
        (*str)++;
        number++;
      } else
        stop = 1;
    }
    if (error) *res *= sign;
  }
  return error;
}

int long_int_parser(
    char **str, long int *res) {  // считывает из входящей строки число типа int
  delete_spaces(str);
  *res = 0;
  int stop = 0, error = 1, number = 1, sign = 1;

  if (mtoken.specif == 'x' || mtoken.specif == 'X') {
    long_hexal_parser(str, res);
  } else if (mtoken.specif == 'o') {
    long_octal_parser(str, res);
    //*res = *res + 2147483648;
  } else {
    if (mtoken.wight == 0) number = -1000;
    if (47 < **str && **str < 58) {
      *res = **str - '0';
      (*str)++;
    } else if (**str == '-') {
      sign = -1;
      (*str)++;
    } else {
      stop = 1;
      error = 0;
    }
    while (stop == 0 && number < mtoken.wight) {
      if (47 < **str && **str < 58) {
        *res *= 10;
        *res += **str - '0';
        (*str)++;
        number++;
      } else
        stop = 1;
    }
    if (error) *res *= sign;
  }
  return error;
}

int p_parser(char **str, void **res) {
  int error = 1;
  char char_result[2048];
  char *ptr = char_result;

  s21_memset(&char_result, 0, 2048);

  while (is_hex(**str) || **str == 'x') {
    *ptr = **str;
    (*str)++;
    ptr++;
  }

  *res = char_result;
  // printf("<<%p>>", char_result);
  //  delete_spaces(str);
  //  if (mtoken.wight == 0) number = -1000;
  //  while (**str != '\n' && number <= mtoken.wight && **str != ' '){
  //      **res = **str;
  //      (*str)++;
  //      (*res)++;;
  //      number++;
  //  }
  return error;
}

int long_hexal_parser(
    char **str, long int *res) {  // считывает из входящей строки число типа int
  delete_spaces(str);
  *res = 0;
  int stop = 0, error = 1, number = 1, sign = 1;

  char temp[2048];
  char *char_result = temp;

  s21_memset(char_result, 0, 20);

  if (mtoken.wight == 0) number = -1000;

  if (is_hex(**str)) {
    *char_result += **str;
    char_result++;
    (*str)++;
  } else if (**str == '-') {
    sign = -1;
    (*str)++;
  } else {
    stop = 1;
    error = 0;
  }

  while (stop == 0 && number < mtoken.wight) {
    if (is_hex(**str)) {
      *char_result += **str;
      (*str)++;
      char_result++;
      number++;
    } else
      stop = 1;
  }
  // for (int i = s21_strlen(temp) - 1; i >= 0; i--) {
  //   printf(" %d", (hex_converter(temp[i])));
  // }
  // printf("\n");
  for (int i = s21_strlen(temp) - 1; i >= 0; i--) {
    *res += (hex_converter(temp[i]) * (int)pow(16, s21_strlen(temp) - i - 1));
  }

  if (error) *res *= sign;
  return error;
}

int hexal_parser(char **str,
                 int *res) {  // считывает из входящей строки число типа int
  delete_spaces(str);
  *res = 0;
  int stop = 0, error = 1, number = 1, sign = 1;

  char temp[2048];
  char *char_result = temp;

  s21_memset(char_result, 0, 20);

  if (mtoken.wight == 0) number = -1000;

  if (is_hex(**str)) {
    *char_result += **str;
    char_result++;
    (*str)++;
  } else if (**str == '-') {
    sign = -1;
    (*str)++;
  } else {
    stop = 1;
    error = 0;
  }

  while (stop == 0 && number < mtoken.wight) {
    if (is_hex(**str)) {
      *char_result += **str;
      (*str)++;
      char_result++;
      number++;
    } else
      stop = 1;
  }

  for (int i = s21_strlen(temp) - 1; i >= 0; i--) {
    *res += (hex_converter(temp[i]) * (int)pow(16, s21_strlen(temp) - i - 1));
  }

  if (error) *res *= sign;
  return error;
}

int is_hex(char hex) {
  int res = 0;
  if ((47 < hex && hex < 58) || (64 < hex && hex <= 71) ||
      (96 < hex && hex <= 102))
    res = 1;
  return res;
}

int hex_converter(char hex) {
  int result;
  if (47 < hex && hex < 58) {
    result = s21_atoi(&hex);
  } else {
    if (hex == 'a' || hex == 'A')
      result = 10;
    else if (hex == 'b' || hex == 'B')
      result = 11;
    else if (hex == 'c' || hex == 'C')
      result = 12;
    else if (hex == 'd' || hex == 'D')
      result = 13;
    else if (hex == 'e' || hex == 'E')
      result = 14;
    else if (hex == 'f' || hex == 'F')
      result = 15;
    else
      result = 0;
  }
  return result;
}

int long_octal_parser(
    char **str, long int *res) {  // считывает из входящей строки число типа int
  delete_spaces(str);
  *res = 0;
  int stop = 0, error = 1, number = 1, sign = 1;
  if (mtoken.wight == 0) number = -1000;

  if (47 < **str && **str < 56) {
    *res = **str - '0';
    (*str)++;
  } else if (**str == '-') {
    sign = -1;
    (*str)++;
  } else if (**str == '8' || **str == '9') {
    *res = 0;
    stop = 1;
  } else {
    stop = 1;
    error = 0;
  }

  while (stop == 0 && number < mtoken.wight) {
    if (47 < **str && **str < 56) {
      *res *= 10;
      *res += **str - '0';
      (*str)++;
      number++;
    } else
      stop = 1;
  }

  long int result = 0, i = 0;
  long int remainder = *res;
  if (remainder < 0) remainder *= -1;

  while (remainder >= 1) {
    result += (remainder % 10) * pow(8, i);
    i++;
    remainder /= 10;
  }

  *res = result;
  if (error) *res *= sign;

  return error;
}

int octal_parser(char **str,
                 int *res) {  // считывает из входящей строки число типа int
  delete_spaces(str);
  *res = 0;
  int stop = 0, error = 1, number = 1, sign = 1;
  if (mtoken.wight == 0) number = -1000;

  if (47 < **str && **str < 56) {
    *res = **str - '0';
    (*str)++;
  } else if (**str == '-') {
    sign = -1;
    (*str)++;
  } else if (**str == '8' || **str == '9') {
    *res = 0;
    stop = 1;
  } else {
    stop = 1;
    error = 0;
  }

  while (stop == 0 && number < mtoken.wight) {
    if (47 < **str && **str < 56) {
      *res *= 10;
      *res += **str - '0';
      (*str)++;
      number++;
    } else
      stop = 1;
  }

  int result = 0, i = 0;
  int remainder = *res;
  remainder = abs(remainder);

  while (remainder >= 1) {
    result += (remainder % 10) * pow(8, i);
    i++;
    remainder /= 10;
  }

  *res = result;
  if (error) *res *= sign;

  return error;
}

// void *s21_memset(void *str, int c, s21_size_t n) {  // очищает входящую
// строчку
//   for (s21_size_t i = 0; i < n; i++) {
//     ((char *)str)[i] = c;
//   }
//   return 0;
// }

int str_parser(char **str, char **res) {
  **res = 0;
  s21_memset(*res, 0, s21_strlen(*res));
  int error = 1, number = 1;
  delete_spaces(str);
  if (mtoken.wight == 0) number = -1000;
  if (mtoken.specif == 'c') {
    number = 1;
    mtoken.wight = 1;
  }
  while (**str != '\n' && number <= mtoken.wight && **str != ' ') {
    **res = **str;
    (*str)++;
    (*res)++;
    ;
    number++;
  }
  return error;
}

void delete_spaces(char **str) {
  while (**str == ' ') (*str)++;
}

int short_unsigned_int_parser(char **str, short unsigned int *res) {
  *res = 0;  // считывает из входящей строки число типа unsigned int
  unsigned int temp = 0;
  int error = 1;
  if (!unsigned_int_parser(str, &temp)) error = 0;
  *res = (short int)temp;
  return error;
}

int long_unsigned_int_parser(
    char **str,
    long unsigned int
        *res) {  // считывает из входящей строки число типа unsigned int
  delete_spaces(str);
  *res = 0;
  int stop = 0, error = 1, number = 1, sign = 0;
  if (mtoken.wight == 0) number = -1000;

  if (47 < **str && **str < 58) {
    *res = **str - '0';
    (*str)++;
  } else if (**str == '-') {
    sign = 1;
    (*str)++;
  } else {
    stop = 1;
    error = 0;
  }

  while (stop == 0 && number < mtoken.wight) {
    if (47 < **str && **str < 58) {
      *res *= 10;
      *res += **str - '0';
      (*str)++;
      number++;
    } else
      stop = 1;
  }
  if (error && sign == 1)
    *res = 4611686018427387904 - *res - 4611686018427387904 -
           4611686018427387904 - 4611686018427387904 - 4611686018427387904 -
           4611686018427387904;
  return error;
}

int unsigned_int_parser(char **str,
                        unsigned int *res) {  // считывает из входящей строки
                                              // число типа unsigned int
  delete_spaces(str);
  *res = 0;
  int stop = 0, error = 1, number = 1, sign = 0;
  if (mtoken.wight == 0) number = -1000;

  if (47 < **str && **str < 58) {
    *res = **str - '0';
    (*str)++;
  } else if (**str == '-') {
    sign = 1;
    (*str)++;
  } else {
    stop = 1;
    error = 0;
  }

  while (stop == 0 && number < mtoken.wight) {
    if (47 < **str && **str < 58) {
      *res *= 10;
      *res += **str - '0';
      (*str)++;
      number++;
    } else
      stop = 1;
  }
  if (error && sign == 1) *res = 4294967296 - *res;
  return error;
}

int int_parser(char **str,
               int *res) {  // считывает из входящей строки число типа int
  delete_spaces(str);
  *res = 0;
  int stop = 0, error = 1, number = 1, sign = 1;
  if (mtoken.wight == 0) number = -1000;

  if (47 < **str && **str < 58) {
    *res = **str - '0';
    (*str)++;
  } else if (**str == '-') {
    sign = -1;
    (*str)++;
  } else {
    stop = 1;
    error = 0;
  }

  while (stop == 0 && number < mtoken.wight) {
    if (47 < **str && **str < 58) {
      *res *= 10;
      *res += **str - '0';
      (*str)++;
      number++;
    } else
      stop = 1;
  }
  if (error) *res *= sign;
  return error;
}

int float_parser(char **str,
                 float *res) {  // считывает из входящей строки число типа float
  delete_spaces(str);
  *res = 0;
  int stop = 0, error = 1, devider = 0, exp = 1, number = 1, sign = 1;
  if (mtoken.wight == 0) number = -1000;

  if (47 < **str && **str < 58) {
    *res = **str - '0';
    (*str)++;
  } else if (**str == '-') {
    sign = -1;
    (*str)++;
  } else {
    stop = 1;
    error = 0;
  }
  while (stop == 0 && number < mtoken.wight) {
    if (47 < **str && **str < 58) {
      *res *= 10;
      *res += **str - '0';
      (*str)++;
      number++;
      if (devider) exp *= 10;
    } else if (**str == '.' && 6 < **str + 1 && **str + 1 < 58) {
      devider = 1;
      (*str)++;
      number++;
    } else
      stop = 1;
  }
  if (error) {
    *res /= exp;
    *res *= sign;
  }
  return error;
}

int token(char **str,
          char **f) {  // проверяет возможные комбанации флагов, удаляет символы
                       // между флагами и заполняет структуру
  int error = 0;

  if (!delete_chars(str, f)) error = 1;

  int stop = 0;

  if (!error) {
    while (**f != '\0' && stop == 0) {
      if (**f == '*' && mtoken.wight == 0 && mtoken.height == '0' &&
          mtoken.specif == '0') {
        mtoken.flag = 1;
        (*f)++;
      } else if (is_number(*f) && add_number(f)) {
        stop = 1;
      } else if (is_specificator(*f) && add_specificator(f)) {
        stop = 1;
      } else if ((is_hl(*f) || **f == 'L') && add_lenght(f)) {
        stop = 1;
      } else {
        stop = 1;
        error = 1;
      }
    }
  }

  // printf("\nError: %d\n", error);
  // printf("str: <%s>;\n", str);
  // printf("f  : <%s>;\n\n", *f);
  return error;
}

int delete_chars(
    char **str,
    char **f) {  // смотрим совпадают ли символы до "%" и обрабатывает символ %
  int error = 1;
  int stop = 0;
  while (**f != '\0' && stop != 1 && error == 1) {
    if (**str != **f) {
      if (**f == ' ') {
        (*f)++;
      } else if (**f == '%' && **str == ' ') {
        (*str)++;
      } else if ((47 < *(*f + 1) && *(*f + 1) < 58) || is_hl(*f + 1) ||
                 is_specificator(*f + 1) || *(*f + 1) == 'L' ||
                 *(*f + 1) == '*') {
        stop = 1;
        (*f)++;
      } else
        error = 0;
    } else if (**f == '%' && **str == '%') {
      if (*(*f + 1) == '%') {
        (*f)++;
        (*f)++;
        (*str)++;
      } else {
        stop = 1;
        error = 0;
      }
    } else {
      (*f)++;
      (*str)++;
    }
  }
  return error;
}

int add_number(
    char **f) {  // проверяет и добавляет длинну символов для считывания
  int res = 1;
  if (is_number(*f) && mtoken.height == '0' && mtoken.specif == '0') {
    while (47 < **f && **f < 58) {
      if (mtoken.wight != 48) {
        mtoken.wight = mtoken.wight * 10;
      }
      char c = (char)**f;
      mtoken.wight += atoi(&c);
      (*f)++;
    }
    if (is_specificator(*f) && mtoken.height == '0') {
      mtoken.specif = **f;
      (*f)++;
    } else if (is_hl(*f) && mtoken.height == '0' && mtoken.specif == '0') {
      mtoken.height = **f;
      (*f)++;
      if (is_hl_flags(*f)) {
        mtoken.specif = **f;
        (*f)++;
      } else
        res = 0;
    } else if (**f == 'L' && mtoken.height == '0' && mtoken.specif == '0') {
      mtoken.height = **f;
      (*f)++;
      if (is_L_flags(*f)) {
        mtoken.specif = **f;
        (*f)++;
      } else
        res = 0;
    } else
      res = 0;
  } else
    res = 0;
  return res;
}

int add_lenght(char **f) {  // проверяет и добавляет флвги h l L
  int res = 1;
  if (is_hl(*f) && mtoken.height == '0' && mtoken.specif == '0') {
    mtoken.height = **f;
    (*f)++;
    if (is_hl_flags(*f)) {
      mtoken.specif = **f;
      (*f)++;
    } else
      res = 0;
  } else if (**f == 'L' && mtoken.height == '0' && mtoken.specif == '0') {
    mtoken.height = **f;
    (*f)++;
    if (is_L_flags(*f)) {
      mtoken.specif = **f;
      (*f)++;
    }
  } else
    res = 0;

  return res;
}

int add_specificator(
    char **f) {  // проверяет и заполняет структуру нужным спецификатором
  int res = 1;
  if (is_specificator(*f) && mtoken.height == '0' && mtoken.specif == '0' &&
      mtoken.wight == 0) {
    mtoken.specif = **f;
    (*f)++;
  } else
    res = 0;
  return res;
}

int is_number(char *f) {
  int error = 0;
  if (47 < *f && *f < 58) {
    error = 1;
  }
  return error;
}

int is_hl(char *f) {
  int error = 0;
  if (*f == 'h' || *f == 'l') {
    error = 1;
  }
  return error;
}

int is_hl_flags(char *f) {
  int error = 0;
  if (*f == 'i' || *f == 'd' || *f == 'o' || *f == 'u' || *f == 'x' ||
      *f == 'X') {
    error = 1;
  }
  return error;
}

int is_L_flags(char *f) {
  int error = 0;
  if (*f == 'e' || *f == 'E' || *f == 'f' || *f == 'g' || *f == 'G') {
    error = 1;
  }
  return error;
}

int is_specificator(char *f) {
  int error = 0;
  if (*f == 'c' || *f == 'd' || *f == 'i' || *f == 'e' || *f == 'E' ||
      *f == 'f' || *f == 'g' || *f == 'G' || *f == 'o' || *f == 's' ||
      *f == 'u' || *f == 'x' || *f == 'X' || *f == 'p' || *f == 'n') {
    error = 1;
  }
  return error;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *fin = NULL;
  s21_size_t src_length, str_length;
  src_length = (src == NULL) ? 0 : s21_strlen(src);
  str_length = (str == NULL) ? 0 : s21_strlen(str);

  s21_size_t fin_length = src_length + str_length;
  if (start_index <= src_length) {
    fin = (char *)calloc(src_length + str_length + 1, sizeof(char));
  }

  if (fin != NULL) {
    for (s21_size_t i = 0; i < fin_length; i++) {
      if (i < start_index) {
        fin[i] = src[i];
      } else if (i < str_length + start_index) {
        fin[i] = str[i - start_index];
      } else {
        fin[i] = src[i - str_length];
      }
    }
  }

  return fin;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  int flag = 0;
  char *ans;
  char *pstr = (char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    if (pstr[i] == c) {
      ans = &pstr[i];
      flag = 1;
      break;
    }
  }
  return flag ? ans : NULL;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int flag = 0;
  char *ptr1 = (char *)str1;
  char *ptr2 = (char *)str2;
  for (s21_size_t i = 0; i < n; i++) {
    // if(ptr1[i] == 0 && ptr2[i]!=0){
    //     flag=ptr2[i]*(-1);
    //     break;
    // }
    // else if(ptr2[i] == 0 && ptr1[i]!=0){
    //     flag=ptr1[i];
    //     break;
    // }
    if (ptr1[i] > ptr2[i]) {
      flag = 1;
      break;
    } else if (ptr1[i] < ptr2[i]) {
      flag = -1;
      break;
    }
  }
  return flag;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *ptr1 = (char *)src;
  char *ptr2 = (char *)dest;
  for (int i = 0; i < (int)n; i++) {
    ptr2[i] = ptr1[i];
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  char *ptr = (char *)str;
  for (s21_size_t i = 0; i <= n; i++) {
    ptr[i] = c;
  }
  ptr[n] = '\0';
  return str;
}

char *s21_strchr(const char *str, int c) {
  char *res = NULL;
  while (*str && *str != c) {
    str++;
  }
  return res = (c == *str) ? (char *)str : res;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  while (*str1) {
    if (s21_strchr(str2, *str1)) {
      break;
    } else {
      str1++;
      result++;
    }
  }
  return result;
}

char *s21_strerror(int errnum) {
  char *ptr = s21_NULL;
  if (errnum >= MAX_ERRLIST || errnum <= MIN_ERRLIST) {
    static char part1[33] = ERROR;
    static char part2[33];
    s21_errnum_tostring(part2, errnum);
    s21_strcat(part1, part2);
    ptr = part1;
  } else {
    ptr = (char *)maserror[errnum];
  }
  return (char *)ptr;
}

void s21_errnum_tostring(char *str, int num) {
  int i, rem, len = 0, n;
  n = num;
  while (n != 0) {
    len++;
    n /= 10;
  }
  if (num >= 0) {
    for (i = 0; i < len; i++) {
      rem = num % 10;
      num = num / 10;
      str[len - (i + 1)] = rem + '0';
    }
  } else {
    len++;
    str[0] = '-';
    for (i = 0; i < len - 1; i++) {
      rem = num % 10;
      num = num / 10;
      str[len - (i + 1)] = rem + '0';
      if (i == len - 2) {
        str[len - (i + 1)] = (-1 * rem) + '0';
      }
    }
  }
  str[len] = '\0';
}

char *s21_strcat(char *dest, const char *src) {
  int len = 0;
  while (*dest) {
    dest++;
    len++;
  }
  while (*src) {
    *dest = *src;
    dest++;
    src++;
    len++;
  }
  *dest = '\0';
  dest -= len;
  return dest;
}

char *s21_strncat(char *dest, const char *src,
                  s21_size_t n) {  // Не работает при максимальном заполнение,
                                   // например если str2[9] и символов 9
  s21_size_t dest_len = s21_strlen(dest);
  // const int len = dest_len + n;
  //  p = (char *) realloc (p,18);
  char *dest1 = dest;
  // **(dest[dest_len])=*src;
  for (s21_size_t i = 0; i <= n; i++) {
    // printf("%d", dest[dest_len+i]);
    dest1[dest_len + i] = src[i];
  }
  dest1[dest_len + n] = '\0';

  // dest+='\0';
  return dest;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  if (str1 && str2 && n > 0) {
    for (s21_size_t i = 0; i < n; i++) {
      if (str1[i] == '\0' || str1[i] != str2[i]) {
        result = str1[i] - str2[i];
        break;
      }
    }
  }
  return result;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  while ((src[i] != '\0') && (i < n)) {
    dest[i] = src[i];
    i++;
  }
  while (i < n) {
    dest[i] = '\0';
    i++;
  }
  return dest;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = NULL;
  int flag = 0;
  for (int i = 0; str1[i] != '\0' && !flag; i++) {
    for (int j = 0; str2[j] != '\0' && !flag; j++) {
      if (str1[i] == str2[j]) {
        result = (char *)&str1[i];
        flag = 1;
        break;
      }
    }
  }
  return result;
}

char *s21_strrchr(const char *str, int c) {
  char *res = NULL;

  while (*str) {
    if (*str == c) {
      res = (char *)str;
    }
    str++;
  }
  return res;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *search = NULL;
  char *hay = (char *)haystack;
  if (*needle == '\0') search = (char *)haystack;
  for (; *hay != '\0'; hay++) {
    if (!search) {
      if (*hay == *needle) {
        search = hay;
        char *ned = (char *)needle;
        while ((*ned != '\0') && (search != NULL)) {
          if (*hay == '\0') {
            search = NULL;
          }
          if (*hay != *ned) search = NULL;
          ned++;
          hay++;
        }
      }
    }
  }
  return search;
}

s21_size_t s21_strspn(const char *str, const char *sym) {
  s21_size_t result = 0;
  char *string1 = (char *)str;
  char *string2 = (char *)sym;
  while (*string1 && s21_strchr(string1, *string2++)) {
    result++;
  }

  return result;
}

char *s21_strtok(char *str, const char *delim) {
  static char *pointer = NULL;
  int result = 0;
  if (str != NULL) {
    pointer = str;
  }
  if (pointer) {
    str = pointer + s21_strspn(pointer, delim);
    pointer = str + s21_strcspn(str, delim);
    if (pointer == str) {
      pointer = NULL;
      result = 1;
    } else if (*pointer) {
      *pointer = 0;
      pointer = pointer + 1;
    } else {
      pointer = 0;
    }
  }
  return result == 0 ? str : NULL;
}

void *s21_to_lower(const char *str) {
  char *new_str = NULL;
  if (str) {
    new_str = calloc(s21_strlen(str) + 2, sizeof(char));
    if (new_str != NULL) {
      for (int i = 0; str[i]; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
          new_str[i] = str[i] + 32;
        } else {
          new_str[i] = str[i];
        }
      }
    }
  }
  return (void *)new_str;
}

void *s21_to_upper(const char *str) {
  char *new_str = NULL;
  if (str) {
    new_str = calloc(s21_strlen(str) + 2, sizeof(char));
    if (new_str != NULL) {
      for (int i = 0; str[i]; i++) {
        if (str[i] >= 97 && str[i] <= 122) {
          new_str[i] = str[i] - 32;
        } else {
          new_str[i] = str[i];
        }
      }
    }
  }
  return (void *)new_str;
}

void *s21_trim(const char *src, const char *trim_chars) {
  void *result = NULL;
  static char *buf = NULL;

  buf = malloc(s21_strlen(src) + 1);
  if (!buf) exit(0);

  s21_strncpy(buf, src,
              s21_strlen(src));  // правил, было s21_s21_strcpy(buf, src);

  if (src) {
    if (trim_chars && *trim_chars) {
      for (int i = (int)s21_strlen(src) - 1;
           i >= 0 && s21_strrchr(trim_chars, buf[i]) != NULL; i--)
        buf[i] = '\0';

      while (buf[0] != '\0' && s21_strrchr(trim_chars, buf[0]) != NULL)
        s21_memmove(&buf[0], &buf[1], s21_strlen(src));

      result = buf;
    } else {
      char def_trim[] = " \n\t\r\x0B\f";
      for (int i = (int)s21_strlen(src) - 1;
           i >= 0 && s21_strrchr(def_trim, buf[i]) != NULL; i--)
        buf[i] = '\0';

      while (buf[0] != '\0' && s21_strrchr(def_trim, buf[0]) != NULL)
        s21_memmove(&buf[0], &buf[1], s21_strlen(src));

      result = buf;
    }
  }
  return result;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  unsigned char *dest_p = (unsigned char *)dest;
  const unsigned char *src_p = (const unsigned char *)src;
  if (dest_p < src_p) {
    while (n--) *dest_p++ = *src_p++;
  } else {
    dest_p += n - 1;
    src_p += n - 1;
    while (n--) *dest_p-- = *src_p--;
  }
  return dest;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t length = 0;
  for (; *(str + length); length++) continue;
  return length;
}

char *s21_strcpy(char *dest, const char *src) {
  char *original = dest;
  while ((*dest++ = *src++) != '\0') continue;
  return original;
}

void bl_mod_off(int *buffermod, int *long_mode) {
  *buffermod = 0;
  *long_mode = 0;
}

void form_d_plus_null(syntx synt, long *tempfactor, char *result_buffer,
                      int *buffpointer, int is_signed) {
  //  Слева нули
  int len_int = lenint(*tempfactor);

  if (synt.accuracy.num != 0) {
    for (int i = 0; (i < synt.width.num - len_int -
                             ((*tempfactor < 0) || (synt.flags.plus))) &&
                    (i < synt.width.num - synt.accuracy.num -
                             ((*tempfactor < 0) || (synt.flags.plus)));
         i++) {  //  Добить спэйсами до ширины
      touch_space(result_buffer, buffpointer);
    }
  }
  //   Ставим знак
  if ((synt.flags.plus == 1) && (*tempfactor >= 0)) {
    is_signed = touch_plus(result_buffer, buffpointer);
  }
  if (*tempfactor < 0) {
    is_signed = touch_minus(result_buffer, buffpointer);
  }
  if ((synt.flags.space == 1) && (synt.flags.plus == 0) && (*tempfactor >= 0)) {
    is_signed = touch_space(result_buffer, buffpointer);
  }
  //  Длинна аргумента
  for (int i = *buffpointer;
       (i < synt.width.num - len_int - (*tempfactor == 0));
       i++) {  //  Добить нулями до ширины
    touch_null(result_buffer, buffpointer);
  }
  for (int i = *buffpointer;
       i < synt.accuracy.num - len_int - (*tempfactor == 0) + is_signed;
       i++) {  //  Добить нулями до ширины
    touch_null(result_buffer, buffpointer);
  }
  if (*tempfactor < 0) {
    *tempfactor = *tempfactor * -1;
  }
  if (len_int == 0) {
    touch_null(result_buffer, buffpointer);
  }

  print_dec(result_buffer, buffpointer, len_int, *tempfactor);
}

void form_f_plus_null(syntx synt, char *result_buffer, double *tempfactor,
                      int *buffpointer, int *len_int, int *bit_for_sign,
                      char type) {
  if ((synt.flags.plus == 1) && (*tempfactor >= 0)) {
    *bit_for_sign = touch_plus(result_buffer, buffpointer);
  }
  if (*tempfactor < 0) {
    *bit_for_sign = touch_minus(result_buffer, buffpointer);
  }
  if ((synt.flags.space == 1) && (synt.flags.plus == 0) && (*tempfactor >= 0)) {
    *bit_for_sign = touch_space(result_buffer, buffpointer);
  }
  if (type == 'f') {
    if (synt.width.num == 0) {
      for (int i = 0; i < (synt.width.num - *len_int - 2); i++) {
        touch_null(result_buffer, buffpointer);
      }
    } else {
      if (*len_int == 0) {
        for (int i = 0; i < synt.width.num - *len_int - synt.accuracy.num - 2 -
                                *bit_for_sign;
             i++) {
          touch_null(result_buffer, buffpointer);
        }
      } else {
        for (int i = 0; i < synt.width.num - *len_int - synt.accuracy.num - 1 -
                                *bit_for_sign;
             i++) {
          touch_null(result_buffer, buffpointer);
        }
      }
    }
  }
}

void form_f_plus_space(syntx synt, char *result_buffer, int *buffpointer,
                       double *tempfactor, int *len_int, char type) {
  int is_signed = 0;  //  Для пробелов
  if ((*tempfactor < 0) || (synt.flags.plus == 1) || (synt.flags.space == 1)) {
    is_signed = 1;
  }
  if (synt.width.num == 0) {
    for (int i = 0; i < synt.width.num - *len_int - 2 - is_signed; i++) {
      touch_space(result_buffer, buffpointer);
    }
  } else {
    int add_space = 1;
    if (synt.accuracy.num == 0) {
      if (synt.flags.sharp) {
        add_space = 1;
      } else {
        add_space = 0;
      }
    }
    if (*len_int == 0) {
      add_space++;
    }
    if (type == 'f') {
      for (int i = 0; i < synt.width.num - *len_int - synt.accuracy.num -
                              add_space - is_signed;
           i++) {
        touch_space(result_buffer, buffpointer);
      }
    }
    if ((type == 'g') || (type == 'G')) {
      for (int i = 0;
           i < synt.width.num - *len_int - (synt.accuracy.num - *len_int) -
                   add_space - is_signed;
           i++) {
        touch_space(result_buffer, buffpointer);
      }
    }
  }
  if ((synt.flags.plus == 1) && (*tempfactor >= 0)) {
    touch_plus(result_buffer, buffpointer);
  }
  if (*tempfactor < 0) {
    touch_minus(result_buffer, buffpointer);
  }
  if ((synt.flags.space == 1) && (synt.flags.plus == 0) && (*tempfactor >= 0)) {
    touch_space(result_buffer, buffpointer);
  }
}

void form_f_fractal(syntx synt, char *result_buffer, int *buffpointer,
                    double *fract_patr, char type, int *real_acc,
                    int *len_int) {
  result_buffer[*buffpointer] = '.';
  *buffpointer = *buffpointer + 1;
  if (type == 'f') {
    for (int i = 0; i < synt.accuracy.num; i++) {
      print_fract(result_buffer, buffpointer, fract_patr, real_acc);
    }
  }
  if ((type == 'g') || (type == 'G')) {
    form_f_fractal_gmod(synt, result_buffer, buffpointer, fract_patr, real_acc,
                        len_int);
  }
  if (((int)(*fract_patr * 10)) >= 5) {  //  Костылик для округления
    result_buffer[*buffpointer - 1] = result_buffer[*buffpointer - 1] + 1;
  }
  while (result_buffer[*buffpointer - 1] ==
         58) {  //  Округляем это добро "nf cerf hf,jntn bvtyyj nfr b yb[thf
    result_buffer[*buffpointer - 2] = result_buffer[*buffpointer - 2] + 1;
    result_buffer[*buffpointer - 1] = 48;
    *buffpointer = *buffpointer - 1;
    *real_acc = *real_acc - 1;
  }
  for (int i = *real_acc; i < synt.accuracy.num; i++) {
    touch_null(result_buffer, buffpointer);
  }
  if ((type == 'g') || (type == 'G')) {
    while (result_buffer[*buffpointer - 1] == '0') {
      result_buffer[*buffpointer - 1] = '\0';
      *buffpointer = *buffpointer - 1;
    }
  }
  form_f_fractal_additional_nullspace(synt, result_buffer, buffpointer);
  if (result_buffer[*buffpointer - 1] == '.') {
    if ((synt.flags.nul) && (*buffpointer <= synt.width.num)) {
      buff_shift_right(result_buffer, buffpointer, '0');
    }
    if ((synt.flags.nul == 0) && (*buffpointer <= synt.width.num)) {
      buff_shift_right(result_buffer, buffpointer, ' ');
    }
    result_buffer[*buffpointer - 1] = '\0';
    *buffpointer = *buffpointer - 1;
  }
}

void print_fract(char *result_buffer, int *buffpointer, double *fract_patr,
                 int *real_acc) {
  result_buffer[*buffpointer] = ((long int)(*fract_patr * 10)) + 48;
  *fract_patr = *fract_patr * 10 - (long int)(*fract_patr * 10);
  *buffpointer = *buffpointer + 1;
  *real_acc = *real_acc + 1;
}

void form_f_fractal_gmod(syntx synt, char *result_buffer, int *buffpointer,
                         double *fract_patr, int *real_acc, int *len_int) {
  if (*len_int != 0) {
    for (int i = 0; i < synt.accuracy.num - *len_int;
         i++) {  //    Может быть косячок при лен_инт == 0.
      print_fract(result_buffer, buffpointer, fract_patr, real_acc);
    }
  } else {
    int nipel = 0;
    *fract_patr = *fract_patr * 10;
    while ((nipel < 18) && (*fract_patr < 1)) {
      result_buffer[*buffpointer] = '0';
      *buffpointer = *buffpointer + 1;
      *fract_patr = *fract_patr * 10;
      nipel++;
    }
    *fract_patr = *fract_patr / 10;
    for (int i = 0; i < synt.accuracy.num;
         i++) {  //    Может быть косячок при лен_инт == 0.
      print_fract(result_buffer, buffpointer, fract_patr, real_acc);
    }
  }
}

void form_f_fractal_additional_nullspace(syntx synt, char *result_buffer,
                                         int *buffpointer) {
  if (synt.flags.nul == 0) {
    while (*buffpointer < synt.width.num) {
      for (int i = *buffpointer; i > 0; i--) { /* Поехали вправо. */
        result_buffer[i] = result_buffer[i - 1];
      }
      *buffpointer = *buffpointer + 1;
      result_buffer[0] = ' ';
    }
  } else {
    while (*buffpointer < synt.width.num) {
      if ((result_buffer[0] == '+') ||
          (result_buffer[0] == '-')) { /* Поехали вправо. */
        for (int i = *buffpointer; i > 1; i--) {
          result_buffer[i] = result_buffer[i - 1];
        }
        *buffpointer = *buffpointer + 1;
        result_buffer[1] = '0';
      } else {
        for (int i = *buffpointer; i > 0; i--) {
          result_buffer[i] = result_buffer[i - 1];
        }
        *buffpointer = *buffpointer + 1;
        result_buffer[0] = '0';
      }
    }
  }
}

void print_e_printer(syntx synt, double *tempfactor, char *result_buffer,
                     int *buffpointer, char type, int *int_part,
                     double *fract_patr) {
  //  First Symbol print

  result_buffer[*buffpointer] = *int_part + 48;
  *buffpointer = *buffpointer + 1;
  int len_int = lenint(*int_part);

  //  Dot print

  if ((synt.accuracy.num > 0) || (synt.flags.sharp)) {
    result_buffer[*buffpointer] = '.';
    *buffpointer = *buffpointer + 1;
  }

  //   Print accuracy
  *tempfactor = 10 * *fract_patr;

  if ((type == 'e') || (type == 'E')) {
    for (int i = 0; i < synt.accuracy.num; i++) {
      *int_part = (int)*tempfactor;
      *fract_patr = *tempfactor - *int_part;

      result_buffer[*buffpointer] = *int_part + 48;
      *buffpointer = *buffpointer + 1;
      *tempfactor = 10 * *fract_patr;
    }
  }

  if ((type == 'g') || (type == 'G')) {
    for (int i = 0; i < synt.accuracy.num - len_int; i++) {
      *int_part = (int)*tempfactor;
      *fract_patr = *tempfactor - *int_part;

      result_buffer[*buffpointer] = *int_part + 48;
      *buffpointer = *buffpointer + 1;
      *tempfactor = 10 * *fract_patr;
    }
  }
}