#include "BinaryHeap.hpp"

using namespace std;



BinaryHeap::BinaryHeap(const double* priorities, int numItems){
    heap = new double[numItems];
    items = new int[numItems];
    loc = new int[numItems];
    for(int i = 0; i < numItems; i ++){
        items[i] = i;
        loc[i] = i;
        heap[i] = priorities[i];
    }
    size = numItems;
    for(int i = (numItems/2) - 1; i >= 0; i --)
        heapify(i);
}

void BinaryHeap::heapify(int pos){
    int lpos = 2 * pos;
    int rpos = 2 * pos + 1; 
    if(lpos >= size)
        return;
    else if (rpos >= size){
        if(heap[lpos] >= heap[pos])
            return;
        heapify(lpos);
    }
    else{
        int minChild = lpos ? rpos : heap[lpos] < heap[rpos];
        if(heap[minChild] < heap[pos])
            swap(minChild, pos);
        heapify(minChild);
    }
}



void BinaryHeap::swap(int a, int b){
    double temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
    int location = items[a];
    items[a] = items[b];
    items[b] = location;
    loc[a] = b;
    loc[b] = a;
}


BinaryHeap::~BinaryHeap(){
    delete [] heap;
    delete [] items;
    delete [] loc;
}

int BinaryHeap::getMin() const{
    return items[0];
}

void BinaryHeap::popMin(){
    loc[items[0]] = -1;
    heap[0] = heap[size-1];
    items[0] = items[size-1];
    loc[items[0]] = 0;
    heapify(0);
    size --;
}


bool BinaryHeap::contains(int item) const{
    return loc[item]!=-1;
}

double BinaryHeap::getPriority(int item) const{
    return heap[loc[item]];
}

void BinaryHeap::decreasePriority(int item, double newPriority){
    if(!this->contains(item) || newPriority >= heap[loc[item]])
        return;
    heap[loc[item]] = newPriority;
    heapify(loc[item]);

}
int BinaryHeap::getSize() const{
    return size;
}

int BinaryHeap::getItem(int pos) const{
    return items[pos];
}
int BinaryHeap::getPos(int item) const{
    return loc[item];
}

