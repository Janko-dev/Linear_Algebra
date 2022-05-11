#include "hamming.h"

static inline int mod2(int n){
    return n%2;
}

int main(void){

    int d_size = 4;
    int p_size = 3;

    Vector* vec = create_vector(d_size);
    for (int i = 0; i < vec->n; i++) vec->data[i] = i % 2 == 0 ? 0 : 1;

    Matrix* G = create_G_matrix(d_size, p_size);
    Matrix* H = create_H_matrix(G, d_size, p_size);
    
    print_vector(vec);
    
    Vector* res = map_vector(mul_matrix_vector(G, vec), mod2);
    print_vector(res);

    res->data[0] = 1;

    res = map_vector(mul_matrix_vector(H, res), mod2);
    print_vector(res);
    
    
    free_matrix(G);
    free_matrix(H);
    free_vector(res);
    free_vector(vec);
    return 0;
}
