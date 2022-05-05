
AULALISTA: main.o listas.o
	gcc main.o listas.o -o AULALISTA

main.o: main.c
	gcc -c main.c

listas.o: listas.c listas.h
	gcc -c listas.c
