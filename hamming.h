#ifndef _HAMMING_
#define _HAMMING_

#include "la.h"

Matrix* create_G_matrix(int size_data, int size_par);
Matrix* create_H_matrix(Matrix* G, int size_data, int size_par);

#endif //_HAMMING_