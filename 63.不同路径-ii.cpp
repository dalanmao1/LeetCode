#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] ‰∏çÂêåË∑ØÂæÑ II
 */

// @lc code=start
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid.size() == 0)
            return 0;
        const size_t m = obstacleGrid.size();
        size_t n = obstacleGrid[0].size();
        int dp[m][n]; //ª·±®¥Ì
        int i = 0, j = 0;
        for (i = 0; i < n && obstacleGrid[0][i] == 0; ++i)
        {
            dp[0][i] = 1;
        }
        for (; i < n; ++i)
            dp[0][i] = 0;

        for (i = 0; i < m && obstacleGrid[i][0] == 0; ++i)
        {
            dp[i][0] = 1;
        }
        for (; i < m; ++i)
            dp[i][0] = 0;

        for (i = 1; i < m; ++i)
        {
            for (j = 1; j < n; ++j)
            {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
