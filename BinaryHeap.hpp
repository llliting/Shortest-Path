#ifndef BINARYHEAP_HPP
#define BINARYHEAP_HPP


class BinaryHeap{
    private:
        void heapify(int i);
        void swap(int a, int b);
        double* heap;
        int* items;
        int* loc;
        int size;
        

    public:
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
