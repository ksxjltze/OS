CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic-errors -Wconversion -std=c11

SRC = exec.c
OUT = a.out

all: build split
	./${OUT}

build:
	${CC} ${CFLAGS} ${SRC} -o ${OUT}

split:
	${CC} ${CFLAGS} hello.c -o hello
	${CC} ${CFLAGS} world.c -o world
	${CC} ${CFLAGS} sit.c -o sit