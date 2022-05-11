#include "hamming.h"



int main(void){

    int d_size = 4;
    int p_size = 3;

    Vector* vec = create_vector(d_size);
    for (int i = 0; i < vec->n; i++) vec->data[i] = (i > 2) == 0 ? 0 : 1;

    Matrix* G = create_G_matrix(d_size, p_size);
    Matrix* H = create_H_matrix(G, d_size, p_size);
    
    uint8_t res = create_byte(G, vec);
    for (int i = 0; i < 8; i++){
        printf("%1d", (res>>i)&1 ? 1 : 0);
    }
    printf("\n");

    res = res|(1<<1);
    for (int i = 0; i < 8; i++){
        printf("%1d", (res>>i)&1 ? 1 : 0);
    }
    printf("\n");
    
    Vector* parity = check_parity(res, H);
    

    free_matrix(G);
    free_matrix(H);
    // free_vector(res);
    free_vector(vec);
    return 0;
}
