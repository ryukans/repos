all: main readers writer

main: main.c
	gcc -o main main.c

sem.o: ../../sem/source/sem.c 
	gcc -c ../../sem/source/sem.c

readers: readers.c sem.o
	gcc -o readers readers.c sem.o

writer: writer.c sem.o
	gcc -o writer writer.c sem.o


clean:
	rm -f main readers writer
	rm -f *.o
