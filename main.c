#include <stdio.h>
#include <stdlib.h>
#include "la.h"
#include <time.h>

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

    // if (argc != 3){
    //     fprintf(stderr, "ERROR: Supply a whole number for the amount of rows and columns of the matrix.\n");
    //     exit(1);
    // }

    // int m = convert(argv[1]);
    // int n = convert(argv[2]);

    // printf("Matrix of size (%2d, %2d)\n---------------------\n", m, n);

    // Matrix* mat = create_matrix(m, n);
    // populate_matrix_random(mat);
    // print_matrix(mat);

    Matrix* m = create_mat(4, 4);
    // srand(time(0));
    m = randomize(m, 0.f, 10.f);
    // m->data[0][0] = 1.f;
    // m->data[0][1] = 2.f;
    // m->data[0][2] = 3.f;
    // m->data[1][0] = 4.f;
    // m->data[1][1] = 5.f;
    // m->data[1][2] = 6.f;
    // m->data[2][0] = 7.f;
    // m->data[2][1] = 8.f;
    // m->data[2][2] = 10.f;
    print_mat(m);
    
    for (int k = 0; k < m->n; k++){
        for (int i = k+1; i < m->m; i++){
            float val = m->data[i][k]/m->data[k][k];
            for (int j = k; j < m->n; j++){
                m->data[i][j] -= m->data[k][j] * val;
            }
        }
    }
    
    

    print_mat(m);
    return 0;
}