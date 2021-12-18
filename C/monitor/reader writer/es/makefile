all: weather

weather: weather.o procedure.o monitor_hoare.o
	gcc -o weather weather.o procedure.o monitor_hoare.o

weather.o: weather.c procedure.h
	gcc -c -o weather.o weather.c

procedure.o: procedure.c procedure.h
	gcc -c -o procedure.o procedure.c

monitor_hoare.o: monitor_hoare.c monitor_hoare.h
	gcc	-c -o monitor_hoare.o monitor_hoare.c

clean:
	rm -rf *.o
	rm -rf *~
	rm -rf weather