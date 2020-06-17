#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class maxHeap
{
public:
    int size;
    int capacity;
    vector<int> heap;

    int parent(int i) { return (i - 1) >> 1; };
    int left(int i) { return i << 1 + 1; };
    int right(int i) { return i << 1 + 2; };

public:
    maxHeap(int capacity);
    void insert(int val);
    void print_heap();
    int extractmax();
    void heapify(int i);
};

maxHeap::maxHeap(int capacity)
{
    this->capacity = capacity;
    size = 0;
    heap.resize(capacity);
}

void maxHeap::insert(int val)
{
    if (size == capacity)
    {
        cout << "Heap Full!\n";
        return;
    }
    int i = size;
    heap[size] = val;
    size++;
    while (i > 0 && heap[parent(i)] < heap[i])
    {
        swap(heap[parent(i)], heap[i]);
        i = parent(i);
    }
    cout << "After inserting " << val << ":" << endl;
    print_heap();
    cout << endl;
}

int maxHeap::extractmax()
{
    if (size == 0)
    {
        cout << "Empty Heap";
        return -1;
    }
    else if (size == 1)
    {
        --size;
        return heap[0];
    }
    else
    {
        int m = heap[0];
        heap[0] = heap[size - 1];
        --size;
        heapify(0);
        return m;
    }
    return -1;
}

void maxHeap::heapify(int i)
{
    int l = left(i);
    int r = right(i);
    int max = i;

    if (l < size && heap[l] > heap[max])
        max = l;

    if (r < size && heap[r] > heap[max])
        max = r;

    if (max != i)
    {
        swap(heap[max], heap[i]);
        heapify(max);
    }
}

void maxHeap::print_heap()
{
    int i = 0;
    int power = 0;
    while (i < size)
    {
        for (int j = 0; j < pow(2, power); ++j)
        {

            cout << heap[i] << " ";
            ++i;
            if (i == size)
                break;
        }
        cout << endl;
        power++;
    }
}
// 1 2 3 4 5
int main()
{
    maxHeap h(10);
    h.insert(5);
    h.insert(15);
    h.insert(-5);
    h.insert(-50);
    h.insert(-500);
    h.insert(-15);
    h.insert(245);
    h.insert(52);
    cout << h.extractmax() << endl;
    // h.print_heap();
    // cout << h.extractmax();
    cout << endl;
    for (int i = 0; i < h.size; ++i)-
        cout << h.heap[i] << " ";
    // h.print_heap();
    return 0;
}