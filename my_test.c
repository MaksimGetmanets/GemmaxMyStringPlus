#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_string.h"

#define BUFFER_SIZE 1024

START_TEST(memchr_test) {
  char str1[] = "Hello, world!";
  ck_assert_ptr_eq(my_memchr(str1, 'w', 13), memchr(str1, 'w', 13));
  ck_assert_ptr_eq(my_memchr(str1, 'z', 13), memchr(str1, 'z', 13));
  ck_assert_ptr_eq(my_memchr(str1, 'H', 0), memchr(str1, 'H', 0));

  ck_assert_ptr_eq(my_memchr(str1, 'H', 13), memchr(str1, 'H', 13));

  ck_assert_ptr_eq(my_memchr(str1, '!', 13), memchr(str1, '!', 13));

  ck_assert_ptr_eq(my_memchr(str1, 'o', 13), memchr(str1, 'o', 13));

  ck_assert_ptr_eq(my_memchr(str1, '\0', 14), memchr(str1, '\0', 14));

  ck_assert_ptr_eq(my_memchr(str1, 'o', 5), memchr(str1, 'o', 5));
  ck_assert_ptr_eq(my_memchr(str1, 'o', 4), memchr(str1, 'o', 4));

  ck_assert_ptr_eq(my_memchr(str1, 'w', 8), memchr(str1, 'w', 8));

  char empty1[] = "";
  ck_assert_ptr_eq(my_memchr(empty1, 'a', 0), memchr(empty1, 'a', 0));
  ck_assert_ptr_eq(my_memchr(empty1, '\0', 1), memchr(empty1, '\0', 1));

  char single[] = "A";
  ck_assert_ptr_eq(my_memchr(single, 'A', 1), memchr(single, 'A', 1));
  ck_assert_ptr_eq(my_memchr(single, 'B', 1), memchr(single, 'B', 1));

  char repeated[] = "aaaabaaaa";
  ck_assert_ptr_eq(my_memchr(repeated, 'b', 9), memchr(repeated, 'b', 9));

  unsigned char binary_data[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x00};
  ck_assert_ptr_eq(my_memchr(binary_data, 0x03, 6),
                   memchr(binary_data, 0x03, 6));
  ck_assert_ptr_eq(my_memchr(binary_data, 0xFF, 6),
                   memchr(binary_data, 0xFF, 6));

  char special_chars[] = "\n\t\r\0\xFF";
  ck_assert_ptr_eq(my_memchr(special_chars, '\n', 6),
                   memchr(special_chars, '\n', 6));
  ck_assert_ptr_eq(my_memchr(special_chars, '\t', 6),
                   memchr(special_chars, '\t', 6));
  ck_assert_ptr_eq(my_memchr(special_chars, '\r', 6),
                   memchr(special_chars, '\r', 6));
  ck_assert_ptr_eq(my_memchr(special_chars, 0xFF, 6),
                   memchr(special_chars, 0xFF, 6));

  char large_buffer[100] = "test string";
  ck_assert_ptr_eq(my_memchr(large_buffer, 'g', 100),
                   memchr(large_buffer, 'g', 100));
  ck_assert_ptr_eq(my_memchr(large_buffer, 'x', 100),
                   memchr(large_buffer, 'x', 100));

  ck_assert_ptr_eq(my_memchr(large_buffer, '\0', 100),
                   memchr(large_buffer, '\0', 100));

  char str3[] = "hello";
  ck_assert_ptr_eq(my_memchr(str3, 'h', 0), memchr(str3, 'h', 0));
  ck_assert_ptr_eq(my_memchr(str3, 'o', 0), memchr(str3, 'o', 0));
  ck_assert_ptr_eq(my_memchr(str3, 'x', 0), memchr(str3, 'x', 0));

  char empty2[] = "";
  ck_assert_ptr_eq(my_memchr(empty2, 'a', 0), memchr(empty2, 'a', 0));

  char same_chars[] = "oooooo";
  ck_assert_ptr_eq(my_memchr(same_chars, 'o', 6), memchr(same_chars, 'o', 6));

  char with_space[] = "hello world";
  ck_assert_ptr_eq(my_memchr(with_space, ' ', 11), memchr(with_space, ' ', 11));

  char numbers[] = "1234567890";
  ck_assert_ptr_eq(my_memchr(numbers, '5', 10), memchr(numbers, '5', 10));

  char mixed[] = "Hello123!@#";
  ck_assert_ptr_eq(my_memchr(mixed, '!', 11), memchr(mixed, '!', 11));
  ck_assert_ptr_eq(my_memchr(mixed, '@', 11), memchr(mixed, '@', 11));
  ck_assert_ptr_eq(my_memchr(mixed, '#', 11), memchr(mixed, '#', 11));

  char last_char_test[] = "abc";
  ck_assert_ptr_eq(my_memchr(last_char_test, 'c', 3),
                   memchr(last_char_test, 'c', 3));
  ck_assert_ptr_eq(my_memchr(last_char_test, 'c', 2),
                   memchr(last_char_test, 'c', 2));

  char with_null[] = "test\0string";
  ck_assert_ptr_eq(my_memchr(with_null, '\0', 12), memchr(with_null, '\0', 12));

  char big_buffer[50];
  memset(big_buffer, 'A', 49);
  big_buffer[49] = '\0';
  big_buffer[25] = 'X';
  ck_assert_ptr_eq(my_memchr(big_buffer, 'X', 50), memchr(big_buffer, 'X', 50));
}
END_TEST

Suite* suite_memchr(void) {
  Suite* s = suite_create("my_memchr");
  TCase* tc = tcase_create("Core");
  tcase_add_test(tc, memchr_test);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(memcmp_test) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  char str3[] = "Hellp";
  char str4[] = "Hell";

  ck_assert_int_eq(my_memcmp(str1, str2, 5), memcmp(str1, str2, 5));
  ck_assert_int_eq(my_memcmp(str1, str2, 3), memcmp(str1, str2, 3));

  ck_assert_int_eq(my_memcmp(str1, str3, 5), memcmp(str1, str3, 5));
  ck_assert_int_eq(my_memcmp(str3, str1, 5), memcmp(str3, str1, 5));

  ck_assert_int_eq(my_memcmp(str1, str4, 4), memcmp(str1, str4, 4));

  char empty1[] = "";
  char empty2[] = "";
  ck_assert_int_eq(my_memcmp(empty1, empty2, 0), memcmp(empty1, empty2, 0));

  ck_assert_int_eq(my_memcmp(str1, str3, 0), memcmp(str1, str3, 0));

  ck_assert_int_eq(my_memcmp("abc", "abd", 2), memcmp("abc", "abd", 2));
  ck_assert_int_eq(my_memcmp("abc", "abd", 3), memcmp("abc", "abd", 3));

  unsigned char bin1[] = {0x01, 0x02, 0x03, 0x04};
  unsigned char bin2[] = {0x01, 0x02, 0x03, 0x05};
  unsigned char bin3[] = {0x01, 0x02, 0x04, 0x04};

  ck_assert_int_eq(my_memcmp(bin1, bin2, 4), memcmp(bin1, bin2, 4));
  ck_assert_int_eq(my_memcmp(bin1, bin3, 4), memcmp(bin1, bin3, 4));

  signed char neg1[] = {-1, -2, -3};
  signed char neg2[] = {-1, -2, -4};
  ck_assert_int_eq(my_memcmp(neg1, neg2, 3), memcmp(neg1, neg2, 3));

  char spec1[] = "\n\t\r";
  char spec2[] = "\n\t ";
  ck_assert_int_eq(my_memcmp(spec1, spec2, 3), memcmp(spec1, spec2, 3));

  char long1[100] = "A";
  char long2[100] = "B";
  ck_assert_int_eq(my_memcmp(long1, long2, 100), memcmp(long1, long2, 100));

  ck_assert_int_eq(my_memcmp(str1, str1, 5), memcmp(str1, str1, 5));

  ck_assert_int_eq(my_memcmp("A", "B", 1), memcmp("A", "B", 1));
  ck_assert_int_eq(my_memcmp("B", "A", 1), memcmp("B", "A", 1));

  char with_null1[] = "abc\0def";
  char with_null2[] = "abc\0xyz";
  ck_assert_int_eq(my_memcmp(with_null1, with_null2, 7),
                   memcmp(with_null1, with_null2, 7));

  int my_result = my_memcmp("a", "b", 1);
  int std_result = memcmp("a", "b", 1);
  ck_assert_int_eq((my_result > 0), (std_result > 0));
  ck_assert_int_eq((my_result < 0), (std_result < 0));

  int my_res = my_memcmp("hello", "HELLO", 5);
  int std_res = memcmp("hello", "HELLO", 5);
  ck_assert((my_res > 0 && std_res > 0) || (my_res < 0 && std_res < 0) ||
            (my_res == 0 && std_res == 0));

  char nums1[] = "12345";
  char nums2[] = "12346";
  ck_assert_int_eq(my_memcmp(nums1, nums2, 5), memcmp(nums1, nums2, 5));
}
END_TEST

Suite* suite_memcmp(void) {
  Suite* s = suite_create("my_memcmp");
  TCase* tc = tcase_create("Core");
  tcase_add_test(tc, memcmp_test);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(memcpy_test) {
  char src[] = "Copy this!";
  char dest1[20] = {0}, dest2[20] = {0};
  my_memcpy(dest1, src, strlen(src) + 1);
  memcpy(dest2, src, strlen(src) + 1);
  ck_assert_str_eq(dest1, dest2);

  memset(dest1, 0, 20);
  memset(dest2, 0, 20);
  my_memcpy(dest1, src, 5);
  memcpy(dest2, src, 5);
  ck_assert_int_eq(memcmp(dest1, dest2, 20), 0);

  char dest3[20] = "original";
  char dest4[20] = "original";
  my_memcpy(dest3, src, 0);
  memcpy(dest4, src, 0);
  ck_assert_str_eq(dest3, dest4);

  unsigned char bin_src[] = {0x00, 0x01, 0xFF, 0x7F, 0x80};
  unsigned char bin_dest1[10] = {0};
  unsigned char bin_dest2[10] = {0};
  my_memcpy(bin_dest1, bin_src, sizeof(bin_src));
  memcpy(bin_dest2, bin_src, sizeof(bin_src));
  ck_assert_int_eq(memcmp(bin_dest1, bin_dest2, sizeof(bin_src)), 0);

  char large_src[100];
  char large_dest1[100] = {0};
  char large_dest2[100] = {0};
  memset(large_src, 'X', 99);
  large_src[99] = '\0';
  my_memcpy(large_dest1, large_src, 100);
  memcpy(large_dest2, large_src, 100);
  ck_assert_int_eq(memcmp(large_dest1, large_dest2, 100), 0);

  char single1 = 'A', single2 = 'B', single3 = 'A', single4 = 'B';
  my_memcpy(&single2, &single1, 1);
  memcpy(&single4, &single3, 1);
  ck_assert_int_eq(single2, single4);

  char with_null1[] = "abc\0def";
  char with_null2[10] = {0}, with_null3[10] = {0};
  my_memcpy(with_null2, with_null1, 7);
  memcpy(with_null3, with_null1, 7);
  ck_assert_int_eq(memcmp(with_null2, with_null3, 7), 0);

  signed char neg_src[] = {-1, -2, -3, -4};
  signed char neg_dest1[10] = {0}, neg_dest2[10] = {0};
  my_memcpy(neg_dest1, neg_src, 4);
  memcpy(neg_dest2, neg_src, 4);
  ck_assert_int_eq(memcmp(neg_dest1, neg_dest2, 4), 0);

  char empty_src[] = "";
  char empty_dest1[10] = "notempty", empty_dest2[10] = "notempty";
  my_memcpy(empty_dest1, empty_src, 1);
  memcpy(empty_dest2, empty_src, 1);
  ck_assert_str_eq(empty_dest1, empty_dest2);

  char exact_src[] = "12345";
  char exact_dest1[6] = {0}, exact_dest2[6] = {0};
  my_memcpy(exact_dest1, exact_src, 6);
  memcpy(exact_dest2, exact_src, 6);
  ck_assert_str_eq(exact_dest1, exact_dest2);

  char mid_src[] = "Hello World";
  char mid_dest1[20] = {0}, mid_dest2[20] = {0};
  my_memcpy(mid_dest1, mid_src + 6, 5);
  memcpy(mid_dest2, mid_src + 6, 5);
  ck_assert_str_eq(mid_dest1, mid_dest2);
}
END_TEST

Suite* suite_memcpy(void) {
  Suite* s = suite_create("my_memcpy");
  TCase* tc = tcase_create("Core");
  tcase_add_test(tc, memcpy_test);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(memset_test) {
  char str1[20] = "Hello", str2[20] = "Hello";
  my_memset(str1, '*', 5);
  memset(str2, '*', 5);
  ck_assert_int_eq(memcmp(str1, str2, 20), 0);
}
END_TEST

Suite* suite_memset(void) {
  Suite* s = suite_create("my_memset");
  TCase* tc = tcase_create("Core");
  tcase_add_test(tc, memset_test);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(strncat_test) {
  char dest1[50] = "Hello, ", dest2[50] = "Hello, ";
  char src[] = "world!";
  my_strncat(dest1, src, 7);
  strncat(dest2, src, 7);
  ck_assert_str_eq(dest1, dest2);
  char dest3[50] = "Test: ", dest4[50] = "Test: ";
  my_strncat(dest3, src, 3);
  strncat(dest4, src, 3);
  ck_assert_str_eq(dest3, dest4);
}
END_TEST
Suite* suite_strncat(void) {
  Suite* s = suite_create("my_strncat");
  TCase* tc = tcase_create("Core");
  tcase_add_test(tc, strncat_test);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(strchr_test) {
  char str[] = "Find me!";
  ck_assert_ptr_eq(my_strchr(str, 'm'), strchr(str, 'm'));
  ck_assert_ptr_eq(my_strchr(str, 'z'), strchr(str, 'z'));
  ck_assert_ptr_eq(my_strchr(str, '\0'), strchr(str, '\0'));

  char empty_str[] = "";
  ck_assert_ptr_eq(my_strchr(empty_str, '\0'), strchr(empty_str, '\0'));

  char null_str[1] = {'\0'};
  ck_assert_ptr_eq(my_strchr(null_str, '\0'), strchr(null_str, '\0'));

  char mid_str[] = "hello\0world";
  ck_assert_ptr_eq(my_strchr(mid_str, '\0'), strchr(mid_str, '\0'));

  char long_str[] = "test string with multiple words";
  ck_assert_ptr_eq(my_strchr(long_str, '\0'), strchr(long_str, '\0'));

  char test_str[] = "some text";
  char* my_result = my_strchr(test_str, '\0');
  char* std_result = strchr(test_str, '\0');
  ck_assert_ptr_eq(my_result, std_result);

  if (my_result != NULL && std_result != NULL) {
    ck_assert_int_eq(*my_result, *std_result);
    ck_assert_ptr_eq(my_result, test_str + strlen(test_str));
  }

  char mixed_str[] = "find both";
  ck_assert_ptr_eq(my_strchr(mixed_str, 'b'), strchr(mixed_str, 'b'));
  ck_assert_ptr_eq(my_strchr(mixed_str, '\0'), strchr(mixed_str, '\0'));

  char space_str[] = "   ";
  ck_assert_ptr_eq(my_strchr(space_str, '\0'), strchr(space_str, '\0'));

  char special_str[] = "hello\nworld\t!";
  ck_assert_ptr_eq(my_strchr(special_str, '\0'), strchr(special_str, '\0'));
}
END_TEST
Suite* suite_strchr(void) {
  Suite* s = suite_create("my_strchr");
  TCase* tc = tcase_create("Core");
  tcase_add_test(tc, strchr_test);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(strncmp_test) {
  char s1[] = "abc", s2[] = "abd";
  ck_assert_int_lt(my_strncmp(s1, s2, 3), 0);
  ck_assert_int_gt(my_strncmp(s2, s1, 3), 0);
  ck_assert_int_eq(my_strncmp(s1, s2, 2), 0);
}
END_TEST
Suite* suite_strncmp(void) {
  Suite* s = suite_create("my_strncmp");
  TCase* tc = tcase_create("Core");
  tcase_add_test(tc, strncmp_test);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(strncpy_test) {
  char src[] = "Test";
  char dest1[10] = {0}, dest2[10] = {0};
  my_strncpy(dest1, src, 8);
  strncpy(dest2, src, 8);
  ck_assert_int_eq(memcmp(dest1, dest2, 10), 0);
}
END_TEST
Suite* suite_strncpy(void) {
  Suite* s = suite_create("my_strncpy");
  TCase* tc = tcase_create("Core");
  tcase_add_test(tc, strncpy_test);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(strcspn_test) {
  char str1[] = "abcdef";
  char str2[] = "xyz";
  char str3[] = "cde";
  ck_assert_int_eq(my_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_int_eq(my_strcspn(str1, str3), strcspn(str1, str3));

  char empty_str[] = "";
  ck_assert_int_eq(my_strcspn(empty_str, str2), strcspn(empty_str, str2));

  ck_assert_int_eq(my_strcspn(str1, empty_str), strcspn(str1, empty_str));

  char str4[] = "cdefgh";
  ck_assert_int_eq(my_strcspn(str4, str3), strcspn(str4, str3));

  char str5[] = "abcxyz";
  char str6[] = "xyz";
  ck_assert_int_eq(my_strcspn(str5, str6), strcspn(str5, str6));

  char str7[] = "abcdef";
  char str8[] = "ghijkl";
  ck_assert_int_eq(my_strcspn(str7, str8), strcspn(str7, str8));

  char str9[] = "123abc";
  char str10[] = "abc";
  ck_assert_int_eq(my_strcspn(str9, str10), strcspn(str9, str10));

  char str11[] = "   hello";
  char str12[] = "hel";
  ck_assert_int_eq(my_strcspn(str11, str12), strcspn(str11, str12));

  char str13[] = "apple";
  char str14[] = "a";
  ck_assert_int_eq(my_strcspn(str13, str14), strcspn(str13, str14));
}
END_TEST

START_TEST(strcspn_edge_cases_test) {
  char str[] = "test string";
  char empty[] = "";

  my_size_t my_res = my_strcspn(str, my_NULL);

  ck_assert_int_eq(my_res, 11);

  my_res = my_strcspn(str, empty);
  my_size_t std_res = strcspn(str, empty);
  ck_assert_int_eq(my_res, std_res);

  my_res = my_strcspn(my_NULL, str);

  ck_assert_int_eq(my_res, 0);

  my_res = my_strcspn(my_NULL, my_NULL);

  ck_assert_int_eq(my_res, 0);

  my_res = my_strcspn(empty, my_NULL);

  ck_assert_int_eq(my_res, 0);

  my_res = my_strcspn(empty, empty);
  std_res = strcspn(empty, empty);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

Suite* suite_strcspn(void) {
  Suite* s = suite_create("my_strcspn");
  TCase* tc_core = tcase_create("Core");
  TCase* tc_edge = tcase_create("EdgeCases");

  tcase_add_test(tc_core, strcspn_test);
  tcase_add_test(tc_edge, strcspn_edge_cases_test);

  suite_add_tcase(s, tc_core);
  suite_add_tcase(s, tc_edge);
  return s;
}

START_TEST(strerror_test) {
  for (int i = -100; i < 200; i++) {
    ck_assert_str_eq(my_strerror(i), strerror(i));
  }
}
END_TEST
Suite* suite_strerror(void) {
  Suite* s = suite_create("my_strerror");
  TCase* tc = tcase_create("Core");
  tcase_add_test(tc, strerror_test);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(strlen_test) {
  ck_assert_int_eq(my_strlen("Hello"), strlen("Hello"));
  ck_assert_int_eq(my_strlen(""), strlen(""));
}
END_TEST
Suite* suite_strlen(void) {
  Suite* s = suite_create("my_strlen");
  TCase* tc = tcase_create("Core");
  tcase_add_test(tc, strlen_test);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(strpbrk_test) {
  char str[] = "hello world";
  ck_assert_ptr_eq(my_strpbrk(str, "ol"), strpbrk(str, "ol"));
  ck_assert_ptr_eq(my_strpbrk(str, "xyz"), strpbrk(str, "xyz"));
}
END_TEST
Suite* suite_strpbrk(void) {
  Suite* s = suite_create("my_strpbrk");
  TCase* tc = tcase_create("Core");
  tcase_add_test(tc, strpbrk_test);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(strrchr_test) {
  char str[] = "hello world";
  ck_assert_ptr_eq(my_strrchr(str, 'o'), strrchr(str, 'o'));
  ck_assert_ptr_eq(my_strrchr(str, 'z'), strrchr(str, 'z'));

  ck_assert_ptr_eq(my_strrchr(str, '\0'), strrchr(str, '\0'));

  char empty[] = "";
  ck_assert_ptr_eq(my_strrchr(empty, '\0'), strrchr(empty, '\0'));

  ck_assert_ptr_eq(my_strrchr(str, 'h'), strrchr(str, 'h'));

  ck_assert_ptr_eq(my_strrchr(str, 'd'), strrchr(str, 'd'));

  char multi[] = "test string test";
  ck_assert_ptr_eq(my_strrchr(multi, 't'), strrchr(multi, 't'));
}
END_TEST

Suite* suite_strrchr(void) {
  Suite* s = suite_create("my_strrchr");
  TCase* tc = tcase_create("Core");
  tcase_add_test(tc, strrchr_test);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(strstr_test) {
  char* my_res = my_strstr("Hello world", "world");
  char* std_res = strstr("Hello world", "world");
  ck_assert_ptr_eq(my_res, std_res);

  my_res = my_strstr("abcdef", "cde");
  std_res = strstr("abcdef", "cde");
  ck_assert_ptr_eq(my_res, std_res);

  my_res = my_strstr("Hello world", "test");
  std_res = strstr("Hello world", "test");
  ck_assert_ptr_eq(my_res, std_res);

  my_res = my_strstr("Hello world", "Hello");
  std_res = strstr("Hello world", "Hello");
  ck_assert_ptr_eq(my_res, std_res);

  my_res = my_strstr("Hello world", "world");
  std_res = strstr("Hello world", "world");
  ck_assert_ptr_eq(my_res, std_res);

  my_res = my_strstr("Hello world", "");
  std_res = strstr("Hello world", "");
  ck_assert_ptr_eq(my_res, std_res);

  my_res = my_strstr("", "needle");
  std_res = strstr("", "needle");
  ck_assert_ptr_eq(my_res, std_res);

  my_res = my_strstr("", "");
  std_res = strstr("", "");
  ck_assert_ptr_eq(my_res, std_res);

  my_res = my_strstr("abc", "abcdef");
  std_res = strstr("abc", "abcdef");
  ck_assert_ptr_eq(my_res, std_res);

  my_res = my_strstr("identical", "identical");
  std_res = strstr("identical", "identical");
  ck_assert_ptr_eq(my_res, std_res);

  my_res = my_strstr("abcdef", "c");
  std_res = strstr("abcdef", "c");
  ck_assert_ptr_eq(my_res, std_res);

  my_res = my_strstr("aaaaab", "aab");
  std_res = strstr("aaaaab", "aab");
  ck_assert_ptr_eq(my_res, std_res);
}
END_TEST

START_TEST(strstr_null_test) {
  char* my_res;

  my_res = my_strstr(my_NULL, "needle");
  ck_assert_ptr_eq(my_res, my_NULL);

  my_res = my_strstr(my_NULL, my_NULL);
  ck_assert_ptr_eq(my_res, my_NULL);
}
END_TEST

Suite* suite_strstr(void) {
  Suite* s = suite_create("my_strstr");
  TCase* tc_core = tcase_create("Core");
  TCase* tc_null = tcase_create("NullCases");

  tcase_add_test(tc_core, strstr_test);
  tcase_add_test(tc_null, strstr_null_test);

  suite_add_tcase(s, tc_core);
  suite_add_tcase(s, tc_null);
  return s;
}

START_TEST(strtok_basic_test) {
  char str1[] = "hello,world,test";
  char str2[] = "hello,world,test";
  const char* delim = ",";
  char* my_token = my_strtok(str1, delim);
  char* std_token = strtok(str2, delim);
  while (my_token != NULL || std_token != NULL) {
    ck_assert_str_eq(my_token, std_token);
    my_token = my_strtok(NULL, delim);
    std_token = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(strtok_multiple_delimiters_test) {
  char str1[] = "hello, world; test";
  char str2[] = "hello, world; test";
  const char* delim = ",; ";
  char* my_token = my_strtok(str1, delim);
  char* std_token = strtok(str2, delim);
  while (my_token != NULL || std_token != NULL) {
    ck_assert_str_eq(my_token, std_token);
    my_token = my_strtok(NULL, delim);
    std_token = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(strtok_consecutive_delimiters_test) {
  char str1[] = "test1,,test2,,,test3";
  char str2[] = "test1,,test2,,,test3";
  const char* delim = ",";
  char* my_token = my_strtok(str1, delim);
  char* std_token = strtok(str2, delim);
  while (my_token != NULL || std_token != NULL) {
    ck_assert_str_eq(my_token, std_token);
    my_token = my_strtok(NULL, delim);
    std_token = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(strtok_no_delimiters_test) {
  char str1[] = "hello";
  char str2[] = "hello";
  const char* delim = ",";
  char* my_token = my_strtok(str1, delim);
  char* std_token = strtok(str2, delim);
  while (my_token != NULL || std_token != NULL) {
    ck_assert_str_eq(my_token, std_token);
    my_token = my_strtok(NULL, delim);
    std_token = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(strtok_only_delimiters_test) {
  char str1[] = ",,,,";
  char str2[] = ",,,,";
  const char* delim = ",";
  char* my_token = my_strtok(str1, delim);
  char* std_token = strtok(str2, delim);
  while (my_token != NULL || std_token != NULL) {
    ck_assert_str_eq(my_token, std_token);
    my_token = my_strtok(NULL, delim);
    std_token = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(strtok_empty_string_test) {
  char str1[] = "";
  char str2[] = "";
  const char* delim = ",";
  char* my_token = my_strtok(str1, delim);
  char* std_token = strtok(str2, delim);
  while (my_token != NULL || std_token != NULL) {
    ck_assert_str_eq(my_token, std_token);
    my_token = my_strtok(NULL, delim);
    std_token = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(strtok_delimiter_at_ends_test) {
  char str1[] = ",hello,world,";
  char str2[] = ",hello,world,";
  const char* delim = ",";
  char* my_token = my_strtok(str1, delim);
  char* std_token = strtok(str2, delim);
  while (my_token != NULL || std_token != NULL) {
    ck_assert_str_eq(my_token, std_token);
    my_token = my_strtok(NULL, delim);
    std_token = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(strtok_single_char_delimiter_test) {
  char str1[] = "a b c d";
  char str2[] = "a b c d";
  const char* delim = " ";
  char* my_token = my_strtok(str1, delim);
  char* std_token = strtok(str2, delim);
  while (my_token != NULL || std_token != NULL) {
    ck_assert_str_eq(my_token, std_token);
    my_token = my_strtok(NULL, delim);
    std_token = strtok(NULL, delim);
  }
}
END_TEST

Suite* suite_strtok(void) {
  Suite* s = suite_create("my_strtok");
  TCase* tc = tcase_create("Core");

  tcase_add_test(tc, strtok_basic_test);
  tcase_add_test(tc, strtok_multiple_delimiters_test);
  tcase_add_test(tc, strtok_consecutive_delimiters_test);
  tcase_add_test(tc, strtok_no_delimiters_test);
  tcase_add_test(tc, strtok_only_delimiters_test);
  tcase_add_test(tc, strtok_empty_string_test);
  tcase_add_test(tc, strtok_delimiter_at_ends_test);
  tcase_add_test(tc, strtok_single_char_delimiter_test);

  suite_add_tcase(s, tc);
  return s;
}

START_TEST(to_upper_test) {
  char* res1 = my_to_upper("hello world 123");
  ck_assert_str_eq(res1, "HELLO WORLD 123");
  free(res1);
  char* res2 = my_to_upper(NULL);
  ck_assert_ptr_null(res2);
}
END_TEST
Suite* suite_to_upper(void) {
  Suite* s = suite_create("my_to_upper");
  TCase* tc = tcase_create("Core");
  tcase_add_test(tc, to_upper_test);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(to_lower_test) {
  char* res1 = my_to_lower("HELLO WORLD");
  ck_assert_str_eq(res1, "hello world");
  free(res1);
}
END_TEST
Suite* suite_to_lower(void) {
  Suite* s = suite_create("my_to_lower");
  TCase* tc = tcase_create("Core");
  tcase_add_test(tc, to_lower_test);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(insert_test) {
  char* res1 = my_insert("hello", " world", 5);
  ck_assert_str_eq(res1, "hello world");
  free(res1);
  char* res2 = my_insert("test", "FAIL", 100);
  ck_assert_ptr_null(res2);
}
END_TEST
Suite* suite_insert(void) {
  Suite* s = suite_create("my_insert");
  TCase* tc = tcase_create("Core");
  tcase_add_test(tc, insert_test);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(trim_test) {
  char* res1 = my_trim("  hello  ", " ");
  ck_assert_str_eq(res1, "hello");
  free(res1);
  char* res2 = my_trim(".....", ".");
  ck_assert_str_eq(res2, "");
  free(res2);
}
END_TEST
Suite* suite_trim(void) {
  Suite* s = suite_create("my_trim");
  TCase* tc = tcase_create("Core");
  tcase_add_test(tc, trim_test);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(sscanf_d_specifiers_test) {
  int my_d1, std_d1, my_d2, std_d2;
  int my_res = my_sscanf(" -123 456 ", "%d%d", &my_d1, &my_d2);
  int std_res = sscanf(" -123 456 ", "%d%d", &std_d1, &std_d2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_d1, std_d1);
  ck_assert_int_eq(my_d2, std_d2);

  long int my_ld, std_ld;
  my_res = my_sscanf("+1234567890", "%ld", &my_ld);
  std_res = sscanf("+1234567890", "%ld", &std_ld);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_ld, std_ld);

  short int my_hd, std_hd;
  my_res = my_sscanf("1234567890", "%hd", &my_hd);
  std_res = sscanf("1234567890", "%hd", &std_hd);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_hd, std_hd);

  my_res = my_sscanf("100 200 300", "%d %*d %d", &my_d1, &my_d2);
  std_res = sscanf("100 200 300", "%d %*d %d", &std_d1, &std_d2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_d1, std_d1);
  ck_assert_int_eq(my_d2, std_d2);

  my_res = my_sscanf("999 888 777", "%ld %*d %d", &my_ld, &my_d1);
  std_res = sscanf("999 888 777", "%ld %*d %d", &std_ld, &std_d1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_ld, std_ld);
  ck_assert_int_eq(my_d1, std_d1);

  my_res = my_sscanf("50 60 70", "%hd %*d %hd", &my_hd, &my_hd);
  std_res = sscanf("50 60 70", "%hd %*d %hd", &std_hd, &std_hd);
  ck_assert_int_eq(my_res, std_res);

  my_res = my_sscanf("12345", "%3d", &my_d1);
  std_res = sscanf("12345", "%3d", &std_d1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_d1, std_d1);

  my_res = my_sscanf("987654", "%4ld", &my_ld);
  std_res = sscanf("987654", "%4ld", &std_ld);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_ld, std_ld);

  my_res = my_sscanf("12345 678", "%2d %*d %d", &my_d1, &my_d2);
  std_res = sscanf("12345 678", "%2d %*d %d", &std_d1, &std_d2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_d1, std_d1);
  ck_assert_int_eq(my_d2, std_d2);

  my_res = my_sscanf("-32768 32767", "%hd %hd", &my_hd, &my_hd);
  std_res = sscanf("-32768 32767", "%hd %hd", &std_hd, &std_hd);
  ck_assert_int_eq(my_res, std_res);

  my_res = my_sscanf("1 2 3 4 5", "%d %*d %*d %d %d", &my_d1, &my_d2, &my_d2);
  std_res = sscanf("1 2 3 4 5", "%d %*d %*d %d %d", &std_d1, &std_d2, &std_d2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_d1, std_d1);

  my_res = my_sscanf("2147483647", "%d", &my_d1);
  std_res = sscanf("2147483647", "%d", &std_d1);
  ck_assert_int_eq(my_res, std_res);
  if (my_res == 1 && std_res == 1) {
    ck_assert_int_eq(my_d1, std_d1);
  }

  my_res = my_sscanf("-2147483648", "%d", &my_d1);
  std_res = sscanf("-2147483648", "%d", &std_d1);
  ck_assert_int_eq(my_res, std_res);
  if (my_res == 1 && std_res == 1) {
    ck_assert_int_eq(my_d1, std_d1);
  }

  my_res = my_sscanf("9999999999999999999", "%d", &my_d1);
  std_res = sscanf("9999999999999999999", "%d", &std_d1);
  ck_assert_int_eq(my_res, std_res);

  my_res = my_sscanf("2147483648", "%9d", &my_d1);
  std_res = sscanf("2147483648", "%9d", &std_d1);
  ck_assert_int_eq(my_res, std_res);
  if (my_res == 1 && std_res == 1) {
    ck_assert_int_eq(my_d1, std_d1);
  }
}
END_TEST

START_TEST(sscanf_i_specifiers_test) {
  int my_i1, std_i1, my_i2, std_i2;
  int my_res = my_sscanf(" -123 456 ", "%i%i", &my_i1, &my_i2);
  int std_res = sscanf(" -123 456 ", "%i%i", &std_i1, &std_i2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_i1, std_i1);
  ck_assert_int_eq(my_i2, std_i2);

  my_res = my_sscanf("012 077", "%i%i", &my_i1, &my_i2);
  std_res = sscanf("012 077", "%i%i", &std_i1, &std_i2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_i1, std_i1);
  ck_assert_int_eq(my_i2, std_i2);

  my_res = my_sscanf("0xFF 0x1A", "%i%i", &my_i1, &my_i2);
  std_res = sscanf("0xFF 0x1A", "%i%i", &std_i1, &std_i2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_i1, std_i1);
  ck_assert_int_eq(my_i2, std_i2);

  long int my_li, std_li;
  my_res = my_sscanf("0xFFFFFFFF", "%li", &my_li);
  std_res = sscanf("0xFFFFFFFF", "%li", &std_li);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_li, std_li);

  short int my_hi, std_hi;
  my_res = my_sscanf("0x7FFF", "%hi", &my_hi);
  std_res = sscanf("0x7FFF", "%hi", &std_hi);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_hi, std_hi);

  my_res = my_sscanf("100 0x200 300", "%i %*i %i", &my_i1, &my_i2);
  std_res = sscanf("100 0x200 300", "%i %*i %i", &std_i1, &std_i2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_i1, std_i1);
  ck_assert_int_eq(my_i2, std_i2);

  my_res = my_sscanf("0777 0x888 999", "%li %*i %i", &my_li, &my_i1);
  std_res = sscanf("0777 0x888 999", "%li %*i %i", &std_li, &std_i1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_li, std_li);
  ck_assert_int_eq(my_i1, std_i1);

  my_res = my_sscanf("050 0x60 070", "%hi %*i %hi", &my_hi, &my_hi);
  std_res = sscanf("050 0x60 070", "%hi %*i %hi", &std_hi, &std_hi);
  ck_assert_int_eq(my_res, std_res);

  my_res = my_sscanf("12345", "%3i", &my_i1);
  std_res = sscanf("12345", "%3i", &std_i1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_i1, std_i1);

  my_res = my_sscanf("07777", "%4li", &my_li);
  std_res = sscanf("07777", "%4li", &std_li);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_li, std_li);

  my_res = my_sscanf("0x123 456 0789", "%4i %*i %i", &my_i1, &my_i2);
  std_res = sscanf("0x123 456 0789", "%4i %*i %i", &std_i1, &std_i2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_i1, std_i1);
  ck_assert_int_eq(my_i2, std_i2);

  my_res = my_sscanf("-32768 0x7FFF", "%hi %hi", &my_hi, &my_hi);
  std_res = sscanf("-32768 0x7FFF", "%hi %hi", &std_hi, &std_hi);
  ck_assert_int_eq(my_res, std_res);

  my_res =
      my_sscanf("1 02 0x3 4 05", "%i %*i %*i %i %i", &my_i1, &my_i2, &my_i2);
  std_res =
      sscanf("1 02 0x3 4 05", "%i %*i %*i %i %i", &std_i1, &std_i2, &std_i2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_i1, std_i1);

  my_res = my_sscanf("10 012 0xA", "%i %i %i", &my_i1, &my_i2, &my_i1);
  std_res = sscanf("10 012 0xA", "%i %i %i", &std_i1, &std_i2, &std_i1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_i1, std_i1);
  ck_assert_int_eq(my_i2, std_i2);
  ck_assert_int_eq(my_i1, std_i1);

  int my_i_empty = 0, std_i_empty = 0;
  my_res = my_sscanf("", "%i", &my_i_empty);
  std_res = sscanf("", "%i", &std_i_empty);
  ck_assert_int_eq(my_res, std_res);

  long int my_li_empty = 0, std_li_empty = 0;
  my_res = my_sscanf("", "%li", &my_li_empty);
  std_res = sscanf("", "%li", &std_li_empty);
  ck_assert_int_eq(my_res, std_res);

  short int my_hi_empty = 0, std_hi_empty = 0;
  my_res = my_sscanf("", "%hi", &my_hi_empty);
  std_res = sscanf("", "%hi", &std_hi_empty);
  ck_assert_int_eq(my_res, std_res);

  int my_i_plus, std_i_plus;
  my_res = my_sscanf("+123", "%i", &my_i_plus);
  std_res = sscanf("+123", "%i", &std_i_plus);
  ck_assert_int_eq(my_res, std_res);
  if (my_res == 1 && std_res == 1) {
    ck_assert_int_eq(my_i_plus, std_i_plus);
  }

  long int my_li_plus, std_li_plus;
  my_res = my_sscanf("+456", "%li", &my_li_plus);
  std_res = sscanf("+456", "%li", &std_li_plus);
  ck_assert_int_eq(my_res, std_res);
  if (my_res == 1 && std_res == 1) {
    ck_assert_int_eq(my_li_plus, std_li_plus);
  }

  short int my_hi_plus, std_hi_plus;
  my_res = my_sscanf("+789", "%hi", &my_hi_plus);
  std_res = sscanf("+789", "%hi", &std_hi_plus);
  ck_assert_int_eq(my_res, std_res);
  if (my_res == 1 && std_res == 1) {
    ck_assert_int_eq(my_hi_plus, std_hi_plus);
  }

  int my_i_letters, std_i_letters;
  my_res = my_sscanf("abc", "%i", &my_i_letters);
  std_res = sscanf("abc", "%i", &std_i_letters);
  ck_assert_int_eq(my_res, std_res);

  short int my_hi_letters, std_hi_letters;
  my_res = my_sscanf("xyz", "%hi", &my_hi_letters);
  std_res = sscanf("xyz", "%hi", &std_hi_letters);
  ck_assert_int_eq(my_res, std_res);

  int my_i_invalid_prefix, std_i_invalid_prefix;
  my_res = my_sscanf("0xGHI", "%i", &my_i_invalid_prefix);
  std_res = sscanf("0xGHI", "%i", &std_i_invalid_prefix);
  ck_assert_int_eq(my_res, std_res);
  if (my_res == 1 && std_res == 1) {
    ck_assert_int_eq(my_i_invalid_prefix, std_i_invalid_prefix);
  }

  short int my_hi_invalid_prefix, std_hi_invalid_prefix;
  my_res = my_sscanf("0JKL", "%hi", &my_hi_invalid_prefix);
  std_res = sscanf("0JKL", "%hi", &std_hi_invalid_prefix);
  ck_assert_int_eq(my_res, std_res);
  if (my_res == 1 && std_res == 1) {
    ck_assert_int_eq(my_hi_invalid_prefix, std_hi_invalid_prefix);
  }

  int my_i_mixed, std_i_mixed;
  my_res = my_sscanf("123abc", "%i", &my_i_mixed);
  std_res = sscanf("123abc", "%i", &std_i_mixed);
  ck_assert_int_eq(my_res, std_res);
  if (my_res == 1 && std_res == 1) {
    ck_assert_int_eq(my_i_mixed, std_i_mixed);
  }

  short int my_hi_mixed, std_hi_mixed;
  my_res = my_sscanf("456xyz", "%hi", &my_hi_mixed);
  std_res = sscanf("456xyz", "%hi", &std_hi_mixed);
  ck_assert_int_eq(my_res, std_res);
  if (my_res == 1 && std_res == 1) {
    ck_assert_int_eq(my_hi_mixed, std_hi_mixed);
  }
}
END_TEST

START_TEST(sscanf_c_specifiers_test) {
  char my_c1, std_c1, my_c2, std_c2;
  int my_res = my_sscanf(" a b ", "%c%c", &my_c1, &my_c2);
  int std_res = sscanf(" a b ", "%c%c", &std_c1, &std_c2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_c1, std_c1);
  ck_assert_int_eq(my_c2, std_c2);

  my_res = my_sscanf("\n\t\x01", "%c%c", &my_c1, &my_c2);
  std_res = sscanf("\n\t\x01", "%c%c", &std_c1, &std_c2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_c1, std_c1);
  ck_assert_int_eq(my_c2, std_c2);

  my_res = my_sscanf("abc", "%c%*c%c", &my_c1, &my_c2);
  std_res = sscanf("abc", "%c%*c%c", &std_c1, &std_c2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_c1, std_c1);
  ck_assert_int_eq(my_c2, std_c2);

  my_res = my_sscanf("12345", "%c%*c%c", &my_c1, &my_c2);
  std_res = sscanf("12345", "%c%*c%c", &std_c1, &std_c2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_c1, std_c1);
  ck_assert_int_eq(my_c2, std_c2);

  my_res = my_sscanf("\0x", "%c", &my_c1);
  std_res = sscanf("\0x", "%c", &std_c1);
  ck_assert_int_eq(my_res, std_res);

  my_res = my_sscanf("123456", "%c%*c%*c%c", &my_c1, &my_c2);
  std_res = sscanf("123456", "%c%*c%*c%c", &std_c1, &std_c2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_c1, std_c1);
  ck_assert_int_eq(my_c2, std_c2);

  int my_i, std_i;
  my_res = my_sscanf("X 123 Y", "%c%d%c", &my_c1, &my_i, &my_c2);
  std_res = sscanf("X 123 Y", "%c%d%c", &std_c1, &std_i, &std_c2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_c1, std_c1);
  ck_assert_int_eq(my_i, std_i);
  ck_assert_int_eq(my_c2, std_c2);

  my_res = my_sscanf("   A", "%c", &my_c1);
  std_res = sscanf("   A", "%c", &std_c1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_c1, std_c1);

  my_res = my_sscanf("ñ", "%c", &my_c1);
  std_res = sscanf("ñ", "%c", &std_c1);
  ck_assert_int_eq(my_res, std_res);

  my_res = my_sscanf("X", "%c", &my_c1);
  std_res = sscanf("X", "%c", &std_c1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_c1, std_c1);
}
END_TEST

START_TEST(sscanf_s_specifiers_test) {
  char my_s1[100] = {0}, std_s1[100] = {0};
  char my_s2[100] = {0}, std_s2[100] = {0};
  int my_res = my_sscanf(" hello world ", "%s%s", my_s1, my_s2);
  int std_res = sscanf(" hello world ", "%s%s", std_s1, std_s2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_s1, std_s1);
  ck_assert_str_eq(my_s2, std_s2);

  my_res = my_sscanf("test1\ttest2\ntest3", "%s%s%s", my_s1, my_s2, my_s1);
  std_res = sscanf("test1\ttest2\ntest3", "%s%s%s", std_s1, std_s2, std_s1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_s1, std_s1);
  ck_assert_str_eq(my_s2, std_s2);

  wchar_t my_ws[100] = {0}, std_ws[100] = {0};
  my_res = my_sscanf("wide", "%ls", my_ws);
  std_res = sscanf("wide", "%ls", std_ws);
  ck_assert_int_eq(my_res, std_res);

  my_res = my_sscanf("first second third", "%s%*s%s", my_s1, my_s2);
  std_res = sscanf("first second third", "%s%*s%s", std_s1, std_s2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_s1, std_s1);
  ck_assert_str_eq(my_s2, std_s2);

  my_res = my_sscanf("one two three four", "%s%*s%s", my_s1, my_s2);
  std_res = sscanf("one two three four", "%s%*s%s", std_s1, std_s2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_s1, std_s1);
  ck_assert_str_eq(my_s2, std_s2);

  my_res = my_sscanf("abcdefgh", "%3s", my_s1);
  std_res = sscanf("abcdefgh", "%3s", std_s1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_s1, std_s1);

  my_res = my_sscanf("hello world test", "%4s%*s%s", my_s1, my_s2);
  std_res = sscanf("hello world test", "%4s%*s%s", std_s1, std_s2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_s1, std_s1);
  ck_assert_str_eq(my_s2, std_s2);

  my_res = my_sscanf("", "%s", my_s1);
  std_res = sscanf("", "%s", std_s1);
  ck_assert_int_eq(my_res, std_res);

  my_res = my_sscanf("a b c d e", "%s%*s%*s%s", my_s1, my_s2);
  std_res = sscanf("a b c d e", "%s%*s%*s%s", std_s1, std_s2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_s1, std_s1);
  ck_assert_str_eq(my_s2, std_s2);

  int my_i, std_i;
  my_res = my_sscanf("text 123 more", "%s%d%s", my_s1, &my_i, my_s2);
  std_res = sscanf("text 123 more", "%s%d%s", std_s1, &std_i, std_s2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_s1, std_s1);
  ck_assert_int_eq(my_i, std_i);
  ck_assert_str_eq(my_s2, std_s2);

  my_res = my_sscanf("   leading", "%s", my_s1);
  std_res = sscanf("   leading", "%s", std_s1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_s1, std_s1);

  my_res = my_sscanf("hello-world_test", "%s", my_s1);
  std_res = sscanf("hello-world_test", "%s", std_s1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_s1, std_s1);

  my_res = my_sscanf("123abc 456def", "%s%s", my_s1, my_s2);
  std_res = sscanf("123abc 456def", "%s%s", std_s1, std_s2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_s1, std_s1);
  ck_assert_str_eq(my_s2, std_s2);

  my_res = my_sscanf("short", "%10s", my_s1);
  std_res = sscanf("short", "%10s", std_s1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_s1, std_s1);

  my_res = my_sscanf("final", "%s", my_s1);
  std_res = sscanf("final", "%s", std_s1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_s1, std_s1);

  my_res = my_sscanf("line1\nline2", "%s%s", my_s1, my_s2);
  std_res = sscanf("line1\nline2", "%s%s", std_s1, std_s2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_s1, std_s1);
  ck_assert_str_eq(my_s2, std_s2);
}
END_TEST

START_TEST(sscanf_u_o_x_specifiers_test) {
  unsigned int my_u1, std_u1, my_u2, std_u2;
  int my_res = my_sscanf(" 123 456 ", "%u%u", &my_u1, &my_u2);
  int std_res = sscanf(" 123 456 ", "%u%u", &std_u1, &std_u2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_uint_eq(my_u1, std_u1);
  ck_assert_uint_eq(my_u2, std_u2);

  unsigned long int my_lu, std_lu;
  my_res = my_sscanf("4294967295", "%lu", &my_lu);
  std_res = sscanf("4294967295", "%lu", &std_lu);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_uint_eq(my_lu, std_lu);

  unsigned short int my_hu, std_hu;
  my_res = my_sscanf("655354563563", "%hu", &my_hu);
  std_res = sscanf("655354563563", "%hu", &std_hu);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_uint_eq(my_hu, std_hu);

  my_res = my_sscanf("100 200 300", "%u %*u %u", &my_u1, &my_u2);
  std_res = sscanf("100 200 300", "%u %*u %u", &std_u1, &std_u2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_uint_eq(my_u1, std_u1);
  ck_assert_uint_eq(my_u2, std_u2);

  unsigned int my_o1, std_o1, my_o2, std_o2;
  my_res = my_sscanf(" 123 456 ", "%o%o", &my_o1, &my_o2);
  std_res = sscanf(" 123 456 ", "%o%o", &std_o1, &std_o2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_uint_eq(my_o1, std_o1);
  ck_assert_uint_eq(my_o2, std_o2);

  unsigned long int my_lo, std_lo;
  my_res = my_sscanf("777", "%lo", &my_lo);
  std_res = sscanf("777", "%lo", &std_lo);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_uint_eq(my_lo, std_lo);

  my_res = my_sscanf("100 200 300", "%o %*o %o", &my_o1, &my_o2);
  std_res = sscanf("100 200 300", "%o %*o %o", &std_o1, &std_o2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_uint_eq(my_o1, std_o1);
  ck_assert_uint_eq(my_o2, std_o2);

  unsigned int my_x1, std_x1, my_x2, std_x2;
  my_res = my_sscanf(" FF 1A ", "%x%x", &my_x1, &my_x2);
  std_res = sscanf(" FF 1A ", "%x%x", &std_x1, &std_x2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_uint_eq(my_x1, std_x1);
  ck_assert_uint_eq(my_x2, std_x2);

  unsigned long int my_lx, std_lx;
  my_res = my_sscanf("FFFFFFFF", "%lx", &my_lx);
  std_res = sscanf("FFFFFFFF", "%lx", &std_lx);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_uint_eq(my_lx, std_lx);

  my_res = my_sscanf("A B C", "%x %*x %x", &my_x1, &my_x2);
  std_res = sscanf("A B C", "%x %*x %x", &std_x1, &std_x2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_uint_eq(my_x1, std_x1);
  ck_assert_uint_eq(my_x2, std_x2);

  my_res = my_sscanf("999 888 777", "%lu %*u %u", &my_lu, &my_u1);
  std_res = sscanf("999 888 777", "%lu %*u %u", &std_lu, &std_u1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_uint_eq(my_lu, std_lu);
  ck_assert_uint_eq(my_u1, std_u1);

  my_res = my_sscanf("50 60 70", "%hu %*u %hu", &my_hu, &my_hu);
  std_res = sscanf("50 60 70", "%hu %*u %hu", &std_hu, &std_hu);
  ck_assert_int_eq(my_res, std_res);

  my_res = my_sscanf("12345", "%3u", &my_u1);
  std_res = sscanf("12345", "%3u", &std_u1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_uint_eq(my_u1, std_u1);

  my_res = my_sscanf("12345", "%3o", &my_o1);
  std_res = sscanf("12345", "%3o", &std_o1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_uint_eq(my_o1, std_o1);

  my_res = my_sscanf("ABCDE", "%3x", &my_x1);
  std_res = sscanf("ABCDE", "%3x", &std_x1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_uint_eq(my_x1, std_x1);

  my_res = my_sscanf("12345 678", "%2u %*u %u", &my_u1, &my_u2);
  std_res = sscanf("12345 678", "%2u %*u %u", &std_u1, &std_u2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_uint_eq(my_u1, std_u1);
  ck_assert_uint_eq(my_u2, std_u2);

  my_res = my_sscanf("0 65535", "%hu %hu", &my_hu, &my_hu);
  std_res = sscanf("0 65535", "%hu %hu", &std_hu, &std_hu);
  ck_assert_int_eq(my_res, std_res);

  my_res = my_sscanf("1 2 3 4 5", "%u %*u %*u %u %u", &my_u1, &my_u2, &my_u2);
  std_res = sscanf("1 2 3 4 5", "%u %*u %*u %u %u", &std_u1, &std_u2, &std_u2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_uint_eq(my_u1, std_u1);

  my_res = my_sscanf("255 377 FF", "%u %o %x", &my_u1, &my_o1, &my_x1);
  std_res = sscanf("255 377 FF", "%u %o %x", &std_u1, &std_o1, &std_x1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_uint_eq(my_u1, std_u1);
  ck_assert_uint_eq(my_o1, std_o1);
  ck_assert_uint_eq(my_x1, std_x1);

  unsigned short int my_ho, std_ho;
  my_res = my_sscanf("777", "%ho", &my_ho);
  std_res = sscanf("777", "%ho", &std_ho);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_uint_eq(my_ho, std_ho);

  unsigned short int my_hx, std_hx;
  my_res = my_sscanf("FFFF", "%hx", &my_hx);
  std_res = sscanf("FFFF", "%hx", &std_hx);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_uint_eq(my_hx, std_hx);

  unsigned long int my_lu_empty = 0, std_lu_empty = 0;
  my_res = my_sscanf("", "%lu", &my_lu_empty);
  std_res = sscanf("", "%lu", &std_lu_empty);
  ck_assert_int_eq(my_res, std_res);

  unsigned long int my_lo_empty = 0, std_lo_empty = 0;
  my_res = my_sscanf("", "%lo", &my_lo_empty);
  std_res = sscanf("", "%lo", &std_lo_empty);
  ck_assert_int_eq(my_res, std_res);

  unsigned long int my_lx_empty = 0, std_lx_empty = 0;
  my_res = my_sscanf("", "%lx", &my_lx_empty);
  std_res = sscanf("", "%lx", &std_lx_empty);
  ck_assert_int_eq(my_res, std_res);

  unsigned int my_o_letters, std_o_letters;
  my_res = my_sscanf("abc", "%o", &my_o_letters);
  std_res = sscanf("abc", "%o", &std_o_letters);
  ck_assert_int_eq(my_res, std_res);

  unsigned short int my_ho_letters, std_ho_letters;
  my_res = my_sscanf("xyz", "%ho", &my_ho_letters);
  std_res = sscanf("xyz", "%ho", &std_ho_letters);
  ck_assert_int_eq(my_res, std_res);

  unsigned int my_u_letters, std_u_letters;
  my_res = my_sscanf("hello", "%u", &my_u_letters);
  std_res = sscanf("hello", "%u", &std_u_letters);
  ck_assert_int_eq(my_res, std_res);

  unsigned short int my_hu_letters, std_hu_letters;
  my_res = my_sscanf("world", "%hu", &my_hu_letters);
  std_res = sscanf("world", "%hu", &std_hu_letters);
  ck_assert_int_eq(my_res, std_res);

  unsigned int my_x_invalid, std_x_invalid;
  my_res = my_sscanf("GHI", "%x", &my_x_invalid);
  std_res = sscanf("GHI", "%x", &std_x_invalid);
  ck_assert_int_eq(my_res, std_res);

  unsigned short int my_hx_invalid, std_hx_invalid;
  my_res = my_sscanf("JKL", "%hx", &my_hx_invalid);
  std_res = sscanf("JKL", "%hx", &std_hx_invalid);
  ck_assert_int_eq(my_res, std_res);

  unsigned int my_mixed, std_mixed;
  my_res = my_sscanf("123abc", "%u", &my_mixed);
  std_res = sscanf("123abc", "%u", &std_mixed);
  ck_assert_int_eq(my_res, std_res);
  if (my_res == 1 && std_res == 1) {
    ck_assert_uint_eq(my_mixed, std_mixed);
  }

  unsigned int my_o_invalid, std_o_invalid;
  my_res = my_sscanf("89", "%o", &my_o_invalid);
  std_res = sscanf("89", "%o", &std_o_invalid);
  ck_assert_int_eq(my_res, std_res);
  if (my_res == 1 && std_res == 1) {
    ck_assert_uint_eq(my_o_invalid, std_o_invalid);
  }

  unsigned long int my_lu_limit, std_lu_limit;
  my_res = my_sscanf("123", "%10lu", &my_lu_limit);
  std_res = sscanf("123", "%10lu", &std_lu_limit);
  ck_assert_int_eq(my_res, std_res);
  if (my_res == 1 && std_res == 1) {
    ck_assert_uint_eq(my_lu_limit, std_lu_limit);
  }

  unsigned long int my_lo_limit, std_lo_limit;
  my_res = my_sscanf("77", "%5lo", &my_lo_limit);
  std_res = sscanf("77", "%5lo", &std_lo_limit);
  ck_assert_int_eq(my_res, std_res);
  if (my_res == 1 && std_res == 1) {
    ck_assert_uint_eq(my_lo_limit, std_lo_limit);
  }

  unsigned long int my_lx_limit, std_lx_limit;
  my_res = my_sscanf("ABC", "%8lx", &my_lx_limit);
  std_res = sscanf("ABC", "%8lx", &std_lx_limit);
  ck_assert_int_eq(my_res, std_res);
  if (my_res == 1 && std_res == 1) {
    ck_assert_uint_eq(my_lx_limit, std_lx_limit);
  }
}
END_TEST

START_TEST(sscanf_f_e_g_specifiers_test) {
  float my_f1, std_f1, my_f2, std_f2;
  int my_res = my_sscanf(" 123.456 789.012 ", "%f%f", &my_f1, &my_f2);
  int std_res = sscanf(" 123.456 789.012 ", "%f%f", &std_f1, &std_f2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_float_eq_tol(my_f1, std_f1, 1e-6);
  ck_assert_float_eq_tol(my_f2, std_f2, 1e-6);

  double my_lf1, std_lf1, my_lf2, std_lf2;
  my_res = my_sscanf("123.456 789.012", "%lf%lf", &my_lf1, &my_lf2);
  std_res = sscanf("123.456 789.012", "%lf%lf", &std_lf1, &std_lf2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_double_eq_tol(my_lf1, std_lf1, 1e-6);
  ck_assert_double_eq_tol(my_lf2, std_lf2, 1e-6);

  long double my_Lf1, std_Lf1, my_Lf2, std_Lf2;
  my_res = my_sscanf("123.456 789.012", "%Lf%Lf", &my_Lf1, &my_Lf2);
  std_res = sscanf("123.456 789.012", "%Lf%Lf", &std_Lf1, &std_Lf2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_ldouble_eq_tol(my_Lf1, std_Lf1, 1e-6);
  ck_assert_ldouble_eq_tol(my_Lf2, std_Lf2, 1e-6);

  my_res = my_sscanf("1.5 2.5 3.5", "%f %*f %f", &my_f1, &my_f2);
  std_res = sscanf("1.5 2.5 3.5", "%f %*f %f", &std_f1, &std_f2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_float_eq_tol(my_f1, std_f1, 1e-6);
  ck_assert_float_eq_tol(my_f2, std_f2, 1e-6);

  my_res = my_sscanf("1.23e4 5.67e-2", "%e%e", &my_f1, &my_f2);
  std_res = sscanf("1.23e4 5.67e-2", "%e%e", &std_f1, &std_f2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_float_eq_tol(my_f1, std_f1, 1e-6);
  ck_assert_float_eq_tol(my_f2, std_f2, 1e-6);

  my_res = my_sscanf("1.23e4 5.67e-2", "%le%le", &my_lf1, &my_lf2);
  std_res = sscanf("1.23e4 5.67e-2", "%le%le", &std_lf1, &std_lf2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_double_eq_tol(my_lf1, std_lf1, 1e-6);
  ck_assert_double_eq_tol(my_lf2, std_lf2, 1e-6);

  my_res = my_sscanf("1e1 2e2 3e3", "%e %*e %e", &my_f1, &my_f2);
  std_res = sscanf("1e1 2e2 3e3", "%e %*e %e", &std_f1, &std_f2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_float_eq_tol(my_f1, std_f1, 1e-6);
  ck_assert_float_eq_tol(my_f2, std_f2, 1e-6);

  my_res = my_sscanf("123.456 1.23e4", "%g%g", &my_f1, &my_f2);
  std_res = sscanf("123.456 1.23e4", "%g%g", &std_f1, &std_f2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_float_eq_tol(my_f1, std_f1, 1e-6);
  ck_assert_float_eq_tol(my_f2, std_f2, 1e-6);

  my_res = my_sscanf("123.456 1.23e4", "%lg%lg", &my_lf1, &my_lf2);
  std_res = sscanf("123.456 1.23e4", "%lg%lg", &std_lf1, &std_lf2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_double_eq_tol(my_lf1, std_lf1, 1e-6);
  ck_assert_double_eq_tol(my_lf2, std_lf2, 1e-6);

  my_res = my_sscanf("1.5 2.5 3.5", "%g %*g %g", &my_f1, &my_f2);
  std_res = sscanf("1.5 2.5 3.5", "%g %*g %g", &std_f1, &std_f2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_float_eq_tol(my_f1, std_f1, 1e-6);
  ck_assert_float_eq_tol(my_f2, std_f2, 1e-6);

  my_res = my_sscanf("1.23E4 5.67E-2", "%E%E", &my_f1, &my_f2);
  std_res = sscanf("1.23E4 5.67E-2", "%E%E", &std_f1, &std_f2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_float_eq_tol(my_f1, std_f1, 1e-6);
  ck_assert_float_eq_tol(my_f2, std_f2, 1e-6);

  my_res = my_sscanf("1.23E4 5.67E-2", "%lE%lE", &my_lf1, &my_lf2);
  std_res = sscanf("1.23E4 5.67E-2", "%lE%lE", &std_lf1, &std_lf2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_double_eq_tol(my_lf1, std_lf1, 1e-6);
  ck_assert_double_eq_tol(my_lf2, std_lf2, 1e-6);

  my_res = my_sscanf("123.456 1.23E4", "%G%G", &my_f1, &my_f2);
  std_res = sscanf("123.456 1.23E4", "%G%G", &std_f1, &std_f2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_float_eq_tol(my_f1, std_f1, 1e-6);
  ck_assert_float_eq_tol(my_f2, std_f2, 1e-6);

  my_res = my_sscanf("123.456 1.23E4", "%lG%lG", &my_lf1, &my_lf2);
  std_res = sscanf("123.456 1.23E4", "%lG%lG", &std_lf1, &std_lf2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_double_eq_tol(my_lf1, std_lf1, 1e-6);
  ck_assert_double_eq_tol(my_lf2, std_lf2, 1e-6);

  my_res = my_sscanf("9.99 8.88 7.77", "%lf %*f %f", &my_lf1, &my_f1);
  std_res = sscanf("9.99 8.88 7.77", "%lf %*f %f", &std_lf1, &std_f1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_double_eq_tol(my_lf1, std_lf1, 1e-6);
  ck_assert_float_eq_tol(my_f1, std_f1, 1e-6);

  my_res = my_sscanf("12.34567", "%4f", &my_f1);
  std_res = sscanf("12.34567", "%4f", &std_f1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_float_eq_tol(my_f1, std_f1, 1e-6);

  my_res = my_sscanf("1.23456e2", "%6e", &my_f1);
  std_res = sscanf("1.23456e2", "%6e", &std_f1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_float_eq_tol(my_f1, std_f1, 1e-6);

  my_res = my_sscanf("123.456 789.012", "%3f %*f %f", &my_f1, &my_f2);
  std_res = sscanf("123.456 789.012", "%3f %*f %f", &std_f1, &std_f2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_float_eq_tol(my_f1, std_f1, 1e-6);
  ck_assert_float_eq_tol(my_f2, std_f2, 1e-6);

  my_res = my_sscanf("-3.40282e+38 3.40282e+38", "%f%f", &my_f1, &my_f2);
  std_res = sscanf("-3.40282e+38 3.40282e+38", "%f%f", &std_f1, &std_f2);
  ck_assert_int_eq(my_res, std_res);

  my_res = my_sscanf("1.1 2.2 3.3 4.4 5.5", "%f %*f %*f %f %f", &my_f1, &my_f2,
                     &my_f2);
  std_res = sscanf("1.1 2.2 3.3 4.4 5.5", "%f %*f %*f %f %f", &std_f1, &std_f2,
                   &std_f2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_float_eq_tol(my_f1, std_f1, 1e-6);

  my_res =
      my_sscanf("123.456 1.23e2 987.654", "%f %e %g", &my_f1, &my_f2, &my_f1);
  std_res =
      sscanf("123.456 1.23e2 987.654", "%f %e %g", &std_f1, &std_f2, &std_f1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_float_eq_tol(my_f1, std_f1, 1e-6);
  ck_assert_float_eq_tol(my_f2, std_f2, 1e-6);
  ck_assert_float_eq_tol(my_f1, std_f1, 1e-6);

  my_res = my_sscanf("inf -inf nan", "%f%f%f", &my_f1, &my_f2, &my_f1);
  std_res = sscanf("inf -inf nan", "%f%f%f", &std_f1, &std_f2, &std_f1);
  ck_assert_int_eq(my_res, std_res);

  my_res = my_sscanf("", "%f", &my_f1);
  std_res = sscanf("", "%f", &std_f1);
  ck_assert_int_eq(my_res, std_res);

  long double my_Le = 0, std_Le = 0;
  my_res = my_sscanf("", "%Le", &my_Le);
  std_res = sscanf("", "%Le", &std_Le);
  ck_assert_int_eq(my_res, std_res);

  my_res = my_sscanf("inf", "%f", &my_f1);
  std_res = sscanf("inf", "%f", &std_f1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_float_eq(my_f1, std_f1);

  my_res = my_sscanf("infinity", "%f", &my_f1);
  std_res = sscanf("infinity", "%f", &std_f1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_float_eq(my_f1, std_f1);

  my_res = my_sscanf("INF", "%f", &my_f1);
  std_res = sscanf("INF", "%f", &std_f1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_float_eq(my_f1, std_f1);

  my_res = my_sscanf("INFINITY", "%f", &my_f1);
  std_res = sscanf("INFINITY", "%f", &std_f1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_float_eq(my_f1, std_f1);

  my_res = my_sscanf("-inf", "%f", &my_f1);
  std_res = sscanf("-inf", "%f", &std_f1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_float_eq(my_f1, std_f1);

  my_res = my_sscanf("nan", "%f", &my_f1);
  std_res = sscanf("nan", "%f", &std_f1);
  ck_assert_int_eq(my_res, std_res);

  ck_assert_int_eq(isnan(my_f1), isnan(std_f1));

  my_res = my_sscanf("NAN", "%f", &my_f1);
  std_res = sscanf("NAN", "%f", &std_f1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(isnan(my_f1), isnan(std_f1));

  my_res = my_sscanf("nan", "%e", &my_f1);
  std_res = sscanf("nan", "%e", &std_f1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(isnan(my_f1), isnan(std_f1));

  my_res = my_sscanf("inf", "%e", &my_f1);
  std_res = sscanf("inf", "%e", &std_f1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_float_eq(my_f1, std_f1);

  my_res = my_sscanf("nan", "%le", &my_lf1);
  std_res = sscanf("nan", "%le", &std_lf1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(isnan(my_lf1), isnan(std_lf1));

  my_res = my_sscanf("inf", "%le", &my_lf1);
  std_res = sscanf("inf", "%le", &std_lf1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_double_eq(my_lf1, std_lf1);

  unsigned my_hex1, std_hex1, my_hex2, std_hex2;
  my_res = my_sscanf("abc def", "%x%x", &my_hex1, &my_hex2);
  std_res = sscanf("abc def", "%x%x", &std_hex1, &std_hex2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_uint_eq(my_hex1, std_hex1);
  ck_assert_uint_eq(my_hex2, std_hex2);

  my_res = my_sscanf("1a2b3c deadbeef", "%x%x", &my_hex1, &my_hex2);
  std_res = sscanf("1a2b3c deadbeef", "%x%x", &std_hex1, &std_hex2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_uint_eq(my_hex1, std_hex1);
  ck_assert_uint_eq(my_hex2, std_hex2);

  unsigned long my_lhex, std_lhex;
  my_res = my_sscanf("abcdef123456", "%lx", &my_lhex);
  std_res = sscanf("abcdef123456", "%lx", &std_lhex);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_uint_eq(my_lhex, std_lhex);

  unsigned short my_hhex, std_hhex;
  my_res = my_sscanf("abc", "%hx", &my_hhex);
  std_res = sscanf("abc", "%hx", &std_hhex);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_uint_eq(my_hhex, std_hhex);

  my_res = my_sscanf("0xabc 0xdef", "%x%x", &my_hex1, &my_hex2);
  std_res = sscanf("0xabc 0xdef", "%x%x", &std_hex1, &std_hex2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_uint_eq(my_hex1, std_hex1);
  ck_assert_uint_eq(my_hex2, std_hex2);

  double my_le_empty = 0, std_le_empty = 0;
  my_res = my_sscanf("", "%le", &my_le_empty);
  std_res = sscanf("", "%le", &std_le_empty);
  ck_assert_int_eq(my_res, std_res);

  float my_e_empty = 0, std_e_empty = 0;
  my_res = my_sscanf("", "%e", &my_e_empty);
  std_res = sscanf("", "%e", &std_e_empty);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(sscanf_p_n_percent_test) {
  void *my_p1, *std_p1, *my_p2, *std_p2;
  int my_res = my_sscanf("0x1234 0xabcd", "%p%p", &my_p1, &my_p2);
  int std_res = sscanf("0x1234 0xabcd", "%p%p", &std_p1, &std_p2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_ptr_eq(my_p1, std_p1);
  ck_assert_ptr_eq(my_p2, std_p2);

  my_res = my_sscanf("0x100 0x200 0x300", "%p %*p %p", &my_p1, &my_p2);
  std_res = sscanf("0x100 0x200 0x300", "%p %*p %p", &std_p1, &std_p2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_ptr_eq(my_p1, std_p1);
  ck_assert_ptr_eq(my_p2, std_p2);

  int my_n1 = 0, std_n1 = 0, my_n2 = 0, std_n2 = 0;
  my_res = my_sscanf("test string", "test%n string%n", &my_n1, &my_n2);
  std_res = sscanf("test string", "test%n string%n", &std_n1, &std_n2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_n1, std_n1);
  ck_assert_int_eq(my_n2, std_n2);

  int my_val, std_val;
  my_res = my_sscanf("12345", "%d%n", &my_val, &my_n1);
  std_res = sscanf("12345", "%d%n", &std_val, &std_n1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_val, std_val);
  ck_assert_int_eq(my_n1, std_n1);

  my_res = my_sscanf("hello 123 world", "hello %*d world%n", &my_n1);
  std_res = sscanf("hello 123 world", "hello %*d world%n", &std_n1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_n1, std_n1);

  char my_c1, std_c1, my_c2, std_c2;
  my_res = my_sscanf("%% hello", "%%%c", &my_c1);
  std_res = sscanf("%% hello", "%%%c", &std_c1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_c1, std_c1);

  char my_str1[100] = {0}, std_str1[100] = {0};
  my_res = my_sscanf("100% complete", "%d%% %s", &my_val, my_str1);
  std_res = sscanf("100% complete", "%d%% %s", &std_val, std_str1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_val, std_val);
  ck_assert_str_eq(my_str1, std_str1);

  my_res = my_sscanf("test data", "test data%n", &my_n1);
  std_res = sscanf("test data", "test data%n", &std_n1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_n1, std_n1);

  my_res = my_sscanf("0x1234 pointer", "%p%n", &my_p1, &my_n1);
  std_res = sscanf("0x1234 pointer", "%p%n", &std_p1, &std_n1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_ptr_eq(my_p1, std_p1);
  ck_assert_int_eq(my_n1, std_n1);

  my_res = my_sscanf("% value", "%%%n", &my_n1);
  std_res = sscanf("% value", "%%%n", &std_n1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_n1, std_n1);

  my_res = my_sscanf("0x12345678", "%4p", &my_p1);
  std_res = sscanf("0x12345678", "%4p", &std_p1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_ptr_eq(my_p1, std_p1);

  my_res = my_sscanf("0x1111 0x2222 0x3333", "%3p %*p %p", &my_p1, &my_p2);
  std_res = sscanf("0x1111 0x2222 0x3333", "%3p %*p %p", &std_p1, &std_p2);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_ptr_eq(my_p1, std_p1);
  ck_assert_ptr_eq(my_p2, std_p2);

  my_res = my_sscanf("", "%n", &my_n1);
  std_res = sscanf("", "%n", &std_n1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_n1, std_n1);

  my_res = my_sscanf("a b c d e", "%c%n%c%n%c", &my_c1, &my_n1, &my_c2, &my_n2,
                     &my_c1);
  std_res = sscanf("a b c d e", "%c%n%c%n%c", &std_c1, &std_n1, &std_c2,
                   &std_n2, &std_c1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_n1, std_n1);
  ck_assert_int_eq(my_n2, std_n2);

  int my_i, std_i;
  my_res = my_sscanf("Value: 123 at 0x100 50%", "Value: %d at %p %d%%", &my_i,
                     &my_p1, &my_val);
  std_res = sscanf("Value: 123 at 0x100 50%", "Value: %d at %p %d%%", &std_i,
                   &std_p1, &std_val);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_i, std_i);
  ck_assert_ptr_eq(my_p1, std_p1);
  ck_assert_int_eq(my_val, std_val);

  my_res = my_sscanf("%%", "%%%%");
  std_res = sscanf("%%", "%%%%");
  ck_assert_int_eq(my_res, std_res);

  my_res = my_sscanf("end", "end%n", &my_n1);
  std_res = sscanf("end", "end%n", &std_n1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_n1, std_n1);

  my_res = my_sscanf("123 test 456", "%d%n test %d", &my_i, &my_n1, &my_val);
  std_res = sscanf("123 test 456", "%d%n test %d", &std_i, &std_n1, &std_val);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_i, std_i);
  ck_assert_int_eq(my_n1, std_n1);
  ck_assert_int_eq(my_val, std_val);

  void* my_p3 = NULL;
  void* my_p4 = NULL;
  void* std_p3 = NULL;
  void* std_p4 = NULL;

  my_res = my_sscanf("0XABCD 0XEF12", "%p%p", &my_p3, &my_p4);
  std_res = sscanf("0XABCD 0XEF12", "%p%p", &std_p3, &std_p4);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_ptr_eq(my_p3, std_p3);
  ck_assert_ptr_eq(my_p4, std_p4);

  void *my_p_empty = NULL, *std_p_empty = NULL;
  my_res = my_sscanf("", "%p", &my_p_empty);
  std_res = sscanf("", "%p", &std_p_empty);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(sscanf_scanset_test) {
  char my_str1[20] = {0}, std_str1[20] = {0};
  int my_res = my_sscanf("hello world", "%[a-z]", my_str1);
  int std_res = sscanf("hello world", "%[a-z]", std_str1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_str1, std_str1);

  char my_str3[20] = {0}, std_str3[20] = {0};
  my_res = my_sscanf("ABC123", "%[A-Z]", my_str3);
  std_res = sscanf("ABC123", "%[A-Z]", std_str3);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_str3, std_str3);

  char my_str4[20] = {0}, std_str4[20] = {0};
  my_res = my_sscanf("test123", "%[a-z0-9]", my_str4);
  std_res = sscanf("test123", "%[a-z0-9]", std_str4);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_str4, std_str4);

  char my_str5[10] = {0}, std_str5[10] = {0};
  my_res = my_sscanf("abcdefghij", "%5[a-z]", my_str5);
  std_res = sscanf("abcdefghij", "%5[a-z]", std_str5);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_str5, std_str5);

  char my_str6[20] = {0}, std_str6[20] = {0};
  my_res = my_sscanf("skip123data", "%*[a-z]%[0-9]", my_str6);
  std_res = sscanf("skip123data", "%*[a-z]%[0-9]", std_str6);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_str6, std_str6);

  char my_str7[20] = {0}, std_str7[20] = {0};
  my_res = my_sscanf("  hello world", "%[ a-z]", my_str7);
  std_res = sscanf("  hello world", "%[ a-z]", std_str7);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_str7, std_str7);

  char my_str8[20] = {0}, std_str8[20] = {0};
  my_res = my_sscanf("a-b-c123", "%[a-c-]", my_str8);
  std_res = sscanf("a-b-c123", "%[a-c-]", std_str8);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_str8, std_str8);

  char my_str9[20] = {0}, std_str9[20] = {0};
  my_res = my_sscanf("", "%[a-z]", my_str9);
  std_res = sscanf("", "%[a-z]", std_str9);
  ck_assert_int_eq(my_res, std_res);

  char my_str10[20] = {0}, std_str10[20] = {0};
  my_res = my_sscanf("123", "%[a-z]", my_str10);
  std_res = sscanf("123", "%[a-z]", std_str10);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_str10, std_str10);
}
END_TEST

START_TEST(sscanf_error_cases_test) {
  int my_res = my_sscanf("abc", "xyz");
  int std_res = sscanf("abc", "xyz");
  ck_assert_int_eq(my_res, std_res);

  my_res = my_sscanf("abc", "abx");
  std_res = sscanf("abc", "abx");
  ck_assert_int_eq(my_res, std_res);

  int my_val = 0, std_val = 0;
  my_res = my_sscanf("", "%d", &my_val);
  std_res = sscanf("", "%d", &std_val);
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(sscanf_whitespace_handling_test) {
  char my_str1[20] = {0}, std_str1[20] = {0};
  int my_res = my_sscanf("  \t\n  hello", "%s", my_str1);
  int std_res = sscanf("  \t\n  hello", "%s", std_str1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_str1, std_str1);

  int my_a = 0, std_a = 0, my_b = 0, std_b = 0;
  my_res = my_sscanf("123 456", "%d %d", &my_a, &my_b);
  std_res = sscanf("123 456", "%d %d", &std_a, &std_b);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_a, std_a);
  ck_assert_int_eq(my_b, std_b);

  my_res = my_sscanf("\t123\n456", "%d%d", &my_a, &my_b);
  std_res = sscanf("\t123\n456", "%d%d", &std_a, &std_b);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_int_eq(my_a, std_a);
  ck_assert_int_eq(my_b, std_b);
}
END_TEST

START_TEST(sscanf_edge_cases_test) {
  int my_val = 0, std_val = 0;
  int my_res = my_sscanf("", "%d", &my_val);
  int std_res = sscanf("", "%d", &std_val);
  ck_assert_int_eq(my_res, std_res);

  int my_num = 0, std_num = 0;
  my_res = my_sscanf("abc123", "abc%d", &my_num);
  std_res = sscanf("abc123", "abc%d", &std_num);
  ck_assert_int_eq(my_res, std_res);
  if (my_res > 0 && std_res > 0) {
    ck_assert_int_eq(my_num, std_num);
  }

  my_res = my_sscanf("hello", "hello");
  std_res = sscanf("hello", "hello");
  ck_assert_int_eq(my_res, std_res);
}
END_TEST

START_TEST(sscanf_invalid_formats_test) {
  char buffer[20];
  int val;

  int my_res = my_sscanf("hello", "%[a-z", buffer);
  (void)my_res;

  my_res = my_sscanf("123", "%k", &val);
  (void)my_res;

  my_res = my_sscanf("123", my_NULL);
  (void)my_res;
}
END_TEST

START_TEST(test_char_specifier) {
  char canon_buffer[BUFFER_SIZE], test_buf[BUFFER_SIZE];
  char ch = 'A';

  sprintf(canon_buffer, "%c", ch);
  my_sprintf(test_buf, "%c", ch);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%5c", ch);
  my_sprintf(test_buf, "%5c", ch);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%-5c", ch);
  my_sprintf(test_buf, "%-5c", ch);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%c", '\n');
  my_sprintf(test_buf, "%c", '\n');
  ck_assert_str_eq(canon_buffer, test_buf);
}
END_TEST

START_TEST(test_decimal_specifiers) {
  char canon_buffer[BUFFER_SIZE], test_buf[BUFFER_SIZE];
  int num = 12345;
  int negative = -12345;

  sprintf(canon_buffer, "%d", num);
  my_sprintf(test_buf, "%d", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%i", num);
  my_sprintf(test_buf, "%i", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%d", negative);
  my_sprintf(test_buf, "%d", negative);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%10d", num);
  my_sprintf(test_buf, "%10d", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%-10d", num);
  my_sprintf(test_buf, "%-10d", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%010d", num);
  my_sprintf(test_buf, "%010d", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%+d", num);
  my_sprintf(test_buf, "%+d", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "% d", num);
  my_sprintf(test_buf, "% d", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%d", INT_MAX);
  my_sprintf(test_buf, "%d", INT_MAX);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%d", INT_MIN);
  my_sprintf(test_buf, "%d", INT_MIN);
  ck_assert_str_eq(canon_buffer, test_buf);
}
END_TEST

START_TEST(test_scientific_notation) {
  char canon_buffer[BUFFER_SIZE], test_buf[BUFFER_SIZE];
  double num = 123.456;

  sprintf(canon_buffer, "%e", num);
  my_sprintf(test_buf, "%e", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%E", num);
  my_sprintf(test_buf, "%E", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%.2e", num);
  my_sprintf(test_buf, "%.2e", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%15e", num);
  my_sprintf(test_buf, "%15e", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%e", -num);
  my_sprintf(test_buf, "%e", -num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%-15e", num);
  my_sprintf(test_buf, "%-15e", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%30e", num);
  my_sprintf(test_buf, "%30e", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%-30e", num);
  my_sprintf(test_buf, "%-30e", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%20.10e", num);
  my_sprintf(test_buf, "%20.10e", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%-20.10e", num);
  my_sprintf(test_buf, "%-20.10e", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%e", 0.0);
  my_sprintf(test_buf, "%e", 0.0);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%e", 0.000000123);
  my_sprintf(test_buf, "%e", 0.000000123);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%e", 1234567.0);
  my_sprintf(test_buf, "%e", 1234567.0);
  ck_assert_str_eq(canon_buffer, test_buf);
}
END_TEST

START_TEST(test_float_specifier) {
  char canon_buffer[BUFFER_SIZE], test_buf[BUFFER_SIZE];
  double num = 123.456;

  sprintf(canon_buffer, "%f", num);
  my_sprintf(test_buf, "%f", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%.2f", num);
  my_sprintf(test_buf, "%.2f", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%10.2f", num);
  my_sprintf(test_buf, "%10.2f", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%-10.2f", num);
  my_sprintf(test_buf, "%-10.2f", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%010.2f", num);
  my_sprintf(test_buf, "%010.2f", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%+f", num);
  my_sprintf(test_buf, "%+f", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%f", -num);
  my_sprintf(test_buf, "%f", -num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%f", 0.0);
  my_sprintf(test_buf, "%f", 0.0);
  ck_assert_str_eq(canon_buffer, test_buf);
}
END_TEST

START_TEST(test_shortest_float) {
  char canon_buffer[BUFFER_SIZE], test_buf[BUFFER_SIZE];
  double num = 123.456;

  sprintf(canon_buffer, "%g", num);
  my_sprintf(test_buf, "%g", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%G", num);
  my_sprintf(test_buf, "%G", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  num = 0.0 / 0.0;
  sprintf(canon_buffer, "%g", num);
  my_sprintf(test_buf, "%g", num);
  ck_assert(strstr(canon_buffer, "nan") != NULL ||
            strstr(canon_buffer, "NAN") != NULL);

  sprintf(canon_buffer, "%G", num);
  my_sprintf(test_buf, "%G", num);
  ck_assert(strstr(canon_buffer, "NAN") != NULL);

  num = 1.0 / 0.0;
  sprintf(canon_buffer, "%g", num);
  my_sprintf(test_buf, "%g", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%G", num);
  my_sprintf(test_buf, "%G", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  num = -1.0 / 0.0;
  sprintf(canon_buffer, "%g", num);
  my_sprintf(test_buf, "%g", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  num = 0.0000123;
  sprintf(canon_buffer, "%g", num);
  my_sprintf(test_buf, "%g", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  num = 0.0000999;
  sprintf(canon_buffer, "%g", num);
  my_sprintf(test_buf, "%g", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  num = 1234567.89;
  sprintf(canon_buffer, "%.3g", num);
  my_sprintf(test_buf, "%.3g", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  num = -123.456;
  sprintf(canon_buffer, "%g", num);
  my_sprintf(test_buf, "%g", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  num = 123.456;
  sprintf(canon_buffer, "%+g", num);
  my_sprintf(test_buf, "%+g", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "% g", num);
  my_sprintf(test_buf, "% g", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%10g", num);
  my_sprintf(test_buf, "%10g", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%-10g", num);
  my_sprintf(test_buf, "%-10g", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%g", 0.0);
  my_sprintf(test_buf, "%g", 0.0);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%g", 1.0);
  my_sprintf(test_buf, "%g", 1.0);
  ck_assert_str_eq(canon_buffer, test_buf);

  num = 0.001;
  sprintf(canon_buffer, "%g", num);
  my_sprintf(test_buf, "%g", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  num = 999999.0;
  sprintf(canon_buffer, "%g", num);
  my_sprintf(test_buf, "%g", num);
  ck_assert_str_eq(canon_buffer, test_buf);
}
END_TEST

START_TEST(test_octal_specifier) {
  char canon_buffer[BUFFER_SIZE], test_buf[BUFFER_SIZE];
  unsigned int num = 12345;

  sprintf(canon_buffer, "%o", num);
  my_sprintf(test_buf, "%o", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%10o", num);
  my_sprintf(test_buf, "%10o", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%#o", num);
  my_sprintf(test_buf, "%#o", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%o", 0);
  my_sprintf(test_buf, "%o", 0);
  ck_assert_str_eq(canon_buffer, test_buf);
}
END_TEST

START_TEST(test_string_specifier) {
  char canon_buffer[BUFFER_SIZE], test_buf[BUFFER_SIZE];
  char* test_string = "Hello World";

  sprintf(canon_buffer, "Hello, World!");
  my_sprintf(test_buf, "Hello, World!");
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%s", test_string);
  my_sprintf(test_buf, "%s", test_string);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%15s", test_string);
  my_sprintf(test_buf, "%15s", test_string);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%-15s", test_string);
  my_sprintf(test_buf, "%-15s", test_string);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%.5s", test_string);
  my_sprintf(test_buf, "%.5s", test_string);
  ck_assert_str_eq(canon_buffer, test_buf);
}
END_TEST

START_TEST(test_unsigned_specifier) {
  char canon_buffer[BUFFER_SIZE], test_buf[BUFFER_SIZE];
  unsigned int num = 12345;

  sprintf(canon_buffer, "%u", num);
  my_sprintf(test_buf, "%u", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%10u", num);
  my_sprintf(test_buf, "%10u", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%-10u", num);
  my_sprintf(test_buf, "%-10u", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%010u", num);
  my_sprintf(test_buf, "%010u", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%u", UINT_MAX);
  my_sprintf(test_buf, "%u", UINT_MAX);
  ck_assert_str_eq(canon_buffer, test_buf);
}
END_TEST

START_TEST(test_hexadecimal_specifiers) {
  char canon_buffer[BUFFER_SIZE], test_buf[BUFFER_SIZE];
  unsigned int num = 255;

  sprintf(canon_buffer, "%x", num);
  my_sprintf(test_buf, "%x", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%X", num);
  my_sprintf(test_buf, "%X", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%10x", num);
  my_sprintf(test_buf, "%10x", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%#x", num);
  my_sprintf(test_buf, "%#x", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%#X", num);
  my_sprintf(test_buf, "%#X", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%x", 0);
  my_sprintf(test_buf, "%x", 0);
  ck_assert_str_eq(canon_buffer, test_buf);
}
END_TEST

START_TEST(test_pointer_specifier) {
  char canon_buffer[BUFFER_SIZE], test_buf[BUFFER_SIZE];
  int num = 42;
  void* ptr;

  ptr = NULL;
  sprintf(canon_buffer, "%p", ptr);
  my_sprintf(test_buf, "%p", ptr);
  ck_assert_str_eq(canon_buffer, test_buf);

  ptr = &num;
  sprintf(canon_buffer, "%p", ptr);
  my_sprintf(test_buf, "%p", ptr);
  ck_assert_str_eq(canon_buffer, test_buf);

  ptr = NULL;
  sprintf(canon_buffer, "%10p", ptr);
  my_sprintf(test_buf, "%10p", ptr);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%-10p", ptr);
  my_sprintf(test_buf, "%-10p", ptr);
  ck_assert_str_eq(canon_buffer, test_buf);

  ptr = &num;
  sprintf(canon_buffer, "%15p", ptr);
  my_sprintf(test_buf, "%15p", ptr);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%-15p", ptr);
  my_sprintf(test_buf, "%-15p", ptr);
  ck_assert_str_eq(canon_buffer, test_buf);

  char str[] = "test";
  ptr = str;
  sprintf(canon_buffer, "%p", ptr);
  my_sprintf(test_buf, "%p", ptr);
  ck_assert_str_eq(canon_buffer, test_buf);

  int arr[5] = {1, 2, 3, 4, 5};
  ptr = arr;
  sprintf(canon_buffer, "%p", ptr);
  my_sprintf(test_buf, "%p", ptr);
  ck_assert_str_eq(canon_buffer, test_buf);

  ptr = &num;
  sprintf(canon_buffer, "Pointer: %p", ptr);
  my_sprintf(test_buf, "Pointer: %p", ptr);
  ck_assert_str_eq(canon_buffer, test_buf);

  ptr = NULL;
  sprintf(canon_buffer, "Ptr is %p here", ptr);
  my_sprintf(test_buf, "Ptr is %p here", ptr);
  ck_assert_str_eq(canon_buffer, test_buf);
}
END_TEST

START_TEST(test_percent_specifier) {
  char canon_buffer[BUFFER_SIZE], test_buf[BUFFER_SIZE];

  sprintf(canon_buffer, "%%");
  my_sprintf(test_buf, "%%");
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%5c", '%');
  my_sprintf(test_buf, "%5c", '%');
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%10c", '%');
  my_sprintf(test_buf, "%10c", '%');
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%-5c", '%');
  my_sprintf(test_buf, "%-5c", '%');
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%-10c", '%');
  my_sprintf(test_buf, "%-10c", '%');
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "Hello%%World");
  my_sprintf(test_buf, "Hello%%World");
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "Test %5c end", '%');
  my_sprintf(test_buf, "Test %5c end", '%');
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%%%%");
  my_sprintf(test_buf, "%%%%");
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%% %%");
  my_sprintf(test_buf, "%% %%");
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%%");
  my_sprintf(test_buf, "%%");
  ck_assert_str_eq(canon_buffer, test_buf);
}
END_TEST

START_TEST(test_float_special_cases) {
  char canon_buffer[BUFFER_SIZE], test_buf[BUFFER_SIZE];
  double num;

  num = 0.0 / 0.0;
  sprintf(canon_buffer, "%e", num);
  my_sprintf(test_buf, "%e", num);
  ck_assert(strstr(canon_buffer, "nan") != NULL);

  sprintf(canon_buffer, "%E", num);
  my_sprintf(test_buf, "%E", num);
  ck_assert(strstr(canon_buffer, "NAN") != NULL);

  sprintf(canon_buffer, "%g", num);
  my_sprintf(test_buf, "%g", num);
  ck_assert(strstr(canon_buffer, "nan") != NULL);

  sprintf(canon_buffer, "%G", num);
  my_sprintf(test_buf, "%G", num);
  ck_assert(strstr(canon_buffer, "NAN") != NULL);

  num = 1.0 / 0.0;
  sprintf(canon_buffer, "%e", num);
  my_sprintf(test_buf, "%e", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%E", num);
  my_sprintf(test_buf, "%E", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%f", num);
  my_sprintf(test_buf, "%f", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%g", num);
  my_sprintf(test_buf, "%g", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  num = -1.0 / 0.0;
  sprintf(canon_buffer, "%e", num);
  my_sprintf(test_buf, "%e", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%E", num);
  my_sprintf(test_buf, "%E", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%f", num);
  my_sprintf(test_buf, "%f", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%g", num);
  my_sprintf(test_buf, "%g", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  num = 0.0 / 0.0;
  sprintf(canon_buffer, "%10e", num);
  my_sprintf(test_buf, "%10e", num);
  ck_assert_int_eq(strlen(canon_buffer), strlen(test_buf));

  num = 1.0 / 0.0;
  sprintf(canon_buffer, "%-10E", num);
  my_sprintf(test_buf, "%-10E", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  num = -1.0 / 0.0;
  sprintf(canon_buffer, "%.2f", num);
  my_sprintf(test_buf, "%.2f", num);
  ck_assert_str_eq(canon_buffer, test_buf);

  sprintf(canon_buffer, "%.2g", num);
  my_sprintf(test_buf, "%.2g", num);
  ck_assert_str_eq(canon_buffer, test_buf);
}
END_TEST

Suite* suite_sscanf(void) {
  Suite* s = suite_create("my_sscanf");
  TCase* tc_core = tcase_create("Core");
  tcase_add_test(tc_core, sscanf_d_specifiers_test);
  tcase_add_test(tc_core, sscanf_i_specifiers_test);
  tcase_add_test(tc_core, sscanf_c_specifiers_test);
  tcase_add_test(tc_core, sscanf_s_specifiers_test);
  tcase_add_test(tc_core, sscanf_u_o_x_specifiers_test);
  tcase_add_test(tc_core, sscanf_f_e_g_specifiers_test);
  tcase_add_test(tc_core, sscanf_p_n_percent_test);
  tcase_add_test(tc_core, sscanf_scanset_test);
  tcase_add_test(tc_core, sscanf_error_cases_test);
  tcase_add_test(tc_core, sscanf_whitespace_handling_test);
  tcase_add_test(tc_core, sscanf_edge_cases_test);
  tcase_add_test(tc_core, sscanf_invalid_formats_test);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite* my_sprintf_test_suite(void) {
  Suite* spr;
  TCase* sprintf_core;

  spr = suite_create("my_sprintf");

  sprintf_core = tcase_create("Core");

  tcase_add_test(sprintf_core, test_char_specifier);
  tcase_add_test(sprintf_core, test_decimal_specifiers);
  tcase_add_test(sprintf_core, test_scientific_notation);
  tcase_add_test(sprintf_core, test_float_specifier);
  tcase_add_test(sprintf_core, test_shortest_float);
  tcase_add_test(sprintf_core, test_octal_specifier);
  tcase_add_test(sprintf_core, test_string_specifier);
  tcase_add_test(sprintf_core, test_unsigned_specifier);
  tcase_add_test(sprintf_core, test_hexadecimal_specifiers);
  tcase_add_test(sprintf_core, test_pointer_specifier);
  tcase_add_test(sprintf_core, test_percent_specifier);
  tcase_add_test(sprintf_core, test_float_special_cases);

  suite_add_tcase(spr, sprintf_core);

  return spr;
}

int main(void) {
  Suite* (*suite_functions[])(void) = {
      suite_memchr,   suite_memcmp,   suite_memcpy,  suite_memset,
      suite_strncat,  suite_strchr,   suite_strncmp, suite_strncpy,
      suite_strcspn,  suite_strerror, suite_strlen,  suite_strpbrk,
      suite_strrchr,  suite_strstr,   suite_strtok,  suite_to_upper,
      suite_to_lower, suite_insert,   suite_trim,

      suite_sscanf};

  int failed_count = 0;

  for (size_t i = 0; i < sizeof(suite_functions) / sizeof(suite_functions[0]);
       i++) {
    SRunner* sr = srunner_create(suite_functions[i]());
    srunner_run_all(sr, CK_NORMAL);
    failed_count += srunner_ntests_failed(sr);
    srunner_free(sr);
  }

  int number_failed = 0;
  Suite* spr;
  SRunner* sprnt;

  spr = my_sprintf_test_suite();
  sprnt = srunner_create(spr);

  srunner_run_all(sprnt, CK_NORMAL);
  number_failed = srunner_ntests_failed(sprnt) + failed_count;
  srunner_free(sprnt);

  return (number_failed == 0) ? 0 : 1;
}
