all: JAVOshell.o executor.o
	gcc JAVOshell.o executor.o
	./a.out
JAVOshell.o: executor.c JAVOshell.c
	gcc -c JAVOshell.c
executor.o: executor.c
	gcc -c executor.c
clean:
	rm *.o
	rm a.out
