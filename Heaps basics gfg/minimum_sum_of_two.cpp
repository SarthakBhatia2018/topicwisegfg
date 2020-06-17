#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    vector<int> v = {5, 3, 0, 7, 4};
    sort(v.begin(), v.end());
    int carry = 0;
    string res;
    while (v.size() > 1)
    {
        int a = v.back();
        v.pop_back();
        int b = v.back();
        v.pop_back();
        res = to_string((a + b + carry) % 10) + res;
        if (a + b + carry >= 10)
            carry = 1;
        else
            carry = 0;
    }
    if (v.size() == 1)
    {
        res = to_string(v[0] + carry) + res;
    }
    else if (carry == 1)
    {
        res = to_string(carry) + res;
    }
    stringstream s(res);
    int x;
    s >> x;
    cout << x << endl;
    return 0;
}