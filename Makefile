CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

ifeq ($(shell uname -s), Darwin)
    CHECK_CFLAGS = $(shell pkg-config --cflags check 2>/dev/null)
    CHECK_LIBS = $(shell pkg-config --libs check 2>/dev/null)
    ifeq ($(CHECK_LIBS),)
        CHECK_INCLUDE_DIR = $(shell find /usr/local/include /opt/homebrew/include -name "check.h" 2>/dev/null | head -1 | xargs dirname 2>/dev/null)
        ifneq ($(CHECK_INCLUDE_DIR),)
            CHECK_CFLAGS = -I$(CHECK_INCLUDE_DIR)
            CHECK_LIBS = -L$(CHECK_INCLUDE_DIR)/../lib -lcheck
        else
            CHECK_LIBS = -lcheck
        endif
    endif
else
    # Linux
    CHECK_CFLAGS = 
    CHECK_LIBS = -lcheck -lsubunit -lm -lpthread
endif

all: my_string.a test_my_string

test: my_string.a test_my_string

my_string.a: my_string.o
	ar rcs my_string.a my_string.o
	ranlib my_string.a
	rm -f my_string.o

my_string.o: my_string.c my_string.h
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o

test_my_string: test_my_string.o
	$(CC) $(CFLAGS) test_my_string.o my_string.a $(CHECK_LIBS) -o test_my_string
	rm -f test_my_string.o

test_my_string.o: my_test.c
	$(CC) $(CFLAGS) $(CHECK_CFLAGS) -c my_test.c -o test_my_string.o

gcov_report: test_my_string_gcov
	./test_my_string_gcov
	gcovr --filter "my_string.c" --html --html-details -o coverage_report.html
	@echo "HTML report generated: coverage_report.html"
	rm -f *.gcno *.gcda *.gcov

test_my_string_gcov: my_test.c my_string.c my_string.h
	$(CC) $(CFLAGS) $(CHECK_CFLAGS) $(GCOV_FLAGS) my_test.c my_string.c $(CHECK_LIBS) -o test_my_string_gcov

clean:
	rm -f *.o *.a *.gcno *.gcda *.gcov *.html *.css program test_my_string_gcov test_my_string