#ifndef MATRIX_
#define MATRIX_
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <pthread.h>

struct matrix{
    double *ptr;
    int rows;
    int cols;
};

struct args {
    struct matrix A;
    struct matrix B;
    struct matrix R;
    struct matrix C;
    struct matrix P;
    int thread_n;
    int blocks;
    int *flags;
};

typedef struct matrix* Matrix;
typedef struct args* Args;

void create_matrix(Matrix m, int rows, int cols);
void free_matrix(Matrix m);
void fill_matrix_with_values(Matrix m, int argc, ...);
double get_value(Matrix m, int y, int x);
void set_value(Matrix m, int y, int x, double value);
void print_matrix(Matrix m);
int multiply_matrices(Matrix m1, Matrix m2, Matrix r);
void *t_multiply_matrices(void *params);
void fill_matrix_with_number(Matrix m, double n);

#endif // MATRIX_