#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool check_bound(int i, int j, vector<vector<bool>> visited, int R, int C)
    {
        if (i >= 0 && j >= 0 && i < R && j < C && !visited[i][j])
            return true;
        return false;
    }
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        if (matrix.size() == 0)
            return res;
        int R = matrix.size();
        int C = matrix[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C));
        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};
        int r = 0, c = 0, di = 0, cr, cc;
        
        for (int i = 0; i < R * C; ++i)
        {
            res.push_back(matrix[r][c]);
            visited[r][c] = true;
            cr = r + dr[di];
            cc = c + dc[di];
            if (check_bound(cr, cc, visited, R, C))
            {
                r = cr;
                c = cc;
            }
            else
            {
                di = (di + 1) % 4;
                r += dr[di];
                c += dc[di];
            }
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
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<int> res = s.spiralOrder(matrix);
    print_matrix(res);
    return 0;
}