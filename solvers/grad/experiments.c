#include "matrix.h"
#include "func_of_grad.h"
#include <stdio.h>
#include <stdlib.h>

#define ACCEPTABLE_ERROR 1e-12

int main(int argc, char** argv)
{
	FILE* in = fopen("test_1", "r");
	matrix_t* m1 = read_matrix(in); 
	fclose(in);
	in = fopen("test_2", "r");
	matrix_t* m2 = read_matrix(in); 
	fclose(in);
	in = fopen("test_A", "r");
	matrix_t* A = read_matrix(in);
	fclose(in);

	write_matrix(A, stdout);
	make_it_symmetrical(A, m1);
	write_matrix(A, stdout);
	write_matrix(m1, stdout);

    printf("%d\n",insert_solution_into_eqs(A,m1));
	write_matrix(A, stdout);
	//x = get_matrix_A(eqs);
	//write_matrix(x, fopen("wyniki.txt", "w"));
	return 0;
}
