#ifndef _FUNC_OF_GRAD_H_
#define _FUNC_OF_GRAD_H_

#include "matrix.h"

double inner_product(matrix_t *vec1, matrix_t *vec2, matrix_t *A);

matrix_t *add_mat_and_multi_second(matrix_t *first, matrix_t *second, double scalar);

int is_sufficiently_small(matrix_t * vec);

int insert_solution_into_eqs(matrix_t *eqs, matrix_t *x);

int make_it_symmetrical (matrix_t *A,  matrix_t *b);

#endif
