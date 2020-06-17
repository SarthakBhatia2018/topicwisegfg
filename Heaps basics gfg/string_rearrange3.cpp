#include <iostream>
#include <queue>

using namespace std;

const int max_char = 26;
struct key
{
public:
    int freq;
    char ch;
    key(int freq, char c)
    {
        this->freq = freq;
        ch = c;
    }
};

bool operator<(const key &k1, const key &k2)
{
    return k1.freq < k2.freq;
}

void rearrange(string s)
{
    int n = s.length();
    int chars[max_char] = {0};

    for (char c : s)
        chars[c - 'a'] += 1;

    priority_queue<key> p;
    for (char c = 'a'; c <= 'z'; ++c)
    {
        if (chars[c-'a'])
        {
            key k(chars[c-'a'], c);
            p.push(k);
        }
    }
    string res = "";
    key temp(-1, '*');
    while (!p.empty())
    {
        key k = p.top();
        p.pop();
        res += k.ch;
        if (temp.freq > 0)
            p.push(temp);
        k.freq -= 1;
        temp = k;
    }
    if (res.length() == n)
        cout << res << endl;
    else
        cout << "Not Valid" << endl;
}

int main()
{
    string s = "aaaaabbcc";
    rearrange(s);
    return 0;
}