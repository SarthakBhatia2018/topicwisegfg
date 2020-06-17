#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// void sort_nearly_sorted(int *arr, int n, int k)
// {
//     priority_queue<int, vector<int>, greater<int>> p;
//     int j = 0;
//     for (int i = 0; i < n; ++i)
//     {
//         p.push(arr[i]);
//         if (p.size() > k)
//         {
//             arr[j] = p.top();
//             p.pop();
//             ++j;
//         }
//     }
//     while (p.size() > 0)
//     {
//         arr[j] = p.top();
//         p.pop();
//         ++j;
//     }
// }

void sort_nearly_sorted(int *arr, int n, int k)
{
    for (int j = 1; j < n; ++j)
    {
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 && key < arr[i])
        {
            arr[i + 1] = arr[i];
            --i;
        }
        arr[i + 1] = key;
    }
}

// 3,5, 6, 2, 8, 10, 9

void print_Arr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    print_Arr(arr, n);
    sort_nearly_sorted(arr, n, k);
    print_Arr(arr, n);
    return 0;
}