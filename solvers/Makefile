gauss: matrix.o pivot.o piv_ge_solver.o
	ar rvs libsolve.a $^

gradient: matrix.o grad_solver.o
	ar rvs libsolve.a $^
	
matrix.o: matrix.c matrix.h

pivot.o:  gaus/pivot.c matrix.h
	$(CC)	-I . -c gaus/pivot.c
piv_ge_solver.o: gaus/piv_ge_solver.c solver.h matrix.h
	$(CC)	-I . -c gaus/piv_ge_solver.c
	
grad_solver.o: gradient/grad_solver.c matrix.h func_of_grad.h
	$(CC)	-I . -c gradient/grad_solver.c

test_gauss: gaus/gaus_main.c libsolve.a
	$(CC)	-I . -o gaus/test_gauss gaus/gaus_main.c  -L . -l solve
	
.PHONY: clean

clean:
	-rm *.o libsolve.a 