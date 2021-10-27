CC = gcc
CFLAGS = -Wall -Werror -Wconversion -pedantic-errors -Wextra -std=c11

PRODUCER_SRC = adder.c
CONSUMER_SRC = result.c

PRODUCER_OUT = adder
CONSUMER_OUT = result

build:
	${CC} ${CFLAGS} ${PRODUCER_SRC} -o ${PRODUCER_OUT}
	${CC} ${CFLAGS} ${CONSUMER_SRC} -o ${CONSUMER_OUT}