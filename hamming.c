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

