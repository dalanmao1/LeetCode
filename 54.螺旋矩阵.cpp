#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> sol;
        if (matrix.empty())
        {
            return sol;
        }
        //定义边界
        int up = 0;
        int down = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        int i = 0;
        while (1)
        {
            for (i = left; i <= right; ++i)
                sol.push_back(matrix[up][i]); //向右
            if (++up > down)                  //重新定义上边�?
                break;

            for (i = up; i <= down; ++i)
                sol.push_back(matrix[i][right]); //向下

            if (--right < left) //重新定义右边�?
                break;
            for (i = right; i >= left; --i)
                sol.push_back(matrix[down][i]); //向左

            if (--down < up) //重新定义下边�?
                break;
            for (i = down; i >= up; --i)
                sol.push_back(matrix[i][left]); //向上
            if (++left > right)                 //重新定义左边�?
                break;
        }
        return sol;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<vector<int>> ivec{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution sol;
    sol.spiralOrder(ivec);
    return 0;
}
