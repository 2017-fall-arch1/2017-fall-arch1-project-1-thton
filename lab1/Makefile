all: Demo

Demo: Employees.o
	cc Employees.o -o Demo

Employees.o: Employees.c Btree.h
	cc -c Employees.c

run: Demo
	./Demo

clean:
	rm -f *.o Demo
