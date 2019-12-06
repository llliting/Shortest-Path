#include <iostream>
#include <chrono>
#include "readGraph.hpp"
#include "shortestPath.hpp"
#include <fstream>
#include <string>
#include <cmath>

using namespace std;




int main(int argc, char* argv[]){
    if (argc != 6) {
        cout << "Wrong Number of Command Line Arguments Passed";
        return 0;
    }

    string inGraph = argv[1];
    string output = argv[2];
    string source_str = argv[3];
    string dist_str = argv[4];
    float cost = stof(argv[5]);

    int source, dist, ** edgeList, numEdges;
    double* distination, *weights;
    ifstream fin;
    ofstream fout;
    fin.open(inGraph);
    fout.open(output);
    string* vLabel, *eLabel;
    int* prev, *path;
    int len;
    int numVer = readGraph(fin, edgeList, weights, numEdges, vLabel, eLabel);
    double* logged = new double [numEdges];
    for(int i = 0; i < numEdges; i ++){
        logged[i] = -log(weights[i]) * (1-cost);
    }


    for(int i = 0; i < numVer; i++){
        if(vLabel[i] == source_str)
            source = i;
        if(vLabel[i] == dist_str)
            dist = i;
    }

    auto start = chrono::system_clock::now();
    int neg = bellmanFord(edgeList, logged, numVer, numEdges, source, distination, prev);
    auto end = chrono::system_clock::now();
    

    
    if(neg != -1){
        int* cycle;
        len = getCycle(neg, prev, numVer, cycle);
        cout << "Arbitrage Opportunity Detected!" << endl;
        path = cycle;
    }
    else{
        len = getPath(source, dist, prev, path);
    }


    auto dur = end - start;
    auto durNS = chrono::duration_cast<chrono::microseconds>(dur);
    double elapsed = (double)durNS.count();
    cout << "number of microseconds for bellmanFord's algo: " << elapsed << endl;
    
    
    fout << numVer << " " << len-1 << endl;
    for(int i = 0; i < numVer; i ++)
        fout << vLabel[i] << endl;
    
    double weight = 0;    
    for(int j = 0; j < len; j ++){
        for(int i = 0; i < numEdges; i ++){
            if(edgeList[i][0] == path[j] && edgeList[i][1] == path[j+1]){
                //fout << path[j] << " " << path[j+1] << " " << weights[i] << " " << eLabel[i] << endl;
                fout << path[j] << " " << path[j+1] << " " << exp(-logged[j]) << " " << eLabel[i] << endl;
                weight += logged[i];
            }
        }
    }
    cout << "Effective Exchange Rate:" << exp(-weight) << endl;

    for(int i = 0; i < numEdges; i++){
        delete [] edgeList[i];
    }
    
    delete [] weights;
    delete [] distination; 
    delete [] vLabel;
    delete [] eLabel;
    delete [] prev;
    delete [] path;
    
        
}






