#include <iostream>

using namespace std;

void sort_nearly(int arr[], int n, int k)
{
    for (int i = 1; i < n; ++i)
    {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
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