main: main.o funcs.o
	g++ -o main main.o funcs.o

main.o: main.cpp funcs.h time.h movie.h timeslot.h

funcs.o: funcs.cpp funcs.h time.h movie.h timeslot.h

test.o: test.cpp doctest.h funcs.h time.h movie.h timeslot.h

clean:
	rm -f main.o funcs.o test.o