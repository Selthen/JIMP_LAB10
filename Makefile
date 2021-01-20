aprox: main.o splines.o points.o aproksymator_na_bazie.o solvers/libsolve.a bin
	$(CC) -o bin/aprox  main.o splines.o points.o aproksymator_na_bazie.o -L solvers -l solve

intrp: main.o splines.o points.o interpolator.o solvers/libsolve.a bin
	$(CC) -o bin/intrp  main.o splines.o points.o interpolator.o -L solvers -l solve

prosta: main.o splines.o points.o prosta.o bin
	$(CC) -I . -o bin/prosta  main.o splines.o points.o prosta.o	

aproksymator_na_bazie.o: makespl.h points.h solvers/matrix.h solvers/solver.h
	$(CC) -I . -I solvers -c aprox/aproksymator_na_bazie.c

interpolator.o: makespl.h points.h solvers/solver.h
	$(CC) -I . -I solvers -c aprox/interpolator.c

prosta.o: makespl.h
	$(CC) -I . -c aprox/prosta.c

bin:
	mkdir bin
	
write_test_data: main.o splines.o points.o solvers/libsolve.a bin
	$(CC) -I . -I solvers -c aprox/aproksymator_na_bazie.c -DTEST_DATA
	$(CC) -o bin/aprox main.o splines.o points.o aproksymator_na_bazie.o -L solvers -l solve

write_test_data2: main.o splines.o points.o solvers/libsolve.a bin
	$(CC) -I . -I solvers -c aprox/interpolator.c -DTEST_DATA
	$(CC) -o bin/intrp  main.o splines.o points.o interpolator.o -L solvers -l solve

.PHONY: clean clean_all

clean: 
	-rm *.o solvers/*.o

clean_all: clean
	-rm bin/* solvers/libsolve.a
