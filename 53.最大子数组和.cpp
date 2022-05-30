#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int dp = 0;
        int maxval = nums[0];
        for (auto i : nums)
        {
            dp = max(dp + i, i);
            maxval = max(dp, maxval);
        }
        return maxval;
    }
};
// @lc code=end
