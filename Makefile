CC = gcc
CFLAGS = -Wall -g -Wextra -lm
IN = la.c main.c
OUT = -o out

default:
	$(CC) $(IN) $(OUT) $(CFLAGS)

debug:
	$(CC) $(IN) $(OUT) $(CFLAGS)
	./out