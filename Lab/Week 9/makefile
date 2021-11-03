CC = gcc
CFLAGS = -Wall -Werror -Wconversion -Wextra -pedantic-errors -std=c11

EXE = lab

all: build
	./${EXE}

build:
	${CC} ${CFLAGS} lab.c -o ${EXE} -lpthread -lrt