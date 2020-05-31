#include <iostream>
#include <queue>

using namespace std;

void find_closest(int arr[], int n, int x, int k)
{
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == x)
            continue;
        q.push({abs(arr[i] - x), arr[i]});
        if (q.size() > k)
            q.pop();
    }
    while (!q.empty())
    {
        cout << q.top().second << " ";
        q.pop();
    }
}

int main()
{
    int arr[] = {1, 2, 3, 6, 5, 5, 4, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5, k = 4;
    find_closest(arr, n, x, k);
    return 0;
}