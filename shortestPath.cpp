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

int bellmanFord(const int* const * edges, const double* weights, int numVertices, int numEdges, int source, double*& dist, int*& prev){
    dist = new double[numVertices];
    prev = new int[numVertices];
    for(int i = 0; i < numVertices; i++){
        dist[i] = numeric_limits<double>::infinity();
        prev[i] = -1;
    }
    dist[source] = 0;
    for(int i = 1; i < numVertices-1; i ++){
        for(int j = 0; j < numEdges; j++){
            double update = weights[j] + dist[edges[j][0]];
            if(update < dist[edges[j][1]]){
                dist[edges[j][1]] = update;
                prev[edges[j][1]] = edges[j][0];
            }
        }
    } 
    for(int i = 0; i < numEdges; i++){
        if(dist[edges[i][1]] > dist[edges[i][0]] + weights[i])
            return edges[i][1];
    }
    return -1;
}

int getCycle(int vertex, const int* prev, int numVertices, int*& cycle){
    bool* helper = new bool[numVertices];
    for(int i = 0; i < numVertices; i++){
        helper[i] = false;
    }
    int i = vertex;
    //int counter = 1;
    while(!helper[i]){
       // cout << "i: " << i << endl;
        helper[i] = true;
        i = prev[i];
        //counter ++;
    }
    int start = i;
    int counter = 2;
    while(prev[i]!=start){
        i = prev[i];
        counter++;
    }
    cycle = new int[counter];
    int curr = vertex;
    for(int i = counter-1; i >= 0; i-- ){
        cycle[i] = curr;
        curr = prev[curr];
    }
    //for(int i = 0; i < counter; i ++)
      //  cout << cycle[i] << "-> "; 
    //cout << endl;
    //cout << "counter: " << counter << endl;
    delete [] helper;
    return counter;
}