all: main client server

main: main.c
	gcc -o main main.c

client: client.c
	gcc -o client client.c

server: server.c
	gcc -o server server.c -pthread

clean:
	rm -f main client server
	rm -f *.o
