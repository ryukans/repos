

app: app.o
	gcc -g -o app app.o

viewer: viewer.o procedure.o
	gcc -g -o viewer viewer.o procedure.o

procedure.o: ../source/procedure.c ../header/viewer.h
	gcc -g -c ../source/procedure.c

