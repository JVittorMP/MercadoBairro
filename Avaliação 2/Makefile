all: Avaliação_2

Avaliação_2: Principal.o Funções.o Menus.o
	gcc -o Avaliações_2 Principal.o Funções.o Menus.o

Funções.o: Funções.c
	gcc -o Funções.o -c Funções.c -Wall

Menus.o: Menus.c
	gcc -o Menus.o -c Menus.c -Wall

Principal.o: Principal.c Funções.h Menus.h Registros.h
	gcc -o Principal.o -c Principal.c -Wall

clean:
	rm -rf *.o