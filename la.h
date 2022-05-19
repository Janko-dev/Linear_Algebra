#ifndef _LA_
#define _LA_

typedef struct{
    float** data;
    int m;
    int n;
} Matrix;

typedef struct{
    float* data;
    int n;
}Vector;

// Create matrix with m rows and n columns
Matrix* create_mat(int m, int n);
// Create vector of size n
Vector* create_vec(int n);

// Destroy matrix
void free_mat(Matrix* matrix);
// Destroy vector
void free_vec(Vector* vector);

// Print matrix 
void print_mat(Matrix* matrix);
// Print vector
void print_vec(Vector* vector);

// Product between matrix and vector
Vector* prod_mat_vec(Matrix* mat, Vector* vec);
// product between matrix A and matrix B
Matrix* prod_mat(Matrix* A, Matrix* B);

// Scale vector by scalar value
Vector* scale_vec(Vector* vec, float scalar);
// Scale matrix by scalar value
Matrix* scale_mat(Matrix* mat, float scalar);

// Apply function to members of vector by supplying a pointer to a function with 1 float argument and float return value
Vector* apply_vec(Vector* vec, float(*func)(float));
// Apply function to members of matrix by supplying a pointer to a function with 1 float argument and float return value
Matrix* apply_mat(Matrix* vec, float(*func)(float));

// Convert vector to matrix
Matrix* vec_to_mat(Vector* vec);
// Convert matrix to vector if possible
Vector* mat_to_vec(Matrix* mat);

// Randomize values of matrix between min and max 
Matrix* randomize(Matrix* mat, float min, float max);

// Transpose Matrix
Matrix* transpose(Matrix* mat);

#endif