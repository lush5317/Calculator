cc = clang

all: main test_cal

main: utils.o main.o
	$(cc) -gdwarf-4 utils.o main.o -lm -o main -Wall

test_cal: test/test.cc
	clang++ -gdwarf-4 test/test.cc -lgtest -lm -o test_cal -Wall
	
utils.o: utils.c utils.h
	$(cc) -c -g -gdwarf-4 utils.c -Wall

main.o: utils.c utils.h
	$(cc) -c -g -gdwarf-4 main.c -Wall

clean: 
	rm *.o
	