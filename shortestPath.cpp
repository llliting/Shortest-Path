#include <fstream>
#include <string>
#include <limits>


void dijkstra(const double* const * matrix, int numVertices, int source, double*& dist, int*& prev){
    dist = new double[numVertices];
    prev = new int[numVertices];
    bool sptSet[numVertices];
    for(int i = 0; i < numVertices; i++){
        dist[i] = numeric_limits<double>::infinity();
        prev[i] = numeric_limits<int>::quiet_NaN();
        sptSet[i] = false;
    }
    dist[source] = 0;
    sptSet[source] = true;
    int curr = source;
    for(int i = 0; i < numVertices-1; i++){

        //find the shortest path 
        double min = numeric_limits<double>::infinity();
        int minIdx;
        for(int j = 0; j < numVertices; j++){
            if( !sptSet[j] && dist[j] < min)
                min = dist[j];
                minIdx = j;
        }
        sptSet[minIdx] = true;
        
        //update adjacent vertices
        for(int j = 0; j < numVertices; j++){
            int checkDist = matrix[curr][j] + dist[curr];
            if( !sptSet[j] && checkDist < dist[j]){
                dist[j] = checkDist;
                prev[j] = curr;
            }
        }
    }
}



int getPath(int source, int dest, const int* prev, int*& path){
    int length = 1;
    int temp = dest;
    while(temp != source){
        int temp = prev[temp];
        length ++;
    }

    path = new int[length];
    temp = dest;
    for(int i = 0; i < length; i ++){
        path[length - 1 - i] = prev[dest];
        temp = prev[dest];
    }
    return length;
    
}

