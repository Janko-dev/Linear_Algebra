CC = gcc
CFLAGS = -Wall -g -Wextra -lm
IN = main.c
OUT = -o out

default:
	$(CC) $(IN) $(OUT) $(CFLAGS)
	./out