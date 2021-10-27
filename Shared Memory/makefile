CC = gcc
CFLAGS = -Wall -Werror -Wconversion -pedantic-errors -Wextra -std=c11

PRODUCER_SRC = producer.c
CONSUMER_SRC = consumer.c

PRODUCER_OUT = producer
CONSUMER_OUT = consumer

build:
	${CC} ${CFLAGS} ${PRODUCER_SRC} -o ${PRODUCER_OUT}
	${CC} ${CFLAGS} ${CONSUMER_SRC} -o ${CONSUMER_OUT}