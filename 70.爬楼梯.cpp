/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] ÅÀÂ¥ÌÝ
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n < 4)
            return n;
        else
        {
            int val = 0;
            int i_last = 3, i_last2 = 2;
            for (int i = 4; i <= n; ++i)
            {
                val = i_last + i_last2;
                i_last2 = i_last;
                i_last = val;
            }
            return val;
        }
    }
};
// @lc code=end
