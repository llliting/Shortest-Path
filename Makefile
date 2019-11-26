CC = g++
FLAGS = -Wall -O0 -std=c++11
DEBUG = --DDEBUG -g

readGraph.o: readGraph.cpp readGraph.hpp
		$(CC) $(FLAGS) -c readGraph.cpp

shortestPath.o: shortestPath.cpp shortestPath.hpp
		$(CC) $(FLAGS) -c shortestPath.cpp

readgraph: readGraph_TEST.cpp readGraph.o
		$(CC) $(FLAGS) -o readGraph.exe readGraph_TEST.cpp readGraph.o
		./readGraph.exe

shortestpath: shortestPath_TEST.cpp shortestPath.o readGraph.o
		$(CC) $(FLAGS) -o shortestPath.exe shortestPath_TEST.cpp shortestPath.o readGraph.o
		./shortestPath.exe

matrixd: matrixDijkstra.cpp readGraph.o shortestPath.o
		$(CC) $(FLAGS) -o matrixdijkstra.exe matrixDijkstra.cpp readGraph.o shortestPath.o
		
clean:
		rm -f *.exe, *.o