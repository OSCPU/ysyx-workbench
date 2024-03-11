CC=cc
CFLAGS=-Wall -g -Os

all: ex01 ex03 ex04 ex05 ex06 ex07 ex08 ex09 ex10 ex11 ex12 ex13 ex14 ex15 ex16 ex17 ex18 ex32 clean

ex01:
	${CC} ex01.c -o ex01 ${CFLAGS}
	./ex01

ex03:
	${CC} ex03.c -o ex03 ${CFLAGS}
	./ex03

ex04:
	${CC} ex04.c -o ex04 ${CFLAGS}
	valgrind ./ex04

ex05:
	${CC} ex05.c -o ex05 ${CFLAGS}
	./ex05

ex06:
	${CC} ex06.c -o ex06 ${CFLAGS}
	./ex06

ex07:
	${CC} ex07.c -o ex07 ${CFLAGS}
	./ex07

ex08:
	${CC} ex08.c -o ex08 ${CFLAGS}
	./ex08

ex09:
	${CC} ex09.c -o ex09 ${CFLAGS}
	./ex09

ex10:
	${CC} ex10.c -o ex10 ${CFLAGS}
	./ex10

ex11:
	${CC} ex11.c -o ex11 ${CFLAGS}
	./ex11

ex12:
	${CC} ex12.c -o ex12 ${CFLAGS}
	./ex12 yes no

ex13:
	${CC} ex13.c -o ex13 ${CFLAGS}
	./ex13 A

ex14:
	${CC} ex14.c -o ex14 ${CFLAGS}
	./ex14

ex15:
	${CC} ex15.c -o ex15 ${CFLAGS}
	./ex15

ex16:
	${CC} ex16.c -o ex16 ${CFLAGS}
	./ex16

ex17:
	${CC} ex17.c -o ex17 ${CFLAGS}
	./ex17 db.dat c
	./ex17 db.dat s 1 zed zed@zedshaw.com
	./ex17 db.dat s 2 frank frank@zedshaw.com
	./ex17 db.dat s 3 joe joe@zedshaw.com
	./ex17 db.dat l

ex18:
	${CC} ex18.c -o ex18 ${CFLAGS}
	./ex18 4 3 1 2

ex32:
	${CC} ex32.c -o ex32 ${CFLAGS}
	./ex32

clean:
	rm ex01 -f
	rm ex03 -f
	rm ex04 -f
	rm ex05 -f
	rm ex06 -f
	rm ex07 -f
	rm ex08 -f
	rm ex09 -f
	rm ex10 -f
	rm ex11 -f
	rm ex12 -f
	rm ex13 -f
	rm ex14 -f
	rm ex15 -f
	rm ex16 -f
	rm ex17 db.dat -f
	rm ex18 -f
	rm ex32 -f
