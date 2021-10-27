CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic-errors -Wconversion -std=c11

SRC = refresher.c
OUT = refresher

all: build
	./${OUT}

build:
	${CC} ${CFLAGS} ${SRC} -o ${OUT}