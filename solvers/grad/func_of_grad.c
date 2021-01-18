#include "matrix.h"

// standardowy iloczyn skalarny(gdy A == NULL, można by powiedieć że A stanowi wtedy macierz jednostkową,
// mnożenie to byłoby jednak marnotractwem mocy obliczeniowej, bo nic nie zmienia) lub zadany przez macierz A
double inner_product(matrix_t *vec1, matrix_t *vec2, matrix_t *A)
{
    matrix_t *result;
    if(A == NULL)
        result = mull_matrix(transpose_matrix(vec1), vec2);
    else
        result = mull_matrix(mull_matrix(transpose_matrix(vec1), A), vec2);

    if(result != NULL)
        return get_entry_matrix(result, 0, 0);
    else
    {
        fprintf(stderr, "Trying to multiply NULL matrix");
        return -999;
    }
}    

matrix_t *add_mat_and_multi_second(matrix_t *first, matrix_t *second, double scalar)
{

    if(first == NULL || second == NULL || first->rn != second->rn || first->cn != second->cn)
        return NULL;
//    if (scalar != 1)
        
}

int multiply_matrix_by_scalar(matrix_t *mat, double scalar)
{
    
}

int is_sufficiently_small(matrix_t * vec)
{
    return 0;
}

int insert_solution_into_eqs(matrix_t *eqs, matrix_t *x)
{
    return 0;
}

int make_it_symmetrical (matrix_t *A,  matrix_t *b)
{
    return 0;
}
