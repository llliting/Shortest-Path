#include "BinaryHeap.hpp"
#include <iostream>
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
    num = numItems;
    for(int i = (numItems/2) - 1; i >= 0; i --)
        heapify(i);
        
}

void BinaryHeap::heapify(int pos){
    int lpos = 2 * pos + 1;
    int rpos = 2 * pos + 2; 
    if(lpos >= num)
        return;
    else if (rpos >= num){
        if(heap[lpos] >= heap[pos])
            return;
        swap(lpos, pos);
        heapify(lpos);
    }
    else{
        int minChild = lpos;
        if(heap[lpos] > heap[rpos])
            minChild = rpos;
        
        if(heap[minChild] < heap[pos]){
            swap(minChild, pos);
            heapify(minChild);
        }
        return;
        
    }
}



void BinaryHeap::swap(int a, int b){
    double temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
    int location = items[a];
    items[a] = items[b];
    items[b] = location;
    loc[items[a]] = a;
    loc[items[b]] = b;
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
    num --;
}


bool BinaryHeap::contains(int item) const{
    return loc[item]!=-1 && item < size;
}

double BinaryHeap::getPriority(int item) const{
    return heap[loc[item]];
}

void BinaryHeap::bubbleUp(int idx){
    int parent = (idx-1)/2;
    if(heap[idx] < heap[parent]){
        swap(idx, parent);
        bubbleUp(parent);
    }
    return;
}


void BinaryHeap::decreasePriority(int item, double newPriority){
    if(!this->contains(item) || newPriority >= heap[loc[item]])
        return;
    heap[loc[item]] = newPriority;
    bubbleUp(loc[item]);
}

int BinaryHeap::getSize() const{
    return num;
}

int BinaryHeap::getItem(int pos) const{
    return items[pos];
}
int BinaryHeap::getPos(int item) const{
    return loc[item];
}

