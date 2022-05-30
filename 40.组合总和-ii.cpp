#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 * 给定一个候选人编号的集�? candidates 和一个目标数 target ，找�? candidates 中所有可以使数字和为 target 的组合�?
 * candidates 中的每个数字在每个组合中只能使用 一�? �?
 * 注意：解集不能包含重复的组合�?
 */

/**
 * 思路�?
 * 用递归+回溯，关键在于去重复，所以需要排序一下，
 *
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> conbine;
    vector<int> row;

public:
    void dfs(vector<int> &candidates, int target, int idx)
    {
        if (target == 0)
        {
            conbine.push_back(row);
            return;
        }
        // target > 0不写函数体开头，代码更简�?
        for (int pos = idx; pos < candidates.size() && target > 0; ++pos)
        {
            // pos>0不可，会少算一个结�?,精髓就在这，比如1122,112可以再来�?112就不行了，当前重复可以使用，后面的重复就不能�?
            if (pos > idx && candidates[pos] == candidates[pos - 1])
                continue;
            row.push_back(candidates[pos]);
            dfs(candidates, target - candidates[pos], pos + 1);
            row.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return conbine;
    }
};
// @lc code=end
