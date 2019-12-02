#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "readGraph.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


TEST_CASE("TESTING readGraph Class ")
{

    SECTION("TESTING readGraph1")
    {   
        double** matrix;
        string* vLabel;
        string** eLabel;
        ifstream input;
        input.open("graph.txt");
        int numV = readGraph(input, matrix, vLabel, eLabel);
        REQUIRE(numV == 4);
        //for(int i = 0; i < numV; i ++){
         //   delete matrix[i];
         //   delete eLabel[i];
        //}
        delete [] vLabel;
        delete [] eLabel;
        delete [] matrix;
    }

    SECTION("TESTING readGraph2")
    {
        int** adj, *lengths;
        double ** weights;
        string* vLabel;
        string** eLabel;
        ifstream input;
        input.open("graph.txt");
        int numV = readGraph(input, adj, weights, lengths, vLabel, eLabel);
        REQUIRE(adj[0][0] == 3);
       // for(int i = 0; i < numV; i ++){
         //   delete adj[i];
         //   delete eLabel[i];
         //   delete weights[i];
       // }
        delete [] vLabel;
        delete [] eLabel;
        delete [] weights;
        delete [] adj;
    }

    SECTION("TESTING readGraph3")
    {
        int** edgeList, numEdges;
        double * weights;
        string* vLabel;
        string* eLabel;
        ifstream input;
        input.open("graph.txt");
        int numV = readGraph(input, edgeList, weights, numEdges, vLabel, eLabel);
        REQUIRE(edgeList[3][0] == 2);
       // for(int i = 0; i < numV; i ++){
       //     delete edgeList[i];
       // }
        delete [] vLabel;
        delete [] eLabel;
        delete [] weights;
        delete [] edgeList;
    }
}
