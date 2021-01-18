#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// standardowy iloczyn skalarny(gdy A == NULL, można by powiedieć że A stanowi wtedy macierz jednostkową,
// mnożenie to byłoby jednak marnotractwem mocy obliczeniowej, bo nic nie zmienia) lub zadany przez macierz A
double inner_product(matrix_t *vec1, matrix_t *vec2, matrix_t *A)
{
    if(vec1 == NULL || vec2 == NULL || vec1->cn == 1 || vec2->cn == 1 || vec1->rn != vec2->rn)
    {
        fprintf(stderr, "Some matrix is NULL OR some matrix isn't vector OR their length doesn't match!\n");
        return -999;
    }
 
    matrix_t *result = NULL;
    if(A == NULL)
        result = mull_matrix(transpose_matrix(vec1), vec2);
    else if(A->rn == A->cn && vec1->rn == A->cn)
        result = mull_matrix(mull_matrix(transpose_matrix(vec1), A), vec2);

    if(result != NULL)
        return get_entry_matrix(result, 0, 0);
    else
    {
        fprintf(stderr, "A isn't square OR has wrong size compared to vectors OR trying to multiply NULL matrix!\n");
        return -999;
    }
}    

// dodanie do pierwszej macierzy drugiej, gdzie druga jest najepierw przemnożona przez skalar (-1 pozwala na odejmowanie)
matrix_t *add_mat_and_multi_second(matrix_t *first, matrix_t *second, double scalar)
{
    matrix_t *result = copy_matrix(first);
    if(result == NULL || first == NULL || second == NULL || first->rn != second->rn || first->cn != second->cn)
    {
        fprintf(stderr, "Some matrix is NULL OR matrices' size doesn't match!\n");
        return NULL;
    }
    int rn = first->rn;
    int cn = first->cn;
    
    for(int i = 0; i < rn; i++) 
        for(int j = 0; j < cn; j++)
             result->e[i * cn + j] += scalar * second->e[i * cn + j];
    return result;
}

// sprawdzenie czy każdy element macierzy jest odpowiednio bliski zeru
// wartość 0 oznacza fałsz a 1 prawdę
int is_sufficiently_small(matrix_t *mat, double acceptable_error)
{
    if(mat == NULL)
    {
        fprintf(stderr, "Matrix is NULL!\n");
        return 0;
    }
    for(int i = 0; i < mat->rn; i++) 
        for(int j = 0; j < mat->cn; j++)
            if(fabs(mat->e[i * mat->cn + j]) > acceptable_error)
                return 0;
    return 1;
}

// wprowadzenie rozwiązań do macierzy początkowej, by dopasować się do pierwotnego formatu danych
int insert_solution_into_eqs(matrix_t *eqs, matrix_t *x)
{
    if(eqs == NULL || x == NULL || eqs->rn != x->rn)
    {
        fprintf(stderr, "Some matrix is NULL OR matrices eqs and x don't match!\n");
        return 1;
    }
    int rn = eqs->rn;
    for (int i = 0;i <rn ;i++)
    {
        eqs->e[i * rn + rn-1] = x->e[i];
    }
 
    return 0;
}

// zamiana układu równań Ax=b w taki sposób, żeby macierz A była kwadratowa, symetryczna i dodatnio określona
// uzyskujemy to poprzez pomnożenie układu przez transopzycję macierzy A z lewej strony
int make_it_symmetrical (matrix_t *A,  matrix_t *b)
{
    if (A == NULL || b == NULL || b->rn != A->cn || b->cn != 1)
    {
        fprintf(stderr, "Some matrix is NULL OR matrices A and b don't make proper system of equations!\n");
        return 1;
    }

    A = mull_matrix(transpose_matrix(A),A);
    b = mull_matrix(transpose_matrix(A),b);
 
    return 0;
}
