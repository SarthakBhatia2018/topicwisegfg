#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

// O(nlogn)
int sumBetweenTwoKth(int arr[], int n, int k1, int k2)
{
    sort(arr, arr + n);
    return accumulate(arr + k1, arr + k2 - 1, 0);
}

int main()
{
    int arr[] = {10, 2, 50, 12, 48, 13};
    int k1 = 2, k2 = 6;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << sumBetweenTwoKth(arr, n, k1, k2);
    return 0;
}