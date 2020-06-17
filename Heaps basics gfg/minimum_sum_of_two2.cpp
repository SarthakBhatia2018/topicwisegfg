#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    vector<int> v = {6, 8, 4, 5, 2, 3};
    sort(v.begin(), v.end());
    int num1 = 0;
    int num2 = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if ((i & 1) == 0)
            num1 = num1 * 10 + v[i];
        else
            num2 = num2 * 10 + v[i];
    }
    cout << num1 + num2 << endl;
    return 0;
}