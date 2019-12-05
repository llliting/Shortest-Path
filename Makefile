CC = g++
FLAGS = -Wall -O0 -std=c++11
DEBUG = --DDEBUG -g

all: matrixd listd bf
debug: readgraph shortestpath binaryheap
cov: readgraph_cov binaryheap_cov shortestPath_cov

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

bf: bellmanFord.cpp readGraph.o shortestPath.o BinaryHeap.o
		$(CC) $(FLAGS) -o bellmanFord.exe bellmanFord.cpp readGraph.o shortestPath.o BinaryHeap.o

binaryheap: BinaryHeap_TEST.cpp BinaryHeap.o
		$(CC) $(FLAGS) -o binaryheap.exe BinaryHeap_TEST.cpp BinaryHeap.o
		./binaryheap.exe

currency: currency.cpp readGraph.o shortestPath.o BinaryHeap.o
		$(CC) $(FLAGS) -o currency.exe currency.cpp readGraph.o shortestPath.o BinaryHeap.o

readgraph_cov: readGraph_TEST.cpp readGraph.cpp
		g++ --coverage readGraph_TEST.cpp -o readgraph.out readGraph.cpp 
		./readgraph.out
		gcov readGraph_TEST.cpp
		gcov -f readGraph_TEST.cpp
		gcov -b readGraph_TEST.cpp
		lcov --directory . --zerocounters
		./readgraph.out
		lcov --directory . --capture --output-file readGraph.info
		genhtml readGraph.info -o readGraph

binaryheap_cov:BinaryHeap_TEST.cpp BinaryHeap.cpp
		g++ --coverage BinaryHeap_TEST.cpp -o BinaryHeap.out BinaryHeap.cpp 
		./BinaryHeap.out
		gcov BinaryHeap_TEST.cpp
		gcov -f BinaryHeap_TEST.cpp
		gcov -b BinaryHeap_TEST.cpp
		lcov --directory . --zerocounters
		./BinaryHeap.out
		lcov --directory . --capture --output-file BinaryHeap.info
		genhtml BinaryHeap.info -o BinaryHeap

shortestPath_cov: shortestPath_TEST.cpp shortestPath.cpp BinaryHeap.hpp readGraph.cpp
		g++ --coverage shortestPath_TEST.cpp -o shortestPath.out shortestPath.cpp BinaryHeap.cpp readGraph.cpp
		./shortestPath.out
		gcov shortestPath_TEST.cpp
		gcov -f shortestPath_TEST.cpp
		gcov -b shortestPath_TEST.cpp
		lcov --directory . --zerocounters
		./shortestPath.out
		lcov --directory . --capture --output-file shortestPath.info
		genhtml shortestPath.info -o shortestPath


test: test.cpp BinaryHeap.o
		$(CC) $(FLAGS) -o test.exe test.cpp BinaryHeap.o
		./test.exe
		
clean:
		rm -f *.html *.exe *.info *.out *.o *.gcno *.gcda *.gcov 
		rm -f -r readGraph BinaryHeap shortestPath
