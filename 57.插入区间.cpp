#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int sz = intervals.size();
        auto it = intervals.end();
        int i = 0;
        vector<vector<int>> sol;
        while (i < sz && intervals[i][1] < newInterval[0])
        {
            sol.push_back(intervals[i]);
            ++i;
        }
        while (i < sz && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            ++i;
        }
        sol.push_back(newInterval);
        while (i < sz)
        {
            sol.push_back(intervals[i]);
            ++i;
        }

        return sol;
    }
};
// @lc code=end
