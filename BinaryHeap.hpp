#ifndef BINARYHEAP_HPP
#define BINARYHEAP_HPP


class BinaryHeap{
    //private:
    public:
        void heapify(int i);
        void swap(int a, int b);
        void bubbleUp(int idx);
        double* heap;
        int* items;
        int* loc;
        int size;
        int num;
        

   // public:
        BinaryHeap(const double* priorities, int numItems);
        ~BinaryHeap();
        int getMin() const;
        void popMin();
        bool contains(int item) const;
        double getPriority(int item) const;
        void decreasePriority(int item, double newPriority);
        int getSize() const;
        int getItem(int pos) const;
        int getPos(int item) const;

};

#endif 
