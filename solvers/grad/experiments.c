#include "matrix.h"
#include "func_of_grad.h"
#include <stdio.h>
#include <stdlib.h>

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

    printf("%f\n", inner_product(m1, m2, NULL));
    printf("%f\n", inner_product(m1, m2, A));


	//x = get_matrix_A(eqs);
	//write_matrix(x, fopen("wyniki.txt", "w"));
	return 0;
}
