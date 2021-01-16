libge: pivot.o piv_ge_solver.o
	ar rvs libge.a $^

pivot.o: ../matrix.h
	$(CC) -I ../ -c pivot.c

piv_ge_solver.o: piv_ge_solver.c piv_ge_solver.h ../matrix.h
	$(CC) -I ../ -c piv_ge_solver.c
.PHONY: clean

clean:
	-rm *.o
