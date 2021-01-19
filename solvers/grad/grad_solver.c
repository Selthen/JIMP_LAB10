#include "solver.h"
#include "func_of_grad.h"
#include <stdlib.h>
#include <math.h>

#define ACCEPTABLE_ERROR 1e-12

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

//    write_matrix(A,stdout);
//    write_matrix(b,stdout);

    int n = A -> rn;
    matrix_t *x = make_matrix(n, 1);
    matrix_t *p;
    matrix_t *r;
    matrix_t *new_r;
    matrix_t *new_x;
    matrix_t *new_p;
    double alpha;
    double beta;

    r = copy_matrix(b);
    if(is_sufficiently_small(r, ACCEPTABLE_ERROR))
    {
        insert_solution_into_eqs(eqs, x);
        return 0;
    }
    p = copy_matrix(r);
    
    int k = 0;
    while(k++ < n)
    {
        alpha = inner_product(r, r, NULL) / inner_product(p, p, A);
        new_x = add_mat_and_multi_second(x, p, alpha);
        new_r = add_mat_and_multi_second(r, mull_matrix(A, p), -1 * alpha);
        if(is_sufficiently_small(new_r, ACCEPTABLE_ERROR))
        {
            insert_solution_into_eqs(eqs, new_x);
            return 0;
        }   
        beta = inner_product(new_r, new_r, NULL) / inner_product(r, r, NULL);
        new_p = add_mat_and_multi_second(new_r, p, beta);
        r = new_r;
        x = new_x;
        p = new_p;
    }
  
    insert_solution_into_eqs(eqs, new_x);
    return 0;
}
