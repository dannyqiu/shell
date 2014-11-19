all: shell.o
	gcc shell.o
	make run
shell.o: shell.c
	gcc -c shell.c
clean:
	rm *.o
run:
	./a.out