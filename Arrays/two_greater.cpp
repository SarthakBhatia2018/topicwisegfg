#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
// int main()
// {
//     int arr[] = {2, 8, 7, 1, 5};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     sort(arr, arr + n);
//     int c = 0, i, check = INT_MAX;
//     for (i = n - 1; i >= 0; --i)
//     {
//         if (c < 2)
//         {
//             if (check == arr[i])
//                 continue;
//             check = arr[i];
//             ++c;
//         }
//         else
//         {
//             while (arr[i - 1] == check)
//                 --i;
//             break;
//         }
//     }
//     for (int j = 0; j <= i; ++j)
//         cout << arr[j] << " ";
//     return 0;
// }

pair<int, int> find_second(int arr[], int n)
{
    int first = INT_MIN, second = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second)
        {
            second = arr[i];
        }
    }
    return {first, second};
}

int main()
{
    int arr[] = {7, -2, 3, 4, 9, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    pair<int, int> p = find_second(arr, n);
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] != p.first && arr[i] != p.second)
            cout << arr[i] << " ";
    }
    return 0;
}