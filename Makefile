CC = g++
FLAGS = -Wall -O0 -std=c++11
DEBUG = --DDEBUG -g

readGraph.o: readGraph.cpp readGraph.hpp
		$(CC) $(FLAGS) -c readGraph.cpp


readgraph: readGraph_TEST.cpp readGraph.o
		$(CC) $(FLAGS) -o readGraph.exe readGraph_TEST.cpp readGraph.o
		./readGraph.exe