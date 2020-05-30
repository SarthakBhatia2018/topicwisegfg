#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void find_closest(int arr[], int n, int x, int k)
{
    vector<int> v(arr, arr + n);
    for (int i = 0; i < n; ++i)
    {
        v[i] = abs(v[i] - k);
    }
    for (int i = 0; i < k; ++i)
    {
        auto x = min_element(v.begin(), v.end());
        int ind = x - v.begin();
        cout << v[ind]+ << " ";
        v.erase(x);
    }
}
int main()
{
    int arr[] = {5, 6, 7, 8, 9};
    int x = 7, k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    find_closest(arr, n, x, k);
    return 0;
}