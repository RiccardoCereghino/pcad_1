#include <pthread.h>

#include <stdio.h>
#include <time.h>

#include "matrix/matrix.h"

int main(int argc, char **argv) {
    struct matrix A, B, R, C, P;
    pthread_t *threads = NULL;
    int *flags = NULL;
    struct args *arguments = NULL;

    int n_threads, blocks;

    if (argc != 2) {
        fprintf(stderr, "USAGE: %s <blocks>\n", argv[0]);
        exit(1);
    }

    int size = 1000;

    /* matrices initializations */
    create_matrix(&A, size, size);
    create_matrix(&B, size, size);
    create_matrix(&R, size, size);
    create_matrix(&C, size, size);
    create_matrix(&P, size, size);

    /* fulfillment operation */
    fill_matrix_with_number(&A, 1);
    fill_matrix_with_number(&B, 1);
    fill_matrix_with_number(&C, 1);


    blocks = atoi(argv[1]);

    if (blocks > size) {
        fprintf(stderr, "USAGE: %s <blocks> must be < 8\n", argv[0]);
        exit(1);
    }

    /* start thread configuration */
    clock_t begin = clock();


    n_threads = size / blocks;
    printf("Threads: %d\n", n_threads);

    threads = (pthread_t *) malloc(n_threads * sizeof(pthread_t));
    arguments = (struct args *) malloc(n_threads * sizeof(struct args));
    flags = (int *) malloc(n_threads * sizeof(int));
    if (flags == NULL)
        perror("malloc failed\n");

    for ( int k = 0; k < n_threads; ++k)
        flags[k] = 0;

    /* A * B = R */
    for (int count = 0; count < n_threads; ++count)
    {
        arguments[count].A = A;
        arguments[count].B = B;
        arguments[count].R = R;
        arguments[count].C = C;
        arguments[count].P = P;
        arguments[count].thread_n = count;
        arguments[count].blocks = blocks;
        arguments[count].flags = flags;

        if (pthread_create(&threads[count], NULL, t_multiply_matrices, &arguments[count]) != 0)
        {
            fprintf(stderr, "error: Cannot create thread # %d\n", count);
            break;
        }
    }


    /* Closing threads */
    void *returnCode;
    for (int i = 0; i < n_threads; ++i)
    {
        if (pthread_join(threads[i], &returnCode) != 0)
        {
            fprintf(stderr, "error: Cannot join thread # %d\n", i);
        }
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent: %f", time_spent);

    /* print_matrix(&P); */

    free_matrix(&A);
    free_matrix(&B);
    free_matrix(&R);


    return 0;
}
