all: main

main: ./procedure.o ./sem.o ./main.o
	gcc -o main ./procedure.o ./sem.o ./main.o

main.o: ./source/main.c
	gcc -c ./source/main.c

procedure.o: ./header/procedure.h ./source/procedure.c
	gcc -c ./source/procedure.c

sem.o: ./header/sem.h ./source/sem.c
	gcc -c ./source/sem.c

clean:
	rm -rf ./*.o
	rm -rf ./main
