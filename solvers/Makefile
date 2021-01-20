gradient: matrix.o func_of_grad.o grad_solver.o
	ar rvs libsolve.a $^
	
gauss: matrix.o pivot.o piv_ge_solver.o
	ar rvs libsolve.a $^

matrix.o: matrix.c matrix.h

grad_solver.o: grad/grad_solver.c solver.h matrix.h grad/func_of_grad.h
	$(CC)  -I . -c grad/grad_solver.c
func_of_grad.o: grad/func_of_grad.c matrix.h grad/func_of_grad.h
	$(CC)  -I . -c grad/func_of_grad.c

piv_ge_solver.o: gaus/piv_ge_solver.c solver.h matrix.h
	$(CC)  -I . -c gaus/piv_ge_solver.c	
pivot.o:  gaus/pivot.c matrix.h
	$(CC)  -I . -c gaus/pivot.c

test_gauss: gaus/gaus_main.c libsolve.a
	$(CC)	-I . -o gaus/test_gauss gaus/gaus_main.c  -L . -l solve
	
.PHONY: clean

clean:
	-rm *.o libsolve.a 
