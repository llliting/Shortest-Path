#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "readGraph.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


TEST_CASE("TESTING readGraph Class ")
{

    SECTION("TESTING readGraph")
    {   
        double** matrix;
        string* vLabel;
        string** eLabel;
        ifstream input;
        input.open("graph.txt");
        int numV = readGraph(input, matrix, vLabel, eLabel);
        REQUIRE(numV == 4);
    }
}