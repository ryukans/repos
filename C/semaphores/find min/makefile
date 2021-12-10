min-mutex: ./main.o ./mutex_processes.o ./sem.o
	gcc -o min-mutex ./main.o ./mutex_processes.o ./sem.o

main.o: ./source/main.c
	gcc -c -g -o ./main.o ./source/main.c

mutex_processes.o: ./source/mutex_processes.c
	gcc -c -g -o ./mutex_processes.o ./source/mutex_processes.c

sem.o: ../sem/source/sem.c
	gcc -c -g -o sem.o ../sem/source/sem.c

clean:
	rm -f *.o
	rm -f ./min-mutex