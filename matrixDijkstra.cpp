#include <iostream>
#include <chrono>
#include "readGraph.hpp"
#include "shortestPath.hpp"
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    string inGraph = argv[1];
    string output = argv[2];
    int source = stoi(argv[3]);
    int dist = stoi(argv[4]);
    double* distination;
    ifstream fin;
    fin.open(inGraph);
    string* vLabel, *eLabel;
    double** m;
    int* prev, *path;
    int numVer = readGraph(fin, m, vLabel, eLabel);

    auto start = chrono::system_clock::now();
    dijkstra(m, numVer, source, distination, prev);
    auto end = chrono::system_clock::now();
    auto dur = end - start;
    auto durNS = chrono::duration_cast<chrono::nanoseconds>(dur);
    double elapsed = (double)durNS.count();
    cout << "number of nanoseconds for djkstra's algo: " << elapsed << endl;

    int len = getPath(source, dist, prev, path);


}