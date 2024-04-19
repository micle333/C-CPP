TARGET = untitled_try
CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra -g
SOURCES= untitled_try/smart_calc.c
OBJECTS=$(SOURCES:.c=.o)
OS = $(shell uname)
TEST_FILE_NAME = s21_SmartCalc_tests.c

ifeq ($(OS), Darwin)
	TEST_LIBS=-lcheck
else
    TEST_LIBS=-lcheck -lsubunit -lm
endif

all: gcov_report

s21_SmartCalc.a: clean $(OBJECTS)
	ar -rcs s21_SmartCalc.a $(OBJECTS)
	rm -f *.o

test: $(TEST_FILE_NAME) s21_SmartCalc.a
	$(CC) $(CFLAGS) $(TEST_FILE_NAME) $(SOURCES) -o test $(TEST_LIBS)  --coverage
	./test

gcov_report: test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

install:
	qmake -o Executables/Makefile $(TARGET)/$(TARGET).pro
	cd Executables && make

uninstall: clean
	rm -rf Executables

dvi:
	@open ./README.md

dist: install 
	cd .. && tar -czf $(TARGET).tgz src

clean:
	rm -rf *.o *.a *.so *.gcda *.gcno *.gch rep.info *.html *.css test report *.txt test.info test.dSYM
