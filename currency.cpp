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
    int source, dist, ** edgeList, numEdges, len;
    double* distination, *weights;
    ifstream fin;
    ofstream fout;
    fin.open(inGraph);
    fout.open(output);
    string* vLabel, *eLabel;
    int* prev, *path;
    int numVer = readGraph(fin, edgeList, weights, numEdges, vLabel, eLabel);
    //double* rate = new double [numEdges];
    for(int i = 0; i < numEdges; i++){
        weights[i] = log(weights[i] * (1-cost));
    }


    for(int i = 0; i < numVer; i++){
        if(vLabel[i] == source_str)
            source = i;
        if(vLabel[i] == dist_str)
            dist = i;
    }

    auto start = chrono::system_clock::now();
    int neg = bellmanFord(edgeList, weights, numVer, numEdges, source, distination, prev);
    auto end = chrono::system_clock::now();


    if(neg != -1){
         int* cycle;
        len = getCycle(neg, prev, numVer, cycle);
        cout << "Effective Exchange Rate Detected!" << endl;
        int weight = 0;
        for(int i = 0; i < len-1; i ++){
            for(int j = 0; j < numEdges; j++){
                if(edgeList[j][0] == cycle[i] && edgeList[j][1] == cycle[i+1])
                    weight += weights[j];
            }
        }
        cout << "Effective Exchange Rate:" << exp(weight) << endl;
        path = cycle;
    }
    else{
        len = getPath(source, dist, prev, path);
    }



    auto dur = end - start;
    auto durNS = chrono::duration_cast<chrono::microseconds>(dur);
    double elapsed = (double)durNS.count();
    cout << "number of microseconds for bellmanFord's algo: " << elapsed << endl;

    fout << len+1 << " " << len-1 << endl;
    for(int i = 0; i < numVer; i ++)
        fout << vLabel[i] << endl;
    for(int j = 0; j < len; j ++){
        for(int i = 0; i < numEdges; i ++){
            if(edgeList[i][0] == path[j] && edgeList[i][1] == path[j+1])
                fout << path[j] << " " << path[j+1] << " " << weights[i] << " " << eLabel[i] << endl;

        }
    }

    delete [] edgeList;    
    delete [] weights;
    delete [] distination; 
    delete [] vLabel;
    delete [] eLabel;
    delete [] prev;
    delete [] path;
    
    
        
}