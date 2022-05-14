#ifndef _LA_
#define _LA_

typedef struct{
    int** data;
    int m;
    int n;
} Matrix;

typedef struct{
    int* data;
    int n;
}Vector;

typedef struct{
    float** data;
    int m;
    int n;
} Matrix_f;

typedef struct{
    float* data;
    int n;
}Vector_f;

// m rows and n columns
Matrix* create_matrix(int m, int n);
Vector* create_vector(int n);

void free_matrix(Matrix* matrix);
void free_vector(Vector* vector);

void print_matrix(Matrix* matrix);
void print_vector(Vector* vector);

Vector* prod_matrix_vector(Matrix* mat, Vector* vec);
Matrix* prod_matrix(Matrix* A, Matrix* B);

void mul_vector_scalar(Vector* vec, int scalar);
Vector* apply_vector(Vector* vec, int(*f)(int));
Matrix* apply_matrix(Matrix* vec, int(*f)(int));

Matrix* populate_matrix_random(Matrix* mat);

// m rows and n columns
Matrix_f* create_matrix_f(int m, int n);
Vector_f* create_vector_f(int n);

void free_matrix_f(Matrix_f* matrix);
void free_vector_f(Vector_f* vector);

void print_matrix_f(Matrix_f* matrix);
void print_vector_f(Vector_f* vector);

Vector_f* prod_matrix_vector_f(Matrix_f* mat, Vector_f* vec);
Matrix_f* prod_matrix_f(Matrix_f* A, Matrix_f* B);

void mul_vector_scalar_f(Vector_f* vec, float scalar);
Vector_f* apply_vector_f(Vector_f* vec, float(*f)(float));
Matrix_f* apply_matrix_f(Matrix_f* vec, float(*f)(float));

Matrix_f* populate_matrix_random_f(Matrix_f* mat);

#endif