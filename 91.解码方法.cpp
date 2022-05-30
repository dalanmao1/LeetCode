#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution
{
public:
    int numDecodings(string s)
    {
        int sz = s.size();

        if (s[0] == '0')
            return 0;
        if (sz == 1)
            return 1;

        int dp[sz];
        dp[0] = 1;
        for (int i = 1; i < sz; ++i)
        {
            if (s[i] == '0')
            {
                if (s[i - 1] == '1' || s[i - 1] == '2')
                {
                    dp[i] = i > 1 ? dp[i - 2] : 1;
                }
                else
                    return 0;
            }
            else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
            {
                dp[i] = i > 1 ? dp[i - 2] + dp[i - 1] : 1 + dp[i - 1];
            }
            else
                dp[i] = dp[i - 1];
        }
        return dp[sz - 1];
    }
};
// @lc code=end
