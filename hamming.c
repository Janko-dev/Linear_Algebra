#include "hamming.h"

Matrix* create_G_matrix(int size_data, int size_par){
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
    return g_mat;
}


Matrix* create_H_matrix(Matrix* G, int size_data, int size_par){
    
    Matrix* h_mat = create_matrix(size_par, size_data+size_par);
    for (int i = 0; i < size_par; i++){
        for (int j = 0; j <= size_par; j++){
            h_mat->data[i][j] = G->data[i+size_data][j];
        }
    }

    for (int i = 0; i < size_par; i++){
        for (int j = size_data; j < size_data+size_par; j++){
            h_mat->data[j-size_data][j] = 1;
        }
    }
    return h_mat;
}

static inline int mod2(int n){
    return n%2;
}

uint8_t create_byte(Matrix* G, Vector* vec){
    Vector* res = map_vector(mul_matrix_vector(G, vec), mod2);
    print_vector(res);
    uint8_t byte = 0;
    for (int i = 0; i < res->n; i++){
        byte |= res->data[i]<<(i+1);
    }
    return byte;
}

Vector* check_parity(uint8_t byte, Matrix* H){
    Vector* res = create_vector(7);
    for (int i = 0; i < 7; i++) res->data[i] = (byte>>(i+1))&1;
    return map_vector(mul_matrix_vector(H, res), mod2);
}

