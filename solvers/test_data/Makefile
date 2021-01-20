gen: matrix.o gen.c ../matrix.h
	$(CC) -o gen -I .. $^
	-rm *.o
matrix.o: ../matrix.c ../matrix.h
	$(CC) -o matrix.o -c -I .. ../matrix.c 
