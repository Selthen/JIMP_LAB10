aprox: main.o splines.o points.o aproksymator_na_bazie.o solvers/gaus/libge.a
	$(CC) -o aprox  main.o splines.o points.o aproksymator_na_bazie.o -L solvers/gaus -l ge

intrp: main.o splines.o points.o interpolator.o solvers/gaus/libge.a
	$(CC) -o intrp  main.o splines.o points.o interpolator.o -L solvers/gaus -l ge

prosta: main.o splines.o points.o prosta.o
	$(CC) -o prosta  main.o splines.o points.o prosta.o	

aproksymator_na_bazie.o: makespl.h points.h solvers/matrix.h solvers/gaus/piv_ge_solver.h
	$(CC) -I solvers  -I solvers/gaus -c aproksymator_na_bazie.c

interpolator.o: makespl.h points.h solvers/gaus/piv_ge_solver.h
	$(CC) -I solvers/gaus -c interpolator.c

.PHONY: clean

clean:
	-rm *.o aprox intrp prosta
