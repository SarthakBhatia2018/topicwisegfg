#include <iostream>
#include <set>

using namespace std;

int main()
{
    int arr[] = {7, 10, 4, 3, 3, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    set<int> s;
    for (int i  = 0; i < n; ++i)
    {
        s.insert(arr[i]);
    }
    int k = 4;
    int a = 0;
    for (auto x : s)
    {
        ++a;
        if (a == k)
        {
            cout << x;
            break;
        }
    }
    return 0;
}