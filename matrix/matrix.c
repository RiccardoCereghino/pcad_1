#include "matrix.h"


void create_matrix(Matrix m, int rows, int cols) {
    m->ptr = NULL;

    if (rows < 0 || cols < 0)
        perror("Rows and cols must be greater than 0");

    m->ptr = (double *) malloc(rows * cols * sizeof(double));

    if (m->ptr == NULL)
        perror("malloc failed\n");

    m->rows = rows;
    m->cols = cols;

    for (int i = 0; i < m->rows * m->cols; ++i)
        m->ptr[i] = 0;
}


void free_matrix(Matrix m) {
    free(m->ptr);
}


void fill_matrix_with_values(Matrix m, int argc, ...) {
    va_list params;
    va_start(params, argc);

    for (int i = 0; i < m->rows * m->cols; ++i)
        m->ptr[i] = va_arg(params, int);

    va_end(params);
}

void fill_matrix_with_number(Matrix m, double n) {
    for (int i = 0; i < m->rows * m->cols; ++i)
        m->ptr[i] = n;
}

double get_value(Matrix m, int y, int x) {
    return m->ptr[y * m->cols + x];
}

void set_value(Matrix m, int y, int x, double value) {
    m->ptr[y * m->cols + x] = value;
}


void print_matrix(Matrix m) {
    printf("\n");

    for (int y = 0; y < m->rows; ++y) {
        printf("(");
        for (int x = 0; x < m->cols; ++x)
            printf(" %f ", get_value(m, y, x));

        printf(")\n");
    }

    printf("\n");
}


int multiply_matrices(Matrix m1, Matrix m2, Matrix r) {
    if (m1->cols != m2->rows)
        return -1;

    r->rows = m1->rows;
    r->cols = m2->cols;

    create_matrix(r, r->rows, r->cols);

    double p;

    for (int y = 0; y < r->rows; ++y) {

        for (int x = 0; x < r->cols; ++x) {
            p = 0;
            for (int n = 0; n < m1->cols; ++n)
                p += get_value(m1, y, n) * get_value(m2, n, x);
            set_value(r, y, x, p);
        }

    }
    return 0;
}


void *t_multiply_matrices(void *args) {
    Args arg = args;
    double p;
    int y,x,n, f;

    for (y = arg->thread_n * arg->blocks; y < ((arg->thread_n * arg->blocks) + arg->blocks) && (arg->R.rows); ++y) {
        for (x = 0; x < arg->R.cols; ++x) {
            p = 0;
            for (n = 0; n < arg->A.cols; ++n)
                p += get_value(&arg->A, y, n) * get_value(&arg->B, n, x);
            set_value(&arg->R, y, x, p);
        }
    }

    arg->flags[arg->thread_n] = 1;
    __sync_synchronize();

    clock_t begin = clock();

    while (1) {
        f = 1;
        for (int k = 0; k < arg->R.rows / arg->blocks; ++k)
            if (arg->flags[k] == 0) {
                f = 0;
                break;
            }
        if (!f)
            continue;
        break;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("AAA spent: %f\n", time_spent);


    for (y = arg->thread_n * arg->blocks; y < ((arg->thread_n * arg->blocks) + arg->blocks) && (arg->P.rows); ++y) {
        for (x = 0; x < arg->P.cols; ++x) {
            p = 0;
            for (n = 0; n < arg->C.cols; ++n)
                p += get_value(&arg->C, y, n) * get_value(&arg->R, n, x);
            set_value(&arg->P, y, x, p);
        }
    }
}
