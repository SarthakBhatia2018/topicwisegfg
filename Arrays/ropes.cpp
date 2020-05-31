#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void conn_ropes(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> p;
    for (int i = 0; i < n; ++i)
        p.push(arr[i]);
    int Tcost = 0;
    while (p.size() >= 2)
    {
        int a = p.top();
        p.pop();
        int b = p.top();
        p.pop();
        p.push(a + b);
        Tcost = Tcost + a + b;
    }
    cout << Tcost << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    conn_ropes(arr, n);
    return 0;
}