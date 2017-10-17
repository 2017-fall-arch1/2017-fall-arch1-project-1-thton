all: Demo



Demo: Employees.o
	cc -o $@ $^

Employees.o: Employees.c Btree.h
	cc -c -g -03 Employees.c

run: Demo
	./Demo

clean:
	rm -f *.o 
