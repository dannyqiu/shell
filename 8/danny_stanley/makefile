FILES = main.c shell.c

all: clean build run

clean:
	@rm -f shell

build:
	@gcc -Wall -o shell $(FILES)

run:
	@./shell

test:
	@./shell < test.txt
