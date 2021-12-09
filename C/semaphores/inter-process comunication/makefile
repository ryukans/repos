all: main

main: ./main.o ./sem.o
	gcc	-o main ./main.o ./sem.o

sem.o: ../sem/source/sem.c
	gcc	-c ../sem/source/sem.c

main.o: ./main.c
	gcc	-c ./main.c

clean:
	rm -f *.o
	rm -f ./main