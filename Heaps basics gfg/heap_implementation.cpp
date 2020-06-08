#include <iostream>
#include <vector>

using namespace std;
class minHeap
{
private:
    // Current size of the heap
    int size;
    // Max size of the heap
    int capacity;
    // Store elements in the heap
    vector<int> heap;
    // return the parent index
    int parent(int i) { return (i - 1) >> 1; };
    // to get the left child
    int left(int i) { return i << 1 + 1; };
    // to get the right child
    int right(int i) { return i << 1 + 2; };

public:
    // constructor
    minHeap(int capacity);
    // printHeap
    void printHeap();
    // insert elements in the min heap
    void insert(int val);
    // to extact the minimum of the heap
    int extractMin();
    // Recursively Heapify a subtree
    void heapify(int i);
};

minHeap::minHeap(int capacity)
{
    size = 0;
    this->capacity = capacity;
    heap.resize(capacity);
}

void minHeap::insert(int val)
{
    if (size >= capacity)
    {
        cout << "Heap full\n";
        return;
    }
    heap.push_back(val);
    ++size;
    int i = size - 1;
    heap[i] = val;
    while (i != 0 && heap[parent(i)] > heap[i])
    {
        swap(heap[parent(i)], heap[i]);
        i = parent(i);
    }
}

int minHeap::extractMin()
{
    if (size == 0)
    {
        cout << "Empty Heap\n";
        return -1;
    }
    else if (size == 1)
    {
        --size;
        return heap[0];
    }
    else
    {
        int min = heap[0];
        
    }
}
