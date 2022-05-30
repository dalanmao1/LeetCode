#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int step1 = cost[1];
        int step2 = cost[0];
        int minval = 0;
        if (cost.size() == 3)
        {
            return min(step1, step1 + step2);
        }

        for (int i = 2; i < cost.size(); ++i)
        {

            minval = cost[i]+min(step1, step2);
            step2 = step1;
            step1 = minval;
        }
        minval=min(step1,step2);//最后一步需要判断
        return minval;
    }
};
// @lc code=end
