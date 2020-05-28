#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

bool check(vector<int> v)
{
    map<int, int> m, m2;
    for (int i = 0; i < v.size(); ++i)
        m[v[i]] += 1;
    for (auto x : m)
    {
        if (m2.find(x.second) != m2.end())
            return false;
        m2[x.second] += 1;
    }
    m[v[0]] -= 1;
    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i] == v[i - 1])
        {
            m[v[i]] -= 1;
            continue;
        }
        else
        {
            if (m[v[i - 1]] != 0)
                return false;
            m[v[i]] -= 1;
        }
    }
    if (m[v.back()] != 0)
        return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    vector<string> res;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; ++i)
        {
            int q;
            cin >> q;
            v.push_back(q);
        }
        if (check(v))
            res.push_back("YES");
        else
            res.push_back("NO");
    }
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << endl;
    return 0;
}