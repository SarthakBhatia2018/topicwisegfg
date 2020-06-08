#include <iostream>
#include <queue>

using namespace std;

void sort_nearly(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> q(arr, arr + k + 1);
    int j = 0;
    for (int i = k + 1; i < n; ++i)
    {
        arr[j++] = q.top();
        q.pop();
        q.push(arr[i]);
    }
    while (false == q.empty())
    {
        arr[j++] = q.top();
        q.pop();
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
    int arr[] = {10, 9, 8, 7, 4, 70, 60, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    sort_nearly(arr, n, k);
    print_arr(arr, n);
    return 0;
}