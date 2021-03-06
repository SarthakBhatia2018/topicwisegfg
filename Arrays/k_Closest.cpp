#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void find_closest(int arr[], int n, int x, int k)
{
    vector<int> v(arr, arr + n);
    for (int i = 0; i < n; ++i)
    {
        v[i] = abs(v[i] - x);
    }
    priority_queue<pair<int, int>> p;
    for (int i = 0; i < v.size(); ++i)
    {
        p.push({v[i], i});
        if (p.size() > k)
        p.pop();
    }
    while (!p.empty())
    {
        cout << arr[p.top().second] << " ";
        // cout << p.top().first << " " << p.top().second << endl;
        p.pop();
    }
}
int main()
{
    int arr[] = {5, 6, 7, 8, 9};
    int x = 7, k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    find_closest(arr, n, x, k);
    return 0;
}