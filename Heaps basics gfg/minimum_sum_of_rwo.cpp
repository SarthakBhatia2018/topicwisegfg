#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        priority_queue<int> p;
        while (n--)
        {
            int a;
            cin >> a;
            p.push(a);
        }
        string res = "";
        int carry = 0;
        while (p.size() > 1)
        {
            int a = p.top();
            p.pop();
            int b = p.top();
            p.pop();
            res = to_string((a + b + carry) % 10) + res;
            if (a + b + carry >= 10)
                carry = 1;
            else
                carry = 0;
        }
        if (p.size() == 1)
        {
            res = to_string(p.top() + carry) + res;
        }
        else if (carry == 1)
        {
            res = to_string(carry) + res;
        }
        stringstream s(res);
        int a;
        s >> a;
        cout << a << endl;
    }

    return 0;
}