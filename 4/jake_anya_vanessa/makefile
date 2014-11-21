all: JAVOshell.o executor.o signal.o
	gcc JAVOshell.o executor.o signal.o
JAVOshell.o: JAVOshell.c
	gcc -c JAVOshell.c
executor.o: executor.c
	gcc -c executor.c
signal.o: signal.c signal.h
	gcc -c signal.c signal.h
clean:
	rm *.o
	rm a.out
