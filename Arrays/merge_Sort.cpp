#include <iostream>

using namespace std;

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void merge(int l[], int nl, int r[], int nr, int *arr)
{
    int i = 0, j = 0, k = 0;
    while (i < nl && j < nr)
    {
        if (l[i] < r[j])
        {
            arr[k] = l[i];
            ++i;
        }
        else
        {
            arr[k] = r[j];
            ++j;
        }
        ++k;
    }
    while (i < nl)
    {
        arr[k] = l[i];
        ++i;
        ++k;
    }
    while (j < nr)
    {
        arr[k] = r[j];
        ++j;
        ++k;
    }
}

void merge_sort(int *arr, int n)
{
    if (n < 2)
        return;
    int mid = n / 2;
    int l[mid], r[n - mid];
    for (int i = 0; i < mid; ++i)
        l[i] = arr[i];
    for (int i = 0; i < n - mid; ++i)
        r[i] = arr[i + mid];
    merge_sort(l, mid);
    merge_sort(r, n - mid);
    merge(l, mid, r, n - mid, arr);
}

int main()
{
    int arr[] = {2363, 235, 23, 6, 236, 23, 623};
    int n = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, n);
    print_arr(arr, n);
    return 0;
}