CC = gcc
CFLAGS = -Wall -Werror -Wconversion -Wextra -pedantic-errors -std=c11

EXE = lab
SRC = increment.c

all: build
	./${EXE}

build:
	${CC} ${CFLAGS} ${SRC} -o ${EXE} -lpthread -lrt