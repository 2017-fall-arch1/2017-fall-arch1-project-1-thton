all: Demo

Demo: Employees.o
	cc -o $@ $^

Employees.o: Employees.c Btree.h
	cc -c Employees.c

run: Demo
	./Demo

clean:
	rm -f *.o Demo
