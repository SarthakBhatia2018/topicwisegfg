#include <iostream>
#include <climits>

using namespace std;

void print_large3(int arr[], int n)
{
    int f = INT_MIN, s = INT_MIN, t = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > f)
        {
            t = s;
            s = f;
            f = arr[i];
        }
        else if (arr[i] > s)
        {
            t = s;
            s = arr[i];
        }
        else if(arr[i]>t)
        {
            t = arr[i];
        }
    }
    cout << f << " " << s << " " << t << endl;
}

void print_Arr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {1,11,10,2,4,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    print_Arr(arr, n);
    print_large3(arr, n);
    return 0;
}