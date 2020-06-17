#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int sum(int arr[], int n, int k1, int k2)
{
    priority_queue<int> p;
    for (int i = 0; i < n; ++i)
    {
        p.push(arr[i]);
        if (p.size() > k2)
            p.pop();
    }
    int sum = 0;
    while (p.size() != k1)
    {
        p.pop();
        if (p.size() == k1)
            break;
        sum += p.top();
    }
    return sum;
}

int main()
{
    int arr[] = {10, 2, 50, 12, 48, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k1 = 4, k2 = 6;
    cout << sum(arr, n, k1, k2) << endl;
    return 0;
}