#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

string rearrange(string s)
{
    unordered_map<char, int> m;
    for (char c : s)
        m[c] += 1;
    priority_queue<pair<int, char>> q;
    for (auto x : m)
    {
        q.push({x.second, x.first});
    }
    string res = "";
    while (q.size() > 1)
    {
        pair<int, char> p1 = q.top();
        q.pop();
        pair<int, char> p2 = q.top();
        q.pop();
        res += p1.second;
        res += p2.second;
        cout << p1.second << " " << p2.second << p1.first << " " << p2.first << endl;
        p1.first -= 1;
        p2.first -= 1;
        if (p1.first > 0)
            q.push(p1);
        if (p2.first > 0)
            q.push(p2);
    }
    if (q.size() > 0)
    {

        if (q.top().first > 1)
            return "";
        else
            res += q.top().second;
    }
    return res;
}

int main()
{
    string s = "abbabbaaab";
    cout << rearrange(s);
    return 0;
}