#ifndef MY_STRING
#define MY_STRING

#include <errno.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __linux__
#define MAX_ERRNO 133
#elif __APPLE__
#define MAX_ERRNO 107
#else
#error "Unsupported platform"
#endif

#define my_NULL ((void*)0)
#define my_NAN_LD (0.0L / 0.0L)
#define my_INF_POS_LD (1.0L / 0.0L)
#define my_INF_NEG_LD (-1.0L / 0.0L)

#define INT_BUF_SIZE 64
#define EXP_BUF_SIZE 128

typedef unsigned long my_size_t;

typedef struct {
  int width;
  int precision;
  int left_align;
  int plus_sign;
  int space;
  int alternate;
  int zero_pad;
} format_options;

my_size_t my_strlen(const char* string);
void* my_memchr(const void* str, int c, my_size_t n);
int my_memcmp(const void* str1, const void* str2, my_size_t n);
void* my_memcpy(void* dest, const void* src, my_size_t n);
void* my_memset(void* str, int c, my_size_t n);
char* my_strncat(char* dest, const char* src, my_size_t n);
int my_strncmp(const char* str1, const char* str2, my_size_t n);
const char* my_strerror(int error_num);
char* my_strncpy(char* dest, const char* src, my_size_t n);
char* my_strpbrk(const char* str1, const char* str2);
char* my_strchr(const char* str, int c);
char* my_strrchr(const char* str, int c);
my_size_t my_strcspn(const char* str1, const char* str2);
char* my_strstr(const char* haystack, const char* needle);
char* my_strtok(char* str, const char* delim);
void* my_to_upper(const char* str);
void* my_to_lower(const char* str);
void* my_insert(const char* src, const char* str, my_size_t start_index);
void* my_trim(const char* src, const char* trim_chars);

int my_sscanf(const char* str, const char* format, ...);
void skip_space(const char* str, int* str_index);

void process_ignore_int(const char* str, int* str_index, int limit);
void process_ignore_char(const char* str, int* str_index, int limit);
void process_ignore_string(const char* str, int* str_index, int limit);
void process_ignore_uint(const char* str, int* str_index, int limit);
void process_ignore_oct(const char* str, int* str_index, int limit);
void process_ignore_hex(const char* str, int* str_index, int limit);
void process_ignore_float(const char* str, int* str_index, int limit);
void process_ignore_pointer(const char* str, int* str_index, int limit);

int process_scanset(const char* str, int* str_index, char* output,
                    const char* scanset, int limit, int is_ignore);
int process_string(const char* str, int* str_index, char* result_str,
                   int limit);

int process_char(const char* str, int* str_index, char* result_char);
int process_long_int(const char* str, int* str_index, long int* result_int,
                     int limit);
int process_int(const char* str, int* str_index, int* result_int, int limit);
int process_short_int(const char* str, int* str_index, short int* result_int,
                      int limit);

int process_long_hex(const char* str, int* str_index,
                     unsigned long int* result_hex, int limit);
int process_hex(const char* str, int* str_index, unsigned int* result_hex,
                int limit);
int process_short_hex(const char* str, int* str_index,
                      unsigned short int* result_hex, int limit);
int process_pointer(const char* str, int* str_index, void** result_ptr,
                    int limit);
int process_uns_long_int(const char* str, int* str_index,
                         unsigned long int* result_uns_int, int limit);
int process_uns_short_int(const char* str, int* str_index,
                          unsigned short int* result_uns_int, int limit);
int process_uns_int(const char* str, int* str_index,
                    unsigned int* result_uns_int, int limit);
int process_long_oct(const char* str, int* str_index,
                     unsigned long int* result_int, int limit);
int process_short_oct(const char* str, int* str_index,
                      unsigned short int* result_int, int limit);
int process_oct(const char* str, int* str_index, unsigned int* result_int,
                int limit);
int process_i(const char* str, int* str_index, int* result_int, int limit);
int process_long_i(const char* str, int* str_index, long int* result_int,
                   int limit);
int process_short_i(const char* str, int* str_index, short int* result_int,
                    int limit);
int process_e(const char* str, int* str_index, float* result_float, int limit);
int process_long_e(const char* str, int* str_index, double* result_double,
                   int limit);
int process_long_long_e(const char* str, int* str_index,
                        long double* result_double, int limit);

int my_sprintf(char* str, const char* format, ...);

#endif
