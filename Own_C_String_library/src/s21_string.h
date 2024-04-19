// #ifndef S21_STRING_PLUS_H
// #define S21_STRING_PLUS_H

#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define MAX_ERROR_LEN 256
#define s21_NULL ((void *)0)

typedef unsigned long s21_size_t;

typedef struct token {
  int flag;
  int wight;
  char height;
  char specif;
} tok;

typedef struct {
  int minus;
  int plus;
  int space;
  int sharp;
  int nul;
} sflags;

typedef struct {
  int num;
  int star;
} swidht;

typedef struct {
  int num;
  int star;
} saccuracy;

typedef struct {
  int h;
  int l;
  int L;
} slenght;

typedef struct {
  sflags flags;
  swidht width;
  saccuracy accuracy;
  slenght lenght;
} syntx;

int s21_sscanf(char *str, const char *format, ...);
int is_number(char *f);
int is_hl(char *f);
int is_hl_flags(char *f);
int is_L_flags(char *f);
int is_specificator(char *f);
int token(char **str, char **f);
int add_number(char **f);
int add_lenght(char **f);
int add_specificator(char **f);
int delete_chars(char **str, char **f);
void delete_spaces(char **str);
int unsigned_int_parser(char **str, unsigned int *res);
int long_int_parser(char **str, long int *res);
int long_hexal_parser(char **str, long int *res);
int long_octal_parser(char **str, long int *res);
int long_unsigned_int_parser(char **str, long unsigned int *res);
int short_int_parser(char **str, short int *res);
int short_unsigned_int_parser(char **str, short unsigned int *res);
int long_double_parser(char **str, long double *res);
int flag_parser(char **st, va_list ap, int *ret);
int max(int num1, int num2);
void atoo(int *o);
int octal_parser(char **str, int *res);
int is_hex(char hex);
int hex_converter(char hex);
int hexal_parser(char **str, int *res);
int p_parser(char **str, void **res);
void *s21_memset(void *str, int c, s21_size_t n);
void clear_mtoken();
int s21_atoi(const char *str);
int int_parser(char **str, int *res);
int float_parser(char **str, float *res);
int str_parser(char **str, char **res);

int s21_sprintf(char *str, const char *format, ...);
int form_d(char *str, char *buff, int factor);
void clean_buffer(char *str);
void synt_parser(syntx *synt, char *buff);
int lenint(long tempfactor);
void from_d_minus(syntx synt, char *result_buffer, int *buffpointer,
                  long tempfactor);
void from_d_plus(syntx synt, char *result_buffer, int *buffpointer,
                 long tempfactor);
int form_f(char *str, char *buff, double factor);
void form_f_minus(syntx synt, char *result_buffer, int *buffpointer,
                  double tempfactor, char type);
void form_f_plus(syntx synt, char *result_buffer, int *buffpointer,
                 double tempfactor, char type);
int touch_minus(char *result_buffer, int *buffpointer);
int touch_plus(char *result_buffer, int *buffpointer);
int touch_space(char *result_buffer, int *buffpointer);
int touch_null(char *result_buffer, int *buffpointer);
int form_u(char *str, char *buff, unsigned int factor);
int form_o(char *str, char *buff, int factor);
void print_dec(char *result_buffer, int *buffpointer, int len_int,
               long tempfactor);
void print_oct(char *result_buffer, int *buffpointer, int len_int,
               long tempfactor);
int len_oct(long tempfactor);
void from_o_minus(syntx synt, char *result_buffer, int *buffpointer,
                  long tempfactor);
void from_o_plus(syntx synt, char *result_buffer, int *buffpointer,
                 long tempfactor);
void from_u_plus(syntx synt, char *result_buffer, int *buffpointer,
                 long tempfactor);
void from_u_minus(syntx synt, char *result_buffer, int *buffpointer,
                  long tempfactor);
void from_x_minus(syntx synt, char *result_buffer, int *buffpointer,
                  long tempfactor, char type);
void from_x_plus(syntx synt, char *result_buffer, int *buffpointer,
                 long tempfactor, char type);
void print_hex(char *result_buffer, int *buffpointer, int len_int,
               long tempfactor, char type);
int len_hex(long tempfactor);
int form_x(char *str, char *buff, int factor);
int form_X(char *str, char *buff, int factor);
int form_g(char *str, char *buff, double factor);
int form_e(char *str, char *buff, double factor);
int form_e_minus(syntx synt, char *result_buffer, int *buffpointer,
                 double tempfactor, char type);
int form_e_plus(syntx synt, char *result_buffer, int *buffpointer,
                double tempfactor, char type);
void e_normalization(double *tempfactor, int *emer_counter);
int print_e(syntx synt, char *result_buffer, int *buffpointer,
            double *tempfactor, int *emer_counter, char type);
void sign_e(syntx synt, char *result_buffer, int *buffpointer,
            double *tempfactor);
int form_E(char *str, char *buff, double factor);

void round_e(char *result_buffer, int *buffpointer, int *int_part,
             double *tempfactor, int *emer_counter);

int form_G(char *str, char *buff, double factor);

void buff_shift_right(char *result_buffer, int *buffpointer, char shift_type);

int form_c(char *str, char *buff, int factor);

void from_c_minus(syntx synt, char *result_buffer, int *buffpointer,
                  int tempfactor);
void from_c_plus(syntx synt, char *result_buffer, int *buffpointer,
                 int tempfactor);

int form_s(char *str, char *buff, char *factor);
void from_s_minus(syntx synt, char *result_buffer, int *buffpointer,
                  char *tempfactor);
void from_s_plus(syntx synt, char *result_buffer, int *buffpointer,
                 char *tempfactor);

int form_p(char *str, char *buff, int factor);

void from_p_minus(syntx synt, char *result_buffer, int *buffpointer,
                  long tempfactor, char type);
void from_p_plus(syntx synt, char *result_buffer, int *buffpointer,
                 long tempfactor, char type);
void int_to_string(char *tstr, int argument);

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

void *s21_memmove(void *dest, const void *src, s21_size_t n);
void s21_errnum_tostring(char *str, int num);
char *s21_strcat(char *dest, const char *src);
s21_size_t s21_strlen(const char *str);

char *s21_strcpy(char *dest, const char *src);
void bl_mod_off(int *buffermod, int *long_mode);
void form_d_plus_null(syntx synt, long *tempfactor, char *result_buffer,
                      int *buffpointer, int is_signed);
void form_f_plus_null(syntx synt, char *result_buffer, double *tempfactor,
                      int *buffpointer, int *len_int, int *bit_for_sign,
                      char type);
void form_f_plus_space(syntx synt, char *result_buffer, int *buffpointer,
                       double *tempfactor, int *len_int, char type);
void form_f_fractal(syntx synt, char *result_buffer, int *buffpointer,
                    double *fract_patr, char type, int *real_acc, int *len_int);
void print_fract(char *result_buffer, int *buffpointer, double *fract_patr,
                 int *real_acc);
void form_f_fractal_gmod(syntx synt, char *result_buffer, int *buffpointer,
                         double *fract_patr, int *real_acc, int *len_int);
void form_f_fractal_additional_nullspace(syntx synt, char *result_buffer,
                                         int *buffpointer);
void print_e_printer(syntx synt, double *tempfactor, char *result_buffer,
                     int *buffpointer, char type, int *int_part,
                     double *fract_patr);

// #if defined(__APPLE__)

// #elif defined(__linux__)
// #define MAX_ERRLIST 134
// #define MIN_ERRLIST -1
// #define ERROR  "Unknown error "

// static const char *maserror[] = {
//     "Success",
//     "Operation not permitted",
//     "No such file or directory",
//     "No such process",
//     "Interrupted system call",
//     "Input/output error",
//     "No such device or address",
//     "Argument list too long",
//     "Exec format error",
//     "Bad file descriptor",
//     "No child processes",
//     "Resource temporarily unavailable",
//     "Cannot allocate memory",
//     "Permission denied",
//     "Bad address",
//     "Block device required",
//     "Device or resource busy",
//     "File exists",
//     "Invalid cross-device link",
//     "No such device",
//     "Not a directory",
//     "Is a directory",
//     "Invalid argument",
//     "Too many open files in system",
//     "Too many open files",
//     "Inappropriate ioctl for device",
//     "Text file busy",
//     "File too large",
//     "No space left on device",
//     "Illegal seek",
//     "Read-only file system",
//     "Too many links",
//     "Broken pipe",
//     "Numerical argument out of domain",
//     "Numerical result out of range",
//     "Resource deadlock avoided",
//     "File name too long",
//     "No locks available",
//     "Function not implemented",
//     "Directory not empty",
//     "Too many levels of symbolic links",
//     "Unknown error 41",
//     "No message of desired type",
//     "Identifier removed",
//     "Channel number out of range",
//     "Level 2 not synchronized",
//     "Level 3 halted",
//     "Level 3 reset",
//     "Link number out of range",
//     "Protocol driver not attached",
//     "No CSI structure available",
//     "Level 2 halted",
//     "Invalid exchange",
//     "Invalid request descriptor",
//     "Exchange full",
//     "No anode",
//     "Invalid request code",
//     "Invalid slot",
//     "Unknown error 58",
//     "Bad font file format",
//     "Device not a stream",
//     "No data available",
//     "Timer expired",
//     "Out of streams resources",
//     "Machine is not on the network",
//     "Package not installed",
//     "Object is remote",
//     "Link has been severed",
//     "Advertise error",
//     "Srmount error",
//     "Communication error on send",
//     "Protocol error",
//     "Multihop attempted",
//     "RFS specific error",
//     "Bad message",
//     "Value too large for defined data type",
//     "Name not unique on network",
//     "File descriptor in bad state",
//     "Remote address changed",
//     "Can not access a needed shared library",
//     "Accessing a corrupted shared library",
//     ".lib section in a.out corrupted",
//     "Attempting to link in too many shared libraries",
//     "Cannot exec a shared library directly",
//     "Invalid or incomplete multibyte or wide character",
//     "Interrupted system call should be restarted",
//     "Streams pipe error",
//     "Too many users",
//     "Socket operation on non-socket",
//     "Destination address required",
//     "Message too long",
//     "Protocol wrong type for socket",
//     "Protocol not available",
//     "Protocol not supported",
//     "Socket type not supported",
//     "Operation not supported",
//     "Protocol family not supported",
//     "Address family not supported by protocol",
//     "Address already in use",
//     "Cannot assign requested address",
//     "Network is down",
//     "Network is unreachable",
//     "Network dropped connection on reset",
//     "Software caused connection abort",
//     "Connection reset by peer",
//     "No buffer space available",
//     "Transport endpoint is already connected",
//     "Transport endpoint is not connected",
//     "Cannot send after transport endpoint shutdown",
//     "Too many references: cannot splice",
//     "Connection timed out",
//     "Connection refused",
//     "Host is down",
//     "No route to host",
//     "Operation already in progress",
//     "Operation now in progress",
//     "Stale file handle",
//     "Structure needs cleaning",
//     "Not a XENIX named type file",
//     "No XENIX semaphores available",
//     "Is a named type file",
//     "Remote I/O error",
//     "Disk quota exceeded",
//     "No medium found",
//     "Wrong medium type",
//     "Operation canceled",
//     "Required key not available",
//     "Key has expired",
//     "Key has been revoked",
//     "Key was rejected by service",
//     "Owner died",
//     "State not recoverable",
//     "Operation not possible due to RF-kill",
//     "Memory page has hardware error"
// };
// #endif
