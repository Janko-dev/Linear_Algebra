#include <stdio.h>
#include <stdlib.h>
#include "la.h"

long int convert(char* x){
    long int total = 0;
    while(*x != '\0'){
        //printf("%c\n", *x);
        if (*x < '0' || *x > '9'){
            fprintf(stderr, "ERROR: Supply a whole number\n");
            exit(1);
        }
        total = 10 * total + (*x - '0');
        x++;
    }
    return total;
}

int main(int argc, char** argv){

    if (argc != 3){
        fprintf(stderr, "ERROR: Supply a whole number for the amount of rows and columns of the matrix.\n");
        exit(1);
    }

    int m = convert(argv[1]);
    int n = convert(argv[2]);

    printf("Matrix of size (%2d, %2d)\n---------------------\n", m, n);

    Matrix* mat = create_matrix(m, n);
    populate_matrix_random(mat);
    print_matrix(mat);

    return 0;
}