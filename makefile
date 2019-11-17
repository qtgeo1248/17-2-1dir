ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

ifeq ($(TROLL),true)
	FILEC = troll.c
	FILEO = troll.o
else
	FILEC = main.c
	FILEO = main.o
endif


all: $(FILEO) direct_funcs.o
	$(CC) -o program $(FILEO) direct_funcs.o

main.o: $(FILEC) direct.h
	$(CC) -c $(FILEC)

direct_funcs.o: direct_funcs.c direct.h
	$(CC) -c direct_funcs.c

run:
	./program

clean:
	rm *.o

memcheck:
	valgrind --leak-check=yes ./program
