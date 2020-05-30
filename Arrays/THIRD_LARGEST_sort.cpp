#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int arr[] = {12, 45, 1, -1, 45, 54, 23, 5, 0, -10};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    int c = 0, check = INT_MAX;
    for (int i = 1; i <= n; ++i)
    {
        if (c < 3)
        {
            if (check == arr[n - i])
                continue;
            cout << arr[n - i] << " ";
            check = arr[n - i];
            ++c;
        }
        else
        {
            break;
        }
    }
    // cout << arr[n - 1] << " " << arr[n - 2] << " " << arr[n - 3];
    return 0;
}