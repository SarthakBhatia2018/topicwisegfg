#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

void func(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i)
        m[arr[i]] += 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p; //Min heap
    for (auto x : m)
    {
        p.push({x.second, x.first});
        if (p.size() > k)
            p.pop();
    }
    while (!p.empty())
    {
        cout << p.top().second << " ";
        p.pop();
    }
}

int main()
{
    int arr[] = {1, 1, 1, 3, 3, 2, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    func(arr, n, k);
    return 0;
}