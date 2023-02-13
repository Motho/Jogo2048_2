all: 
	gcc -Wall -o 2048 2048.c
	
run:
	./2048

clean:
	rm 2048.o