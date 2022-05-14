#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "la.h"

Matrix* create_matrix(int m, int n){
    Matrix* result = (Matrix*)malloc(sizeof(Matrix));
    result->m = m;
    result->n = n;
    result->data = (int**)malloc(sizeof(int*)*result->m);
    for (int i = 0; i < result->m; i++){
        result->data[i] = (int*)calloc(result->n, sizeof(int));
    }
    return result;
}

Vector* create_vector(int n){
    Vector* result = (Vector*)malloc(sizeof(Vector));
    result->n = n;
    result->data = (int*)calloc(result->n, sizeof(int));
    return result;
}

Matrix_f* create_matrix_f(int m, int n){
    Matrix_f* result = (Matrix_f*)malloc(sizeof(Matrix_f));
    result->m = m;
    result->n = n;
    result->data = (float**)malloc(sizeof(float*)*result->m);
    for (int i = 0; i < result->m; i++){
        result->data[i] = (float*)calloc(result->n, sizeof(float));
    }
    return result;
}

Vector_f* create_vector_f(int n){
    Vector_f* result = (Vector_f*)malloc(sizeof(Vector_f));
    result->n = n;
    result->data = (float*)calloc(result->n, sizeof(float));
    return result;
}

void free_matrix(Matrix* matrix){
    for (int i = 0; i < matrix->m; i++){
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

void free_matrix_f(Matrix_f* matrix){
    for (int i = 0; i < matrix->m; i++){
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

void free_vector(Vector* vector){
    free(vector->data);
    free(vector);
}

void free_vector_f(Vector_f* vector){
    free(vector->data);
    free(vector);
}

void print_matrix(Matrix* matrix){
    for (int i = 0; i < matrix->m; i++){
        for (int j = 0; j < matrix->n; j++){
            printf("%3d ", matrix->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_matrix_f(Matrix_f* matrix){
    for (int i = 0; i < matrix->m; i++){
        for (int j = 0; j < matrix->n; j++){
            printf("%9.4f ", matrix->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_vector(Vector* vector){
    for (int i = 0; i < vector->n; i++){
        printf("%3d\n", vector->data[i]);
    }
    printf("\n");
}

void print_vector_f(Vector_f* vector){
    for (int i = 0; i < vector->n; i++){
        printf("%9.4f\n", vector->data[i]);
    }
    printf("\n");
}

Vector* prod_matrix_vector(Matrix* mat, Vector* vec){
    if (vec->n != mat->n){
        fprintf(stderr, "ERROR: Columns of matrix do not match rows of vector\n");
        exit(1);
    }

    Vector* result = create_vector(mat->m);
    for (int i = 0; i < mat->m; i++){
        for (int j = 0; j < mat->n; j++){
            result->data[i] += mat->data[i][j] * vec->data[j];
        }
    }
    return result;
}

Vector_f* prod_matrix_vector_f(Matrix_f* mat, Vector_f* vec){
    if (vec->n != mat->n){
        fprintf(stderr, "ERROR: Columns of matrix do not match rows of vector\n");
        exit(1);
    }

    Vector_f* result = create_vector_f(mat->m);
    for (int i = 0; i < mat->m; i++){
        for (int j = 0; j < mat->n; j++){
            result->data[i] += mat->data[i][j] * vec->data[j];
        }
    }
    return result;
}

Matrix* prod_matrix(Matrix* A, Matrix* B){
    if (B->m != A->n){
        fprintf(stderr, "ERROR: Columns of matrix A do not match rows of matrix B\n");
        exit(1);
    }

    Matrix* result = create_matrix(A->m, B->n);
    for (int i = 0; i < A->m; i++){
        for (int j = 0; j < B->n; j++){
            for (int k = 0; k < A->n; k++){
                result->data[i][j] += A->data[i][k] * B->data[k][j];    
            }
        }
    }
    return result;
}

Matrix_f* prod_matrix_f(Matrix_f* A, Matrix_f* B){
    if (B->m != A->n){
        fprintf(stderr, "ERROR: Columns of matrix A do not match rows of matrix B\n");
        exit(1);
    }

    Matrix_f* result = create_matrix_f(A->m, B->n);
    for (int i = 0; i < A->m; i++){
        for (int j = 0; j < B->n; j++){
            for (int k = 0; k < A->n; k++){
                result->data[i][j] += A->data[i][k] * B->data[k][j];    
            }
        }
    }
    return result;
}

void mul_vector_scalar(Vector* vec, int scalar){
    for (int i = 0; i < vec->n; i++){
        vec->data[i] *= scalar;
    }
}

void mul_vector_scalar_f(Vector_f* vec, float scalar){
    for (int i = 0; i < vec->n; i++){
        vec->data[i] *= scalar;
    }
}

Vector* apply_vector(Vector* vec, int(*f)(int)){
    for (int i = 0; i < vec->n; i++) vec->data[i] = f(vec->data[i]);
    return vec;
}

Vector_f* apply_vector_f(Vector_f* vec, float(*f)(float)){
    for (int i = 0; i < vec->n; i++) vec->data[i] = f(vec->data[i]);
    return vec;
}

Matrix* apply_matrix(Matrix* mat, int(*f)(int)){
    for (int i = 0; i < mat->m; i++) {
        for (int j = 0; j < mat->n; j++) {
            mat->data[i][j] = f(mat->data[i][j]);
        }
    }
    return mat;
}

Matrix_f* apply_matrix_f(Matrix_f* mat, float(*f)(float)){
    for (int i = 0; i < mat->m; i++) {
        for (int j = 0; j < mat->n; j++) {
            mat->data[i][j] = f(mat->data[i][j]);
        }
    }
    return mat;
}

Matrix* populate_matrix_random(Matrix* mat){
    for (int i = 0; i < mat->m; i++) {
        for (int j = 0; j < mat->n; j++) {
            mat->data[i][j] = rand() % 100;
        }
    }
    return mat;
}

Matrix_f* populate_matrix_random_f(Matrix_f* mat){
    for (int i = 0; i < mat->m; i++) {
        for (int j = 0; j < mat->n; j++) {
            mat->data[i][j] = 100.0f * ((float)rand()/(float)RAND_MAX);
        }
    }
    return mat;
}