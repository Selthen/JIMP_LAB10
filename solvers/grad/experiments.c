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

    printf("%d\n",is_sufficiently_small(A, ACCEPTABLE_ERROR));
    printf("%d\n",is_sufficiently_small(m1, ACCEPTABLE_ERROR));
	//x = get_matrix_A(eqs);
	//write_matrix(x, fopen("wyniki.txt", "w"));
	return 0;
}
