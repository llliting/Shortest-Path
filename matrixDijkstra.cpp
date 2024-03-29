#include <iostream>
#include <chrono>
#include "readGraph.hpp"
#include "shortestPath.hpp"
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    if (argc != 5) {
        cout << "Wrong Number of Command Line Arguments Passed";
        return 0;
    }

    string inGraph = argv[1];
    string output = argv[2];
    string source_str = argv[3];
    string dist_str = argv[4];
    int source, dist;
    double* distination, **m;
    ifstream fin;
    ofstream fout;
    fin.open(inGraph);
    fout.open(output);
    string* vLabel, **eLabel;
    int* prev, *path;
    int numVer = readGraph(fin, m, vLabel, eLabel);
    for(int i = 0; i < numVer; i++){
        if(vLabel[i] == source_str)
            source = i;
        if(vLabel[i] == dist_str)
            dist = i;
    }


    auto start = chrono::system_clock::now();
    dijkstra(m, numVer, source, distination, prev);
    auto end = chrono::system_clock::now();
    auto dur = end - start;
    auto durNS = chrono::duration_cast<chrono::microseconds>(dur);
    double elapsed = (double)durNS.count();
    cout << "number of microseconds for matrix djkstra's algo: " << elapsed << endl;

    int len = getPath(source, dist, prev, path);
    fout << len+1 << " " << len-1 << endl;
    for(int i = 0; i < numVer; i ++)
        fout << vLabel[i] << endl;

    double weight = 0;
    for(int i = 0; i < len-1; i++){
        fout << path[i] << " " << path[i+1] << " " << m[path[i]][path[i+1]] << " " << eLabel[path[i]][path[i+1]] << endl;
        weight += m[path[i]][path[i+1]];
    }
    cout << "total weight: " << weight << endl; 

    fin.close();
    fout.close();
    delete [] vLabel;
    delete [] distination;
    delete [] prev;
    delete [] path;
    for(int i = 0; i < numVer; i ++){
        delete [] eLabel[i];
        delete [] m[i];
    }

}