#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int sz = prices.size();
        int dp[sz][2];

        dp[0][0] = 0;          //表示没持股票的利润状态
        dp[0][1] = -prices[0]; //表示持股票的利润状态

        for (int i = 1; i < sz; ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
        }
        return dp[sz - 1][0];
    }
};
// @lc code=end
