#include <fstream>
#include <string>
#include <limits>
#include <iostream>

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
        //int minIdx;
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
    
}