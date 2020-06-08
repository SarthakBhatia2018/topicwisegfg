#include <iostream>
#include <math.h>

using namespace std;

void find_prefix(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        arr[i] += arr[i - 1];
    }
}

void print_arr(int arr[], int start, int end)
{
    for (int i = start; i <= end; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int find_sum(int arr[], int i, int j)
{
    if (i == 0)
        return arr[j];
    return arr[j] - arr[i - 1];
}

void print_sub(int arr[], int n, int b[])
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            int s = find_sum(arr, i, j);
            if ((int)sqrt(s) - sqrt(s) == 0)
                print_arr(b, i, j);
        }
    }
}

int main()
{
    int arr[] = {1, 4, 2, 3, 5};
    const int n = sizeof(arr) / sizeof(arr[0]);
    int b[n];
    for (int i = 0; i < n; ++i)
        b[i] = arr[i];
    print_arr(arr, 0, n - 1);
    find_prefix(arr, n);
    print_sub(arr, n, b);
    return 0;
    // 1 5 7 10 15
}