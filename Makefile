CC = gcc
CFLAGS = -Wall -g -Wextra -lm
IN = main.c la.c
OUT = -o out

default:
	$(CC) $(IN) $(OUT) $(CFLAGS)

debug:
	$(CC) $(IN) $(OUT) $(CFLAGS)
	./out