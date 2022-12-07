cc = clang

all: main test_cal

main: utils.o main.o
	$(cc) utils.o main.o -lm -o main

test_cal: test/test.cc
	clang++ test/test.cc -lgtest -lm -o test_cal
	
utils.o: utils.c utils.h
	$(cc) -c -g utils.c

main.o: utils.c utils.h
	$(cc) -c -g main.c

clean: 
	rm *.o
	