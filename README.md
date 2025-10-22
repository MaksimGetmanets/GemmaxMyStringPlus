Теперь у меня есть полная картина проекта! Я получил все файлы: `Makefile`, `my_string.h`, `my_string.c` и `my_test.c`. Создам финальную версию README.

---

## **README.md**

# Библиотека My_String / My_String Library

## Описание / Description

Это проект на языке C, реализующий собственную библиотеку для работы со строками `my_string.h`, а также функции `sprintf` и `sscanf`. Библиотека предоставляет аналоги стандартных функций языка C для работы со строками и памятью, с дополнительными возможностями.

This is a C language project implementing a custom string library `my_string.h`, along with `sprintf` and `sscanf` functions. The library provides analogs of standard C string and memory functions with additional capabilities.

## Основные возможности / Key Features

### Стандартные функции string.h / Standard string.h Functions
- **my_memchr** - поиск символа в блоке памяти / search for character in memory block
- **my_memcmp** - сравнение блоков памяти / compare memory blocks  
- **my_memcpy** - копирование блока памяти / copy memory block
- **my_memset** - заполнение блока памяти / fill memory block
- **my_strlen** - вычисление длины строки / calculate string length
- **my_strncat** - конкатенация строк / concatenate strings
- **my_strncmp** - сравнение строк / compare strings
- **my_strncpy** - копирование строк / copy strings
- **my_strchr** - поиск первого вхождения символа / search for first character occurrence
- **my_strrchr** - поиск последнего вхождения символа / search for last character occurrence
- **my_strpbrk** - поиск любого символа из набора / search for any character from set
- **my_strstr** - поиск подстроки / search for substring
- **my_strtok** - разбиение строки на токены / split string into tokens
- **my_strerror** - получение текста ошибки по коду / get error message by code (Linux/macOS support)
- **my_strcspn** - поиск первого вхождения любого символа не из набора / search for first character not in set

### Дополнительные функции / Additional Functions
- **my_to_upper** - преобразование строки в верхний регистр / convert string to uppercase
- **my_to_lower** - преобразование строки в нижний регистр / convert string to lowercase  
- **my_insert** - вставка строки в указанную позицию / insert string at specified position
- **my_trim** - удаление указанных символов с начала и конца строки / trim characters from start and end of string

### Функции форматированного ввода/вывода / Formatted I/O Functions
- **my_sprintf** - форматированный вывод в строку / formatted output to string
- **my_sscanf** - форматированный ввод из строки / formatted input from string

## Поддерживаемые спецификаторы форматирования / Supported Format Specifiers

### Для my_sprintf:
- `%c` - символ / character
- `%d`, `%i` - целое число / integer
- `%f` - число с плавающей точкой / floating point number
- `%e`, `%E` - научная нотация / scientific notation
- `%g`, `%G` - компактная запись чисел / compact number representation
- `%o` - восьмеричное число / octal number
- `%s` - строка / string
- `%u` - беззнаковое целое / unsigned integer
- `%x`, `%X` - шестнадцатеричное число / hexadecimal number
- `%p` - указатель / pointer
- `%n` - количество записанных символов / number of characters written
- `%%` - символ процента / percent character

### Для my_sscanf:
- Все вышеперечисленные спецификаторы / All above specifiers
- `%[...]` - сканируемое множество / scanset
- Модификаторы: `*` (пропуск), `l`, `L`, `h` / Modifiers: `*` (skip), `l`, `L`, `h`

## Требования / Requirements

- Компилятор GCC / GCC compiler
- Операционная система: Linux или macOS / OS: Linux or macOS
- Фреймворк Check (для тестирования) / Check framework (for testing)

## Сборка и установка / Build and Installation

### Компиляция библиотеки / Compile Library
```bash
make my_string.a
```

### Запуск тестов / Run Tests
```bash
make test
```

### Генерация отчета о покрытии кода / Generate Code Coverage Report
```bash
make gcov_report
```

### Очистка проекта / Clean Project
```bash
make clean
```

## Структура проекта / Project Structure

- `my_string.h` - заголовочный файл библиотеки / library header file
- `my_string.c` - реализация функций библиотеки / library functions implementation
- `my_test.c` - unit-тесты / unit tests
- `Makefile` - файл для сборки / build file

## Особенности реализации / Implementation Features

- **Кроссплатформенность** / Cross-platform: поддержка Linux и macOS / Linux and macOS support
- **Строгая компиляция** / Strict Compilation: с флагами `-Wall -Werror -Wextra`
- **Полное покрытие тестами** / Full Test Coverage: все функции протестированы / all functions tested
- **Покрытие кода** / Code Coverage: поддержка gcov/gcovr / gcov/gcovr support
- **Обработка специальных случаев** / Special Cases Handling: NaN, Inf, крайние значения / NaN, Inf, edge cases
- **Совместимость** / Compatibility: результаты совпадают со стандартными функциями / results match standard functions

## Тестирование / Testing

Проект включает комплексные unit-тесты, проверяющие:
- Корректность работы всех функций
- Пограничные случаи
- Совместимость со стандартными функциями C
- Обработку ошибок

The project includes comprehensive unit tests that verify:
- Correctness of all functions
- Edge cases
- Compatibility with standard C functions
- Error handling

## Примеры использования / Usage Examples

```
#include "my_string.h"

// Работа со строками / String operations
char* upper = my_to_upper("hello"); // "HELLO"
char* trimmed = my_trim("  hello  ", " "); // "hello"

// Форматированный ввод/вывод / Formatted I/O
char buffer[100];
my_sprintf(buffer, "Value: %d, String: %s", 42, "test");

int value;
char str[20];
my_sscanf("123 hello", "%d %s", &value, str);
```

## Лицензия / License

Это учебный проект. / This is an educational project.
