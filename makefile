all: 
	gcc -Wall -o 2048_2 2048_2.c
	
run:
	./2048_2

clean:
	rm 2048_2.o
