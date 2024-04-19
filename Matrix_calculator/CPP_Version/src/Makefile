CC = g++
CFLAGC =  -Wall -Werror -Wextra -std=c++17
STATIC = ar rcs
TESTFLAGC = -lgtest

GCOVFLAGS = --coverage
SOURCES_ALL:=$(wildcard *.c)
SOURCES_FUN:=$(shell find . -not -name "s21_test.cpp" -name "*.cpp")
UNAME:=$(shell uname -s)

ifeq ($(UNAME),Linux)
	LDFLAGS=-lgtest -lsubunit -lm -lrt -lpthread
	OPEN_CM=xdg-open
endif
ifeq ($(UNAME),Darwin)
	LDFLAGS=-lgtest
	OPEN_CM=open
endif

all: clean test s21_matrix_oop.a gcov_report 

s21_matrix_oop.o: s21_matrix_oop.cpp s21_matrix_oop.h
	$(CC) $(CFLAGC) -c s21_matrix_oop.cpp -o s21_matrix_oop.o

s21_matrix_oop_gcov.o: s21_matrix_oop.cpp s21_matrix_oop.h
	$(CC) $(CFLAGC) -c --coverage s21_matrix_oop.cpp -o s21_matrix_oop.o

s21_test: clean s21_test.cpp
	$(CC) $(CFLAGC) -c s21_test.cpp -o s21_test.o

test: s21_test s21_matrix_oop.a
	$(CC) s21_test.o s21_matrix_oop.a -o s21_test $(LDFLAGS)
	./s21_test

s21_matrix_oop.a: s21_matrix_oop.o
	$(STATIC) s21_matrix_oop.a s21_matrix_oop.o
	ranlib s21_matrix_oop.a	

gcov_report: clean s21_matrix_oop.o test s21_matrix_oop_gcov.o
	$(CC) $(CFLAGC) $(GCOVFLAGS) s21_test.o s21_matrix_oop.o -o gcov_unit_tests $(TESTFLAGC)
	./gcov_unit_tests
	lcov -t "s21_matrix_oop_test" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	$(OPEN_CM) ./report/index.html

clang-format:
	cp ../materials/linters/.clang-format .
	clang-format -i *.c *.h 
	
clean:
	rm -rf *.o s21_matrix_oop *.a s21_test *.out *.gcd *.gcno *.gcov *.gcda *.info ./report gcov_unit_tests

