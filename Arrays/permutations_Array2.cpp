#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums,vector<int> numsnew,)
    {
        vector<vector<int>> res;
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
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> res = s.permute(nums);
    print_vec(res);
    return 0;
}