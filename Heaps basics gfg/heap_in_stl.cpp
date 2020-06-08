#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        m[t] += 1;
    }
    priority_queue<int> q;
    for (auto x : m)
    {
        q.push(x.second);
    }
    int t = n / 2;
    int c = 0;
    while (!q.empty())
    {
        n -= q.top();
        q.pop();
        ++c;
        if (n <= t)
        {
            cout << c;
            return 0;
        }
    }
    return 0;
}