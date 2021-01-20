#include "matrix.h"
#include "func_of_grad.h"
#include "solver.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    char *in_name = argc > 1 ? argv[1] : "../TEST_DATA.txt";
	FILE* in = fopen(in_name, "r");
    if(in == NULL)
    {
        fprintf(stderr, "Cannot read from %s\n!", in_name);
        return 1;
    }
    FILE *out = argc > 2 ? fopen(argv[2], "w") : stdout;
	if(out == NULL)
    {
        fprintf(stderr, "Cannot write to output file!\n");
        return 2;
    }

    matrix_t *x;
    matrix_t *eqs = read_matrix(in);
	fclose(in);

    if(out == stdout)
    {
       matrix_t *A = get_matrix_A(eqs);
       matrix_t *b = get_last(eqs);

       if(solver(eqs) != 0)
       {
            fprintf(stderr, "Solver had problems!\n");
            return 1;
       }
       x = get_last(eqs);

       printf("Matrix A:\n"); 
	   write_matrix(A, stdout);
       printf("Matrix b:\n"); 
	   write_matrix(b, stdout);
       printf("Matrix x (result):\n"); 
	   write_matrix(x, stdout);

       free_matrix(A);
       free_matrix(b);
    }
    else
    {
       if(solver(eqs) != 0)
       {
            fprintf(stderr, "Solver had problems!\n");
            return 1;
       }       
       x = get_last(eqs);

	   write_matrix(x, out);
       fclose(out);
    }
    free_matrix(eqs);
    free_matrix(x);

	return 0;
}
