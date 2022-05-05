
TRABALHO: main.o pilhas.o
	gcc main.o pilhas.o -o TRABALHO

main.o: main.c
	gcc -c main.c

pilhas.o: pilhas.c pilhas.h
	gcc -c pilhas.c
