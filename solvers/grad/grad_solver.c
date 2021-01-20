#include "solver.h"
#include "func_of_grad.h"
#include <stdlib.h>
#include <math.h>

#define ACCEPTABLE_ERROR 1e-12

// argument n symbolicznie oznacza, ktore free w kodzie wywolujemy
void free_all(int n, matrix_t *A, matrix_t *b, matrix_t *x, matrix_t *new_x, matrix_t *r, matrix_t *new_r, matrix_t *p) 
{
        free_matrix(A);
        free_matrix(b);
        free_matrix(x);
        free_matrix(r);
        if(n > 1)
            free_matrix(p);
        if(n == 2)
        {
            free_matrix(new_r);
            free_matrix(new_x);
        }

}

int solver (matrix_t * eqs)
{
    if(eqs == NULL || eqs->rn != eqs->cn - 1)
    {
        fprintf(stderr, "Matrix eqs is NULL or it's size is wrong");
        return -1;
    }
    matrix_t *A = get_matrix_A(eqs);
    matrix_t *b = get_last(eqs);
    make_it_symmetrical(&A, &b);

    int n = A -> rn;
    matrix_t *x = make_matrix(n, 1);
    matrix_t *new_x;
    matrix_t *p;
    matrix_t *new_p;
    matrix_t *r;
    matrix_t *new_r;
    matrix_t *tmp;
    double alpha;
    double beta;

    r = copy_matrix(b);
    if(is_sufficiently_small(r, ACCEPTABLE_ERROR))
    {
        insert_solution_into_eqs(eqs, x);
        free_all(1, A, b, x, new_x, r, new_r, p);
        return 0;
    }
    p = copy_matrix(r);
    
    int k = 0;
    while(k++ < n)
    {
        alpha = inner_product(r, r, NULL) / inner_product(p, p, A);
        new_x = add_mat_and_multi_second(x, p, alpha);

        tmp = mull_matrix(A, p);
        new_r = add_mat_and_multi_second(r, tmp, -1 * alpha);
        free_matrix(tmp);

        if(is_sufficiently_small(new_r, ACCEPTABLE_ERROR))
        {
            insert_solution_into_eqs(eqs, new_x);
            free_all(2, A, b, x, new_x, r, new_r, p);
            return 0;
        }   

        beta = inner_product(new_r, new_r, NULL) / inner_product(r, r, NULL);
        new_p = add_mat_and_multi_second(new_r, p, beta);

        free_matrix(r);
        r = new_r;
        free_matrix(x);
        x = new_x;
        free_matrix(p);
        p = new_p;
    }
  
    insert_solution_into_eqs(eqs, new_x);
    free_all(3, A, b, x, new_x, r, new_r, p);
    return 0;
}
