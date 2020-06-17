#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    swap(arr[0], arr[5]);
    for (int i = 0; i < 6; ++i)
        cout << arr[i] << " ";
    return 0;
}