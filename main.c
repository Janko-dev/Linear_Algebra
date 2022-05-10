#include <stdio.h>
#include <stdlib.h>
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

void print_matrix(Matrix* matrix){
    for (int i = 0; i < matrix->m; i++){
        for (int j = 0; j < matrix->n; j++){
            printf("%3d ", matrix->data[i][j]);
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

void free_matrix(Matrix* matrix){
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

Vector* mul_matrix_vector(Matrix* mat, Vector* vec){
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

void mul_vector_scalar(Vector* vec, int scalar){
    for (int i = 0; i < vec->n; i++){
        vec->data[i] *= scalar;
    }
}

Vector* map_vector(Vector* vec, int(*f)(int)){
    for (int i = 0; i < vec->n; i++) vec->data[i] = f(vec->data[i]);
    return vec;
}

static inline int mod2(int n){
    return n%2;
}

void make_G(int size_data, int size_par){
    Matrix* g_mat = create_matrix(size_data+size_par, size_data);
    for (int i = 0; i < size_data; i++){
        for (int j = 0; j < size_data; j++){
            g_mat->data[j][j] = 1;
        }    
    }

    for (int i = size_data; i < size_data+size_par; i++){
        for (int j = 0; j < size_data; j++){
            g_mat->data[i][j] = ((((i-size_data)<j) | ((i-size_data)>j)))%2? 1 : 0;
        }
    }

    Matrix* h_mat = create_matrix(size_par, size_data+size_par);
    for (int i = 0; i < size_par; i++){
        for (int j = 0; j <= size_par; j++){
            h_mat->data[i][j] = g_mat->data[i+size_data][j];
        }
    }

    for (int i = 0; i < size_par; i++){
        for (int j = size_data; j < size_data+size_par; j++){
            h_mat->data[j-size_data][j] = 1;
        }
    }

    Vector* vec = create_vector(size_data);
    for (int i = 0; i < size_data; i++) vec->data[i] = i % 2 == 0 ? 0 : 1;

    print_matrix(g_mat);
    print_matrix(h_mat);
    print_vector(vec);
    
    Vector* res = map_vector(mul_matrix_vector(g_mat, vec), mod2);
    print_vector(res);

    res->data[0] = 1;

    res = map_vector(mul_matrix_vector(h_mat, res), mod2);
    print_vector(res);
    
    
    free_matrix(g_mat);
    free_matrix(h_mat);
    free_vector(res);
    free_vector(vec);
}

int main(void){

    make_G(4, 3);
    return 0;
}
