#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<vector<int>> res)
{
    for (int i = 0; i < res.size(); ++i)
    {
        for (int j = 0; j < res[i].size(); ++j)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res = {};
        res.push_back({});
        for (int i = 0; i < nums.size(); ++i)
        {
            int n = res.size();
            for (int j = 0; j < n; ++j)
            {
                vector<int> a = res[j];
                a.push_back(nums[i]);
                res.push_back(a);
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> v = {1, 2, 3, 4};
    vector<vector<int>> res = s.subsets(v);
    print_vec(res);
    return 0;
}