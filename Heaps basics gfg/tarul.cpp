#include <iostream>
#include <string>

using namespace std;

int func(string s)
{
    int c = 0;
    for (int i = 1; i < s.size(); ++i)
    {
        if (s[i] != s[i - 1])
            continue;
        else
        {
            if (s[i] == 'S')
                s[i] = 'R';
            else
                s[i] = 'S';
            ++c;
        }
    }
    return c;
}
int main()
{
    string s = "SRRRRS";
    cout << func(s);
    return 0;
}