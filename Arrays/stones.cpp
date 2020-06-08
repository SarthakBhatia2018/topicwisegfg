#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        multiset<int> s(stones.begin(), stones.end());
        // while (s.size() > 1)
        // {
        //     int a = s.begin();
        //     erase(s.begin());
        //     int b = s.begin();
        //     erase(s.begin());
        //     if (a != b)
        //         s.insert(abs(a - b));
        // }
        // if (s.empty())
        //     return 0;
        // return s.top();
        for(auto x:s)
            cout<<x<<" ";
        cout<<endl;
        return 0;
    }
};

int main()
{
    Solution s;
    vector<int> v = {2, 7, 4, 1, 8, 1};
    cout << s.lastStoneWeight(v);
    return 0;
}