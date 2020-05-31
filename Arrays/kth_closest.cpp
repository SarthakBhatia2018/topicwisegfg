#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void find_closest(int arr[], int n, int x, int k)
{
    priority_queue<pair<int, int>> p;
    for (int i = 0; i < n; ++i)
    {
        p.push({abs(arr[i] - x), arr[i]});
        if (p.size() > k)
            p.pop();
    }
    while (!p.empty())
    {
        cout << p.top().second << " ";
        // cout << p.top().first << " " << p.top().second << endl;
        p.pop();
    }
}
int main()
{
    int arr[] = {5, 9, 4, 3, 1};
    int x = 7, k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    find_closest(arr, n, x, k);
    return 0;
}