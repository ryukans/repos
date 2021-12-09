CC=gcc
LFLAGS=-pthread

# Nota: versioni precedenti di PThreads utilizzavano
# un flag differente ("-lpthread").
#LFLAGS=-lpthread

all: main

main: main.c
	$(CC) $(LFLAGS) -o main main.c

clean:
	rm -f main
