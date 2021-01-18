#include "solver.h"
#include <stdlib.h>
#include <math.h>

#define ACCEPTABLE_ERROR 1e-12

int solver (matrix_t * eqs)
{
    matrix_t *A = get_matrix_A(eqs);
    matrix_t *b = get_matrix_b(eqs);
    make_it_symmetrical(A, b);
    int n = A -> rn;
    matrix_t *x = make_matrix(n, 1);
    matrix_t *p;
    matrix_t *r;
    matrix_t *new_r;
    double alpha;
    double beta;

    r = copy_matrix(b);
    if(is_sufficiently_small(r, ACCEPTABLE_ERROR))
    {
        insert_solution_into_eqs(eqs, x);
        return 0;
    }
    p = copy_matrix(r);
    
    int i = 0;
    while(i < n)
    {
        alpha = inner_product(r, r) / inner_product(p, p, A);
        x = add_mat_and_multi_second(x, p, alpha);
        new_r = add_mat_and_multi_second(r, mull_matrix(A, p), -1 * alpha);
        if(is_sufficiently_small(new_r, ACCEPTABLE_ERROR));
        {
            insert_solution_in_eqs(eqs, x);
            return 0;
        }   
        beta = inner_product(new_r, new_r) / inner_product(r, r);
        p = add_mat_and_multi_second(new_r, p, beta);
        r = r_new;
        i++;
    }
  
    return 1;
}
