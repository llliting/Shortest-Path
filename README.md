# project3-Liting Huang
The project implements three different algorithms to approach the shortest path problem: Dijkstra using adjacency matrix, Dijkstra using adjacency list, and the bellman ford algorithm. A binary heap program is written in conveinence of the implementation of the bellman ford algorithm. The program can write the graph and the path into a new file while outputting the running time for the algorithm and total weights on screen when given a graph. The last part of the project uses bellman ford to calculate the best currency rate.


## Running the program  
### Compiling the program
```
$ make
```
### matrixDijkstra
The program implements dijkstra algorithm by translating the given graph into adjacency matrix. The program takes in four command line argument inputs: the given graph, the output text file, the source vertex, and the end vertex. 
```
$ ./matrixdijkstra.exe <given graph> <output txt file> <source vertex> <end vertex>
```


### listDijkstra
The program implements dijkstra algorithm by translating the given graph into adjacency list. The program takes in four command line argument inputs: the given graph, the output text file, the source vertex, and the end vertex. 
```
$ ./listDijkstra.exe <given graph> <output txt file> <source vertex> <end vertex>
``` 

### bellmanFord
The program implements bellman ford algorithm to identify the shortes path, even with negative degree edges. The program takes in four command line argument inputs: the given graph, the output text file, the source vertex, and the end vertex. 
```
$ ./bellmanFord.exe <given graph> <output txt file> <source vertex> <end vertex>
``` 

### currency 
The program implements bellman ford algorithm to identify the best currency exchange rate. The program takes in five command line argument inputs: the given graph, the output text file, the source currency, the end currency, and the transaction cost.
```
$ ./currency.exe <given graph> <output txt file> <source vertex> <end vertex> <transaction cost>
``` 

### Unit Testing
Unit tests with Catch2 are utilized to test the project's correctness. 
<br />In terminal, type in `make coverage` to run the coverage tests of "readGraph.cpp", "shortestPath.cpp", and "BinaryHeap.cpp." The coverage test results are stored in readGraph, shortestPath and BinaryHeap folders as "index.html."
<br />To use the debug mode, type in `make debug`.



