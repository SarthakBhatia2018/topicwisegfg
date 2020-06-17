#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int arr[] = {5, 3, 0, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    priority_queue<int, vector<int>, greater<int>> q(arr, arr + n);
    int num1 = 0, num2 = 0;
    int j = 0;
    while (!q.empty())
    {
        if ((j & 1) == 0)
        {
            num1 = num1 * 10 + q.top();
        }
        else
        {
            num2 = num2 * 10 + q.top();
        }
        q.pop();
        ++j;
    }
    cout << num1 + num2 << endl;
    return 0;
}