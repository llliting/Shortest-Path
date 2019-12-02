#include <fstream>
#include <string>
#include <limits>
#include <iostream>
#include "BinaryHeap.hpp"
using namespace std;

void dijkstra(const double* const * matrix, int numVertices, int source, double*& dist, int*& prev){
    dist = new double[numVertices];
    prev = new int[numVertices];
    bool sptSet[numVertices];//if the current vertex is in the final path
    for(int i = 0; i < numVertices; i++){
        dist[i] = numeric_limits<double>::infinity();
        prev[i] = -1;
        sptSet[i] = false;
    }
    dist[source] = 0;
    sptSet[source] = true;
    int curr = source;

    for(int i = 0; i < numVertices-1; i++){

        //update adjacent vertices
        for(int j = 0; j < numVertices; j++){
            double checkDist = matrix[curr][j] + dist[curr];
            if( !sptSet[j] && (checkDist < dist[j])){
                dist[j] = checkDist;
                prev[j] = curr;
            }
        }

        //find the shortest path 
        double min = numeric_limits<double>::infinity();
        for(int j = 0; j < numVertices; j++){
            if( !sptSet[j] && dist[j] <= min){
                min = dist[j];
                curr = j;
            }
        }
        sptSet[curr] = true;
    }
}



int getPath(int source, int dest, const int* prev, int*& path){
    int length = 1;
    int temp = prev[dest];

    while(temp != source){
        temp = prev[temp];
        length ++;
    }

    path = new int[length+1];
    path[0] = source;
    temp = dest;
    for(int i = 0; i < length; i ++){
        path[length - i] = temp;
        temp = prev[temp];
    }
    return length+1;
}



void dijkstra(const int* const * adj, const double* const * weights, const int* lengths, int numVertices, int source, double*& dist, int*& prev){
    dist = new double[numVertices];
	prev = new int[numVertices];
	for (int i = 0; i < numVertices; i++){
		dist[i] = numeric_limits<double>::infinity();
		prev[i] = -1;
	}


    BinaryHeap heap = BinaryHeap(dist, numVertices);
    heap.decreasePriority(source,0);
    heap.popMin();
    dist[source] = 0;
    //prev[source] = source;

    int curr = source;
    for(int i = 1; i < numVertices; i++){
		for(int j = 0; j < lengths[curr] ;j++){
            double update = dist[curr] + weights[curr][j];
			if(heap.contains(adj[curr][j]) && update < dist[adj[curr][j]]){
                heap.decreasePriority(adj[curr][j], update);
                prev[adj[curr][j]] = curr;
                dist[adj[curr][j]] = update;
            }		
            
		}
        //cout << "dist: " << dist[0] << " "<< dist[1] << " "<< dist[2] << " "<< dist[3] << endl;
        //cout << "prev: " << prev[0] << " "<<  prev[1] << " "<< prev[2]<< " " << prev[3]  << endl;
        //cout << "heap: " << heap.heap[0] << " "  << heap.heap[1] << " " << heap.heap[2] << " " << heap.heap[3]<< endl;
        curr = heap.getMin();
        //cout << " curr: " << curr  << "\n" << endl;
        dist[curr] = heap.getPriority(curr);
        heap.popMin();
    }
    

        

}