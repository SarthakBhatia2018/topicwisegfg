#include <iostream>
#include <queue>
#include <climits>

using namespace std;

// ********     max heaps(n+klogn)   ***
// Build max heap O(n)
// heapify is log n for a element but when leaf is o(1)
// for k elements k*log(n)
void find_klar(int arr[], int n, int k)
{
    priority_queue<int> q(arr, arr + n);
    for (int i = 0; i < k; ++i)
    {
        cout << q.top() << " ";
        q.pop();
    }
}

// using min heaps  O(nlogk)
// void find_klar(int arr[], int n, int k)
// {
//     priority_queue<int, vector<int>, greater<int>> q;
//     for (int i = 0; i < n; ++i)
//     {
//         q.push(arr[i]);
//         if (q.size() > k)
//         {
//             q.pop();
//         }
//     }
//     while (!q.empty())
//     {
//         cout << q.top() << " ";
//         q.pop();
//     }
// }

// Using modified bubble sort O(nk)
// void find_klar(int arr[], int n, int k)
// {
//     for (int i = 0; i < k; ++i)
//     {
//         for (int j = 0; j < n-1; ++j)
//         {
//             if (arr[j] > arr[j + 1])
//                 swap(arr[j], arr[j + 1]);
//         }
//     }
//     int i=n-1,j=0;
//     while(j<k)
//     {
//         cout<<arr[i]<<" ";
//         --i;
//         ++j;
//     }
// }

/*

Using temp array O((n-k)k)
void find_min(int temp[], int n, int &min, int &pos)
{
    min = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        if (min > temp[i])
        {
            min = temp[i];
            pos = i;
        }
    }
}

void find_klar(int arr[], int n, const int k)
{
    int temp[k];
    int min = INT_MAX;
    int pos = -1;
    // O(k)
    for (int i = 0; i < k; ++i)
    {
        temp[i] = arr[i];
        if (min > temp[i])
        {
            min = temp[i];
            pos = i;
        }
    }

    // O((n-k)k)
    for (int i = k; i < n; ++i)
    {
        if (min < arr[i])
        {
            temp[pos] = arr[i];
            find_min(temp, k, min, pos);
        }
    }
    // O(k)
    for (int i = 0; i < k; ++i)
        cout << temp[i] << " ";
    cout << endl;
}
*/
void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    const int k = 3;
    print_arr(arr, n);
    find_klar(arr, n, k);
    return 0;
}