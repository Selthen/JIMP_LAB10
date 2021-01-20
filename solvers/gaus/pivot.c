#include "matrix.h"
#include <stdlib.h>
#include <math.h>

void
pivot_ge_in_situ_matrix (matrix_t * c)
{
  int i, j, k;
  int cn = c->cn;
  int rn = c->rn;
  double *e = c->e;
  for (k = 0; k < rn - 1; k++) {        /* eliminujemy (zerujemy) kolumnę nr k */
    int piv = k;                /* wybór elementu dominującego - maks. z k-tej kol., poniżej diag */
    for (i = k + 1; i < rn; i++)
      if (fabs (*(e + i * cn + k)) > fabs (*(e + piv * cn + k)))
        piv = i;
    if (piv != k) {             /* jeśli diag. nie jest pivtem - wymień wiersze */
      xchg_rows (c, piv, k);
    }
    for (i = k + 1; i < rn; i++) {      /* pętla po kolejnych
                                           wierszach poniżej diagonalii k,k */
      double d = *(e + i * cn + k) / *(e + k * cn + k);
      for (j = k; j < cn; j++)
        *(e + i * cn + j) -= d * *(e + k * cn + j);
    }
  }
  free(e);
}

