#include <pthread.h>

#include <stdio.h>
#include <time.h>

#include "matrix/matrix.h"
#include <sys/time.h>

int64_t timestamp_now (void)
{
    struct timeval tv;
    gettimeofday (&tv, NULL);
    return (int64_t) tv.tv_sec * CLOCKS_PER_SEC + tv.tv_usec;
}

double timestamp_to_seconds (int64_t timestamp)
{
    return timestamp / (double) CLOCKS_PER_SEC;
}

int main(int argc, char **argv) {
    struct matrix A, B, R, C, P;
    pthread_t *threads = NULL;
    int *flags = NULL;
    struct args *arguments = NULL;
    int size;

    int n_threads, blocks;

    if (argc != 2) {
        fprintf(stderr, "USAGE: %s <blocks>\n", argv[0]);
        exit(1);
    }

    printf("Insert a positive numeric value for matrix size (S), the program will run C*(A*B) where:\n"
           "A = S * S/2 (filled with 1s)\n"
           "B = S/2 * S (filled with 2s)\n"
           "C = S * S (filled with 3s)\n"
           "Matrices sizes and values can be modified from within the code.\n"
           "Input is not sanitized run at your own risk.\n");

    scanf("%i", &size);

    /* matrices initializations, here matrices sizes can be changed */
    create_matrix(&A, size, size / 2);
    create_matrix(&B, size / 2, size);
    create_matrix(&R, size, size);
    create_matrix(&C, size, size);
    create_matrix(&P, size, size);

    /* Matrix fulfillment operation
    * An alternative is to use:
        fill_matrix_with_values(&A_2, 16,
                            2, 4, -2, 0,
                            1, 3, 0, 1,
                            3, -1, 1, 2,
                            0, -1, 2, 1
        );

    */
    fill_matrix_with_number(&A, 1);
    fill_matrix_with_number(&B, 2);
    fill_matrix_with_number(&C, 3);


    blocks = atoi(argv[1]);

    if (blocks > size) {
        fprintf(stderr, "USAGE: %s <blocks> must be < <size>\n", argv[0]);
        exit(1);
    }

    /* start thread configuration */
    int64_t start = timestamp_now ();

    if (size % blocks == 0)
        n_threads = size / blocks;
    else
        n_threads = size / blocks + 1;

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

    printf ("With %i threads took %f seconds\n",
            n_threads,
            timestamp_to_seconds (timestamp_now () - start));

    /* Uncomment if you want the result printed */
    /*print_matrix(&P);*/

    free_matrix(&A);
    free_matrix(&B);
    free_matrix(&R);


    return 0;
}
