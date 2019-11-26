#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "readGraph.hpp"
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
        //REQUIRE(dist[0] == 9.5);
        //REQUIRE(prev[2] == 1);
        
        int* path;
        //int num = getPath(1, 3, prev, path);
        //cout << num << endl;
        
        for(int i = 0; i < 4; i ++){
            dijkstra(matrix, numV, i, dist, prev);
            cout << "\n------------TESTING " << i << "------------" <<endl;     
            for(int i = 0; i < 6; i ++)
                cout  << prev[i] << " ";
            cout << endl;
            
        }
            /*cout << "\n------------TESTING " << i << "------------" <<endl;
            dijkstra(matrix, numV, i, dist, prev);
            cout << "0: " <<  dist[0] << "      " << prev[0] << endl;
            cout << "1: " <<  dist[1] << "      " << prev[1] << endl;
            cout << "2: " <<  dist[2] << "      " << prev[2] << endl;
            cout << "3: " <<  dist[3] << "      " << prev[3] << endl;
        }*/
        
        
        
        delete [] dist;
        delete [] prev;


    }
}