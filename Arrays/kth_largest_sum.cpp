// Brute force
#include <iostream>
#include <queue>

using namespace std;

void find_kth_subarray(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> p;
    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        for (int j = i; j < n; ++j)
        {
            sum += arr[j];
            p.push(sum);
            if (p.size() > k)
                p.pop();
        }
    }
    cout << p.top() << " ";
}

int main()
{
    int arr[] = {10, -10, 20, -40} ;
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;
    find_kth_subarray(arr, n, k);
    return 0;
}