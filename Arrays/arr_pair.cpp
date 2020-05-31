#include <iostream>
#include <map>

using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 13;
    map<int, int> m;
    for (int i = 0; i < n; ++i)
    {
        if (m.find(k - arr[i]) != m.end())
        {
            cout << "Found";
            return 0;
        }
        m[arr[i]] += 1;
    }
    cout << "Not found!";
    return 0;
}