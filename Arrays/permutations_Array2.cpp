#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void find_per(vector<vector<int>> &res, vector<int> &nums, int l, int r)
    {
        if (l > r)
        {
            res.push_back(nums);
            return;
        }
        for (int i = l; i <= r; ++i)
        {
            swap(nums[l], nums[i]);
            find_per(res, nums, l + 1, r);
            swap(nums[l], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.size() == 0)
        {
            return res;
        }
        find_per(res, nums, 0, nums.size() - 1);
        return res;
    }
};

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
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3,4};
    vector<vector<int>> res = s.permute(nums);
    print_vec(res);
    return 0;
}