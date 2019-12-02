CC = g++
FLAGS = -Wall -O0 -std=c++11
DEBUG = --DDEBUG -g

all: matrixd listd
debug: readgraph shortestpath binaryheap
readGraph.o: readGraph.cpp readGraph.hpp
		$(CC) $(FLAGS) -c readGraph.cpp

shortestPath.o: shortestPath.cpp shortestPath.hpp
		$(CC) $(FLAGS) -c shortestPath.cpp

BinaryHeap.o: BinaryHeap.cpp BinaryHeap.hpp
		$(CC) $(FLAGS) -c BinaryHeap.cpp

readgraph: readGraph_TEST.cpp readGraph.o
		$(CC) $(FLAGS) -o readGraph.exe readGraph_TEST.cpp readGraph.o
		./readGraph.exe

shortestpath: shortestPath_TEST.cpp shortestPath.o readGraph.o BinaryHeap.o
		$(CC) $(FLAGS) -o shortestPath.exe shortestPath_TEST.cpp shortestPath.o readGraph.o BinaryHeap.o
		./shortestPath.exe

matrixd: matrixDijkstra.cpp readGraph.o shortestPath.o BinaryHeap.o
		$(CC) $(FLAGS) -o matrixdijkstra.exe matrixDijkstra.cpp readGraph.o shortestPath.o BinaryHeap.o

listd: listDijkstra.cpp readGraph.o shortestPath.o BinaryHeap.o
		$(CC) $(FLAGS) -o listDijkstra.exe listDijkstra.cpp readGraph.o shortestPath.o BinaryHeap.o

binaryheap: BinaryHeap_TEST.cpp BinaryHeap.o
		$(CC) $(FLAGS) -o binaryheap.exe BinaryHeap_TEST.cpp BinaryHeap.o
		./binaryheap.exe

test: test.cpp BinaryHeap.o
		$(CC) $(FLAGS) -o test.exe test.cpp BinaryHeap.o
		./test.exe
		
clean:
		rm -f *.exe *.o
