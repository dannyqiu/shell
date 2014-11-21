
all: execute.o shell.o
	gcc -o  shell execute.o shell.o
shell.o: shell.c
	gcc -c  shell.c
execute.o: execute.c
	gcc -c  execute.c
clean:
	rm *.o
	rm *~

debug:
	gcc -g shell.c execute.c
