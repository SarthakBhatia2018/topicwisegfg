#include <iostream>
#include <queue>

using namespace std;

void find_kth(int arr[], int n, int k)
{
    priority_queue<int> max_h;
    for (int i = 0; i < n; ++i)
    {
        max_h.push(arr[i]);
        if (max_h.size() > k)
            max_h.pop();
    }
    cout << max_h.top() << " ";
}

int main()
{
    int arr[] = {3, 1, 5, 14, 2, 6};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    find_kth(arr, n, k);
    return 0;
    
}