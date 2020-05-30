#include <iostream>
#include <algorithm>

using namespace std;

void print_Arr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {4, 32, 534, 543, 534, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    print_Arr(arr, n);
    int k;
    cin >> k;
    cout<<arr[k-1];
    return 0;
}