#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
class heapp
{
private:
    int capacity;
    int size;
    vector<int> heap;
    int parent(int i) { return (i - 1) >> 1; };
    int left(int i) { return i << 1 + 1; };
    int right(int i) { return i << 1 + 2; };

public:
    heapp(int capacity);
    void print_heap();
    int extractmax();
    void heapify(int i);
    void insert(int val);
    void heapsort();
    void change_key(int, int);
};

heapp::heapp(int capacity)
{
    this->capacity = capacity;
    size = 0;
    heap.resize(capacity);
}

void heapp::insert(int val)
{
    if (size == capacity)
    {
        cout << "Heap Full";
        return;
    }
    int i = size;
    heap[size] = val;
    ++size;

    change_key(i, val);
}

int heapp::extractmax()
{
    if (size == 0)
    {
        cout << "Empty heap";
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
}

void heapp::change_key(int i, int val)
{
    while (i > 0 && heap[(i - 1) / 2] < heap[i])
    {
        swap(heap[(i - 1) / 2], heap[i]);
        i = (i - 1) / 2;
    }
}

void heapp::print_heap()
{
    int val = 1;
    int power = 0;
    for (int i = 0; i < size; ++i)
    {
        if (val == i)
        {
            cout << endl;
            power += 1;
            val += pow(2, power);
        }
        cout << heap[i] << " ";
    }
}

void heapp::heapify(int i)
{
    int l = left(i);
    int r = right(i);
    int large = i;

    if (l < size && heap[l] > heap[large])
        large = l;

    if (r < size && heap[r] > heap[large])
        large = r;

    // cout << "Heapifying works!\n";
    // cout << heap[i] << " " << heap[max];
    if (large != i)
    {
        swap(heap[large], heap[i]);
        heapify(large);
    }
}

void heapp::heapsort()
{
    int heap_size = size;
    int j = heap_size;
    for (int i = 1; i <= heap_size; ++i)
    {
        heap[j - 1] = extractmax();
    }
    cout << endl;
    for (j = 0; j < heap_size; ++j)
    {
        cout << heap[j] << " ";
    }
}

int main()
{
    heapp h(10);
    h.insert(5);
    h.insert(53);
    h.insert(15);
    h.insert(-5);
    h.insert(0);
    h.insert(12);
    h.insert(100);
    h.print_heap();
    cout << endl;
    cout << h.extractmax() << endl;
    cout << h.extractmax() << endl;
    cout << h.extractmax() << endl;
    cout << h.extractmax() << endl;
    h.print_heap();
    return 0;
}
