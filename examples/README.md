# Examples of uses with the library
Below are some examples of uses where library functions are called

## Polygon Render Pipeline
```
> cd Linear_Algebra/examples
> make prp
> ./prp
```
See comments in code for more details. The vertices of a cube are transformed in the following order:
**Modeling transform** -> **Viewing transform** -> **Perspective transform** 

## Example matrix terminal output
```
> cd Linear_Algebra/examples
> make mat
> ./mat {INPUT_M} {INPUT_N}
```
where {INPUT_M} corresponds to the amount of rows in the matrix and {INPUT_N} corresponds to the amount of columns in the matrix. 
Will print the matrix with supplied dimensions
```
> ./mat 5 4
Matrix of size ( 5,  4)
---------------------
   0.1251   56.3585   19.3304   80.8740
  58.5009   47.9873   35.0291   89.5962
  82.2840   74.6605   17.4108   85.8943
  71.0501   51.3535   30.3995    1.4985
   9.1403   36.4452   14.7313   16.5899
```