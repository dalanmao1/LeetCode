#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() < 2)
        {
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        auto low = intervals.begin(); //这边是迭代器
        auto fast = low + 1;
        vector<vector<int>> combine;

        while (fast < intervals.end())
        {
            if (*((*low).end() - 1) < *((*fast).begin()))
            {
                combine.push_back(*low);
                ++low;
                ++fast;
            }
            else
            {
                if (*((*low).end() - 1) > *((*fast).end() - 1)) //前者把后者吞�?
                {
                    *fast = *low;
                    ++low;
                    ++fast;
                }
                else
                {
                    *((*fast).begin()) = *((*low).begin());
                    ++low;
                    ++fast;
                }
            }
        }
        combine.push_back(*low);
        return combine;
    }
};
// @lc code=end
