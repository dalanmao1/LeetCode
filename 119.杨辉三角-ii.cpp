#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> row{1};
        int dp1 = 0, dp2 = 0;
        for (int i = 1; i < rowIndex + 1; ++i)
        {
            dp1 = 1;
            for (int j = 1; j < i; ++j)
            {
                dp2 = dp1;
                dp1 = row[j]; // dp当前行的当前值加上前一个值
                row[j] = dp1 + dp2;
            }
            row.push_back(1);
        }
        return row;
    }
};
// @lc code=end
