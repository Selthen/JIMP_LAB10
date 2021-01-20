#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>

typedef struct {
	int rn;
    int cn;
    double *e;
} matrix_t;

matrix_t * make_matrix( int rn, int cn );

void free_matrix(matrix_t * a);

matrix_t * read_matrix( FILE *in );

void write_matrix( matrix_t *, FILE *out );

void put_entry_matrix( matrix_t *, int i, int j, double val );

void add_to_entry_matrix( matrix_t *, int i, int j, double val );

double get_entry_matrix( matrix_t *, int i, int j );

matrix_t * copy_matrix( matrix_t *s );

matrix_t * transpose_matrix( matrix_t * s );

matrix_t * mull_matrix( matrix_t *, matrix_t * );

void free_matrix(matrix_t * a);

void xchg_rows( matrix_t *m, int i, int j );

int bs_matrix( matrix_t * );

void pivot_ge_in_situ_matrix( matrix_t * );

matrix_t* get_last(matrix_t * );

matrix_t* get_matrix_A(matrix_t*);

#endif
