# Linear Algebra library
Linear Algebra library in C. The library supports both **Matrix** and **Vector** operations.
Below is a list of operations supported. The library consists of 2 components:
- **la.c/la.h** consists of heap-based Matrix/Vector datastructures
- **lacg.c/lacg.h** consists of stack-based Matrix/Vector datastructures, where there are predefined sizes for Matrices and Vectors (i.e., 3x3, 4x4)
The reason for this divide comes from the freedom of choice that is granted to the user. 

## Currently supported functions
In **la.c/la.h**:
- Dot product between 2 matrices
- Dot product between matrix and vector
- Scalar operations for matrices and vectors
- Higher order function application to the members of both matrices and vectors
- Conversion between matrix and vector and vice versa
- Transpose function of matrix
- Randomize matrix between min and max values
- Hard copy of matrix and vector
- Cross product between 2 vectors of size 3

In **lacg.c/lacg.h**:
- **Vec3** datastructure consisting of several unions (i.e., rgb, xyz, array[3])
- **Vec4** datastructure consisting of several unions (i.e., rgba, xyzh, array[4])
- **Mat3x3** datastructure and **Mat4x4** datastructure
- Fill all members of matrix with specific value
- Scale all members of matrix or vector with specific value
- Add value to all members of vector
- Identity function for matrices
- Dot product between two 3x3 matrices
- Dot product between two 4x4 matrices
- Cross product between 2 vectors of size 3
- Magnitude of **Vec3** and **Vec4**

