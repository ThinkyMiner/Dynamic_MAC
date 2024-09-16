opt=-O3 -Wall -std=c2x

all : clean main

main : main.o
	cc ${opt} $^ -o $@ 	

main.o : main.c
	cc ${opt} -c $^
	

clean:
	rm -f main *.o