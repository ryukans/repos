all: start

start: main.o client.o server.o balancer.o
	gcc -o start main.o client.o server.o balancer.o

main.o: main.c header.h
	gcc -c -o main.o main.c

client.o: client.c header.h
	gcc -c -o client.o client.c

server.o: server.c header.h
	gcc -c -o server.o server.c

balancer.o: balancer.c header.h
	gcc -c -o balancer.o balancer.c

clean:
	rm -f *.o
	rm -f start