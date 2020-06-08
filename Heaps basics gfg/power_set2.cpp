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
    void backtrack(vector<vector<int>> &res, vector<int> nums, int start, vector<int> temp = {})
    {
        res.push_back(temp);
        for (int i = start; i < nums.size(); ++i)
        {
            temp.push_back(nums[i]);
            backtrack(res, nums, i + 1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        backtrack(res, nums, 0);
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