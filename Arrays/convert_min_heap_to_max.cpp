#include <iostream>

using namespace std;

void max_heapify(int arr[], int i, int n)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int m = i;

    if (l < n && arr[l] > arr[i])
        m = l;

    if (r < n && arr[r] > arr[m])
        m = r;

    if (m != i)
    {
        swap(arr[i], arr[m]);
        max_heapify(arr, m, n);
    }
}

void convert(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; --i)
        max_heapify(arr, i, n);
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "MIN HEAP :";
    print(arr, n);
    convert(arr, n);
    cout<<"MAX HEAP :";
    print(arr, n);
    return 0;
}