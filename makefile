ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif


all: main.o direct_funcs.o
	$(CC) -o program main.o direct_funcs.o

main.o: main.c direct.h
	$(CC) -c main.c

direct_funcs.o: direct_funcs.c direct.h
	$(CC) -c direct_funcs.c

run:
	./program

clean:
	rm *.o

memcheck:
	valgrind --leak-check=yes ./program
