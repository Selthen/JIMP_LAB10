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


test_grad: grad/main_grad.c gradient
	$(CC)  -I . -o test_grad grad/main_grad.c  -L . -l solve
test_gaus: gaus/main_gaus.c gauss
	$(CC)  -I . -o test_gaus gaus/main_gaus.c  -L . -l solve

t1: test_grad test_data/TEST_DATA.txt test_data/odp1
	./test_grad test_data/TEST_DATA.txt tmp
	@if [ "$$(diff tmp test_data/odp1 | wc -l)" = "0" ]; then echo "Wyniki met. grad. sprz. sa prawidlowe!"; else echo "Ktorys z wynikow jest bledny!"; fi
	@rm tmp
 
t2: test_grad test_data/TEST_DATA2.txt test_data/odp2
	./test_grad test_data/TEST_DATA2.txt tmp
	@if [ "$$(diff tmp test_data/odp2 | wc -l)" = "0" ]; then echo "Wyniki met. grad. sprz. sa prawidlowe!"; else echo "Ktorys z wynikow jest bledny!"; fi
	@rm tmp
 
t3: test_grad test_data/big_matrix.txt test_data/odp3
	./test_grad test_data/big_matrix.txt tmp
	@if [ "$$(diff tmp test_data/odp3 | wc -l)" = "0" ]; then echo "Wyniki met. grad. sprz. sa prawidlowe!"; else echo "Ktorys z wynikow jest bledny!"; fi
	@rm tmp
 
t4: test_gaus test_data/TEST_DATA.txt test_data/odp1
	./test_gaus test_data/TEST_DATA.txt tmp
	@if [ "$$(diff tmp test_data/odp2 | wc -l)" = "0" ]; then echo "Wyniki met. el. Gaussa sa prawidlowe!"; else echo "Ktorys z wynikow jest bledny!"; fi
	@rm tmp
 
t5: test_gaus test_data/TEST_DATA2.txt test_data/odp2
	./test_gaus test_data/TEST_DATA2.txt tmp
	@if [ "$$(diff tmp test_data/odp3 | wc -l)" = "0" ]; then echo "Wyniki met. el. Gaussa sa prawidlowe!"; else echo "Ktorys z wynikow jest bledny!"; fi
	@rm tmp
 
t6: test_gaus test_data/big_matrix.txt
	./test_gaus test_data/big_matrix.txt tmp
	@if [ "$$(diff tmp test_data/odp6 | wc -l)" = "0" ]; then echo "Wyniki met. el. Gaussa sa prawidlowe!"; else echo "Ktorys z wynikow jest bledny!"; fi
	@rm tmp
 

.PHONY: clean clean_all t1 t2 t3 t4 t5 t6

clean:
	-rm *.o 

clean_all: clean
	-rm libsolve.a test_gaus test_grad 
