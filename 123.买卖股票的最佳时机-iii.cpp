#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 因为只能交易 2 次，所以定义 2 组 buy 和 sell
        int fstbuy = INT_MIN, fstsell = 0;
        int secbuy = INT_MIN, secsell = 0;
        for (auto &p : prices)
        {
            fstbuy = max(fstbuy, -p);           // 第一次买 -p
            fstsell = max(fstsell, fstbuy + p); // 第一次卖 fstbut + p
            secbuy = max(secbuy, fstsell - p);  // 第一次卖了后现在买 fstsell - p
            secsell = max(secsell, secbuy + p); // 第二次买了后现在卖 secbuy + p
        }
        return secsell;
    }
};
// @lc code=end
