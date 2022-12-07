cc = clang

all: main

main: utils.o main.o
	$(cc) utils.o main.o -lm -o main
	
utils.o: utils.c utils.h
	$(cc) -c -g utils.c

main.o: utils.c utils.h
	$(cc) -c -g main.c

clean: 
	rm *.o
	