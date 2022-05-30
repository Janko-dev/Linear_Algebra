SRC = examples/
PRP = prp
MAT = mat

CC = gcc
CFLAGS = -Wall -g -Wextra -lm

LACG = lacg.c
LA   = la.c

IN_PRP = $(SRC)$(PRP).c
IN_MAT = $(SRC)$(MAT).c

prp:
	$(CC) $(LACG) $(IN_PRP) -o $(PRP) $(CFLAGS)

run_prp:
	$(CC) $(LACG) $(IN_PRP) -o $(PRP) $(CFLAGS)
	./$(PRP)

mat:
	$(CC) $(LA) $(IN_MAT) -o $(MAT) $(CFLAGS)

run_mat:
	$(CC) $(LA) $(IN_MAT) -o $(MAT) $(CFLAGS)
	./$(MAT)