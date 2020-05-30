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
    int arr[] = {4, 32, 534, 2, 543, 534, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    print_Arr(arr, n);
    cout << *min_element(arr +1, arr + 4);
    cout << endl;
    auto i = min_element(arr, arr + n);
    cout << *i;
    return 0;
}