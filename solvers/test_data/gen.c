#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"


int main( int argc, char **argv ) {
				int n= argc > 1 ? atoi( argv[1] ) : 100;
				FILE *out= argc > 2 ? fopen( argv[2], "w" ) : stdout;

				srand( argc > 3 ? atoi(argv[3]) : time(NULL) );

				matrix_t*  Ab = make_matrix(n, n + 1);
				fprintf(out, "%d %d\n", n, n + 1);

				int r,k;
				for( r =0; r < n; r++ ) {
					for (int k = 0;k < n + 1;k++)
					{
						put_entry_matrix(Ab, r, k, 0.0 + (double)rand() / RAND_MAX * 30.0);
						fprintf(out, "%g ", get_entry_matrix(Ab,r,k));
					}
					fprintf(out, "\n");
				}
				fclose( out );

				return 0;
}
