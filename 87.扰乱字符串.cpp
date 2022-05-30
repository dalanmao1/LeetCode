#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] ÈÅÂÒ×Ö·û
 */

// @lc code=start
class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        if (n != m)
            return 0;
        bool dp[n][n][n + 1];

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dp[i][j][1] = s1[i] == s2[i];
            }
        }

        for (int len = 2; len <= n; ++len)
        {
            for (int i = 0; i <= n - len; ++i)
            {
                for (int j = 0; j <= n - len; ++j)
                {
                    for (int k = 1; k <= len - 1; ++k)
                    {
                        if (dp[i][j][k] == 1 && dp[i + k][j + k][len - k] == 1)
                        {
                            dp[i][j][len] = 1;
                            break;
                        }
                        if (dp[i][j + len - k][k] && dp[i + k][j][len - k])
                        {
                            dp[i][j][len] = 1;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};
// @lc code=end
