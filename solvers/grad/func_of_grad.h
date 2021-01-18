#ifndef _FUNC_OF_GRAD_H_
#define _FUNC_OF_GRAD_H_

#include "matrix.h"

// standardowy iloczyn skalarny(gdy A == NULL, można by powiedieć że A stanowi wtedy macierz jednostkową,
// mnożenie to byłoby jednak marnotractwem mocy obliczeniowej, bo nic nie zmienia) lub zadany przez macierz A
double inner_product(matrix_t *vec1, matrix_t *vec2, matrix_t *A);

// dodanie do pierwszej macierzy drugiej, gdzie druga jest najepierw przemnożona przez skalar (-1 pozwala na odejmowanie)
matrix_t *add_mat_and_multi_second(matrix_t *first, matrix_t *second, double scalar);

// sprawdzenie czy każdy element macierzy jest odpowiednio bliski zeru
// wartość 0 oznacza fałsz a 1 prawdę
int is_sufficiently_small(matrix_t * vec, double acceptable_error);

// wprowadzenie rozwiązań do macierzy początkowej, by dopasować się do pierwotnego formatu danych
int insert_solution_into_eqs(matrix_t *eqs, matrix_t *x);

// zamiana układu równań Ax=b w taki sposób, żeby macierz A była symetryczna i dodatnio określona
// uzyskujemy to poprzez pomnożenie układu przez transopzycję macierzy A z lewej strony
int make_it_symmetrical (matrix_t *A,  matrix_t *b);

#endif
