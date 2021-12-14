all: main.o flight.o monitor.o
	gcc -o start main.o flight.o monitor.o -pthread

main.o: main.c flight.h
	gcc -c -o main.o  main.c

flight.o: flight.c flight.h monitor.h
	gcc -c -o flight.o flight.c

monitor.o: monitor.c monitor.h
	gcc -c -o monitor.o monitor.c

clean:
	rm -f *.o
	rm -f start