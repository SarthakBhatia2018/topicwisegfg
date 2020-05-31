#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

void freq_sort(int arr[], int n)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i)
        m[arr[i]] += 1;
    priority_queue<pair<int, int>> p; //Max heap
    for (auto x : m)
    {
        p.push({x.second, x.first});
    }
    int k = 0;
    while (!p.empty())
    {
        for (int i = 0; i < p.top().first; ++i)
        {
            arr[k] = p.top().second;
            ++k;
        }
        p.pop();
    }
}

void print_Arr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {1, 1, 1, 2, 2, 3,3,3, 4,4,4,4,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    print_Arr(arr, n);
    freq_sort(arr, n);
    print_Arr(arr, n);
    return 0;
}