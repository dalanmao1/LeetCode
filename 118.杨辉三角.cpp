#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> out;
        out.push_back({1});
        vector<int> row{1, 1};
        int dp1 = 0, dp2 = 0;

        for (int i = 1; i < numRows; ++i)
        {
            dp1 = 1;
            for (int j = 1; j < i; ++j)
            {
                dp2 = dp1;
                dp1 = row[j]; // dp当前行的当前值加上前一个值
                row[j] = dp1 + dp2;
            }
            if (i > 1)
                row.push_back(1);
            out.push_back(row);
        }
        return out;
    }
};
// @lc code=end
