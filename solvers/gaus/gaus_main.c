#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(int argc, char** argv)
{
	FILE* in = fopen("../TEST_DATA.txt", "r");
	matrix_t* eqs;
	matrix_t* x;
	eqs = read_matrix(in);
	pivot_ge_in_situ_matrix(eqs);
	bs_matrix(eqs);
	x = get_matrix_A(eqs);
	write_matrix(x, fopen("wyniki.txt", "w"));
	fclose(in);
	return 0;
}