#include "BinaryHeap.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    double prio[7] = {9.0, 4.0, 2.0, 3.0, 7.0, 8.0, 2.0};
    BinaryHeap bh = BinaryHeap(prio, 7);
    //cout << " min :  " << bh.getMin() << endl;
    //cout << "contain " << bh.contains(10) << endl; 
   // bh.popMin();
    bh.decreasePriority(0,0);
    cout << "size: " << bh.getSize() << endl;
        /*cout << "items: ";
        for(int i = 0; i < 7; i++){
            cout << bh.items[i] << " ";
        }
        cout << endl;
        */

        cout << "heap: ";
        for(int i = 0; i < 7; i++){
            cout << bh.heap[i] << " ";
        }
        cout << endl;

        /*cout << "location: ";
        for(int i = 0; i < 7; i++){
            cout << bh.loc[i] << " ";
        }
        cout << endl;
        */
}

        