#include <iostream>

using namespace std;

bool check_min(int arr[], int n)
{
    for (int i = (n - 2) / 2; i >= 0; --i)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && arr[l] < arr[i])
            return false;
        if (r < n && arr[r] < arr[i])
            return false;
    }
    return true;
}

int main()
{
    int arr[] = {15, 10, 14, 25, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << check_min(arr, n);
    return 0;
}