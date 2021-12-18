all: main docente studente

main: main.c
	gcc -g -o main main.c

docente: docente.c sem.o
	gcc -o docente docente.c sem.o

studente: studente.c sem.o
	gcc -o studente studente.c sem.o

sem.o: sem.c sem.h
	gcc -c sem.c

clean:
	rm -f *.o
	rm -f main docente studente