#include "BinaryHeap.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    double prio[7] = {9.0, 4.0, 2.0, 3.0, 7.0, 8.0, 2.0};
    BinaryHeap bh = BinaryHeap(prio, 7);
        cout << "items: ";
        for(int i = 0; i < 7; i++){
            cout << bh.items[i] << " ";
        }
        cout << endl;
}

        