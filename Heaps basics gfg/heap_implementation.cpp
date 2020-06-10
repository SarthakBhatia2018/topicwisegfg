#include <iostream>
#include <vector>
#include <climits>

using namespace std;
class minHeap
{
    // private:
public:
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
        heap[0] = heap[size - 1];
        --size;
        heapify(0);
        return min;
    }
    return -1;
}

void minHeap::printHeap()
{
    for (int i = 0; i < size; ++i)
        cout << heap[i] << " ";
    cout << endl;
}

// void minHeap::heapify(int i)
// {
//     int l = left(i);
//     int r = right(i);
//     heap[size] = INT_MAX;
//     while (l < size || r < size)
//     {
//         if (l >= size)
//             l = size;
//         if (r >= size)
//             r = size;
//         int x = heap[l] < heap[r] ? l : r;
//         if (heap[x] < heap[i])
//         {
//             swap(heap[x], heap[i]);
//             l = left(x);
//             r = right(x);
//             i = x;
//         }
//         else
//             return;
//     }
// }

void minHeap::heapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < size && heap[l] < heap[smallest])
        smallest = l;
    else if (r < size && heap[r] < heap[smallest])
        smallest = r;

    if (smallest != i)
    {
        swap(heap[smallest], heap[i]);
        heapify(smallest);
    }
}
int main()
{
    minHeap h(10);
    h.insert(1);
    h.insert(10);
    h.insert(-1);
    h.insert(-100);
    h.insert(11);
    cout << h.extractMin();
    return 0;
}