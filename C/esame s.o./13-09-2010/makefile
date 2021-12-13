all: main.o procedure.o monitor.o
	gcc -o start main.o procedure.o monitor.o

main.o: main.c header.h
	gcc -c -o main.o  main.c

procedure.o: procedure.c header.h monitor.h
	gcc -c -o procedure.o procedure.c

monitor.o: monitor.c monitor.h
	gcc -c -o monitor.o monitor.c


clean:
	rm -f *.o
	rm -f start