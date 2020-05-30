#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void print_kth(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> p;
    for (int i = 0; i < n; ++i)
    {
        p.push(arr[i]);
        if (p.size() > k)
            p.pop();
    }
    // for (int i = 0; i < n; ++i)
    // {
    //     if (arr[i] >= p.top())
    //         cout << arr[i] << " ";
    // }
    while (p.size() > 0)
    {
        cout << p.top() << " ";
        p.pop();
    }
}

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    print_arr(arr, n);
    print_kth(arr, n, k);
    return 0;
}