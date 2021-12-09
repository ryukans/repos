all: main

main: ./main.o ./procedure.o ./sem.o
	gcc -o main ./main.o ./procedure.o ./sem.o

sem.o: ../../sem/source/sem.c 
	gcc -c ../../sem/source/sem.c

procedure.o: ./source/procedure.c
	gcc -c ./source/procedure.c

main.o: ./source/main.c
	gcc -c ./source/main.c

clean:
	rm -f *.o
	rm -f ./main