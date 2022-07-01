all: main

INCLUDE = -I ./public
CFLAGS = -std=c++17

main: graph.o solver.o tree.o main.o
	$(CXX) $(INCLUDE) $(CFLAGS) main.o graph.o solver.o tree.o -o main

graph.o: public/graph.h ./private/graph.cpp
	$(CXX) $(INCLUDE) $(CFLAGS) -c ./private/graph.cpp -o graph.o

solver.o: ./public/solver.h ./private/solver.cpp
	$(CXX) $(INCLUDE) $(CFLAGS) -c ./private/solver.cpp -o solver.o

tree.o: ./public/tree.h ./private/tree.cpp
	$(CXX) $(INCLUDE) $(CFLAGS) -c ./private/tree.cpp -o tree.o

main.o: main.cpp
	$(CXX) $(INCLUDE) $(CFLAGS) -c main.cpp -o main.o

run: main
	./main 1 0 0 5 5 2 5 9_2005515_none.txt
	./main 1 5 0 5 5 2 5 9_2505515_static.txt
	./main 1 0 1 5 5 2 5 9_2015515_dynamic.txt
#	./main 5 0 0 10 20 3 5 us_none.txt
#	./main 5 50 0 10 20 3 5 us_static.txt
#	./main 5 0 5 10 20 3 5 us_dynamic.txt

clean:
	rm *.o
	rm main
