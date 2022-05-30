#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution
{
public:
    int max(int a, int b)
    {
        if (a < b)
            return b;
        return a;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int maxval = 0, width = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int dp[m][n];
        // for (int i = 1; i < m; ++i)
        // {
        //     matrix[i][0] += matrix[i - 1][0] == 0 ? matrix[i - 1][0] : 0;
        //     maxval = max(matrix[i][0], maxval);
        // }
        // for (int i = 1; i < n; ++i)
        // {
        //     matrix[0][i] += matrix[0][i - 1] == 0 ? matrix[0][i - 1] : 0;
        //     maxval = max(matrix[0][i], maxval);
        // }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == '0')
                {
                    dp[i][j] = 0;
                    continue;
                }
                else
                {
                    dp[i][j] = j > 0 ? dp[i][j - 1] + 1 : 1;
                    width = dp[i][j];
                    for (int k = i; k >= 0; --k) //>=排除长度是1*1，里面只有一个1的情况
                    {
                        width = min(width, dp[k][j]);
                        if (width == 0) //这里最重要，一旦出现宽度是0的情况，不必继续了
                            break;
                        maxval = max(maxval, width * (i - k + 1));
                    }
                }
            }
        }
        return maxval;
    }
};
// @lc code=end
