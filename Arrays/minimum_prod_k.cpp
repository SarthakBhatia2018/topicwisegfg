#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int arr[] = {11, 8, 5, 7, 5, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    int f = arr[0];
    int k = 4;
    for (int i = 1; i < k; ++i) 
        f *= arr[i];
    cout << f;
    return 0;
}