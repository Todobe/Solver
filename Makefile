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
	./main 2 0 0 5 5 1 1_200551_none.txt
	./main 2 5 0 5 5 1 1_250551_static.txt
	./main 2 0 1 5 5 1 1_201551_dynamic.txt

clean:
	rm *.o
	rm main
