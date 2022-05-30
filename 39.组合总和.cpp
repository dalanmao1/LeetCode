#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 * 给你一�? 无重复元�? 的整数数�? candidates 和一个目标整�? target ，找�? candidates 中可以使数字和为目标�? target �? 所�? 不同组合 ，并以列表形式返回。你可以�? 任意顺序 返回这些组合�?
 * candidates 中的 同一�? 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的�?
 * 对于给定的输入，保证和为 target 的不同组合数少于 150 个�?
 */

// @lc code=start
class Solution
{
public:
    void dfs(vector<int> &candidates, int target, vector<vector<int>> &result, vector<int> &row, int idx)
    {
        if (idx == candidates.size())
        {
            return;
        }
        if (target == 0)
        {
            result.emplace_back(row);
            return;
        }
        //这是为什么要直接跳过
        dfs(candidates, target, result, row, idx + 1);
        if (target - candidates[idx] >= 0)
        {
            row.push_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], result, row, idx);
            row.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> row;
        dfs(candidates, target, result, row, 0);
        return result;
    }
};
// @lc code=end
