all: main

main: ./procedure.o ./msg.o
	gcc -o main ./procedure.o ./msg.o

msg.o: ./source/msg.c
	gcc -c ./source/msg.c

procedure.o: ./header/procedure.h ./source/procedure.c
	gcc -c ./source/procedure.c

clean:
	rm -rf ./*.o
	rm -rf ./main
