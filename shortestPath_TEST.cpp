#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "readGraph.hpp"
#include "BinaryHeap.hpp"
#include "shortestPath.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


TEST_CASE("TESTING shortestPath Class ")
{
      
    SECTION("TESTING dijkstra")
    {   
        double** matrix;
        string* vLabel;
        string** eLabel;
        double* dist;
        int* prev;
        ifstream input;
        input.open("graph.txt");
        int numV = readGraph(input, matrix, vLabel, eLabel);
        int source = 3;
        dijkstra(matrix, numV, source, dist, prev);
        REQUIRE(dist[0] == 9.5);
        REQUIRE(prev[2] == 1);
        int* path;
        int num = getPath(source, 0, prev, path);
        REQUIRE(num == 4);

    
        
        delete [] dist;
        delete [] prev;
        delete [] path;

    }
    
  
    SECTION("TESTING dijkstra")
    {   

        int ** adj, *lengths;
        double** weights;
        string* vLabels;
        string** eLabels;
        double* dist;
        int* prev;
        ifstream input;
        input.open("graph.txt");
        int numV = readGraph(input, adj, weights, lengths, vLabels, eLabels);
        REQUIRE(numV == 4);
        int source = 3;
        dijkstra(adj, weights, lengths, numV,3, dist, prev);
        REQUIRE(dist[0] == 9.5);
        REQUIRE(prev[2] == 1);
        int* path;
        int num = getPath(source, 0, prev, path);
        REQUIRE(num == 4);
        delete [] dist;
        delete [] prev;
        delete [] path;
       

        /*
        for(int i = 0; i < 4; i ++){
            dijkstra(adj, weights, lengths, numV, i, dist, prev);
            cout<< " --------" << i << "-----------" << endl;
            for(int j = 0; j < 4; j ++)
                cout << dist[j] << " ";
            cout << endl;

            for(int j = 0; j < 4; j ++)
                cout << prev[j] << " ";
            cout << endl;
        } 
        */
        
    }
    
    SECTION("TESTING bellmanford & getPath")
    {  
        int ** edgeList, numEdges;
        double * weights;
        string * vLabels, * eLabels;
        ifstream input;
        input.open("graph2.txt");
        int numV = readGraph(input, edgeList, weights, numEdges, vLabels, eLabels);
        double * dist;
        int * prev;
        int source = 0;
        int negPath = bellmanFord(edgeList, weights, numV, numEdges, source, dist, prev);
        REQUIRE(dist[0] == -3);
        REQUIRE(prev[0] == 2);        
        //cout << "negpath" << negPath << endl;
       
        //for(int j = 0; j < 4; j ++)
          //      cout << dist[j] << " ";
            //cout << endl;

        int* cycle;
        int numCycles = getCycle(negPath, prev, numV, cycle);
        REQUIRE(numCycles == 5);
        cout << "numCycles: " << numCycles << endl;


        delete [] cycle;
        delete [] dist;
        delete [] prev;
        delete [] weights;
        delete [] vLabels;
        delete [] eLabels;
        for(int i = 0; i < numEdges; i ++){
            delete [] edgeList[i];
        }

    }

    
    
}