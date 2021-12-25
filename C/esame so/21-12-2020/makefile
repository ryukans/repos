LFLAGS = -pthread

all: main

main: ./main.o ./procedure.o
	gcc -o main ./main.o ./procedure.o $(LFLAGS)

main.o: ./source/main.c 
	gcc -c ./source/main.c

procedure.o: ./source/procedure.c
	gcc -c ./source/procedure.c

clean:
	rm -f *.o
	rm -f ./main