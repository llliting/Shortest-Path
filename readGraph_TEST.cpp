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
    }

    SECTION("TESTING readGraph2")
    {
        int** adj, *lengths;
        double ** weights;
        string* vLabel;
        string** eLabel;
        ifstream input;
        input.open("graph.txt");
        readGraph(input, adj, weights, lengths, vLabel, eLabel);
        REQUIRE(adj[0][0] == 3);
    }
}