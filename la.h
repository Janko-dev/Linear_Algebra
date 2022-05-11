#ifndef _LA_
#define _LA_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef struct{
    int** data;
    int m;
    int n;
} Matrix;

typedef struct{
    int* data;
    int n;
}Vector;

Matrix* create_matrix(int m, int n);
Vector* create_vector(int n);

void print_matrix(Matrix* matrix);
void print_vector(Vector* vector);

void free_matrix(Matrix* matrix);
void free_vector(Vector* vector);

Vector* mul_matrix_vector(Matrix* mat, Vector* vec);
Matrix* prod_matrix(Matrix* A, Matrix* B);

void mul_vector_scalar(Vector* vec, int scalar);
Vector* map_vector(Vector* vec, int(*f)(int));

#endif