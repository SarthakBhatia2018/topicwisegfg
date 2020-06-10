#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        if (matrix.size() == 0)
            return res;
        int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; ++i)
                res.push_back(matrix[top][i]);
            ++top;
            for (int i = top; i <= bottom; ++i)
                res.push_back(matrix[i][right]);
            --right;
            if (left > right || top > bottom)
                break;
            for (int i = right; i >= left; --i)
                res.push_back(matrix[bottom][i]);
            --bottom;
            for (int i = bottom; i >= top; --i)
                res.push_back(matrix[i][left]);
            ++left;
        }
        return res;
    }
};

void print_matrix(vector<int> res)
{
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << " ";
    cout << endl;
}

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> res = s.spiralOrder(matrix);
    print_matrix(res);
    return 0;
}